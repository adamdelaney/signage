/**
 * Autoscroller library to be used with Signage News Panes and
 * Localist pane functionality.
 */

// @todo: calculate scroll distance and whether we even need to scroll within
// this library.
(function($) {


$.fn.autoScroller = function (options) {
  // Get the options passed from function call.
  var settings = $.extend({}, options);
  // Had to pass "this" as an argument to keep function calls in scope.
  autoScroll(this);

  function scrollDown(element) {
    // Delay the scroll down by the scroll delay from the parent functions.
    element.delay(settings.scrollDelay).animate({scrollTop: settings.distanceToScroll}, settings.scrollDuration, 'linear', function() {

      // Animate has the option to call another function once the animation is
      // complete, so we start the scroll up once that happens.
      element.delay(settings.scrollDelay).animate({scrollTop: 0}, settings.scrollDuration, 'linear');
    });
  }

  function autoScroll(element) {
    element.scroll();
    scrollDown(element);
    setInterval(scrollDown, settings.scrollResetInterval, element);
  }

  return this;
};

})(jQuery);
