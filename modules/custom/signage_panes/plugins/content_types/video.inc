<?php
/**
 * @file
 * Ctools plugin file for video pane.
 */

define('YOUTUBE_REGEX_PATTERN', '/(?:http|https|)(?::\/\/|)(?:www.|)(?:youtu\.be\/|youtube\.com(?:\/embed\/|\/v\/|\/watch\?v=|\/ytscreeningroom\?v=|\/feeds\/api\/videos\/|\/user\S*[^\w\-\s]|\S*[^\w\-\s]))([\w\-]{11})[a-z0-9;:@#?&%=+\/\$_.-]*/');
define('YOUTUBE_PLAYLIST_REGEX_PATTERN', '/(?:http|https|)(?::\/\/|)(?:www.|)(?:youtu\.be\/|youtube\.com(?:\/embed\/|\/v\/|\/watch\?v=|\/ytscreeningroom\?v=|\/feeds\/api\/videos\/|\/user\S*[^\w\-\s]|\S*[^\w\-\s]))([\w\-]{12,})[a-z0-9;:@#?&%=+\/\$_.-]*/');
define('VIMEO_REGEX_PATTERN', '/player\.vimeo\.com\/video\/([0-9]*)/');
/**
 * Additional regex in case of errors.
 *
 * define('YOUTUBE_REGEX_PATTERN', '/(?:https?:\/\/)?(?:www\.)?(?:youtu\.be\/|youtube\.com(?:\/embed\/|\/v\/|\/watch\?v=))([\w-]{10,12})/');
 * define('YOUTUBE_PLAYLIST_REGEX_PATTERN', '/(?:https?:\/\/)?(?:www\.)?(?:youtu\.be\/|youtube\.com.*(?:\?|&)(?:list)=)((?!videoseries)[a-zA-Z0-9\_\-]*)/');
 *
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video pane'),
  'description' => t('Shows an embedded video with basic configuration options.'),
  'category' => t('Media'),
  'edit form' => 'signage_panes_video_edit_form',
  'render callback' => 'signage_panes_video_render',
  'admin info' => 'signage_panes_video_admin_info',
  'defaults' => array(
    'video_provider' => 0,
    'video_playlist' => 0,
    'video_embed_code' => '',
  ),
);

/**
 * Implements 'admin info' callback for panel pane.
 */
function signage_panes_video_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing embedded video from @video_provider provider.', array(
      '@video_provider' => $conf['video_provider'],
    ));
    return $block;
  }
}

/**
 * Implements 'edit form' callback for the content type.
 */
function signage_panes_video_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['video_provider'] = array(
    '#type' => 'select',
    '#title' => t('Video Provider'),
    '#description' => t('Select the video provider that hosts the videos to embed.'),
    '#options' => array(
      0 => t('YouTube'),
      1 => t('Vimeo'),
    ),
    '#default_value' => $conf['video_provider'],
    '#required' => TRUE,
  );

  $form['video_playlist'] = array(
    '#type' => 'checkbox',
    '#title' => t('YouTube Playlist'),
    '#description' => t('Select this option to activate a YouTube playlist.'),
    '#default_value' => $conf['video_playlist'],
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="video_provider"]' => array('value' => 0),
      ),
    ),
  );

  $form['video_embed_code'] = array(
    '#type' => 'textarea',
    '#title' => t('Video Embed Code'),
    '#description' => t('The new IFrame embed code for the video. The embed code is provided by the video provider by clicking on \'Share\', then \'Embed\' (e.g. &lt;iframe width="560" height="315" src="//www.youtube.com/embed/xDMP3i36naA" frameborder="0" allowfullscreen&gt;&lt;/iframe&gt;).<br><strong>NOTE:</strong> Options and parameters for embedded videos are set administratively in the module configuration.'),
    '#resizable' => FALSE,
    '#rows' => '8',
    '#default_value' => $conf['video_embed_code'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Implements the _validate() function to validate the form data.
 */
function signage_panes_video_edit_form_validate($form, &$form_state) {
  $video_provider = $form_state['values']['video_provider'];
  $video_playlist = $form_state['values']['video_playlist'];
  $video_embed_code = $form_state['values']['video_embed_code'];

  // Verify that a valid video ID is found.
  switch ($form_state['values']['video_provider']) {
    case 0:
      if ($form_state['values']['video_playlist']) {
        preg_match(YOUTUBE_PLAYLIST_REGEX_PATTERN, $form_state['values']['video_embed_code'], $matches);
        if (empty($matches[1])) {
          form_set_error('video_embed_code', t('The Video Embed Code does not contain a valid YouTube playlist ID.'));
        }
      } else {
        preg_match(YOUTUBE_REGEX_PATTERN, $form_state['values']['video_embed_code'], $matches);
        if (empty($matches[1])) {
          form_set_error('video_embed_code', t('The Video Embed Code does not contain a valid YouTube video ID.'));
        }
      }
      break;

    case 1:
      preg_match(VIMEO_REGEX_PATTERN, $form_state['values']['video_embed_code'], $matches);
      if (empty($matches[1])) {
        form_set_error('video_embed_code', t('The Video Embed Code does not contain a valid Vimeo video ID.'));
      }
      break;

  }

  // Verify that the embed code contains valid HTML tags.
  if (strip_tags($form_state['values']['video_embed_code']) != '') {
    form_set_error('video_embed_code', t('The Video Embed Code does not appear to be valid.'));
  }
}

/**
 * Implements the _submit() function and stores the data in $conf.
 */
function signage_panes_video_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      // Restrict embed code to iframe, object, param and embed tags only.
      if ($key == 'video_embed_code') {
        $form_state['values'][$key] = strip_tags($form_state['values']['video_embed_code'], '<iframe><object><param><embed>');
      }
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Implements the _render() function for run-time rendering.
 *
 * See ctools_plugin_examples for more advanced info.
 */
function signage_panes_video_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // Set default value of video_playlist in case we have existing
  // video panes.
  if (!isset($conf['video_playlist'])) {
    $conf['video_playlist'] = 0;
  }

  // Determine which provider to build for.
  switch ($conf['video_provider']) {
    case 0:
      if ($conf['video_playlist']) {
        // Extract the playlistID from the video embed code.
        preg_match(YOUTUBE_PLAYLIST_REGEX_PATTERN, $conf['video_embed_code'], $matches);
        $vid = $matches[1];
      } else {
        // Extract the videoID from the video embed code.
        preg_match(YOUTUBE_REGEX_PATTERN, $conf['video_embed_code'], $matches);
        $vid = $matches[1];
      }

      // Rebuild the URL according to newest standard using admin settings for parameters.
      if ($conf['video_playlist']) {
        $url = '//www.youtube.com/embed?listType=playlist&list=' . $vid . '&';
      } else {
        $url = '//www.youtube.com/v/' . $vid . '?';
      }

      $params = '';
      $params .= 'theme=' . variable_get('signage_panes_video_youtube_theme') . '&';
      $params .= 'autoplay=' . variable_get('signage_panes_video_youtube_autoplay') . '&';
      $params .= 'loop=' . variable_get('signage_panes_video_youtube_loop') . '&';
      $params .= 'vq=' . variable_get('signage_panes_video_youtube_vq') . '&';
      $params .= 'rel=' . variable_get('signage_panes_video_youtube_rel') . '&';
      $params .= 'showinfo=' . variable_get('signage_panes_video_youtube_showinfo') . '&';
      $params .= 'modestbranding=' . variable_get('signage_panes_video_youtube_modestbranding') . '&';
      $params .= 'cc_load_policy=' . variable_get('signage_panes_video_youtube_cc_load_policy') . '&';
      $params .= 'iv_load_policy=' . variable_get('signage_panes_video_youtube_iv_load_policy') . '&';
      $params .= 'controls=' . variable_get('signage_panes_video_youtube_controls') . '&';
      $params .= 'autohide=' . variable_get('signage_panes_video_youtube_autohide');

      if (!$conf['video_playlist']) {
        $params .= '&playlist=' . $vid;
      }

      // Recreate embed code based on most recent IFrame version of the HTML5 player from YouTube provider.
      $embed_code = 'width=' . variable_get('signage_panes_video_youtube_width') .
        ' height=' . variable_get('signage_panes_video_youtube_height') .
        ' src=' . $url . '' . $params .
        ' frameborder=0 allowfullscreen=false';

      break;

    case 1:
      // Extract the videoID from the video embed code.
      preg_match(VIMEO_REGEX_PATTERN, $conf['video_embed_code'], $matches);
      $vid = $matches[1];

      // Rebuild the URL according to newest standard using admin settings for
      // parameters.
      $url = '//player.vimeo.com/video/' . $vid;
      $params = '';
      $params .= 'autoplay=' . variable_get('signage_panes_video_vimeo_autoplay') . '&';
      $params .= 'loop=' . variable_get('signage_panes_video_vimeo_loop') . '&';
      $params .= 'color=' . variable_get('signage_panes_video_vimeo_color') . '&';
      $params .= 'portrait=' . variable_get('signage_panes_video_vimeo_portrait') . '&';
      $params .= 'title=' . variable_get('signage_panes_video_vimeo_title') . '&';
      $params .= 'byline=' . variable_get('signage_panes_video_vimeo_byline');

      // Recreate embed code based on most recent IFrame version of the HTML5
      // player from Vimeo provider.
      $embed_code = 'src=' . $url . '?' . $params .
        ' width=' . variable_get('signage_panes_video_vimeo_width') .
      ' height=' . variable_get('signage_panes_video_vimeo_height') .
      ' frameborder=0 webkitallowfullscreen mozallowfullscreen allowfullscreen';

      break;
  }

  // Create the block settings.
  $block->title = '';
  $block->content = '
    <div class="flexible-container">
	  <iframe ' . $embed_code . '></iframe>
	</div>
  ';

  return $block;
}
