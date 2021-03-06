<?php
/**
 * @file
 * signage_common.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function signage_common_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_file_default';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__preview_with_ratios__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_file_download_link';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__preview_with_ratios__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_file_table';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview_with_ratios__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_file_url_plain';
  $file_display->weight = -49;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__preview_with_ratios__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_image';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $export['image__preview_with_ratios__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview_with_ratios__file_field_media_large_icon';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__preview_with_ratios__file_field_media_large_icon'] = $file_display;

  return $export;
}
