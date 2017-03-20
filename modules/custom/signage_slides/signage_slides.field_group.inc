<?php
/**
 * @file
 * signage_slides.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function signage_slides_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sign_group|node|signage_slide|form';
  $field_group->group_name = 'group_sign_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_slide';
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
  $export['group_sign_group|node|signage_slide|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_scheduling|node|signage_slide|form';
  $field_group->group_name = 'group_slide_scheduling';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'signage_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scheduling',
    'weight' => '3',
    'children' => array(
      0 => 'field_slide_day',
      1 => 'field_slide_end_date',
      2 => 'field_slide_start_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Scheduling',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-slide-scheduling field-group-fieldset',
        'description' => 'The date range a slide is displayed in a slideshow.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_slide_scheduling|node|signage_slide|form'] = $field_group;

  return $export;
}
