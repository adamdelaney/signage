<?php
/**
 * @file
 * Ctools content type plugin file for The University of Iowa nameplate.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Group logo'),
  'description' => t('Inheritable logo pane.'),
  'category' => t('General'),
  'edit form' => 'group_logo_edit_form',
  'render callback' => 'group_logo_render',
  'admin info' => 'group_logo_admin_info',
);


/**
 * The 'admin info' callback for panel pane.
 */
function group_logo_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Group logo.');
    return $block;
  }
}

/**
 * The 'Edit form' callback for the content type.
 */
function group_logo_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function group_logo_edit_form_submit($form, &$form_state) {
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
function group_logo_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';

  if ($current_group = og_context('node')) {

    $image = get_nearest_logo($current_group['gid']);

    if (!empty($image)) {
      $block->content = array(
        'image' => $image,
      );
    }
    else {
      return;
    }

  }

  return $block;
}

/**
 * Recursive function that finds the nearest group logo.
 *
 * This function traverses up the organic group tree to find the nearest parent
 * Sign Group that has a logo.
 *
 * @param string $group_id
 *   The node id of the group to load.
 *
 * @return array|NULL
 *   A render array of an image, or NULL if no image was found.
 */
function get_nearest_logo($group_id) {

  // Load group node.
  $group = node_load($group_id);

  // Return the group logo if it exists.
  if (!empty($group->field_group_logo)) {
    return array(
      '#theme' => 'image',
      '#path' => $group->field_group_logo[LANGUAGE_NONE][0]['uri'],
      '#alt' => $group->field_group_logo[LANGUAGE_NONE][0]['alt'],
      '#attributes' => array(
        'class' => array(
          'group-logo',
        ),
      ),
    );
  }

  // If this group has a parent group, recurse into that group.
  // @TODO: Look and see if there's a better way to do the Organic Groups
  // lookup.
  if (!empty($group->og_group_ref)) {
    return get_nearest_logo($group->og_group_ref[LANGUAGE_NONE][0]['target_id']);
  }
  // Otherwise, return NULL since we're at the root of the group hierarchy and
  // no logo was found.
  else {
    return;
  }

}
