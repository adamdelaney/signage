<?php

function signage_preprocess_page(&$variables) {
  // Create a template suggestion for node types.
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
  if (isset($variables['page']['content']['system_main']['default_message'])) {
    unset($variables['page']['content']['system_main']['default_message']);
    drupal_set_title('');
  }
  global $user;

  if ($user->uid) {
  } else {
  if (arg(0) == 'user' && arg(1) == 'login') {
    drupal_set_title(t('Login'));
  }
  if (arg(0) == 'user') {
    drupal_set_title(t('Login'));
  }
  if (arg(0) == 'user' && arg(1) == 'password') {
    drupal_set_title(t('Request password'));
  }
  if (arg(0) == 'user' && arg(1) == 'register') {
    drupal_set_title(t('Create new account'));
  }
  }
}

function signage_preprocess_image(&$variables) {
  unset($variables['width'], $variables['height'], $variables['attributes']['width'], $variables['attributes']['height']);
}

function signage_preprocess_node(&$variables) {
  unset($variables['content']['links']['node']);
}

function signage_preprocess_overlay(&$variables) {
  // Add the path to the content class.
  $item = menu_get_item();
  $path = str_replace('%', '', $item['path']);
  // Remove trailing slash.
  $path = trim($path, '/');
  $path = str_replace('/', '-', $path);

  $variables['content_attributes_array']['class'][] = $path;
}

function signage_preprocess_search_result(&$variables) {
  // Remove user name and modification date from search results
  $variables['info'] = '';
}

/**
 * Changes default meta content-type to HTML5 version.
 */
function signage_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

function signage_css_alter(&$css) {
  unset($css[drupal_get_path('module','system').'/system.menus.css']);
  // List of disabled drupal default css files.
  $disabled_drupal_css = array(
    // Remove jquery.ui css files.
    'misc/ui/jquery.ui.core.css',
    'misc/ui/jquery.ui.theme.css',
  );

  // Remove drupal default css files.
  foreach ($css as $key => $item) {
    if (in_array($key, $disabled_drupal_css)) {
      // Remove css and its altered version that can be added by jquety_update.
      unset($css[$css[$key]['data']]);
      unset($css[$key]);
    }
  }
}

/**
 * Preprocess variables for html.tpl.php
 */
function signage_preprocess_html(&$variables) {
  drupal_add_library('system', 'ui');
  // Uses RDFa attribute if RDF module is enabled.
  // HTML5 + RDFA 1.1
  if (module_exists('rdf')) { $variables['html_version'] = 'version="HTML+RDFa 1.1"'; }
  else { $variables['html_version'] = ''; }

  // Add conditional CSS for IE
  drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'weight' => 115, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/css/ie8.css', array('group' => CSS_THEME, 'weight' => 115, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));

  $meta_viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width,initial-scale=1'
    )
  );
  drupal_add_html_head($meta_viewport, 'viewport');

  // Declare IE meta tag to force IE rendering mode
  $meta_ie_render_tag = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge,chrome=1',
    ),
    '#weight' => '-9999',
  );
  // Add IE meta tag
  drupal_add_html_head($meta_ie_render_tag, 'meta_ie_render_tag');

  // Declare meta tag for caching
  $meta_cache_render_tag = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'cache-control',
      'content' => 'no-cache',
    ),
    '#weight' => '-9999',
  );
  // Add IE meta tag
  drupal_add_html_head($meta_cache_render_tag, 'meta_cache_render_tag');

  // Declare meta tag for caching
  $meta_pragma_render_tag = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'pragma',
      'content' => 'no-cache',
    ),
    '#weight' => '-9999',
  );
  // Add IE meta tag
  drupal_add_html_head($meta_pragma_render_tag, 'meta_pragma_render_tag');

  global $user;
  foreach($user->roles as $key => $value) {
    $variables['classes_array'][] = 'role-' . $key;
  }

  // Add class to views page to provide consistent styling
  $variables['menu_item'] = menu_get_item();
  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'views_page':
      $variables['classes_array'][] = 'node-type-page';
      break;
    }
  }

}

function signage_date_all_day_label() {
  return t('');
}

