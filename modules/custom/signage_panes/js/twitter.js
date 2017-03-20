/**
 * @file
 * Javascript for the twitter pane.
 */

// Namespace jQuery to avoid conflicts.
(function ($) {
  // Attach twitterWidth behavior.
  Drupal.behaviors.twitterWidth = {
    attach: function(context, settings) {
      $('.pane-twitter', context).once('twitterWidth', function() {
        // Force twitter to be 100% width.
        // See https://twittercommunity.com/t/how-can-i-extend-width-of-twitter-timeline-to-100-page-size/46101/2.
        $(window).bind('load', function() {
          $('iframe[id^=twitter-widget-]').each(function () {
            console.log('hi');
            var head = $(this).contents().find('head');
            if (head.length) {
              head.append('<style>.timeline { max-width: 100% !important; width: 100% !important; } .timeline .stream { max-width: none !important; width: 100% !important; }</style>');
            }
            $('#twitter-widget-0').append($('<div class=timeline>'));
          });
        });
      });
    }
  };
})(jQuery);
