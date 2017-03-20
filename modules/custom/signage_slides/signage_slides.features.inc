<?php
/**
 * @file
 * signage_slides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function signage_slides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function signage_slides_node_info() {
  $items = array(
    'signage_slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
