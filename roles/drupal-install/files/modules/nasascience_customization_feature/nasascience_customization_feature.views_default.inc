<?php
/**
 * @file
 * nasascience_customization_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nasascience_customization_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'home_page_science_news_pod';
  $view->description = 'Science news, 4 or 5, that appear in the top nav bar on the home page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home page science news pod';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Home page science news pod';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_news_article' => 'science_news_article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['home_page_science_news_pod'] = $view;

  $view = new view();
  $view->name = 'missions_in_table_block';
  $view->description = 'Missions in Table View.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Table of Missions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Missions In Table Block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'mission-block-view-table-row';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_acronyms' => 'field_acronyms',
    'field_full_name' => 'field_full_name',
    'field_home_page' => 'field_home_page',
    'field_launch_date' => 'field_launch_date',
    'field_launch_date_title' => 'field_launch_date_title',
    'field_phase' => 'field_phase',
    'field_programs' => 'field_programs',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_acronyms' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_full_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_home_page' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_launch_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_launch_date_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phase' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programs' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_acronyms_target_id']['id'] = 'field_acronyms_target_id';
  $handler->display->display_options['relationships']['field_acronyms_target_id']['table'] = 'field_data_field_acronyms';
  $handler->display->display_options['relationships']['field_acronyms_target_id']['field'] = 'field_acronyms_target_id';
  $handler->display->display_options['relationships']['field_acronyms_target_id']['required'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Mission Division';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'science_missions_directorate_vocabulary' => 'science_missions_directorate_vocabulary',
    'gallery_collections' => 0,
    'media_folders' => 0,
    'page_template' => 0,
    'tags' => 0,
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Full Name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Launch Date */
  $handler->display->display_options['fields']['field_launch_date']['id'] = 'field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['table'] = 'field_data_field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['field'] = 'field_launch_date';
  $handler->display->display_options['fields']['field_launch_date']['label'] = '';
  $handler->display->display_options['fields']['field_launch_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_launch_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_launch_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Phase */
  $handler->display->display_options['fields']['field_phase']['id'] = 'field_phase';
  $handler->display->display_options['fields']['field_phase']['table'] = 'field_data_field_phase';
  $handler->display->display_options['fields']['field_phase']['field'] = 'field_phase';
  $handler->display->display_options['fields']['field_phase']['label'] = '';
  $handler->display->display_options['fields']['field_phase']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phase']['element_label_colon'] = FALSE;
  /* Field: Content: Division */
  $handler->display->display_options['fields']['field_division_taxonomy_term']['id'] = 'field_division_taxonomy_term';
  $handler->display->display_options['fields']['field_division_taxonomy_term']['table'] = 'field_data_field_division_taxonomy_term';
  $handler->display->display_options['fields']['field_division_taxonomy_term']['field'] = 'field_division_taxonomy_term';
  $handler->display->display_options['fields']['field_division_taxonomy_term']['label'] = '';
  $handler->display->display_options['fields']['field_division_taxonomy_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_division_taxonomy_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_division_taxonomy_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Mission Image */
  $handler->display->display_options['fields']['field_mission_image_file']['id'] = 'field_mission_image_file';
  $handler->display->display_options['fields']['field_mission_image_file']['table'] = 'field_data_field_mission_image_file';
  $handler->display->display_options['fields']['field_mission_image_file']['field'] = 'field_mission_image_file';
  $handler->display->display_options['fields']['field_mission_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_mission_image_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mission_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mission_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_mission_image_file']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<div class=\'mission_view_row_div\'>
<h4><a href=\'[path]\'>[title]: [field_full_name]</a></h4>
<a href=\'[path]\'>[field_mission_image_file]</a><br/>
<b>Division: </b> [field_division_taxonomy_term]<br/>
<b>Launch Date: </b> [field_launch_date]<br/>
<b>Phase: </b> [field_phase]<br/>
<p>[field_description] </p>
</div>';
  $handler->display->display_options['fields']['field_description']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_description']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_description']['element_class'] = 'mission_view_row_div';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Acronyms (field_acronyms) */
  $handler->display->display_options['sorts']['field_acronyms_target_id']['id'] = 'field_acronyms_target_id';
  $handler->display->display_options['sorts']['field_acronyms_target_id']['table'] = 'field_data_field_acronyms';
  $handler->display->display_options['sorts']['field_acronyms_target_id']['field'] = 'field_acronyms_target_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mission' => 'mission',
  );

  /* Display: Table of Missions */
  $handler = $view->new_display('block', 'Table of Missions', 'block');
  $handler->display->display_options['display_description'] = 'Table of Missions. Can specify division/phase to filter by division and phase of missions.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_launch_date' => 'title',
    'field_phase' => 'title',
    'field_division_taxonomy_term' => 'title',
    'field_mission_image_file' => 'title',
    'field_description' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_launch_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phase' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_division_taxonomy_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mission_image_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'science_missions_directorate_vocabulary' => 'science_missions_directorate_vocabulary',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  /* Contextual filter: Content: Phase (field_phase) */
  $handler->display->display_options['arguments']['field_phase_value']['id'] = 'field_phase_value';
  $handler->display->display_options['arguments']['field_phase_value']['table'] = 'field_data_field_phase';
  $handler->display->display_options['arguments']['field_phase_value']['field'] = 'field_phase_value';
  $handler->display->display_options['arguments']['field_phase_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_phase_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_phase_value']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_phase_value']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_phase_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_phase_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_phase_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_phase_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_phase_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_phase_value']['limit'] = '0';
  $handler->display->display_options['block_description'] = 'Missions Table with thumbnail image';
  $export['missions_in_table_block'] = $view;

  $view = new view();
  $view->name = 'news_and_features_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News and Features View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News and Features View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ prev';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'row-class-in-table-for-news-features';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_redirect_to_link' => 'field_redirect_to_link',
    'title' => 'field_redirect_to_link',
    'created' => 'field_redirect_to_link',
    'field_news_features_image' => 'field_redirect_to_link',
    'field_news_description' => 'field_redirect_to_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_redirect_to_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_features_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Redirect To  */
  $handler->display->display_options['fields']['field_redirect_to_link']['id'] = 'field_redirect_to_link';
  $handler->display->display_options['fields']['field_redirect_to_link']['table'] = 'field_data_field_redirect_to_link';
  $handler->display->display_options['fields']['field_redirect_to_link']['field'] = 'field_redirect_to_link';
  $handler->display->display_options['fields']['field_redirect_to_link']['label'] = '';
  $handler->display->display_options['fields']['field_redirect_to_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_redirect_to_link']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_redirect_to_link]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_type'] = 'strong';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_news_features_image']['id'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['table'] = 'field_data_field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['field'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_features_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_features_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_features_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_features_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['label'] = '';
  $handler->display->display_options['fields']['field_news_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_news_description']['alter']['text'] = '<div class=\'science_headline_news_view_row\'>
  <a href="[field_redirect_to_link">[field_news_features_image]</a>
  <h4><a href="[field_redirect_to_link">[title]</a></h4>
  <p class="date">[created]</p>
  <p class="desc">[field_news_description] </p>
</div>';
  $handler->display->display_options['fields']['field_news_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_description']['element_wrapper_type'] = 'div';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_news_article' => 'science_news_article',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '14',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'science_missions_directorate_vocabulary';

  /* Display: News and Features View */
  $handler = $view->new_display('block', 'News and Features View', 'block');
  $handler->display->display_options['display_description'] = 'View block to display news and features blurbs with image pointing to external URL.';
  $handler->display->display_options['block_description'] = 'News and Features block from view';
  $export['news_and_features_view'] = $view;

  $view = new view();
  $view->name = 'science_at_nasa_headlines_view_for_all_years_in_past';
  $view->description = 'Science at NASA Headline news view block for all years in the past';
  $view->tag = 'default,science_news';
  $view->base_table = 'node';
  $view->human_name = 'Science at NASA Headlines View For All Years in Past';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Science News';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Older';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ prev';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Year of news';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'science_missions_directorate_vocabulary' => 'science_missions_directorate_vocabulary',
    'gallery_collections' => 0,
    'media_folders' => 0,
    'page_template' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Legacy Create Date (field_legacy_create_date) */
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['id'] = 'field_legacy_create_date_value';
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['table'] = 'field_data_field_legacy_create_date';
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['field'] = 'field_legacy_create_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Science at NASA Headlines View For all years in Past */
  $handler = $view->new_display('block', 'Science at NASA Headlines View For all years in Past', 'block');
  $handler->display->display_options['display_description'] = 'This view (block) displays science at NASA headlines for all years in the past.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'title',
    'nid' => 'title',
    'field_news_feature_taxonomy' => 'title',
    'field_news_features_image' => 'title',
    'field_news_description' => 'title',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_feature_taxonomy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_features_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Taxonomy */
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['id'] = 'field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['table'] = 'field_data_field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['field'] = 'field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['label'] = '';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_news_features_image']['id'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['table'] = 'field_data_field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['field'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_features_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_features_image']['alter']['text'] = '<div class=\'science_headline_news_view_row\'>
  <a href=\'/node/[nid]\'>[field_news_features_image]</a>
  <h4><a href=\'/node/[nid]\'>[title]</a></h4>
  <p class="date">[created]</p>
  <p class="container">
    <a href="/science-news/%1/">Science@NASA Headline News — %1</a>
  </p>
  <p class="desc">[field_news_description] </p>
</div>';
  $handler->display->display_options['fields']['field_news_features_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_features_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_news_features_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_features_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['label'] = '';
  $handler->display->display_options['fields']['field_news_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_description']['alter']['text'] = '<div style="padding-left:20px;"><p >[field_news_description] </p></div>';
  $handler->display->display_options['fields']['field_news_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_description']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'science_headline_news_view_row\'>
  <a href=\'[path]\'>[field_news_features_image]</a>
  <h4><a href=\'[path]\'>[title]</a></h4>
  <p class="date">[created]</p>
  <p class="desc">[field_news_description] </p>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'science_headline_news_container';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_news_article' => 'science_news_article',
  );
  /* Filter criterion: Content: Taxonomy (field_news_feature_taxonomy) */
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['id'] = 'field_news_feature_taxonomy_tid';
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['table'] = 'field_data_field_news_feature_taxonomy';
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['field'] = 'field_news_feature_taxonomy_tid';
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['value'] = array(
    82 => '82',
    25 => '25',
    27 => '27',
  );
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['vocabulary'] = 'science_missions_directorate_vocabulary';
  $handler->display->display_options['filters']['field_news_feature_taxonomy_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Science at NASA Headlines News for All Past Years';
  $export['science_at_nasa_headlines_view_for_all_years_in_past'] = $view;

  $view = new view();
  $view->name = 'science_nasa_headlines_for_2013';
  $view->description = 'Science at NASA Headline news view block with SMD taxonomy as context filter';
  $view->tag = 'default,science_news';
  $view->base_table = 'node';
  $view->human_name = 'Science at NASA Headlines View with year as context filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Science News';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Older';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ prev';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Year of news';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'science_missions_directorate_vocabulary' => 'science_missions_directorate_vocabulary',
    'gallery_collections' => 0,
    'media_folders' => 0,
    'page_template' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Legacy Create Date (field_legacy_create_date) */
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['id'] = 'field_legacy_create_date_value';
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['table'] = 'field_data_field_legacy_create_date';
  $handler->display->display_options['sorts']['field_legacy_create_date_value']['field'] = 'field_legacy_create_date_value';
  /* Contextual filter: Content: Taxonomy (field_news_feature_taxonomy) */
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['id'] = 'field_news_feature_taxonomy_tid';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['table'] = 'field_data_field_news_feature_taxonomy';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['field'] = 'field_news_feature_taxonomy_tid';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['validate_options']['vocabularies'] = array(
    'science_missions_directorate_vocabulary' => 'science_missions_directorate_vocabulary',
  );
  $handler->display->display_options['arguments']['field_news_feature_taxonomy_tid']['validate_options']['type'] = 'convert';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Science at NASA Headlines View: takes year as parameter */
  $handler = $view->new_display('block', 'Science at NASA Headlines View: takes year as parameter', 'block');
  $handler->display->display_options['display_description'] = 'This view (block) displays science at NASA headlines. It has a context filter that takes the year taxonomy term.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'title',
    'nid' => 'title',
    'field_news_feature_taxonomy' => 'title',
    'field_news_features_image' => 'title',
    'field_news_description' => 'title',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_feature_taxonomy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_features_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Taxonomy */
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['id'] = 'field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['table'] = 'field_data_field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['field'] = 'field_news_feature_taxonomy';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['label'] = '';
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_feature_taxonomy']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_news_features_image']['id'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['table'] = 'field_data_field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['field'] = 'field_news_features_image';
  $handler->display->display_options['fields']['field_news_features_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_features_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_features_image']['alter']['text'] = '<div class=\'science_headline_news_view_row\'>
  <a href=\'/node/[nid]\'>[field_news_features_image]</a>
  <h4><a href=\'/node/[nid]\'>[title]</a></h4>
  <p class="date">[created]</p>
  <p class="container">
    <a href="/science-news/%1/">Science@NASA Headline News — %1</a>
  </p>
  <p class="desc">[field_news_description] </p>
</div>';
  $handler->display->display_options['fields']['field_news_features_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_features_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_news_features_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_features_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['label'] = '';
  $handler->display->display_options['fields']['field_news_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_description']['alter']['text'] = '<div style="padding-left:20px;"><p >[field_news_description] </p></div>';
  $handler->display->display_options['fields']['field_news_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_description']['element_default_classes'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class=\'science_headline_news_view_row\'>
  <a href=\'[path]\'>[field_news_features_image]</a>
  <h4><a href=\'[path]\'>[title]</a></h4>
  <p class="date">[created]</p>
  <p class="desc">[field_news_description] </p>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'science_headline_news_container';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'science_news_article' => 'science_news_article',
  );
  $handler->display->display_options['block_description'] = 'Science at NASA Headlines with taxonomy year as parameter';
  $export['science_nasa_headlines_for_2013'] = $view;

  $view = new view();
  $view->name = 'slideshow_with_vsx';
  $view->description = 'Slide show for home page with overlays using Slide content type.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SlideShow with VSX';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'SlideShow with VSX';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_vsx_slide_link' => 0,
    'field_vsx_slide_thumbnail_image' => 0,
    'vsx_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_xtra_overlay']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_xtra_overlay']['pause_after_mouse_move'] = '2000';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_vsx_slide_thumbnail_image' => 'field_vsx_slide_thumbnail_image',
    'field_vsx_slide_link' => 0,
    'vsx_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_xtra_overlay']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_xtra_overlay']['pause_after_mouse_move'] = '2000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_vsx_slide_thumbnail_image' => 'field_vsx_slide_thumbnail_image',
  );
  /* Field: Content: Slide Link */
  $handler->display->display_options['fields']['field_vsx_slide_link']['id'] = 'field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['table'] = 'field_data_field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['field'] = 'field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_vsx_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vsx_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vsx_slide_link']['click_sort_column'] = 'url';
  /* Field: Content: Slide Thumbnail Image */
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['id'] = 'field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['table'] = 'field_data_field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['field'] = 'field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['label'] = '';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Slide Image */
  $handler->display->display_options['fields']['vsx_slide_image']['id'] = 'vsx_slide_image';
  $handler->display->display_options['fields']['vsx_slide_image']['table'] = 'field_data_vsx_slide_image';
  $handler->display->display_options['fields']['vsx_slide_image']['field'] = 'vsx_slide_image';
  $handler->display->display_options['fields']['vsx_slide_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['vsx_slide_image']['alter']['path'] = '[field_vsx_slide_link]';
  $handler->display->display_options['fields']['vsx_slide_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['vsx_slide_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Slide Order (vsx_slide_order) */
  $handler->display->display_options['sorts']['vsx_slide_order_value']['id'] = 'vsx_slide_order_value';
  $handler->display->display_options['sorts']['vsx_slide_order_value']['table'] = 'field_data_vsx_slide_order';
  $handler->display->display_options['sorts']['vsx_slide_order_value']['field'] = 'vsx_slide_order_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vsx_slide' => 'vsx_slide',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_vsx_slide_link' => 0,
    'field_vsx_slide_thumbnail_image' => 0,
    'vsx_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_xtra_overlay']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_xtra_overlay']['pause_after_mouse_move'] = '2000';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_vsx_slide_thumbnail_image' => 'field_vsx_slide_thumbnail_image',
    'field_vsx_slide_link' => 0,
    'vsx_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_xtra_overlay']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_xtra_overlay']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_xtra_overlay']['pause_after_mouse_move'] = '2000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_vsx_slide_thumbnail_image' => 'field_vsx_slide_thumbnail_image',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Overlay textbox for home page slide */
  $handler = $view->new_display('attachment', 'Overlay textbox for home page slide', 'attachment_1');
  $handler->display->display_options['display_description'] = 'Create overlay text box for the home page slides.';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'overlay';
  $handler->display->display_options['style_options']['class'] = 'slide-overlay-item-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'slide-overlay-item-list-wrapper';
  $handler->display->display_options['style_options']['overlay_delay'] = '1250';
  $handler->display->display_options['style_options']['overlay_fade_in'] = '0';
  $handler->display->display_options['style_options']['overlay_fade_out'] = '0';
  $handler->display->display_options['style_options']['overlay_fade_out_delay'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Slide Link */
  $handler->display->display_options['fields']['field_vsx_slide_link']['id'] = 'field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['table'] = 'field_data_field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['field'] = 'field_vsx_slide_link';
  $handler->display->display_options['fields']['field_vsx_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_vsx_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vsx_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vsx_slide_link']['click_sort_column'] = 'url';
  /* Field: Content: Slide Thumbnail Image */
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['id'] = 'field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['table'] = 'field_data_field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['field'] = 'field_vsx_slide_thumbnail_image';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['label'] = '';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['element_class'] = 'slide-overlay-thumbnail-wrapper';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_vsx_slide_thumbnail_image']['settings'] = array(
    'image_style' => 'slidethumbnail-130x62',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'slide-overlay-body-wrapper';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="slide-overlay-textbox">
 <h2>
 [field_vsx_slide_link]
 </h2>
 <div class="slide-overlay-body">
  <h4>[title]</h4>
   [body]
 </div>
</div>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $export['slideshow_with_vsx'] = $view;

  $view = new view();
  $view->name = 'solr_search_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_science_at_nasa_solr_search_index';
  $view->human_name = 'SOLR Search View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_science_at_nasa_solr_search_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_science_at_nasa_solr_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Text to Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'solr-search-view';
  $export['solr_search_view'] = $view;

  return $export;
}
