<?php

/**
 * @file
 * Contains functions to output Html export as a tar.gz file.
 *
 * The Html Export module can prepare the output for distribution in more than
 * one way. Each implementation is in an separate file, making it easier to
 * extend.
 */


function html_export_output_format_tar($export_options) {
  _html_export_download_folder($export_options);
}

/**
 * Helper to tar a folder based on Features.
 */
function _html_export_download_folder($export_options) {
  global $base_path;

  // Generate download
  $filename = $export_options['export_path'] . '.tar';
  // Clear out output buffer to remove any garbage from tar output.
  if (ob_get_level()) {
    ob_end_clean();
  }

  drupal_add_http_header('Content-type', 'application/x-tar');
  drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $filename . '"');

  // if (strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE')) {
  //These are a bit of a guess as to format
  //     drupal_add_http_header('Cache-Control', 'must-revalidate, post-check=0, pre-check=0');
  //     drupal_add_http_header('Pragma', 'public');
  // } else {
  //     drupal_add_http_header('Pragma', 'no-cache'); /
  // }

  $tar = array();
  // file_scan_directory() can throw warnings when using PHP 5.3, messing
  // up the output of our file stream. Suppress errors in this one case in
  // order to produce valid output.
  foreach (@file_scan_directory($export_options['export_path'], '/.*/') as $fullfilepath => $file) {
    $filename = drupal_substr($file->filename, strpos($file->filename, $export_options['export_path']));
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
    $contents = file_get_contents($fullfilepath);
    print html_export_tar_create("{$filename}", $contents);
    unset($contents);
  }
  print pack("a1024", "");
  // exit;
  //drupal_exit();
}



 /**
 * Tar creation function. Written by dmitrig01.
 * Taken from the Features module.
 *
 * @param $name
 *   Filename of the file to be tarred.
 * @param $contents
 *   String contents of the file.
 *
 * @return
 *   A string of the tar file contents.
 */
function html_export_tar_create($name, $contents) {
    $tar = '';
    $binary_data_first = pack("a100a8a8a8a12A12",
        $name,
        '100644 ', // File permissions
        '   765 ', // UID,
        '   765 ', // GID,
        sprintf("%11s ", decoct(drupal_strlen($contents))), // Filesize,
        sprintf("%11s", decoct(REQUEST_TIME)) // Creation time
    );
    $binary_data_last = pack("a1a100a6a2a32a32a8a8a155a12", '', '', '', '', '', '', '', '', '', '');

    $checksum = 0;
    for ($i = 0; $i < 148; $i++) {
        $checksum += ord(drupal_strlen($binary_data_first, $i, 1));
    }
    for ($i = 148; $i < 156; $i++) {
        $checksum += ord(' ');
    }
    for ($i = 156, $j = 0; $i < 512; $i++, $j++) {
        $checksum += ord(drupal_strlen($binary_data_last, $j, 1));
    }

    $tar .= $binary_data_first;
    $tar .= pack("a8", sprintf("%6s ", decoct($checksum)));
    $tar .= $binary_data_last;

    $buffer = str_split($contents, 512);
    foreach ($buffer as $item) {
        $tar .= pack("a512", $item);
    }
    return $tar;
}




