<?php
/**
 * @file
 * signage_promotions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function signage_promotions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function signage_promotions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function signage_promotions_image_default_styles() {
  $styles = array();

  // Exported image style: promotional_image.
  $styles['promotional_image'] = array(
    'label' => 'promotional_image (1000x600)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function signage_promotions_node_info() {
  $items = array(
    'promotional_image' => array(
      'name' => t('Promotional Image'),
      'base' => 'node_content',
      'description' => t('Use <em>promotional images</em> for featured content on the home page slideshow.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
