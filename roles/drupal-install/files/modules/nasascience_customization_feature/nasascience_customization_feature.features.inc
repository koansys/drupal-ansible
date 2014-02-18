<?php
/**
 * @file
 * nasascience_customization_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nasascience_customization_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function nasascience_customization_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nasascience_customization_feature_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'managed_link' => array(
      'name' => t('Managed Link'),
      'base' => 'node_content',
      'description' => t('Links (URL etc) to external sites and resource such as Chandra Image Gallery: http://chandra.harvard.edu/photo/chronological.html'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mission' => array(
      'name' => t('Mission'),
      'base' => 'node_content',
      'description' => t('NASA Mission'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mission_acronym' => array(
      'name' => t('Mission Acronym'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'science_news_article' => array(
      'name' => t('Science News  Article'),
      'base' => 'node_content',
      'description' => t('Used for news articles in Science News. Two main uses are 1-Science@NASA Headlines and 2-News and Features.
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'vsx_slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => t('Node type used for making Views Slideshow Slides.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
