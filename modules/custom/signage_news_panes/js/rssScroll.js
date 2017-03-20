/*
jQuery.
*/
(function ($) {

// Attach RSS scrolling behavior.
  Drupal.behaviors.rssScroll = {
    attach: function(context, settings) {
      $('.pane-news-panes-feed-list', context).once('rssScroll', function() {
        // Grab the RSS feed container.
        var $container = $(this);
        // Grab the RSS feed content.
        var $content = $('.view-display-id-feed_list .view-content');
        // Make sure we actually need to autoscroll.
        if ($content.height() > $container.height()) {
          // This is how long (in milliseconds) the beginning and end of the
          // scroll should wait before going down or up.
          var scrollDelay = 5000;
          // Figure out how long it's going to take to scroll by taking the
          // number of RSS items and multiplying it by 2500 (for 2.5 seconds).
          var scrollDuration = Drupal.settings.signageNewsPanes.rssNumberOfResults * 2500;
          // We'll know how far we need to scroll by figuring out how much more
          // content there is than the height of the container.
          var distanceToScroll = $content.height() - $container.height();
          // The reset interval is based on: the scroll duration (times 2 because
          // we're scrolling up and down), the scroll delay(you don't want it to
          // reset in the middle of it waiting), and the initial scroll delay (since
          // it should wait to reset once it gets back to the top as well).
          var scrollResetInterval = (scrollDuration*2) + (scrollDelay*2) + scrollDelay;
          // Start the intial scroll.
          $container.autoScroller({
            "scrollDelay": scrollDelay,
            "scrollDuration": scrollDuration,
            "distanceToScroll": distanceToScroll,
            "scrollResetInterval": scrollResetInterval,
          });
        }
      });
    }
  };


})(jQuery);
