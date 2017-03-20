<?php
// Plugin definition
$plugin = array(
  'title' => t('Delta'),
  'icon' => 'delta.png',
  'category' => t('Signage'),
  'theme' => 'delta',
  'css' => 'delta.css',
  'regions' => array(
    'top-left' => t('Top Left'),
    'top-right' => t('Top Right'),
    'left' => t('Left Column'),
    'middle' => t('Middle Column'),
    'right' => t('Right Column'),
    'bottom' => t('Bottom')
  ),
);
