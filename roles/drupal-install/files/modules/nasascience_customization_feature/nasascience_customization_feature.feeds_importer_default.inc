<?php
/**
 * @file
 * nasascience_customization_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nasascience_customization_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feincms_managed_links_importer';
  $feeds_importer->config = array(
    'name' => 'Feincms Managed Links Importer',
    'description' => 'Import Feincms Managed Links from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'GID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'URL',
            'target' => 'field_link_url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Description',
            'target' => 'field_link_description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'managed_link',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feincms_managed_links_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feincms_mission_acronyms_importer';
  $feeds_importer->config = array(
    'name' => 'Feincms Mission acronyms Importer',
    'description' => 'Mission acronyms Importer ',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'GID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'acronym',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_acronym_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'mission_acronym',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feincms_mission_acronyms_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feincms_missions_importer';
  $feeds_importer->config = array(
    'name' => 'FeinCMS Missions Importer',
    'description' => 'Import missions from feincms to missions content type',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'GID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'slug',
            'target' => 'field_slug',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'acronyms',
            'target' => 'field_acronyms',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'full_name',
            'target' => 'field_full_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'launch_date',
            'target' => 'field_launch_date:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'phase',
            'target' => 'field_phase',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'home_page',
            'target' => 'field_home_page',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'links',
            'target' => 'field_related_content',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'big_questions',
            'target' => 'field_big_question',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'focus_areas',
            'target' => 'field_focus_area',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'programs',
            'target' => 'field_programs',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'image_file',
            'target' => 'field_mission_image_file:uri',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'division',
            'target' => 'field_division_taxonomy_term',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          16 => array(
            'source' => 'visible',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'mission',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feincms_missions_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feincms_top_level_books_importer';
  $feeds_importer->config = array(
    'name' => 'FeinCMS Top Level Books Importer',
    'description' => 'Import top level pages that do not have a parent.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'xml html htm',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => './body',
          'xpathparser:2' => './title',
          'xpathparser:3' => './uid',
          'xpathparser:5' => './uuid',
          'xpathparser:7' => './uuid',
          'xpathparser:8' => './parent',
          'xpathparser:9' => './weight',
          'xpathparser:11' => './description',
          'xpathparser:12' => './level',
          'xpathparser:13' => './in_navigation',
          'xpathparser:14' => './relatedlinktitles',
          'xpathparser:15' => './taxonomy',
          'xpathparser:16' => './create_date',
          'xpathparser:17' => './modify_date',
          'xpathparser:18' => './create_date',
          'xpathparser:20' => './redirect_to',
          'xpathparser:21' => './page_template',
          'xpathparser:22' => './thumb_nail',
          'xpathparser:23' => './parent',
          'xpathparser:24' => './pathalias',
        ),
        'rawXML' => array(
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:24' => 0,
        ),
        'context' => '/root/book/page',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:2' => 'xpathparser:2',
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'input_format' => 'full_html',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'uuid',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'uuid_book_bid',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:9',
            'target' => 'book_weight',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_book_page_description',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_page_level',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_innavigation',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:14',
            'target' => 'entityreference:field_related_content_link',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_taxonomy',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_legacy_create_date:start',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_legacy_modify_date:start',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:18',
            'target' => 'created',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_redirect_to_url',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_top_level_page_template',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          17 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_page_image:uri',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:23',
            'target' => 'uuid_book_parent',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:24',
            'target' => 'path_alias',
            'pathauto_override' => 1,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
        'skip_hash_check' => 1,
        'bundle' => 'book',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feincms_top_level_books_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_django_cms_pages_to_drupal_book';
  $feeds_importer->config = array(
    'name' => 'Import Django CMS pages to Drupal Book',
    'description' => 'Import Django CMS pages to Drupal Book. CAUTION: TURN OFF BOOK HELPER MODULE BEFORE IMPORTING BOOK',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'xml html htm',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => './body',
          'xpathparser:2' => './title',
          'xpathparser:3' => './uid',
          'xpathparser:5' => './uuid',
          'xpathparser:7' => './uuid',
          'xpathparser:8' => './bid',
          'xpathparser:9' => './weight',
          'xpathparser:10' => './parent',
          'xpathparser:11' => './description',
          'xpathparser:12' => './level',
          'xpathparser:13' => './in_navigation',
          'xpathparser:14' => './relatedlinktitles',
          'xpathparser:15' => './taxonomy',
          'xpathparser:16' => './create_date',
          'xpathparser:17' => './modify_date',
          'xpathparser:18' => './create_date',
          'xpathparser:20' => './redirect_to',
          'xpathparser:21' => './page_template',
          'xpathparser:22' => './thumb_nail',
          'xpathparser:23' => './pathalias',
        ),
        'rawXML' => array(
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
        ),
        'context' => '/root/book/page',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:2' => 'xpathparser:2',
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'input_format' => 'full_html',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'uuid',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'uuid_book_bid',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:9',
            'target' => 'book_weight',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:10',
            'target' => 'uuid_book_parent',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_book_page_description',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_page_level',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_innavigation',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:14',
            'target' => 'entityreference:field_related_content_link',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_taxonomy',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_legacy_create_date:start',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_legacy_modify_date:start',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:18',
            'target' => 'created',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_redirect_to_url',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_top_level_page_template',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          18 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_page_image:uri',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
        'skip_hash_check' => 1,
        'bundle' => 'book',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_django_cms_pages_to_drupal_book'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_feincms_news_and_features_articles';
  $feeds_importer->config = array(
    'name' => 'Import FeinCMS Science News articles',
    'description' => 'Importer for Science News articles from FeinCMS. ',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 0,
        'allowed_extensions' => 'xml html htm',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => './body',
          'xpathparser:2' => './title',
          'xpathparser:3' => './uid',
          'xpathparser:5' => './uuid',
          'xpathparser:7' => './create_date',
          'xpathparser:8' => './redirect_to',
          'xpathparser:9' => './active',
          'xpathparser:11' => './description',
          'xpathparser:12' => './taxonomy',
          'xpathparser:13' => './page_template',
          'xpathparser:14' => './thumb_nail',
        ),
        'rawXML' => array(
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:5' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
        ),
        'context' => '/root/page',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:2' => 'xpathparser:2',
            'xpathparser:12' => 'xpathparser:12',
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:11' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'input_format' => 'full_html',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'created',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_redirect_to_link',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:9',
            'target' => 'status',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_news_description',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_news_feature_taxonomy',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_science_new_page_template',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_news_features_image:uri',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
        'skip_hash_check' => 1,
        'bundle' => 'science_news_article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_feincms_news_and_features_articles'] = $feeds_importer;

  return $export;
}
