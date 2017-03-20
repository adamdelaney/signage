/**
 * @file
 *
 * Marquee scroller.
 */

// The jQuery wrapper.
(function ($) {
  // Attach news Marquee behavior.
  Drupal.behaviors.newsMarquee = {
    attach: function(context, settings) {
      $('.pane-signage-marquee', context).once('newsMarquee', function() {
        Drupal.newsMarquee.numberOfFeeds = Drupal.settings.signageMarquee.numberOfItems;
        Drupal.newsMarquee.init();
        Drupal.newsMarquee.playMarquee();
      });
    }
  };

  /*
   * News Marquee.
   */
  Drupal.newsMarquee = {};
  // Keeps track of which marquee is being shown.
  // The initial marquee to show should always be the first.
  var feedCounter = 1;
  // Helper function to hide all marquees that should be hidden.
  Drupal.newsMarquee.init = function () {
    $('.marquee-wrapper-hidden').hide();
  }

  // This function takes care of pausing the old marquee, hiding it's title,
  // and hiding the whole marquee itself.
  // It also shows the title of the new marquee, reveals it,
  // and sets it to play.
  Drupal.newsMarquee.switchMarquees = function(oldMarquee, newMarquee) {
    oldMarquee.marquee('pause');
    oldMarquee.siblings('.marquee-title-wrapper').fadeOut(1000);
    oldMarquee.parent().hide();
    newMarquee.siblings('.marquee-title-wrapper').fadeIn(1000);
    newMarquee.parent().show();
    Drupal.newsMarquee.playMarquee();
  }
  // This helper function sets the conter for the next marquee
  // that should be shown.
  Drupal.newsMarquee.setNextMarqueeCounter = function () {
    if (feedCounter >= Drupal.newsMarquee.numberOfFeeds) {
      feedCounter = 1;
    } else {
      feedCounter++;
    }
    return feedCounter;
  }
  // This is the function that actually plays the marquee.
  Drupal.newsMarquee.playMarquee = function() {
    var $marqueeSelector = $("#marquee-" + feedCounter);
    // If we've seen this marquee already, just resume it.
    if ($marqueeSelector.hasClass('marquee-processed')) {
      $marqueeSelector.marquee('resume');
    } else {
      // Otherwise we need to initialze a new one.
      $marqueeSelector.marquee({
        loop: -1,
        yScroll: "bottom",
        aftershow: function ($marquee, $li) {
          if ($li.hasClass('last') && Drupal.newsMarquee.numberOfFeeds > 1) {
            // Since we stopped on the last list item, the libarary
            // doesn't get a chance to hide it for us so we do it here.
            $li.css({"top": -100, "left": 0});
            // Get the id number of the next marquee.
            var nextMarquee = Drupal.newsMarquee.setNextMarqueeCounter();
            var $next = $('#marquee-' + nextMarquee);
            // The only important class here is the marquee-processed class.
            // The others are just useful for debugging.
            $marquee.removeClass('marquee-shown').addClass('marquee-hidden marquee-processed').parent().removeClass('marquee-wrapper-shown').addClass('marquee-wrapper-hidden');
            $next.removeClass('marquee-hidden').addClass('marquee-shown').parent().removeClass('marquee-wrapper-hidden').addClass('marquee-wrapper-shown');
            // Cycle the marquees.
            Drupal.newsMarquee.switchMarquees($marquee, $next);
          }
        }
      });
    }
  }
})(jQuery);
