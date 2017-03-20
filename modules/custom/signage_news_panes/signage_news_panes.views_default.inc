<?php
/**
 * @file
 * signage_news_panes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function signage_news_panes_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news_panes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'xml';
  $view->human_name = 'News Panes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['row_xpath'] = 'channel/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'marquee';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: pubDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'pubDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'n/j/Y';
  /* Sort criterion: pubDate: Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'xml';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  $handler->display->display_options['sorts']['date']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date']['xpath_selector'] = 'pubDate';

  /* Display: Column pane */
  $handler = $view->new_display('panel_pane', 'Column pane', 'feed_list');
  $handler->display->display_options['pane_title'] = 'RSS Feed List';
  $handler->display->display_options['pane_category']['name'] = 'Data Feeds';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['news_panes'] = $view;

  return $export;
}
