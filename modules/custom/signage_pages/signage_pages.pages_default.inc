<?php
/**
 * @file
 * signage_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function signage_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '36686e70-97ed-44a9-8beb-0dfeeabe8dfc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c86273a4-ef24-4a6b-bfed-222ac3fd3789';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
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
    $pane->uuid = 'c86273a4-ef24-4a6b-bfed-222ac3fd3789';
    $display->content['new-c86273a4-ef24-4a6b-bfed-222ac3fd3789'] = $pane;
    $display->panels['middle'][0] = 'new-c86273a4-ef24-4a6b-bfed-222ac3fd3789';
    $pane = new stdClass();
    $pane->pid = 'new-d5162ebb-2426-4ec7-b1ca-be01349bffec';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'group_membership_list-panel_pane_group_membership_list_tree';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd5162ebb-2426-4ec7-b1ca-be01349bffec';
    $display->content['new-d5162ebb-2426-4ec7-b1ca-be01349bffec'] = $pane;
    $display->panels['middle'][1] = 'new-d5162ebb-2426-4ec7-b1ca-be01349bffec';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_e9e2b493-3169-4756-87c6-59ba778a5769';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Anonymous Users Homepage',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'aloha';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'row-one' => NULL,
      'row-two-left' => NULL,
      'row-two-right' => NULL,
      'row-three' => NULL,
      'row-four-left' => NULL,
      'row-four-middle' => NULL,
      'row-four-right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '982e4e34-9170-4ff7-a538-519a4fd3340b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2bf04954-3f43-42c2-b1cd-bbeb524f1a2d';
    $pane->panel = 'row-four-left';
    $pane->type = 'block';
    $pane->subtype = 'block-1';
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
    $pane->uuid = '2bf04954-3f43-42c2-b1cd-bbeb524f1a2d';
    $display->content['new-2bf04954-3f43-42c2-b1cd-bbeb524f1a2d'] = $pane;
    $display->panels['row-four-left'][0] = 'new-2bf04954-3f43-42c2-b1cd-bbeb524f1a2d';
    $pane = new stdClass();
    $pane->pid = 'new-cdcc9247-491c-4263-b0ae-1c4a523023c7';
    $pane->panel = 'row-four-middle';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
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
    $pane->uuid = 'cdcc9247-491c-4263-b0ae-1c4a523023c7';
    $display->content['new-cdcc9247-491c-4263-b0ae-1c4a523023c7'] = $pane;
    $display->panels['row-four-middle'][0] = 'new-cdcc9247-491c-4263-b0ae-1c4a523023c7';
    $pane = new stdClass();
    $pane->pid = 'new-51988518-0c5e-4ef2-aa6b-64fc51d65885';
    $pane->panel = 'row-four-right';
    $pane->type = 'block';
    $pane->subtype = 'block-3';
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
    $pane->uuid = '51988518-0c5e-4ef2-aa6b-64fc51d65885';
    $display->content['new-51988518-0c5e-4ef2-aa6b-64fc51d65885'] = $pane;
    $display->panels['row-four-right'][0] = 'new-51988518-0c5e-4ef2-aa6b-64fc51d65885';
    $pane = new stdClass();
    $pane->pid = 'new-ee24c4be-3996-4b26-ab93-73f8208d463d';
    $pane->panel = 'row-one';
    $pane->type = 'views';
    $pane->subtype = 'promotional_image_slideshow';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_promotional_image_slideshow',
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
    $pane->uuid = 'ee24c4be-3996-4b26-ab93-73f8208d463d';
    $display->content['new-ee24c4be-3996-4b26-ab93-73f8208d463d'] = $pane;
    $display->panels['row-one'][0] = 'new-ee24c4be-3996-4b26-ab93-73f8208d463d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
