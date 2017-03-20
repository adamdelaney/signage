<?php
// Plugin definition
$plugin = array(
  'title' => t('Beta Flipped'),
  'icon' => 'beta-flipped.png',
  'category' => t('Signage'),
  'theme' => 'beta_flipped',
  'css' => 'beta-flipped.css',
  'regions' => array(
    'top-left' => t('Top Left'),
    'top-right' => t('Top Right'),
    'left' => t('Left Column'),
    'right' => t('Right Column'),
    'bottom' => t('Bottom')
  ),
);
