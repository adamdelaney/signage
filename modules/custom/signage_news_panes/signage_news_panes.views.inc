<?php
/**
* @file
* Views hooks for the signage_news_panes module.
*/

/**
 * Implements hook_views_post_build().
 */
function signage_news_panes_views_post_build($view) {
  if ($view->name == 'news_panes') {
    $feed_url = $view->display_handler->options['pane_conf']['feed_source'];
    $view->query->options['xml_file'] = $feed_url;
  }
}

function signage_news_panes_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  if ($view->name == 'news_panes') {
    $lib = libraries_load('autoscroller');
    if (!empty($lib['loaded'])) {
      $js = array();
      if ($view->current_display == "feed_list") {
        $number_of_rows = count($view->result);
        $js['#attached']['js'][] = array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'signage_news_panes') .'/js/rssScroll.js',
        );

        $js['#attached']['js'][] = array(
          'type' => 'setting',
          'data' => array('signageNewsPanes' => array('rssNumberOfResults' => $number_of_rows)),
        );
      }
      drupal_render($js);
    }
  }
}
