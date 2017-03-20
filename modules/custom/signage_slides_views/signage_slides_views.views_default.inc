<?php
/**
 * @file
 * signage_slides_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function signage_slides_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'slides_slideshows';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'signage';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_sign_primary_slideshow_node']['id'] = 'reverse_field_sign_primary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_primary_slideshow_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_sign_primary_slideshow_node']['field'] = 'reverse_field_sign_primary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_primary_slideshow_node']['required'] = TRUE;
  /* Field: Content: Slide Content */
  $handler->display->display_options['fields']['field_slide_content']['id'] = 'field_slide_content';
  $handler->display->display_options['fields']['field_slide_content']['table'] = 'field_data_field_slide_content';
  $handler->display->display_options['fields']['field_slide_content']['field'] = 'field_slide_content';
  $handler->display->display_options['fields']['field_slide_content']['label'] = '';
  $handler->display->display_options['fields']['field_slide_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_content']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_slide_content']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slide_content']['settings'] = array(
    'image_style' => 'slideshow_1920',
    'image_link' => '',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_slide_duration']['id'] = 'field_slide_duration';
  $handler->display->display_options['fields']['field_slide_duration']['table'] = 'field_data_field_slide_duration';
  $handler->display->display_options['fields']['field_slide_duration']['field'] = 'field_slide_duration';
  $handler->display->display_options['fields']['field_slide_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slide_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
  );
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
    'signage_slide' => 'signage_slide',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: End Date (field_slide_end_date) */
  $handler->display->display_options['filters']['field_slide_end_date_value']['id'] = 'field_slide_end_date_value';
  $handler->display->display_options['filters']['field_slide_end_date_value']['table'] = 'field_data_field_slide_end_date';
  $handler->display->display_options['filters']['field_slide_end_date_value']['field'] = 'field_slide_end_date_value';
  $handler->display->display_options['filters']['field_slide_end_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_slide_end_date_value']['group'] = 3;
  $handler->display->display_options['filters']['field_slide_end_date_value']['form_type'] = 'date_text';
  /* Filter criterion: Content: End Date (field_slide_end_date) */
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['id'] = 'field_slide_end_date_value_1';
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['table'] = 'field_data_field_slide_end_date';
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['field'] = 'field_slide_end_date_value';
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['group'] = 3;
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_slide_end_date_value_1']['default_date'] = 'now';
  /* Filter criterion: Content: Start Date (field_slide_start_date) */
  $handler->display->display_options['filters']['field_slide_start_date_value']['id'] = 'field_slide_start_date_value';
  $handler->display->display_options['filters']['field_slide_start_date_value']['table'] = 'field_data_field_slide_start_date';
  $handler->display->display_options['filters']['field_slide_start_date_value']['field'] = 'field_slide_start_date_value';
  $handler->display->display_options['filters']['field_slide_start_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_slide_start_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_slide_start_date_value']['form_type'] = 'date_text';
  /* Filter criterion: Content: Start Date (field_slide_start_date) */
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['id'] = 'field_slide_start_date_value_1';
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['table'] = 'field_data_field_slide_start_date';
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['field'] = 'field_slide_start_date_value';
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_slide_start_date_value_1']['default_date'] = 'now';
  /* Filter criterion: Content: Day of the Week (field_slide_day) */
  $handler->display->display_options['filters']['field_slide_day_value']['id'] = 'field_slide_day_value';
  $handler->display->display_options['filters']['field_slide_day_value']['table'] = 'field_data_field_slide_day';
  $handler->display->display_options['filters']['field_slide_day_value']['field'] = 'field_slide_day_value';
  $handler->display->display_options['filters']['field_slide_day_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_slide_day_value']['group'] = 4;

  /* Display: Primary Slideshow */
  $handler = $view->new_display('panel_pane', 'Primary Slideshow', 'primary_slideshow');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Primary Slideshow (field_sign_primary_slideshow:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_sign_primary_slideshow';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_sign_primary_slideshow_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Primary Slideshow';
  $handler->display->display_options['pane_category']['name'] = 'Slideshows';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_sign_primary_slideshow_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.field_sign_primary_slideshow',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Primary Slideshow (field_sign_primary_slideshow)',
    ),
  );

  /* Display: Secondary Slideshow */
  $handler = $view->new_display('panel_pane', 'Secondary Slideshow', 'secondary_slideshow');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_sign_secondary_slideshow_node']['id'] = 'reverse_field_sign_secondary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_secondary_slideshow_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_sign_secondary_slideshow_node']['field'] = 'reverse_field_sign_secondary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_secondary_slideshow_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Secondary Slideshow (field_sign_secondary_slideshow:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_sign_secondary_slideshow';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_sign_secondary_slideshow_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Secondary Slideshow';
  $handler->display->display_options['pane_category']['name'] = 'Slideshows';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Tertiary Slideshow */
  $handler = $view->new_display('panel_pane', 'Tertiary Slideshow', 'tertiary_slideshow');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_sign_tertiary_slideshow_node']['id'] = 'reverse_field_sign_tertiary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_tertiary_slideshow_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_sign_tertiary_slideshow_node']['field'] = 'reverse_field_sign_tertiary_slideshow_node';
  $handler->display->display_options['relationships']['reverse_field_sign_tertiary_slideshow_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Tertiary Slideshow (field_sign_tertiary_slideshow:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_sign_tertiary_slideshow';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_sign_tertiary_slideshow_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Tertiary Slideshow';
  $handler->display->display_options['pane_category']['name'] = 'Slideshows';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['slides_slideshows'] = $view;

  return $export;
}
