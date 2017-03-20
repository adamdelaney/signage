<?php
/**
 * @file
 * Ctools content type plugin file for The University of Iowa nameplate.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Marquee Data Feed'),
  'description' => t('Marquee display of RSS feed(s).'),
  'category' => t('Data Feeds'),
  'edit form' => 'signage_marquee_edit_form',
  'render callback' => 'signage_marquee_render',
  'admin info' => 'signage_marquee_admin_info',
  'defaults' => array(
    'items_per_page' => 5,
    'display_date' => 1,
    'primary_source_title' => '',
    'feed_source_primary' => '',
    'secondary_source_title' => '',
    'feed_source_secondary' => '',
    'tertiary_source_title' => '',
    'feed_source_tertiary' => '',
  ),
);


/**
 * The 'admin info' callback for panel pane.
 */
function signage_marquee_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Signage Marquee Data Feed');
    return $block;
  }
}

/**
 * The 'Edit form' callback for the content type.
 */
function signage_marquee_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['items_per_page'] = array(
    '#type' => 'textfield',
    '#description' => t('Select the number of items to display per feed, or 0 to display all results. If the number of items extends beyond the height of the pane, the items will scroll up and down automatically.'),
    '#title' => t('Number of items'),
    '#default_value' => $conf['items_per_page'],
    '#size' => 6,
    '#maxlength' => 3,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['display_date'] = array(
    '#type' => 'checkbox',
    '#description' => t('Display the "pubDate" for each item in the feed.'),
    '#title' => t('Display item date'),
    '#default_value' => $conf['display_date'],
  );

  $form['primary_source_title'] = array(
    '#type' => 'textfield',
    '#description' => t("Provide a title for this data feed. If not provided, the title will default to the feed's channel title."),
    '#title' => t('Primary Feed Title.'),
    '#default_value' => $conf['primary_source_title'],
    '#size' => 128,
    '#maxlength' => 128,
  );

  $form['feed_source_primary'] = array(
    '#type' => 'textfield',
    '#description' => t('Provide a valid RSS feed. Items will be sorted by
      date, in decending order.'),
    '#title' => t('Primary Feed URL'),
    '#default_value' => $conf['feed_source_primary'],
    '#size' => 128,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['secondary_source_title'] = array(
    '#type' => 'textfield',
    '#description' => t("Provide a title for this data feed. If not provided, the title will default to the feed's channel title."),
    '#title' => t('Secondary Feed Title.'),
    '#default_value' => $conf['secondary_source_title'],
    '#size' => 128,
    '#maxlength' => 128,
  );

  $form['feed_source_secondary'] = array(
    '#type' => 'textfield',
    '#description' => t('Optionally provide another valid RSS feed. Items will be sorted by
      date, in decending order.'),
    '#title' => t('Secondary Feed URL'),
    '#default_value' => $conf['feed_source_secondary'],
    '#size' => 128,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['tertiary_source_title'] = array(
    '#type' => 'textfield',
    '#description' => t("Provide a title for this data feed. If not provided, the title will default to the feed's channel title."),
    '#title' => t('Tertiary Feed Title.'),
    '#default_value' => $conf['tertiary_source_title'],
    '#size' => 128,
    '#maxlength' => 128,
  );

  $form['feed_source_tertiary'] = array(
    '#type' => 'textfield',
    '#description' => t('Optionally provide another valid RSS feed. Items will be sorted by
      date, in decending order.'),
    '#title' => t('Tertiary Feed URL'),
    '#default_value' => $conf['feed_source_tertiary'],
    '#size' => 128,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function signage_marquee_edit_form_submit($form, &$form_state) {
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
function signage_marquee_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  // Grab field names.
  // We're also re-indexing the field names filtered array to be 0 indexed.
  $source_field_names = array_values(array_filter(array_keys($conf), '_signage_marquee_sources_filter'));
  // Grab the field names of the title fields. They will be 0 indexed just like
  // the source field names.
  $title_fields = array_values(array_filter(array_keys($conf), '_signage_marquee_titles_filter'));
  // Get the field titles based off their field names.
  $feed_titles = array();
  foreach ($title_fields as $title) {
    $feed_titles[] = $conf[$title];
  }
  $number_of_items = (int) $conf['items_per_page'];
  $number_of_feeds = 0;
  foreach ($source_field_names as $key => $field_name) {
    // Make sure there's data first.
    if (!empty($conf[$field_name])) {
      // Get the parsed data from the feed.
      $result = signage_marquee_get_feed_data($conf[$field_name], $number_of_items, $key, $feed_titles[$key]);
      // Prepare the output for use in signage_marquee_item_list.
      $output = signage_marquee_prepare_output($result['data'], $conf['display_date']);
      // Make sure the first feed is always shown.
      if ($key == 0) {
        $attributes = array(
          'wrapper' => array(
            'class' => 'marquee-wrapper-shown marquee-list',
          ),
          'items' => array(
            'class' => 'marquee-shown',
            'id' => 'marquee-' . ($key + 1),
          ),
        );
      }
      else {
        $attributes = array(
          'wrapper' => array(
            'class' => 'marquee-wrapper-hidden marquee-list',
          ),
          'items' => array(
            'class' => 'marquee-hidden',
            'id' => 'marquee-' . ($key + 1),
          ),
        );
      }
      $block->content .= signage_marquee_item_list($output, $result['title'], 'ul', $attributes);
      $number_of_feeds++;
    }
  }

  // Add the Marquee library.
  libraries_load('jquery.marquee');
  if (($library = libraries_load('jquery.marquee')) && (!empty($library['loaded']))) {
    drupal_add_js(array("signageMarquee" => array('numberOfItems' => $number_of_feeds)), 'setting');
    drupal_add_js(drupal_get_path('module', 'signage_marquee') . '/js/newsMarquee.js');
  }
  return $block;
}

/**
 * Helper function to format feed data for signage_maruqee_item_list().
 *
 * @param array $data
 *         Array of parsed feed data.
 * @param  bool $date
 *         Whether or not to render the date in the feed.
 *
 * @return array $items
 *         An array of items to be passed to theme_item_list().
 */
function signage_marquee_prepare_output($data, $date) {
  $items = array();
  if ($date) {
    foreach ($data as $feed_data) {
      $items[] = array(
        'data' => '<span class="item-title">' . $feed_data['title'] . '</span> <span class="item-date">' . date('n/j/Y', $feed_data['pubDate']) . '</span>',
      );
    }
  }
  else {
    foreach ($data as $feed_data) {
      $items[] = array(
        'data' => '<span class="item-title">' . $feed_data['title'] . '</span>',
      );
    }
  }

  return $items;
}

/**
 * Override of theme_item_list().
 *
 * @param array $items
 * @param string $title
 * @param string $type
 * @param array $attributes
 *
 * @return string $output
 *   The rendered output for the list.
 */
function signage_marquee_item_list($items, $title, $type, $attributes) {

  // Only output the list container and title, if there are any list items.
  // Add the attributes for the wrapper div.
  $output = '<div' . drupal_attributes($attributes['wrapper']) . '>';
  if (isset($title) && $title !== '') {
    $output .= '<div class="marquee-title-wrapper"><div class="marquee-title">' . $title . '</div></div>';
  }

  if (!empty($items)) {
    // Add the attributes for the list items.
    $output .= "<$type" . drupal_attributes($attributes['items']) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(
          array(
            'items' => $children,
            'title' => NULL,
            'type' => $type,
            'attributes' => $attributes,
          )
        );
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}

/**
 * Fetch and decode the feed data.
 *
 * @param string $feed_url
 *        The url of the feed. Used to make an http request.
 * @param int $number_of_items
 *        The number of items to display. Comes from pane config.
 * @param int $field_key
 *        The key of the field we're requesting. Only used for
 *        error reporting.
 * @param string $feed_title
 *        The title of this feed from the pane config.
 *
 * @return array $result
 *         A formated array of the feed data and title.
 */
function signage_marquee_get_feed_data($feed_url, $number_of_items, $field_key, $feed_title) {
  // Get the data from an http request.
  $fetched_data = signage_marquee_decode($feed_url, $field_key);
  // Arrange it into a format we want.
  $decoded_data = signage_marquee_parse_feed_data($fetched_data);
  // Sort it by pubdate.
  // @todo: break out sort function into it's own definition.
  if (!empty($decoded_data)) {
    uasort($decoded_data['data'], '_signage_marquee_feed_data_sort');

    // If 0 is specified from pane config, get everything
    // from the feed.
    if ($number_of_items > 0) {
      $result['data'] = array_slice($decoded_data['data'], 0, $number_of_items);
    }
    else {
      $result['data'] = $decoded_data['data'];
    }
    // If a title was provided for this feed, set it here.
    // Defaults to the channel title.
    if (!empty($feed_title)) {
      $result['title'] = $feed_title;
    }
    else {
      $result['title'] = $decoded_data['title'];
    }

    return $result;
  }
}

/**
 * Helper function to extract desired feed fields and channel title.
 *
 * @param object $feed_data
 *        An object returned from drupal_http_request.
 *
 * @return array $result
 *         An array of the feeds data and channel title.
 */
function signage_marquee_parse_feed_data($feed_data) {
  $xml = simplexml_load_string($feed_data->data);
  $data = array();
  foreach ($xml->channel->item as $feed_item) {
    $data[] = array(
      'title' => (string) $feed_item->title,
      'pubDate' => strtotime((string) $feed_item->pubDate),
    );
  }
  $result = array(
    'data' => $data,
    'title' => (string) $xml->channel->title,
  );
  return $result;
}

/**
 * Decode the XML feed.
 *
 * @param string $url
 *        A url to an xml feed.
 *
 * @return array $result
 *         An array of the data retrived from the url.
 */
function signage_marquee_decode($url, $field_key) {
  // Grab the feed data.
  $result = drupal_http_request($url);
  // Make sure we recieved data.
  if ($result->code == 200) {
    return $result;
  }
  else {
    // Decide what field we're dealing with.
    $field_name = '';
    switch ($field_key) {
      case 0:
        $field_name = "Primary Feed Source";
        break;

      case 1:
        $field_name = "Secondary Feed Source";
        break;

      case 2:
        $field_name = "Tertiary Feed Source";
        break;

      default:
        break;
    }
    // Tell the user we can't fetch this feed.
    drupal_set_message(t("There doesn't seem to be a feed for @field_name at this URL. Please ensure the URL is correct.", array('@field_name' => $field_name)), 'error', FALSE);
  }
}

/**
 * Callback function to sort feed data by pubDate.
 */
function _signage_marquee_feed_data_sort($a, $b) {
  if ($a['pubDate'] == $b['pubDate']) {
    return 0;
  }
  return ($a['pubDate'] > $b['pubDate']) ? -1 : 1;
}

/**
 * Callback function to filter out title field names.
 */
function _signage_marquee_titles_filter($field_title) {
  if (preg_match("/source_title/", $field_title)) {
    return TRUE;
  }
}

/**
 * Callback function used to get feed sources from.
 */
function _signage_marquee_sources_filter($field_name) {
  if (preg_match("/feed_source/", $field_name)) {
    return TRUE;
  }
}
