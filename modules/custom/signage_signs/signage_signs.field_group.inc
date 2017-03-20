<?php
/**
 * @file
 * signage_signs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function signage_signs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sign_group|node|signage_sign|form';
  $field_group->group_name = 'group_sign_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_sign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sign Group',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sign Group',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-sign-group field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sign_group|node|signage_sign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshow_primary|node|signage_sign|form';
  $field_group->group_name = 'group_slideshow_primary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_sign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_slideshow';
  $field_group->data = array(
    'label' => 'Primary Slideshow',
    'weight' => '9',
    'children' => array(
      0 => 'field_sign_primary_slideshow',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-slideshow-primary field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_slideshow_primary|node|signage_sign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshow_secondary|node|signage_sign|form';
  $field_group->group_name = 'group_slideshow_secondary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_sign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_slideshow';
  $field_group->data = array(
    'label' => 'Secondary Slideshow',
    'weight' => '10',
    'children' => array(
      0 => 'field_sign_secondary_slideshow',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-slideshow-secondary field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_slideshow_secondary|node|signage_sign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshow_tertiary|node|signage_sign|form';
  $field_group->group_name = 'group_slideshow_tertiary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_sign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_slideshow';
  $field_group->data = array(
    'label' => 'Tertiary Slideshow',
    'weight' => '11',
    'children' => array(
      0 => 'field_sign_tertiary_slideshow',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-slideshow-tertiary field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_slideshow_tertiary|node|signage_sign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshow|node|signage_sign|form';
  $field_group->group_name = 'group_slideshow';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_sign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slideshows',
    'weight' => '2',
    'children' => array(
      0 => 'group_slideshow_primary',
      1 => 'group_slideshow_secondary',
      2 => 'group_slideshow_tertiary',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Slideshows',
      'instance_settings' => array(
        'classes' => 'group-slideshow field-group-htabs',
      ),
    ),
  );
  $field_groups['group_slideshow|node|signage_sign|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Primary Slideshow');
  t('Secondary Slideshow');
  t('Sign Group');
  t('Slideshows');
  t('Tertiary Slideshow');

  return $field_groups;
}
