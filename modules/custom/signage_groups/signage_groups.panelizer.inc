<?php
/**
 * @file
 * signage_groups.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function signage_groups_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'signage_group';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:signage_group:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '47e962c8-53ab-4532-879d-734ac7a282ba';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:signage_group:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7d36ca88-ac17-40a5-9edf-8fadefb48e2b';
  $pane->panel = 'bottom';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'page_manager',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7d36ca88-ac17-40a5-9edf-8fadefb48e2b';
  $display->content['new-7d36ca88-ac17-40a5-9edf-8fadefb48e2b'] = $pane;
  $display->panels['bottom'][0] = 'new-7d36ca88-ac17-40a5-9edf-8fadefb48e2b';
  $pane = new stdClass();
  $pane->pid = 'new-398de532-91c6-444c-a146-37a3da35aa70';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'og_extras-node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '398de532-91c6-444c-a146-37a3da35aa70';
  $display->content['new-398de532-91c6-444c-a146-37a3da35aa70'] = $pane;
  $display->panels['left'][0] = 'new-398de532-91c6-444c-a146-37a3da35aa70';
  $pane = new stdClass();
  $pane->pid = 'new-c9e23761-fc81-4383-9759-822e79c154f7';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'signage_group_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'type' => 'signage_slide',
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 1,
    'override_title_text' => 'Slides',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c9e23761-fc81-4383-9759-822e79c154f7';
  $display->content['new-c9e23761-fc81-4383-9759-822e79c154f7'] = $pane;
  $display->panels['left'][1] = 'new-c9e23761-fc81-4383-9759-822e79c154f7';
  $pane = new stdClass();
  $pane->pid = 'new-c3314291-3b9b-4ffe-a35b-163662ee363b';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'signage_group_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'type' => 'signage_sign',
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 1,
    'override_title_text' => 'Signs',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c3314291-3b9b-4ffe-a35b-163662ee363b';
  $display->content['new-c3314291-3b9b-4ffe-a35b-163662ee363b'] = $pane;
  $display->panels['right'][0] = 'new-c3314291-3b9b-4ffe-a35b-163662ee363b';
  $pane = new stdClass();
  $pane->pid = 'new-ecf846c8-2ff2-4acc-bea9-ed8d245e49bb';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'signage_group_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'type' => 'signage_group',
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 1,
    'override_title_text' => 'Groups',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ecf846c8-2ff2-4acc-bea9-ed8d245e49bb';
  $display->content['new-ecf846c8-2ff2-4acc-bea9-ed8d245e49bb'] = $pane;
  $display->panels['right'][1] = 'new-ecf846c8-2ff2-4acc-bea9-ed8d245e49bb';
  $pane = new stdClass();
  $pane->pid = 'new-a00da5b7-34cb-49b8-8796-db1c77496d89';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'og_group_subscribe',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'field_name' => '0',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a00da5b7-34cb-49b8-8796-db1c77496d89';
  $display->content['new-a00da5b7-34cb-49b8-8796-db1c77496d89'] = $pane;
  $display->panels['top'][0] = 'new-a00da5b7-34cb-49b8-8796-db1c77496d89';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a00da5b7-34cb-49b8-8796-db1c77496d89';
  $panelizer->display = $display;
  $export['node:signage_group:default'] = $panelizer;

  return $export;
}
