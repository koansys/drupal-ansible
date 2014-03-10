<?php

/**
 * @file
 * Contains functions to output Html export to an Amazon S3 bucket.
 *
 * The Html Export module can prepare the output for distribution in more than
 * one way. Each implementation is in an separate file, making it easier to
 * extend.                                         .
 */

/**
 * A key idea in this code is that data may be exported to one or more buckets.
 *
 * The export bucket/s are given by an array with this format:
 *  $export_options['amazon_s3_bucket']['default'] = array (
 *    'bucket_name' => 'bucket_name',               // the bucket name
 *    'bucket_region'                          // Optional. Defaults to AmazonS3::REGION_US_E1
 *    'file_patterns' => '',                   // Optional. For example '*.mov, *.mp4,'
 *  );
 *
 *  If another bucket is used it could be $export_options['amazon_s3_bucket']['bucket2'].
 */

// An S3 batch is allowed a maximum of 100 items. We'll use the BATCH_SIZE. Later this can become an option
if (!defined('S3_BATCH_SIZE')) {
    define('S3_BATCH_SIZE', 20);
}

/*
 * To prepare for upload, we construct a list of files that might be eligible and assign them to one or more buckets.
 * Then if applicable we prune those where the previously uploaded file has the same MD5 signature as the local file.
 * The result provides a list of all files to upload, and their bucket..
 *
 */
function html_export_output_format_prepare_amazon_s3($export_options, &$context) {

  libraries_load('awssdk');

  static $buckets_exist;

  $s3 = new AmazonS3();

  $bucket_list = $export_options['amazon_s3_bucket'];

  // On the first run...
  if (!isset($context['sandbox']['progress'])) {

    //Some initialization...
    //Check the/each bucket exists, and create it if it doesn't
    if (!isset($buckets_exist)) {

      foreach ($bucket_list as $key => $bucket_info) {

        //Create the bucket on s3 if it doesn't exist
        if (!($s3->if_bucket_exists($bucket_info['bucket_name']))) {
          $create_bucket_response = $s3->create_bucket($bucket_info['bucket_name'],
              (isset($bucket_info['bucket_region']) ? $bucket_info['bucket_region'] : AmazonS3::REGION_US_E1)
          );
          // Todo - perhaps add more options for the bucket - e.g. public, private, used for static hosting etc.

          // Provided response was positive, wait until it exists before doing anything
          if ($create_bucket_response->isOK()) {
            while (!($s3->if_bucket_exists($bucket_info['bucket_name']))) {
               // Not yet? Sleep for 1 second, then check again
               sleep(1);
               // Todo - it shouldn't be possible for OK and not to exist. But if it does happen, then this is an endless loop.
            }

          }
          else {
            $buckets_exist = null;
            throw new Exception(t("The bucket named %name can't be created. Bucket names must be globally unique. Maybe this already exists.", array('name' => $bucket_info['bucket_name'])));
          }
        }
      }

      $buckets_exist = TRUE;
    }
    //Now construct the list of all files that might be uploaded
    //Export everything that's there.

    //Init the file list
    $file_list = array();
    $file_type_map = array();
    foreach ($bucket_list as $key => $bucket_info) {
      $file_list[$key] = array();

      // At the same time as initialising, create a list of filters mapped to bucket, which we need in order to assign files to buckets
      if (isset($bucket_list[$key]['file_patterns']) && $bucket_list[$key]['file_patterns'] != '' ) {
        // Get rid of spaces, * and to be left with file types separated by commas.
        $file_patterns = str_replace(' ', '', $bucket_list[$key]['file_patterns']);
        $file_patterns = str_replace('*', '', $file_patterns);
        $file_types = explode(',', $file_patterns);
        $file_type_list = array_flip($file_types);
        foreach ($file_type_list as $list_key => $list_data) {
          $file_type_list[$list_key] = $key;
        }
        $file_type_map = array_merge($file_type_map, $file_type_list);
      }
    }

    // Roll through the directory assigning each file to an S3 bucket.
    $count = 0;
    foreach (@file_scan_directory($export_options['export_path'], '/.*/', array('recurse' => TRUE)) as $fullfilepath => $file) {
      // Usually there won't be any file_map.
      if (empty($file_type_map)) {
        // Then everything belongs in default.
        $file_list['default'][] = $file;
      }
      else {
        // Otherwise...Grab the file ending if one exists
        $ending = strrchr($fullfilepath,'.');
        // And assign to a bucket using the map
        if (($ending !== FALSE) && isset($file_type_map[$ending])) {
          $file_list[$file_type_map[$ending]][] = $file;

          // But also, if the option is set, store it in default bucket too. This is useful when S3 is used and cloudfront, but there are changes.
          // This way a direct viewing of an html page in the S3 bucket is guaranteed to look right.
          if (isset($export_options['amazon_all_files_in_default']) && $export_options['amazon_all_files_in_default']) {
            $file_list['default'][] = $file;
          }
        }
        else {
          $file_list['default'][] = $file;
        }
      }
      $count++;
    }

    // Prepare the tracking for this stage of the batch
    $context['results']['output_prep'] = array();
    $prep_data = &$context['results']['output_prep'];
    $prep_data['file_list'] = $file_list;
    $prep_data['current_bucket'] = 'default';
    $prep_data['current_file_item'] = 0;
    $prep_data['max_bucket_size'] = array();
    foreach ($bucket_list as $bucket_key => $bucket_data) {
      $prep_data['max_bucket_size'][$bucket_key] = count($file_list[$bucket_key]);
    }

    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $count;
  }

  // We only need to do more processing if we need to check the MD5s.
  if ( !isset($export_options['amazon_export_changes']) ||
      ( isset($export_options['amazon_export_changes']) && !$export_options['amazon_export_changes']))
  {
    $context['finished'] = 1;
  }
  else {
    $prep_data = &$context['results']['output_prep'];
    $current_bucket = &$prep_data['current_bucket'];
    $current_file_item = &$prep_data['current_file_item'];

    $delete_path = $export_options['export_path'].'/';

    // process limit amount of records
    $count = 0;
    $bucket_max = $prep_data['file_list']['max_bucket_size'][$current_bucket];
    while ($count < HTML_EXPORT_PROCESS_LIMIT
      && $context['sandbox']['progress'] < $context['sandbox']['max']
    ) {

      //$context['message'] = t('Now processing file %path', array('%path' => 'temp place holder'));
      $context['message'] = t('Now comparing file %number with the Amazon S3 version', array('%number' => ($context['sandbox']['progress'] + 1) ));

        //Do something
      //Todo if we aren't going to upload all, then prune those where the MD5 matches
      //Create a batch of things to check and check, removing from $export_list those that match

      //What's the MD5 that S3 has?
      $s3_name = str_replace($delete_path, '', $prep_data['file_list'][$current_bucket][$current_file_item]->uri);
      $s3_file_info = $s3->get_object_metadata($bucket_list[$current_bucket]['bucket_name'], $s3_name);

      // If the file exists, then it has metadata, and if the metadata indicates the local file is the same, then there's no need to upload.
      if ($s3_file_info) {
        //Remove the " the tag sometimes contains at the same time
        $etag_digest = str_replace('"', '', $s3_file_info['ETag']);

        // Get the local file digest
        $file_digest = md5_file($prep_data['file_list'][$current_bucket][$current_file_item]->uri);
        // Todo - would it be useful to store the MD5, then reuse with upload?

        if (strcmp($etag_digest, $file_digest) == 0) {
          //They are the same. No need to upload... delete from the list
          unset($prep_data['file_list'][$current_bucket][$current_file_item]);
        }
      }

      // Update our progress information.
      $context['sandbox']['progress']++;
      $count++;
      $current_file_item++;

      // If it's the end of this bucket, flip to the next
      if ($current_file_item == $bucket_max) {
        $current_bucket = _html_export_get_next_bucket($current_bucket, $prep_data['file_list']);

        if ($current_bucket !== FALSE) {
          $current_file_item = 0;
          $bucket_max = $prep_data['file_list']['max_bucket_size'][$current_bucket];;
        }
        else {
          // No more buckets - we must be at the end.

          //Sanity check
          if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
            throw new Exception(t("Problem: Reached the end of the bucket list, but there should still be files to process."));
          }
        }
      }
    }

    // Inform the batch engine that we are not finished,
    // and provide an estimation of the completion level we reached.
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
    else {
      $context['finished'] = 1;

      // Todo - this might be a good place to reorder the uploads. We'd like .html files last. And it would be really nice to
      // size balance the list so that batches happen at about the same speed. But we don't know about batches yet.
    }
  }
}


/*
 *
 */
function _html_export_get_next_bucket($key, $arr) {
  $keys = array_keys($arr);
  $key_indexes = array_flip($keys);

  if (isset($keys[$key_indexes[$key] + 1])) {
    return $keys[$key_indexes[$key] + 1];
  }
  else {
    return FALSE;
  }
}



function html_export_output_format_amazon_s3($export_options, &$context) {

  libraries_load('awssdk');

   $s3 = new AmazonS3();

  $bucket_list = $export_options['amazon_s3_bucket'];

    // On the first run...
  if (!isset($context['sandbox']['progress'])) {
    // Break the list into batches.
    // Todo - we could be more sophisticated about this, trying to get batches of about the same number of bytes, with the
    // proviso that no batch exceeds S3_BATCH_SIZE

    // Amazon say: Performing PUTs against a particular bucket in alphanumerically increasing order by key name
    // can reduce the total response time of each individual call. Performing GETs in any sorted order can have a similar
    // effect. The smaller the objects, the more significantly this will likely impact overall throughput

    //Would also be good to upload .html last of all: it would be useful if Cloudfront was invalidated.
    $context['results']['output_save'] = array();
    $save_data = &$context['results']['output_save'];  // A shortcut for lots of stuff below.
    $save_data['current_bucket'] = 'default';
    $save_data['current_batch'] = 0;

    // Copy the file list from the previous step, chunking it.
    $save_data['export_list'] = array();
    $max = 0;
    foreach ($context['results']['output_prep']['file_list'] as $bucket_key => $filelist) {
      $save_data['export_list'][$bucket_key] = array_chunk($filelist, S3_BATCH_SIZE);
      $max += count($save_data['export_list'][$bucket_key]);
    }

    // Set up the progress meter
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $max;

    // Clean up the output from the previous step. It's no longer needed.
    unset($context['results']['output_prep']);
  }

  $save_data = &$context['results']['output_save'];  // The shortcut might not be initialised
  $batch = &$save_data['current_batch'];
  $current_bucket = &$save_data['current_bucket'];

  // Process limit amount of records
  $count = 0;
  $delete_path = $export_options['export_path'].'/';
  while ($count < HTML_EXPORT_PROCESS_LIMIT
    && $context['sandbox']['progress'] < $context['sandbox']['max']
  ) {

    $context['message'] = t('Now sending file %number to Amazon S3', array('%number' => ($context['sandbox']['progress'] + 1) ));

    // Prepare the batch

    if (!isset($save_data['export_list'][$current_bucket][$batch])) {
      // Sanity check - this should not be possible
      $context['message'] = t('Upload problem - sanity check broken');
      // Stop doing anything more.
      $context['finished'] = 1;
      $count = HTML_EXPORT_PROCESS_LIMIT;
    }
    else {

      // Build the upload batch, adding each file to the batch
      foreach ($save_data['export_list'][$current_bucket][$batch] as $bucket_key => $file) {
        $filename = str_replace($delete_path, '', $file->uri);
        $s3->batch()->create_object( $bucket_list[$current_bucket]['bucket_name'],
                                     $filename,
                                     array( 'fileUpload' => $file->uri,
                                            'acl'    => AmazonS3::ACL_PUBLIC,
                                            'headers' => array(
                                               'Content-MD5' => md5_file($file->uri),
                                             )
                                           )
                                    );
      }

      //Execute the batch upload
      $file_upload_response = $s3->batch()->send();

      // TOdo - check the MD5 of upload: I don't believe this is working, although I think I've followed the api
      // Todo - not convinced that this does not need try, catch - aka
      // 'Upload a publicly accessible file. File size, file type, and md5 hash are automatically calculated by the SDK'

      // Make sure all the responses are ok
      if (!$file_upload_response->areOK()) {
        $context['message'] = t('Upload problem');
        // Stop doing anything more.
        $context['finished'] = 1;
        $count = HTML_EXPORT_PROCESS_LIMIT;

        //Todo - check what it takes to cancel the next step. Maybe a flag?
        //Alternatively, reschedule the failed upload for a later batch?
      }
      else {

        // In the future we may have public or private s3.
        // For private we may want to pre-authenticate access for a while, so they are visible
        // Loop through the individual filenames
        //          foreach ($individual_filenames as $filename) {
        //              /* Display a URL for each of the files we uploaded. Since uploads default to
        //                 private (you can choose to override this setting when uploading), we'll
        //                 pre-authenticate the file URL for the next 5 minutes. */
        //              echo $s3->get_object_url($bucket, $filename, '5 minutes') . PHP_EOL . PHP_EOL;
        //          }

        $batch++;

        // If it's the end of this bucket, flip to the next
        if (!isset($save_data['export_list'][$current_bucket][$batch])) {
          $current_bucket = _html_export_get_next_bucket($current_bucket, $save_data['export_list']);

          $batch = 0;
          $bucket_max = count($save_data['file_list'][$current_bucket]);
        }

      }
    }

    // Update our progress information.
    $context['sandbox']['progress']++;
    $count++;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    if ($export_options['max_number_of_exports'] > 0) {
      $max = min($context['sandbox']['max'], $export_options['max_number_of_exports']);
      $context['finished'] = $context['sandbox']['progress']/$max;
    }
    else {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }


     //$filename = drupal_substr($file->filename, strpos($file->filename, $export_options['export_path']));
     // Add this file.
     //TODO - we are really going to file_get_contents on files of 400MB? Check wehther there's lazy load of contnet. Also ,meybe tar should be a filter.
     //$scheme = file_uri_scheme($file->filename);
     // Transfer file in 1024 byte chunks to save memory usage.
     //if ($fd = fopen($uri, 'rb')) {
     //    while (!feof($fd)) {
     //        print fread($fd, 1024);
     //    }
     //    fclose($fd);
     //}
    // $contents = file_get_contents($fullfilepath);
     //print html_export_tar_create("{$filename}", $contents);
     //unset($contents);
   //}
}


function html_export_output_format_cleanup_amazon_s3($export_options, &$context)
{

  if (!isset($export_options['amazon_invalidate_cloudfront']) ||
       (isset($export_options['amazon_invalidate_cloudfront']) && !$export_options['amazon_invalidate_cloudfront']))
  {
    $context['finished'] = 1;
  }
  else {
    // Invalidate the upload on S3
    libraries_load('awssdk');

    $cloudfront = new AmazonCloudFront();

    if (!isset($context['sandbox']['progress'])) {

      // We use the output from the last step. It's deliberate, rather than keeping and using the output from the
      // very first step. It's because in the future the order of upload is likely to be optimised for upload speed,
      // and to ensure that the very last things to upload are the html pages.
      // Invalidating in the same order might help the edges to update smoothly.

      // There is a maximium of 1000 objects in an invalidation... (and only 3 invalidations may run at once)
      $invalidation_files = array();
      foreach ($context['results']['output_save']['export_list'] as $bucket_key => $bucket_data) {
        foreach ($context['results']['output_save']['export_list'][$bucket_key] as $batch_key => $outputlist) {
          $invalidation_files = array_merge($invalidation_files, $outputlist);
        }
      }
      $invalidation_list = array_chunk($invalidation_files, 999);
      unset($$context['results']['output_save']['export_list']);
      $context['results']['output_cleanup']['invalidation_list'] =  $invalidation_list;
      $context['results']['output_cleanup']['current_batch'] = 0;

      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($invalidation_list); //count($paths);
    }

    // Todo - this might not work on Windows!
    $invalidation_reference = array_pop( explode('/', $export_options['export_path']));

    // Todo - right now we assume less than 3000 records & that there are no invalidations ongoing.
    // process limit amount of records
    $count = 0;
    while ($count < HTML_EXPORT_PROCESS_LIMIT
      && $context['sandbox']['progress'] < $context['sandbox']['max']
    ) {

      $batch = $context['results']['output_cleanup']['current_batch'];

      if (!isset($context['results']['output_cleanup']['invalidation_list'][$batch])) {
        // This should not be possible
        $context['message'] = t('Invalidation problem - sanity check broken');
        // Stop doing anything more.
        $context['finished'] = 1;
        $count = HTML_EXPORT_PROCESS_LIMIT;
      }
      else {

        $context['message'] = t('Now processing invalidation number %batch', array('%batch' => $batch));

        //Execute the invalidation
        $invalidate_response = $cloudfront->create_invalidation($export_options['amazon_cloudfront_dist_id'],
                                                              $invalidation_reference . '_' . $batch,
                                                              $context['results']['output_cleanup']['invalidation_list'][$batch]);

        if (!$invalidate_response->isOK()) {
          $context['message'] = t('Invalidation problem');
          // Stop doing anything more.
          $context['finished'] = 1;
          $count = HTML_EXPORT_PROCESS_LIMIT;
        }
        else {
          $context['results']['output_cleanup']['current_batch']++;
        }
      }

      // Update our progress information.
      $context['sandbox']['progress']++;
      $count++;
    }

    // Inform the batch engine that we are not finished,
    // and provide an estimation of the completion level we reached.
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      if ($export_options['max_number_of_exports'] > 0) {
        $max = min($context['sandbox']['max'], $export_options['max_number_of_exports']);
        $context['finished'] = $context['sandbox']['progress'] / $max;
      }
      else {
        $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
      }
    }
  }
}

