<?php
/**
 * @file
 * signage_common.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function signage_common_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sign_group|file|image|form';
  $field_group->group_name = 'group_sign_group';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sign Group',
    'weight' => '5',
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
  $field_groups['group_sign_group|file|image|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sign Group');

  return $field_groups;
}
