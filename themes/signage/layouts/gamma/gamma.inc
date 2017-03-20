<?php
// Plugin definition
$plugin = array(
  'title' => t('Gamma'),
  'icon' => 'gamma.png',
  'category' => t('Signage'),
  'theme' => 'gamma',
  'css' => 'gamma.css',
  'regions' => array(
    'top-left' => t('Top Left'),
    'top-right' => t('Top Right'),
    'left' => t('Left Column'),
    'middle' => t('Middle Column'),
    'right' => t('Right Column'),
    'bottom' => t('Bottom')
  ),
);
