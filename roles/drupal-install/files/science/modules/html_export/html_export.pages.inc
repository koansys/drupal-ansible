<?php
/**
 * @file
 * Batch processing and heavy lifting associated with export
 */


/**
 * Helper function to start the HTML rendering job
 */
function _html_export_job_page() {
  //TODO - add an export all of files directory (minus the export_html folder)
  //TODO - add option to define paths - e.g. to use the clean url or url without index.html - might not work - e.g. directory and file of the same name. Is this possible? What oses allow it?

  $form = array();
  $path_providers = module_invoke_all('html_export_add_path_provider');
  // allow projects to alter list
  drupal_alter('html_export_add_path_provider', $path_providers);
  // convert providers to options array
  $options = array();
  foreach ($path_providers as $key => $provider) {
    $options[$key] = t($provider['title']);
  }
  // build the form
  $form['path_selector'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Path selectors'),
    '#description' => t('Select paths to combine in formulating a list of paths in which to use for export.'),
    '#options' => $options,
    '#required' => TRUE,
  );

  $form['html_export_other_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Other paths to export'),
    '#description' => t("Provide one path per line of additional paths to export."),
    '#default_value' => variable_get('html_export_other_paths', '<front>'),
  );

   $form['exclude_paths'] = array(
        '#type' => 'textarea',
        '#title' => t('Exclude these paths from export'),
        '#description' => t("Provide one path per line of additional paths to exclude from the export. You can use Drupal wildcard paths here - e.g 'admin/*'. This does not rewrite HTML to remove these items from pages where they are linked."),
        '#default_value' => variable_get('html_export_exclude_paths', ''),
    );

  $form['html_export_dom_remove'] = array(
    '#type' => 'textarea',
    '#title' => t('Advanced dom removal'),
    '#description' => t("Supply a css style selector to target the removal of. This is especially useful for removing things like the admin toolbar, tabs, or other elements you don't want to have exported. Add one selector per line."),
    '#default_value' => variable_get('html_export_dom_remove', ''),
  );

  $form['html_export_other_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Other paths to export'),
    '#description' => t("Provide one path per line of additional paths to export."),
    '#default_value' => variable_get('html_export_other_paths', '<front>'),
  );

  // format for dealing with the export
  $formats = module_invoke_all('html_export_add_format');
  // allow projects to alter list
  drupal_alter('html_export_add_format', $formats);

  // convert providers to options array
  $formats_list = array();
  foreach ($formats as $key => $format) {
    $formats_list[$key] = t($format['option']);
  }
  $form['html_export_format'] = array(
    '#type' => 'select',
    '#title' => t('Packaging format'),
    '#description' => t('What would you like to do with your format?'),
    '#options' => $formats_list,
    '#default_value' => 'amazon_s3',
    '#required' => TRUE,
  );

  $form['dont_render_errors'] = array(
    '#type' => 'checkbox',
    '#default_value' => TRUE,
    '#title' => t("Don't export paths returning errors"),
    '#description' => t("If a path request returns a 403, 404 or 500 error then don't export that page."),
  );

  $form['anonymous'] = array(
    '#type' => 'checkbox',
    '#default_value' => TRUE,
    '#title' => t('Render as anonymous'),
    '#description' => t('Render pages via an external request so that they are treated as anonymous.'),
  );

  $form['write_htaccess'] = array(
    '#type' => 'checkbox',
    '#default_value' => TRUE,
    '#title' => t('Include a .htaccess file in the export.'),
    '#description' => t("If your webserver is not configured to have the files/html_export directories to serve index.html then clean URLs won't work when you view the site. However, a .htaccess file in the files directory is a security risk."),
  );

  $form['greedy_sweep'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("Greedy sweep for assets"),
    '#description' => t("When a file, for example an image, is required by a web page, as well as copying it, include all other files in that directory and its subdirectories."),
  );

  $form['amazon'] = array(
    '#type' => 'fieldset',
    '#title' => t('Amazon settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['amazon']['amazon_export_changes'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("Only export changed files to Amazon."),
    '#description' => t("Tick to check whether a file has changed, and export that file to Amazon. If checked, and Cloudfront is in use, only the altered files will be invalidated."),
  );

  $form['amazon']['amazon_s3_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('Amazon S3 bucket'),
    '#default_value' => variable_get('html_export_amazon_s3_bucket', ''),
    '#size' => 20,
    '#maxlength' => 40, //Todo - check the max size of s3 bucket name.
    '#description' => t("If you are using S3, then enter the bucket name here. The bucket will be created if it doesn't exist. Remember that bucket names must be globally unique, and the rules for names used for static websites."),
  );
  // Todo - might be useful if this was a select, with multiple buckets.

  $form['amazon']['amazon_cloudfront_distro_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Amazon Cloudfront distribution id'),
    '#default_value' => variable_get('html_export_amazon_cloudfront_distro_id', ''),
    '#size' => 20,
    '#maxlength' => 40,  //Todo - check the max size of amazon cloudfront distro id.
    '#description' => t("If you are using Amazon Cloudfront in association with a bucket, then enter the distribution ID here. Otherwise leave this blank. The distribution will not be created, but uploaded files can be invalidated."),
  );

  $form['amazon']['amazon_invalidate_cloudfront'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("Invalidate on Cloudfront for any uploaded files."),
    '#description' => t("Only has effect if you are using Cloudfront and have a valid distro id. If you have a low time to live (TTL) set on Cloudfront objects, then you may not need to invalidate when things change. Remember too that invalidation does not work on streaming distributions."),
  );


  /*
  Not yet implemented

  $form['amazon']['amazon_clean_bucket'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("Clean the Amazon S3 bucket before upload"),
    '#description' => t("Tick to delete everything in the bucket before uploading the files. Normally you will not want to do this."),
  );
  */


  /*
  Not yet implemented

  Don't do this with a tickbox.

  $form['amazon']['amazon_cloudfront_style'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("For Amazon Cloudfront, choose versioning or invalidation"),
    '#description' => t("Invalidation will work, but versioning is faster."),
  );

  Todo - for versioning, when rewriting urls, in the files, add a ?timestamp=whateveritis, and use this as part of the upload filename.

  */

  /*
  Not yet implemented

  $form['amazon']['delete_after_upload'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
    '#title' => t("Delete temporary files after upload to Amazon"),
    '#description' => t("During the process a temporary version of the site is produced. If you want a record, then don't delete it."),
  );

  */

 // Todo - add a textarea here for users to list directories to greedy sweep, so you can have non-greedy, except for a few matches

 $form['max_number_of_exports'] = array(
   '#type' => 'textfield',
   '#title' => t('Maximum number of pages to export.'),
   '#description' => t("Stop after this number of pages. If a page is not exported, it's not counted. Enter zero for all pages."),
   '#default_value' => '10',
   '#size' => 20,
   '#maxlength' => 5,
   '#required' => TRUE,
 );

 // enable ability to export as if you are another user
 if (module_exists('masquerade') && function_exists('masquerade_access')) {
   if (masquerade_access('autocomplete')) {
     $form['masquerade_user_field'] = array(
       '#type' => 'textfield',
       '#title' => t('EXPERIMENTAL: Masquerade for export'),
       '#description' => t('Select a user account to masquerade as during this export. This allows you to render to file as if you were a different user. This has known page rendering conflicts with certain projects, anonymous is recommended for an accurate export.'),
       '#size' => '18',
       '#default_value' => '',
       '#autocomplete_path' => 'masquerade/autocomplete',
       '#required' => FALSE,
     );
   }
 }
 $form['submit'] = array(
   '#type' => 'submit',
   '#value' => t('Render as html'),
 );
 return $form;
}


//Todo - validate the form.
//ToDo - cannot have both masquerade and anonymous export set.

/**
* Submit handler for HTML rendering job
*
* This sets up all the variables needed for the batch job from the form submission, then triggers the batch job.
*/
function _html_export_job_page_submit($form, &$form_state) {
  global $user;

  //Todo - what other variables can sensibly go into $export_options? Maybe uid? Also uid and anonymous flags can be combined.

  // Start by using the Other paths from the form as to what paths to gather
  $paths = array();
  $export_options = array();

  // account for additional paths added manually
  $export_options['frontpage'] = FALSE;
  if (!empty($form_state['values']['html_export_other_paths'])) {
    $other_paths = $form_state['values']['html_export_other_paths'];

    // Check whether <front> is one of the paths, and it is, convert to an actual path
    if (strpos($other_paths, '<front>') !== FALSE) {
      $export_options['frontpage'] = variable_get('site_frontpage', 'node');
      $other_paths = str_replace('<front>', $export_options['frontpage'], $other_paths);
    }

    // Turn into an array of paths
    $paths = html_export_extract_array($other_paths);
  }

  $selector_paths = html_export_get_selector_paths($form_state['values']['path_selector']);

  $paths = array_merge($paths, $selector_paths);

  //Now remove any paths which were listed for exclusion
  if (!empty($form_state['values']['exclude_paths'])) {
    // Turn into an array of paths
    $exclude_paths_list = html_export_extract_array($form_state['values']['exclude_paths']);
    $paths = html_export_remove_exclude_paths($exclude_paths_list, $paths);
  }

  // Bring along advanced dom removal on publish, accounting for multiple
  $export_options['dom_remove'] = html_export_extract_array($form_state['values']['html_export_dom_remove']);

  // Should the first slash be removed from a url like /directory/file.html
  $export_options['remove_base'] = FALSE;

  // How will the final output be handled?
  $export_options['html_export_format'] = $form_state['values']['html_export_format'];

  // Set whether to allow that return errors from export
  $export_options['render_errors'] = !($form_state['values']['dont_render_errors']);

  // Set the user id to use for the export. The default is the current user's id...
  $export_options['original_uid'] = $user->uid;
  $export_options['render_uid'] = $user->uid;
  //Now check whether anonymous or a masquerade user is set...
  if (!empty($form_state['values']['anonymous'])) {
    $export_options['render_uid'] = 0;
  }
  else {
    // see if masquerade was enabled and used
    if (!empty($form_state['values']['masquerade_user_field'])) {
      // convert name we were passed to uid
      $masq_user = array_shift(user_load_multiple(array(), array('name' => $form_state['values']['masquerade_user_field'])));
      if (isset($masq_user->uid)) {
        $export_options['render_uid'] = $masq_user->uid;
      }
    }
  }


  //$export_options['use_clean_paths'] = ($form_state['values']['use_clean_paths']);

  $export_options['write_htaccess'] = $form_state['values']['write_htaccess'];

  $export_options['replace_parameters'] = TRUE; //This can be false, but for a static site, it's unusual

  $export_options['greedy_sweep'] = $form_state['values']['greedy_sweep'];

  $export_options['amazon_export_changes'] = $form_state['values']['amazon_export_changes'];

  $export_options['amazon_s3_bucket'] = array(
   'default' => array (
      'bucket_name' => $form_state['values']['amazon_s3_bucket'],
      'file_patterns' => '',
    )
  );

  $export_options['amazon_all_files_in_default'] = TRUE; // If there are multiple buckets, all files get stored in default, as well as their respective bucket. Useful for Cloudfront.

  $export_options['amazon_cloudfront_dist_id'] = $form_state['values']['amazon_cloudfront_distro_id'];

  $export_options['amazon_invalidate_cloudfront'] = $form_state['values']['amazon_invalidate_cloudfront'];

  $export_options['max_number_of_exports'] = intval($form_state['values']['max_number_of_exports']);

  $export_options['goto'] = 'html_export'; //Back to this url at the end.

  // The base dir for export save.
  $export_options['export_base'] = variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files') . '/html_export';

  // The name of the sub directory to save this export in. This may be only used as part of the process, it's not necessarily the final spot, but it's where the file go
  $export_options['export_path'] = $export_options['export_base'] . '/export' . REQUEST_TIME;


  //Trigger the batch job
  html_export_process_job($paths, $export_options);
}

function html_export_remove_exclude_paths($exclude_paths_list, $paths) { //Roll through this list of paths, preparing the regular expressions
  $exclude_paths_regex = array();
  // We are going (incorrectly) assume that there are no paths involving the string [a-z] or similar.
  // We need to know the PHP version because prior to PHP 5.3 the minus character wasn't quoted in preg_quote function
  // if (!defined('PHP_VERSION_ID')) {
  //   $version = explode('.', PHP_VERSION);
  //   define('PHP_VERSION_ID', ($version[0] * 10000 + $version[1] * 100 + $version[2]));
  // }
  foreach ($exclude_paths_list as $key => $exclude) {
    //Replace * with %% temporarily, then replace with the correct regex characters. Normally we wouldn't have a * in our url, but
    $exclude_paths_regex[] = '/^' . str_replace('%%', '.*', preg_quote(str_replace('*', '%%', $exclude), '/')) . '$/';
  }
  $paths_cleaned = preg_replace($exclude_paths_regex, '', $paths);
  //And make paths into a contiguous array without the matches.
  $paths = array_merge(array_diff($paths_cleaned, array('')));
  return $paths;
}


/**
 * Turn a text list (typically from an input text area) into an array of items.
 *
 * @param $text_list
 *   The text to parse.
 *
 * @return array
 *   An array of lines.
 */
function html_export_extract_array($text_list) {
  $text_list = str_replace("\r", "", $text_list);
  $array_list = explode("\n", $text_list);
  return $array_list;
}

/**
 * @param $selectors
 * @return array
 */
function html_export_get_selector_paths($selectors) {

 // Invoke the hooks that will provide us with a list of paths
  $path_providers = module_invoke_all('html_export_add_path_provider');
  // Allow projects to alter list
  drupal_alter('html_export_add_path_provider', $path_providers);

  $selector_paths = array();
  // Loop through the selectors, generating lists of paths from the appropriate path provider
  foreach ($selectors as $selector) {
    // only submit arg if its set to avoid notices
    if (isset($path_providers[$selector]['arg'])) {
      $paths = call_user_func_array($path_providers[$selector]['callback'], array($path_providers[$selector]['arg']));
    }
    else {
      $paths = call_user_func_array($path_providers[$selector]['callback'], array());
    }
    $selector_paths = array_merge($selector_paths, $paths);
  }

  return $selector_paths;
}


/**
 * Initialize batch job
 */
function html_export_process_job($paths, $export_options=array()) {
  $GLOBALS['html_export_active'] = TRUE;

  //Order paths
  sort($paths);
  // reverse order so that deeper paths of nodes are rendered first.
  $paths = array_reverse($paths);

  if (($export_options['original_uid'] != $export_options['render_uid']) && function_exists('masquerade_switch_user')) {
    masquerade_switch_user($export_options['render_uid']);
  }

  // Create folders.
  file_prepare_directory($export_options['export_base'], FILE_CREATE_DIRECTORY|FILE_MODIFY_PERMISSIONS);

  // Make the directory path for this export (it's just timestamped)
  file_prepare_directory($export_options['export_path'], FILE_CREATE_DIRECTORY|FILE_MODIFY_PERMISSIONS);

  // Render pages and deep copy directories
  $batch = array(
    'operations' => array(
      array('html_export_render_pages', array($paths, $export_options)),
      array('html_export_copy_all_resources', array($export_options)),
      array('html_export_cleanup', array($export_options)),
      array('html_export_format_prepare_output', array($export_options)),
      array('html_export_format_output', array($export_options)),
      array('html_export_format_cleanup_output', array($export_options)),
    ),
    'finished' => 'html_export_finished',
    'title' => t('Processing html export'),
    'init_message' => t('HTML export is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('HTML export has encountered an error.'),
    'file' => drupal_get_path('module', 'html_export') . '/html_export.pages.inc',
  );
  batch_set($batch);
  batch_process(isset($export_options['goto'])?$export_options['goto']:'node');
}


/**
 * Batch Operation Callback to render all pages
 *
 * This is the first of the batch operations.
 */
function html_export_render_pages($paths, $export_options, &$context) {
  // On the first run...
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($paths);
    $context['sandbox']['no_files_written'] = 0; //How many files have been written - maybe better called no_pages_written. Or no_paths_written.
    $context['sandbox']['max_files'] = ($export_options['max_number_of_exports']===0 ? count($paths) : $export_options['max_number_of_exports']);
    $context['results']['paths'] = array(); //This could be useful for add-in post processing, but I don't think it's ever used.
    $context['results']['asset_list'] = array();

    // If we found front then render it first
    if (isset($export_options['frontpage']) && $export_options['frontpage']) {
      $context['frontpage'] = TRUE;
      _html_export_render_to_disk($export_options['frontpage'], $paths, $export_options, $context); //Todo - remove the frontpage from the list
      $context['sandbox']['progress']++;
    }
  }
  // process limit amount of records
  $count = 0;
  $context['frontpage'] = FALSE;
  while ($count < HTML_EXPORT_PROCESS_LIMIT
         && $context['sandbox']['progress'] < $context['sandbox']['max']
         && $context['sandbox']['no_files_written'] < $context['sandbox']['max_files']
        ) {
    $active = $context['sandbox']['progress'];
    $context['message'] = t('Now processing %path', array('%path' => drupal_get_path_alias($paths[$active])));
    // Store some result for post-processing in the finished callback.
    $context['results']['paths'][] = $paths[$active];

    //Don't bother re-rendering the front page. but render all the others
    if (strcmp($paths[$active], $export_options['frontpage']) !== 0) {
      _html_export_render_to_disk($paths[$active], $paths, $export_options, $context);
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
}


/*
 * Find a page, and store it on disk
 */
/**
 * @param $render_path
 * @param $paths
 * @param $export_options
 * @param $context
 */
function _html_export_render_to_disk($render_path, $paths, $export_options, &$context) {

  $data = _html_export_get_page_data($render_path, $export_options);

  // Provided we got a page, find all the resources and write the page to disk.
  if ($data) {
    // locate all the resources used to make this page and copy them
    _html_export_copy_resources($data, $export_options, $context);
    /* Todo - both export_copy_resources and drupal_alter('html_export_data' scan through the html document in the same way, one building an assets list and
     * then copying and the other rewriting the links. It would be much more sensible if this search was done once. Combine
     * building asset list with rewriting. Then save assets separately.
     */

    // Special alter that doesn't rewrite base path
    // Todo - the size of optional and required is getting silly. Make $required into $export_options.
    $required = array(
      'paths' => $paths,
      'active_path' => $render_path,
    );
    $optional = array(
      'dom_remove' =>  $export_options['dom_remove'],
      'remove_base' => $export_options['remove_base'],
      'replace_parameters' => $export_options['replace_parameters']
    );
    drupal_alter('html_export_data', $data, $required, $optional);

    // prepare to save file by creating folders for path
    // Todo - it might be useful to add an option to use the render_path. That means that mostly you'll end up with things like /node/132
    $save_path = drupal_get_path_alias($render_path);
    if ($export_options['replace_parameters']) {
      /* Todo - for the moment - instead of replacing all parameters, just replace ?page=x
      because at the moment the whole url isn't part of the path - e.g. in /something.css?hjfh3 we don't see the hjhh3
      $save_path = str_ireplace('?', '/', $save_path);
      $save_path = str_ireplace('=', '/', $save_path);
      $save_path = str_ireplace('&', '_', $save_path);
      */
      $save_path = preg_replace('#\?page=([[:digit:]])#', '/page/$1', $save_path);
    }

    $tmp = explode('/', $save_path);
    $folder_path = '';
    // Build path leading up to the current one
    foreach ($tmp as $folder) {
      $folder_path .= '/' . $folder;
      $tmppath = $export_options['export_path'] . $folder_path;
      file_prepare_directory($tmppath, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      //file_prepare_directory($tmppath, FILE_CREATE_DIRECTORY);$export_options['export_path'] . (empty($render_path)?'':'' . '/' . $render_path) . '/index.html'
      //file_prepare_directory($tmppath);
    }

    // Write the page into a file at that location
    if ($context['frontpage']) {
      //Write .htaccess
      if ($export_options['write_htaccess']) {
        $file = fopen($export_options['export_path'] . '/.htaccess', 'w');
        fwrite($file, "SetHandler None\nOptions +FollowSymLinks\nDirectoryIndex index.html\n");
        fclose($file);
      }

      $filename = $export_options['export_path'] . '/index.html';
    }
    else {
      $filename = $export_options['export_path'] . (empty($save_path)?'':'' . '/' . $save_path) ;
      //if ($export_options['use_clean_paths']) {
        $filename .= '/index.html';
      //}
    }
    if ($file = fopen($filename, 'w')) {
      fwrite($file, $data);
      fclose($file);
      $context['sandbox']['no_files_written']++;
    }
  }
}


/**
 * Batch Operation Callback to copy all resources
 */
function html_export_copy_all_resources($export_options, &$context) {
  // first run
  if (!isset($context['sandbox']['progress'])) {
    // allow other modules to modify the asset list to include other assets
    drupal_alter('html_export_asset_list', $context['results']['asset_list']);

    $context['sandbox']['progress'] = 0;
    $context['sandbox']['active_copy_id'] = 0;
    $context['results']['files'] = array();
    $context['sandbox']['max'] = count($context['results']['asset_list']);
    // convert keys to array positions
    sort($context['results']['asset_list']);
    // reverse order so that deeper paths of nodes are rendered
    $context['results']['asset_list'] = array_reverse($context['results']['asset_list']);
  }
  // process limit amount of records
  $count = 0;
  $active_copy_id = $context['sandbox']['active_copy_id'];
  while ($count < HTML_EXPORT_FILE_PROCESS_LIMIT && $active_copy_id < $context['sandbox']['max']) {
    _html_export_copy_file(urldecode($context['results']['asset_list'][$active_copy_id]), $export_options, $context);
    // Update our progress information.
    $context['message'] = t('Now copying %file', array('%file' => $context['results']['asset_list'][$active_copy_id]));
    $active_copy_id++;
    $count++;
    $context['sandbox']['progress']++;
    $context['sandbox']['active_copy_id'] = $active_copy_id;
  }
 // $tmpmsg = drupal_get_messages();
  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}


/**
 * Batch Operation Callback to clean up before finished
 */
function html_export_cleanup($export_options, &$context) {
  // Unmasquerade if we are done - providing we switched and weren't rendering as anonymous user
  if ($export_options['render_uid'] &&
      ($export_options['original_uid'] != $export_options['render_uid'] )
      && function_exists('masquerade_switch_back'))
  {
    masquerade_switch_back();
  }

}

function _do_export_output($execute, $export_options, &$context) {
  //$args = func_get_args();

  // Pull out the list of ways of dealing with the export
  $formats = module_invoke_all('html_export_add_format');
  // allow projects to alter list
  drupal_alter('html_export_add_format', $formats);
  $format_data = $formats[$export_options['html_export_format']];

  //Now pull in the file if we need to, then trigger the appropriate output format routine
  if (isset($format_data['file'])) {
    module_load_include('inc',
      (isset($format_data['module']) ? $format_data['module']:'html_export'),
      $format_data['file']
    );
  }
  if (isset($format_data[$execute]) && function_exists($format_data[$execute])) {
    $export_options['output_path'] = $format_data['path'];
    $result = call_user_func_array($format_data[$execute], array($export_options, $context));
  }

  //Display the result
  if (isset($result['message'])) {
    drupal_set_message(filter_xss($result['message']));
  }

}

function html_export_format_prepare_output($export_options, &$context) {
  _do_export_output('prepare', $export_options, $context);
}


function html_export_format_output($export_options, &$context) {
  _do_export_output('execute', $export_options, $context);
}


function html_export_format_cleanup_output($export_options, &$context) {
  _do_export_output('cleanup', $export_options, $context);
  //And we're finished.
  $GLOBALS['html_export_active'] = FALSE;
}

/**
 * Helper function to deep copy all resource files
 */
function _html_export_copy_resources($data, $export_options, &$context) {

  // Todo - this routine is very closely related to the asset rewrite - same structure, same search. Combine?

  // TODO - add in an option to include https in the extraction. Or the 'complement'... i.e. if the base url is http, then include https, and if the url is https, include http.

  // Create a DOM object
  $html_obj = new simple_html_dom();
  $asset_list = array(); //All the links/images which aren't css.
  $css_list = array(); //Anything css. It needs to be scanned for assets.

  // TODO - parse comments for IE conditional imports. Sigh. Or use promiscuous copy. Or quick fix: promiscuous copy for CSS files.

  // Load HTML from a string
  $html_obj->load($data);
  $resources = array('link', 'img', 'script', 'a', 'object', 'style', 'comment');
  // repair paths for these resources
  foreach ($resources as $find) {
    // find the selectors in the document
    $objs = $html_obj->find($find);
    // account for ability to find multiple objects
    foreach ($objs as $obj) {

      // Deal with a href
      if (isset($obj->href) && isset($obj->rel) && (strcasecmp($obj->rel, 'stylesheet') !== 0 )) {
        _html_export_add_asset($obj->href, $asset_list);
      }

      // Deal with img src
      elseif (isset($obj->src)) {
        _html_export_add_asset($obj->src, $asset_list);
      }

      elseif (isset($obj->href) && isset($obj->rel) && (strcasecmp($obj->rel, 'stylesheet') === 0 )) {
        _html_export_add_asset($obj->href, $css_list);

        //Todo - transitional: for now we'll add the css to the assets list too. Css files are assets, but they may contain other assets as images, mpgs, etc.
        // Often a site will export without having to scan for assets in the css and this does that.
        _html_export_add_asset($obj->href, $asset_list);
      }

      //Deal with style @import
      elseif ($obj->tag == 'style' || $obj->tag == 'comment') {

        $text = $obj->innertext;

        /* There can be more than one in a style tag
         Find  or  or similar. This is going to have problems with filenames with inverted commas or brackets in the filename.
         All of these are valid:
         @import url(http://www.style.org/pastoral);
         @import url("bluish.css") projection, tv;
         @import url(some.css) print, tv;
         @import url "import4.css"; -- maybe. Not sure.
         @import 'custom.css';
         @import "common.css" screen, projection;
         @import url('landscape.css') screen and (orientation:landscape);

         The CSS spec (http://www.w3.org/TR/CSS1/#appendix-b) defines import as:
         @import [STRING|URL] ';
         STRING = \"({stringchar}|\')*\"|\'({stringchar}|\")*\'
         Stringchar = {escape}|{latin1}|[ !#$%&(-~]
         Not going to list escape or latin1
         URL = url\({w}{string}{w}\) | url\({w}([^ \n\'\")]|\\\ |\\\'|\\\"|\\\))+{w}\)
         {w} being whitespace.


        */

        $imports = array();

        // Todo - these preg_matches could be much better.
        // Todo - IE conditional statements allow link to be in this too.
        // Or if there's a css parser... possibly https://github.com/sabberworm/PHP-CSS-Parser (what's the licence?) or http://code.google.com/p/cssmin/ or
        // or http://pear.php.net/package/HTML_CSS/ or http://www.phpclasses.org/package/1289-PHP-CSS-parser-class.html or http://www.oscarliang.net/projects/simple_cssparser.php. There are probably more.

        // CSS doesn't allow utf8 character names, so no #imu - however this also means that non-ascii names will break in this match, when they should be allowed because CSS allows Latin1 at least.
        if (preg_match_all('#@import\s+url\(["\']?([^"\';\)]+)["\']?\)[[:word:] ,]*;#im', $text, $imports)) {
          // That's not perfect - for e.g. would match @import ("bob'),tv; and won't allow semicolon in file names, but will allow non-printing characters.
          foreach ($imports[1] as $key => $url) {
            //Add the css files found to the assets.
            _html_export_add_asset($url, $css_list);

            //Todo - for now we'll add the css to the assets list too. Css files are assets, but they may contain other assets as images, mpgs, etc.
            // Often a site will export without having to scan for assets in the css and this does that.
            _html_export_add_asset($url, $asset_list);
          }

        }
        $imports = array();
        if (preg_match_all('#@import\s+["\']([^"\';]+)["\'][[:word:] ,]*;#im', $text, $imports)) {
          foreach ($imports[1] as $key => $filepath) {
            //Add the css files found to the css assets.
            _html_export_add_asset($filepath, $css_list);

            //Todo - for now we'll add the css to the assets list too. Css files are assets, but they may contain other assets as images, mpgs, etc.
            // Often a site will export without having to scan for assets in the css and this does that.
            _html_export_add_asset($filepath, $asset_list);
          }
        }
      }

    }
  }

  // Assets to copy, need to filter out base path because they shouldn't be named '/directory/file.html' but 'directory/file.html'
  foreach ($asset_list as $key => $file) {
    // only replace first occurrence as this will be base path
    $pos = strpos($file, base_path());
    if ($pos !== FALSE) {
      $context['results']['asset_list'][$key] = substr_replace($file, '', $pos, drupal_strlen(base_path()));
    }
  }
  foreach ($css_list as $key => $file) {
    // only replace first occurrence as this will be base path
    $pos = strpos($file, base_path());
    if ($pos !== FALSE) {
      $context['results']['css_list'][$key] = substr_replace($file, '', $pos, drupal_strlen(base_path()));
    }
  }
}


function _html_export_add_asset($asset_url, &$asset_list) {
  global $base_url;

  // Todo - there was "&& strpos($obj->href, '.') !== FALSE" as part of this first if. What was it meant to do? Ensure an ending to the file? Ditto in $obj-src if.
  // Todo - _html_export_clean_link is the analogue of this routine and this may not clean the base url from local full url assets, change the structure here to match the fall through structure of that.

  // If it's a purely local asset ...
  if (strpos($asset_url, 'http://') === FALSE && strpos($asset_url, 'https://') === FALSE && !in_array($asset_url, $asset_list)) {
    $src = explode('?', $asset_url);
    $asset_list[$src[0]] = $src[0];
  }

  // If it's a local asset but has the full URL..
  elseif (strpos($asset_url, $base_url) === 0 && !in_array(str_replace($base_url, '', $asset_url), $asset_list)) {
    $src = explode('?', str_replace($base_url, '', $asset_url));
    $asset_list[$src[0]] = $src[0];
  }

}




/**
 * Helper function to deep copy all resource files
 */
function _html_export_copy_file($source, $export_options, &$context) {
  // Simple copy for a file
  //Todo - isfile may not handle non-ascii file names. Best not to have a site with cyrillic picture names.
  if (is_file($source)) {
    // split to build the folder structure
    $tmp = explode('/', $source);
    $filename = array_pop($tmp);
    $folder_path = '';
    $deepcopy = implode('/', $tmp);
    // build path leading up to the current one
    foreach ($tmp as $folder) {
      $folder_path .= '/' . $folder;
      $tmppath = $export_options['export_path'] . $folder_path;
      file_prepare_directory($tmppath, FILE_CREATE_DIRECTORY|FILE_MODIFY_PERMISSIONS);
      //file_prepare_directory($folder_path, FILE_CREATE_DIRECTORY);
      //file_prepare_directory($folder_path);
    }

    if (isset($export_options['greedy_sweep']) && $export_options['greedy_sweep']) {
      // Copy the file and all siblings and children
      _html_export_deep_file_copy($deepcopy, $export_options['export_path'] . $folder_path, $context);
    }
    else {
      // Actually copy the file.
      copy($source,  $export_options['export_path']  . '/' . $source);
    }

    $context['results']['files'][$source] = $source;

  }
}


/**
 * Helper function to deep copy all resource files
 */
function _html_export_deep_file_copy($source, $dest, &$context) {

  // Don't copy devel module
  if (strpos($source, drupal_get_path('module', 'devel')) !== FALSE) {
    return;
  }

  // deep copy in each directory assembled previously ignoring files and devel
  //if (strpos($deepcopy, variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files')) === FALSE && strpos($deepcopy, drupal_get_path('module', 'devel')) === FALSE) {
  //Todo - is it sensible to promiscuous copy inside files directory? The original code excluded anything in files. Odd. Why?

  // Simple copy for a file
  if (is_file($source)) {
    $context['results']['files'][$source] = $source;
    return copy($source, $dest);
  }

  // Make destination directory (this can happen if one of the things in a directory you copy is a directory)
  if (!is_dir($dest)) {
    mkdir($dest);
  }

  // Loop through the folder
  $dir = dir($source);
  while (FALSE !== $entry = $dir->read()) {
    // skip over all the files types that make no sense in an export
    if ($entry == '.' || $entry == '..' || $entry == '.DS_Store' || $entry == '.htaccess' || $entry == '.project' || $entry == 'Thumbs.db' || $entry == '_notes' || strpos($entry, '.engine') != 0 || strpos($entry, '.php') != 0 || strpos($entry, '.inc') != 0 || strpos($entry, '.include') != 0 || strpos($entry, '.info') != 0 || strpos($entry, '.txt') != 0 || strpos($entry, '.ini') != 0 || strpos($entry, '.po') != 0 || strpos($entry, '.install') != 0 || strpos($entry, '.module') != 0 || strpos($entry, '.html') != 0 || strpos($entry, '.htm') != 0 || strpos($entry, '.test') != 0) {
      continue;
    }

    // Deep copy directories, ignore the html_export ones
    if ($dest !== "$source/$entry" && strpos($source, 'html_export') == 0 ) {
      _html_export_deep_file_copy("$source/$entry", "$dest/$entry", $context);
    }
  }

  // Clean up
  $dir->close();
}


/**
 * Batch 'finished' callback
 */
function html_export_finished($success, $results, $operations) {
  if ($success) {

    //Todo - should this be part of the format output finished function
    // Here we do something meaningful with the results.
    $message = t('Export created %count html pages and %files files.', array('%count' => count($results['paths']), '%files' => count($results['files'])));

    //$args = func_get_args();

    // Pull out the list of ways of dealing with the export
    $formats = module_invoke_all('html_export_add_format');
    // allow projects to alter list
    drupal_alter('html_export_add_format', $formats);
    //$format_data = $formats[$export_options]['html_export_format'];

    //Now pull in the file if we need to, then trigger the appropriate output format routine
    if (isset($format_data['file'])) {
      module_load_include('inc',
        (isset($format_data['module']) ? $format_data['module']:'html_export'),
        $format_data['file']
      );
    }
    if (isset($results['format_finished']) && function_exists($results['format_finished'])) {
      $result = call_user_func_array($results['format_finished'], array($success, $results, $operations));
    }

    //Display the result
    if (isset($result['message'])) {
      drupal_set_message(filter_xss($result['message']));
    }


  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}
