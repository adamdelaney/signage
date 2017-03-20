<?php

/**
 * @file
 * Definition of the 'general layout' pane style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Set custom style'),
  'description' => t('Display the pane with custom styles.'),
  'render pane' => 'signage_panes_custom_style_render_pane',
  'pane settings form' => 'signage_panes_custom_style_settings_form',
  'weight' => -5,
);

/**
 * General Layout panel settings form.
 */
function signage_panes_custom_style_settings_form($style_settings, $display, $pid, $type, $form_state) {

  // Grab the subtype for determining access to specific fields.
  $subtype = $display->content[$pid]->subtype;

  $form['height'] = array(
    '#type' => 'select',
    '#title' => t('Pane height (as a percentage of total screen height)'),
    '#options' => array(
      20 => t('20%'),
      30 => t('30%'),
      40 => t('40%'),
      50 => t('50%'),
      60 => t('60%'),
      70 => t('70%'),
      80 => t('80%'),
      90 => t('90%'),
      100 => t('100%'),
    ),
    '#default_value' => (isset($style_settings['height'])) ? $style_settings['height'] : '',
    '#empty_option' => t('- Automatic -'),
  );

  // Pane subtypes that are allowed to configure the height settings.
  $height = array(
    'localist_pane',
    'news_panes-feed_list',
  );

  // Restrict access to the height field for unapproved pane subtypes.
  if (!in_array($subtype, $height)) {
    $form['height']['#access'] = FALSE;
  }

  $form['font-size'] = array(
    '#type' => 'select',
    '#title' => t('Font size (in relation to base font size'),
    '#options' => array(
      75 => t('75%'),
      125 => t('125%'),
      150 => t('150%'),
      175 => t('175%'),
      200 => t('200%'),
      250 => t('250%'),
      300 => t('300%'),
      400 => t('400%'),
      500 => t('500%'),
      600 => t('600%'),
    ),
    '#default_value' => (isset($style_settings['font-size'])) ? $style_settings['font-size'] : '',
    '#empty_option' => t('- Automatic -'),
  );

  // Pane subtypes that are allowed to configure the font-size settings.
  $font_size = array(
    'astra_schedule',
    'bongo_predictions',
    'bongo_predictions_multiple',
    'custom',
    'ems_events',
  );

  // Restrict access to the font-size field for unapproved pane subtypes.
  if (!in_array($subtype, $font_size)) {
    $form['font-size']['#access'] = FALSE;
  }

  $form['stylize_table'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stylize the table'),
    '#default_value' => (isset($style_settings['stylize_table'])) ? $style_settings['stylize_table'] : '',
  );

  // Pane subtypes that are allowed to configure the font-size settings.
  $stylize = array(
    'ems_events',
  );

  // Restrict access to the font-size field for unapproved pane subtypes.
  if (!in_array($subtype, $stylize)) {
    $form['stylize_table']['#access'] = FALSE;
  }

  return $form;
}
/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_signage_panes_custom_style_render_pane($vars) {

  return theme('panels_pane', $vars);
}
