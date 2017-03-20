<?php
/**
 * @file
 * Ctools content type plugin file for signage panes module.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Twitter user timeline'),
  'description' => t('Shows a twitter user timeline with basic configuration options.'),
  'category' => t('Data Feeds'),
  'edit form' => 'signage_panes_twitter_timeline_edit_form',
  'render callback' => 'signage_panes_twitter_timeline_render',
  'admin info' => 'signage_panes_twitter_timeline_admin_info',
  'defaults' => array(
    'username' => 'uiowa',
    'tweets_to_show' => 10,
    'widget_id' => '',
    'chrome' => array('nofooter'),
  ),
);


/**
 * The 'admin info' callback for panel pane.
 */
function signage_panes_twitter_timeline_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing @tweets_to_show tweets from <em>@@username</em>.', array(
      '@tweets_to_show' => $conf['tweets_to_show'],
      '@username' => $conf['username'],
    ));
    return $block;
  }
}

/**
 * The 'Edit form' callback for the content type.
 */
function signage_panes_twitter_timeline_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['widget_id'] = array(
    '#title' => t('Twitter Widget ID'),
    '#description' => t('The widget_id/application ID from your twitter account. This pane will inherit configuration options from your user timeline widget configuration, except for the theme, which is always the dark theme and Twitter username, which is required below.'),
    '#type' => 'textfield',
    '#default_value' => $conf['widget_id'],
    '#required' => TRUE,
  );

  $form['username'] = array(
    '#title' => t('Twitter username'),
    '#description' => t('The username of the twitter account in which to pull the tweets from.'),
    '#type' => 'textfield',
    '#default_value' => $conf['username'],
    '#required' => TRUE,
  );

  $form['tweets_to_show'] = array(
    '#title' => t('Number of tweets to show'),
    '#description' => t('Used to control the number of tweets shown on the page initially. Defaults to 5.'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(range(1, 12)),
    '#default_value' => $conf['tweets_to_show'],
    '#required' => TRUE,
  );

  $form['chrome'] = array(
    '#title' => t('Control the widget layout'),
    '#description' => t('Control the widget layout and chrome via the following options'),
    '#type' => 'checkboxes',
    '#options' => array(
      'noheader' => t('No header'),
      'nofooter' => t('No footer'),
      'noborders' => t('No borders'),
      'noscrollbar' => t('No scrollbar'),
      'transparent' => t('Transparent'),
    ),
    '#default_value' => $conf['chrome'],
    '#required' => FALSE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function signage_panes_twitter_timeline_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function signage_panes_twitter_timeline_render($subtype, $conf, $panel_args, $context = NULL) {
  // Initial content is blank.
  $block->title = '';

  $block->content = array(
    '#type' => 'link',
    '#title' => t('Tweets by @username', array('@username' => $conf['username'])),
    '#href' => check_url('https://twitter.com/' . $conf['username']),
    '#options' => array(
      'attributes' => array(
        'class' => array('twitter-timeline'),
        'data-widget-id' => check_plain($conf['widget_id']),
        'data-chrome' => '',
        'data-tweet-limit' => check_plain($conf['tweets_to_show']),
        'data-screen-name' => check_plain($conf['username']),
        'data-theme' => 'dark',
        'data-aria-polite' => 'assertive',
      ),
      'html' => FALSE,
    ),
    '#attached' => array(
      'js' => array(
        array(
          'type' => 'external',
          'data' => '//platform.twitter.com/widgets.js',
        ),
        array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'signage_panes') . '/js/twitter.js',
        ),
      ),
    ),
  );

  if (!empty($conf['chrome'])) {
    $options = array();

    foreach ($conf['chrome'] as $option => $status) {
      if ($status) {
        $options[] = $option;
      }
    }

    if (count($options)) {
      $block->content['#options']['attributes']['data-chrome'] = implode(' ', $options);
    }
  }

  return $block;
}
