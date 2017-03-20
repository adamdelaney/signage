<?php
/**
 * @file
 * Ctools content type plugin file for signage panes module.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Date and Time'),
  'description' => t('Shows date and time.'),
  'category' => t('General'),
  'edit form' => 'datetime_edit_form',
  'render callback' => 'datetime_render',
  'admin info' => 'datetime_admin_info',
);


/**
 * The 'admin info' callback for panel pane.
 */
function datetime_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing date and time.');
    return $block;
  }
}

/**
 * The 'Edit form' callback for the content type.
 */
function datetime_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function datetime_edit_form_submit($form, &$form_state) {
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
function datetime_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = t('Date and Time');
  $block->content = array(
    '#markup' => '<span id="datespan"></span><span id="timespan"></span>',
  );
  drupal_add_js(drupal_get_path('module', 'signage_panes') . '/js/datetime.js');
  return $block;
}
