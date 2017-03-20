<?php

/**
 * @file
 * Contains the group context argument default plugin.
 */

/**
 * The group context argument default handler.
 */
class signage_common_plugin_argument_og_parent_group_context extends og_context_plugin_argument_default_group_context {

  /**
   * Retrieve the options when this is a new access control plugin.
   */
  function option_definition() {
    $options = parent::option_definition();

    // Set the default include_current value to checked.
    $options['include_current'] = array('default' => 1);

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['include_current'] = array(
      '#type' => 'checkbox',
      '#title' => t('Include current group'),
      '#default_value' => $this->options['include_current'],
      '#description' => t('Include the current group in the list of parents.'),
    );
  }

  /**
   * Return the group context argument.
   */
  function get_argument() {
    if ($group = og_context($this->options['group_type'])) {

      // Get the parent groups.
      $parent_groups = og_subgroups_parents_load('node', $group['gid'], $filter = FALSE, $fetch_all = TRUE, $include_current = $this->options['include_current'], $reset = FALSE);

      if (!empty($parent_groups['node'])) {

        $parents = implode('+', array_keys($parent_groups['node']));

        return $parents;
      }

      return $group['gid'];
    }
    return FALSE;
  }
}
