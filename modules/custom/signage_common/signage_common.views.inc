<?php


/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function signage_common_views_plugins() {
  return array(
    'argument default' => array(
      'og_context_parents' => array(
        'title' => t('Parent OG group(s) from context'),
        'handler' => 'signage_common_plugin_argument_og_parent_group_context',
        'parent' => 'og_context_plugin_argument_default_group_context',
      ),
    ),
  );
}
