<?php
/**
 * @file
 * nasascience_customization_feature.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function nasascience_customization_feature_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'feincms_missions_importer-launch_date-strtotime';
  $feeds_tamper->importer = 'feincms_missions_importer';
  $feeds_tamper->source = 'launch_date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['feincms_missions_importer-launch_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_12-cast_to_int';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_12-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_14-explode';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_14-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_14-string2id';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'string2id';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => 'node',
      'field_name' => 'field_related_content_link',
      'bundle_name' => NULL,
    ),
    'views' => array(
      'view' => 'related_links_view_block:default',
    ),
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Convert string into entity ID';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_14-string2id'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_3-cast_to_int';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_3-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_8-cast_to_int';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_8-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_django_cms_pages_to_drupal_book-xpathparser_9-cast_to_int';
  $feeds_tamper->importer = 'import_django_cms_pages_to_drupal_book';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_django_cms_pages_to_drupal_book-xpathparser_9-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_feincms_news_and_features_articles-xpathparser_11-rewrite';
  $feeds_tamper->importer = 'import_feincms_news_and_features_articles';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'science-news/[xpathparser:11]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['import_feincms_news_and_features_articles-xpathparser_11-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_feincms_news_and_features_articles-xpathparser_3-cast_to_int';
  $feeds_tamper->importer = 'import_feincms_news_and_features_articles';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_feincms_news_and_features_articles-xpathparser_3-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_feincms_news_and_features_articles-xpathparser_7-strtotime';
  $feeds_tamper->importer = 'import_feincms_news_and_features_articles';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['import_feincms_news_and_features_articles-xpathparser_7-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_feincms_news_and_features_articles-xpathparser_9-cast_to_int';
  $feeds_tamper->importer = 'import_feincms_news_and_features_articles';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_feincms_news_and_features_articles-xpathparser_9-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_science_news_content_from_feincms-xpathparser_19-explode';
  $feeds_tamper->importer = 'import_science_news_content_from_feincms';
  $feeds_tamper->source = 'xpathparser:19';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['import_science_news_content_from_feincms-xpathparser_19-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_science_news_content_from_feincms-xpathparser_19-string2id';
  $feeds_tamper->importer = 'import_science_news_content_from_feincms';
  $feeds_tamper->source = 'xpathparser:19';
  $feeds_tamper->plugin_id = 'string2id';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => 'node',
      'field_name' => 'field_related_content_links',
      'bundle_name' => NULL,
    ),
    'views' => array(
      'view' => 'related_links_view_block:default',
    ),
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert string into entity ID';
  $export['import_science_news_content_from_feincms-xpathparser_19-string2id'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_science_news_content_from_feincms-xpathparser_3-cast_to_int';
  $feeds_tamper->importer = 'import_science_news_content_from_feincms';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_science_news_content_from_feincms-xpathparser_3-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_science_news_content_from_feincms-xpathparser_8-cast_to_int';
  $feeds_tamper->importer = 'import_science_news_content_from_feincms';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_science_news_content_from_feincms-xpathparser_8-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'import_science_news_content_from_feincms-xpathparser_9-cast_to_int';
  $feeds_tamper->importer = 'import_science_news_content_from_feincms';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['import_science_news_content_from_feincms-xpathparser_9-cast_to_int'] = $feeds_tamper;

  return $export;
}
