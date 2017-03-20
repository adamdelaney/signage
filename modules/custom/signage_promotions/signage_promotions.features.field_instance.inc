<?php
/**
 * @file
 * signage_promotions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function signage_promotions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-promotional_image-field_promo_body'
  $field_instances['node-promotional_image-field_promo_body'] = array(
    'bundle' => 'promotional_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_body',
    'label' => 'Promo Body',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-promotional_image-field_promo_headline'
  $field_instances['node-promotional_image-field_promo_headline'] = array(
    'bundle' => 'promotional_image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This text will appear \'floating\' on top of the image in bold stylized text.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_headline',
    'label' => 'Promo Headline',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 90,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-promotional_image-field_promo_image'
  $field_instances['node-promotional_image-field_promo_image'] = array(
    'bundle' => 'promotional_image',
    'deleted' => 0,
    'description' => 'Image will appear above the content and will be scaled and cropped at 1000 x 600 pixels.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'promotional_image',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_image',
    'label' => 'Promo Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'field/promotional_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '5 MB',
      'max_resolution' => '',
      'min_resolution' => '1000x600',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image will appear above the content and will be scaled and cropped at 1000 x 600 pixels.');
  t('Promo Body');
  t('Promo Headline');
  t('Promo Image');
  t('This text will appear \'floating\' on top of the image in bold stylized text.');

  return $field_instances;
}
