<?php

/**
 * Here we override the default HTML output of drupal.
 * refer to http://drupal.org/node/550722
 */

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('clear_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}
// Add current page to breadcrumbs
// From: https://drupal.org/node/743366
function nasa_science_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Adding the title of the current page to the breadcrumb.
    $breadcrumb[] = drupal_get_title();
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<div class="breadcrumb">' . implode(' &rsaquo; ', $breadcrumb) . '</div>';
    return $output;
  }
 }

function nasa_science_preprocess_page (&$vars, $hook)
{
  if ($vars['is_front']) {
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/main.css','all', FALSE );
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/content.css','all', FALSE );
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/home.css','all', FALSE );
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/custom.css','all', FALSE );
    //drupal_add_css(drupal_get_path('theme','nasa_science').'/css/carouFredSel.css','all', FALSE );
    $vars['styles'] = drupal_get_css();
    /*
    //drupal_add_js(drupal_get_path('theme','nasa_science').'/js/jquery.carouFredSel-6.2.0-packed.js' );
    drupal_add_js(drupal_get_path('theme','nasa_science').'/js/home.js' );
    $vars['scripts'] = drupal_get_js();
    */
  } 
  else {
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/main.css','all', FALSE );
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/content.css','all', FALSE );
    drupal_add_css(drupal_get_path('theme','nasa_science').'/css/custom.css','all', FALSE );
    $vars['styles'] = drupal_get_css();
  } 
  if ($node = menu_get_object()) {
    $variables['node'] = $node;
  }
  if (isset($vars['node']) && $vars['node']->type == 'isatpage') {
    drupal_add_js('/media/sot/js/isat.min.js', array('weight' => 16));
    drupal_add_js('/media/sot/cesium/Cesium.js', array('weight' => 17));
    drupal_add_js('/media/sot/js/modernizr-2.7.1.min.js', array('weight' => 18));
    drupal_add_js('/media/sot/js/modernizr_load.js', array('weight' => 19));
    drupal_add_js('/media/sot/js/preload.js', array('weight' => 21)); 
    $vars['scripts'] = drupal_get_js();

    /* css files are pulled in from a file path */
    drupal_add_css(drupal_get_path('theme','nasa_science').'/sot/css/normalize.css', array('group' => CSS_THEME));
    drupal_add_css(drupal_get_path('theme','nasa_science').'/sot/css/main.css', array('group' => CSS_THEME));
    $vars['styles'] = drupal_get_css();

    /* load specific page template */
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;

  }
}
/* 
 * implements template_preprocessor_html()
 */
function nasa_science_preprocess_html (&$vars)
{
  /* change the image in the top header based on the division, i.e earth-science, planets etc.
     The change is done via adding a section-earth-science or section-planets etc class to the
     body tag.
  */
  $path = request_path(); /*drupal_get_path_alias($_GET['q']);*/
  $aliases = explode('/', $path);

  foreach($aliases as $alias) {
    $vars['classes_array'][] = 'section-' . drupal_clean_css_identifier($alias);
  } 
 if ($node = menu_get_object()) {
    if ($node->type == 'book') {
      // Return an array of taxonomy term ID's.
      $termids = field_get_items('node', $node, 'field_top_level_page_template');
      // Load all the terms to get the name and vocab.
      $terms = array();
      foreach ($termids as $termid) {
        $terms[] = taxonomy_term_load($termid['tid']);
      }
      // Assign the taxonomy values.
      foreach ($terms as $term) {
          $class = strtolower(drupal_clean_css_identifier($term->name));
          $vocabulary = drupal_clean_css_identifier($term->vocabulary_machine_name);
          $vars['classes_array'][] = 'section-' . $class;
      }
    }
    if($node->type == 'science_news_article') {
        $vars['classes_array'][] = 'section-science-news';
    }
  }
}
function nasa_science_preprocess_node(&$vars, $hook) {
 if ($node = menu_get_object()) {
    if ($node->type == 'book') {
      // Return an array of taxonomy term ID's.
      $termids = field_get_items('node', $node, 'field_top_level_page_template');
      // Load all the terms to get the name and vocab.
      $terms = array();
      foreach ($termids as $termid) {
        $terms[] = taxonomy_term_load($termid['tid']);
      }
      // Assign the taxonomy values.
      foreach ($terms as $term) {
          $class = strtolower(drupal_clean_css_identifier($term->name));
          $vocabulary = drupal_clean_css_identifier($term->vocabulary_machine_name);
          $vars['classes_array'][] = 'section-' . $class;
      }
    }
    if($node->type == 'science_news_article') {
          $vars['classes_array'][] = 'section-science-news';
    }
  }
}

