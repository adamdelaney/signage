<?php
/**
 * @file
 * signage_promotions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function signage_promotions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'promotional_image_slideshow';
  $view->description = 'Show promotional image content items on the home page slideshow.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promotional Image Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'promotional-image-slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'promotional_image';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_promo_headline']['element_class'] = 'promo-headline';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Promo Image */
  $handler->display->display_options['fields']['field_promo_image']['id'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['table'] = 'field_data_field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['field'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['label'] = '';
  $handler->display->display_options['fields']['field_promo_image']['element_class'] = 'promo-image';
  $handler->display->display_options['fields']['field_promo_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_promo_image']['settings'] = array(
    'image_style' => 'promotional_image',
    'image_link' => '',
  );
  /* Field: Content: Promo Body */
  $handler->display->display_options['fields']['field_promo_body']['id'] = 'field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['table'] = 'field_data_field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['field'] = 'field_promo_body';
  $handler->display->display_options['fields']['field_promo_body']['label'] = '';
  $handler->display->display_options['fields']['field_promo_body']['element_class'] = 'promo-body';
  $handler->display->display_options['fields']['field_promo_body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'promotional_image' => 'promotional_image',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_promotional_image_slideshow');

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_promotional_image_slideshow');
  $export['promotional_image_slideshow'] = $view;

  return $export;
}
