<?php
/**
 * @file
 * Admin form for global html export settings.
 */

/**
 * Implements hook_settings().
 */
function _html_export_settings() {
  // allow for global setting for views if its enabled
  $options = array();
  if (module_exists('views')) {
    $views = views_get_all_views();
    foreach ($views as $key => $view) {
      // pull out enabled views that have node as the base
      if ($view->base_table == 'node' && !$view->disabled) {
        $options[$key] = $key;
      }
    }
    // Todo - is there any reason only node-based? Also, maybe add an All Views, All node-based views, All user-based views etc.

    // build the form
    $form['html_export_available_views'] = array(
      '#type' => 'select',
      '#multiple' => TRUE,
      '#title' => t('Views based selectors'),
      '#default_value' => variable_get('html_export_available_views', array()),
      '#options' => $options,
      '#description' => t('Select the views that are available to use as selectors for pulling their query results. Only use these if you know what you are doing.'),
    );
  }
  // list of all types
  $options = array();
  $types = node_type_get_types();
  foreach ($types as $key => $type) {
    $options[$key] = $type->name;
  }

  // build the form
  $form['html_export_available_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Type based selectors'),
    '#default_value' => variable_get('html_export_available_types', array()),
    '#options' => $options,
    '#description' => t('Select the types that are available for publishing as options.'),
  );

  $form['html_export_other_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Other paths to export'),
    '#description' => t("Provide one path per line of additional paths to export."),
    '#default_value' => variable_get('html_export_other_paths', '<front>'),
  );

  $form['html_export_exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude these paths from export'),
    '#description' => t("Provide one path per line of additional paths to exclude from the export. You can use Drupal wildcard paths here - e.g 'admin/*'. This does not rewrite HTML to remove these items from pages where they are linked."),
    '#default_value' => variable_get('html_export_exclude_paths', ''),
  );

  $form['html_export_dom_remove'] = array(
    '#type' => 'textarea',
    '#title' => t('Default dom removal'),
    '#description' => t("Supply a css style selector to target the removal of. This is especially useful for removing things like the admin toolbar, tabs, or other elements you don't want to have exported. One selectors per line."),
    '#default_value' => variable_get('html_export_dom_remove', ''),
  );

  $form['amazon'] = array(
    '#type' => 'fieldset',
    '#title' => t('Amazon settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['amazon']['html_export_amazon_s3_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('Amazon S3 bucket'),
    '#default_value' => variable_get('html_export_amazon_s3_bucket', ''),
    '#size' => 20,
    '#maxlength' => 40, //Todo - check the max size of s3 bucket name.
    '#description' => t("If you are using S3, then enter the bucket name here. The bucket will be created if it doesn't exist. Remember that bucket names must be globally unique, and the rules for names used for static websites."),
  );

  $form['amazon']['html_export_amazon_cloudfront_distro_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Amazon Cloudfront distribution id'),
    '#default_value' => variable_get('html_export_amazon_cloudfront_distro_id', ''),
    '#size' => 20,
    '#maxlength' => 40,  //Todo - check the max size of amazon cloudfront distro id.
    '#description' => t("If you are using Amazon Cloudfront in association with a bucket, then enter the distribution ID here. Otherwise leave this blank. The distribution will not be created, but uploaded files can be invalidated."),
  );

  return system_settings_form($form);
}

/**
 * Submit handler for HTML rendering job
 *
 * This sets up all the variables needed for the batch job from the form submission, then triggers the batch job.
 */
//function _html_export_settings_submit($form, &$form_state) {
//
//}
