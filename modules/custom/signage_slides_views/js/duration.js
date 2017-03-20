(function ($) {
  Drupal.behaviors.flexsliderDuration = {
    attach: function (context, settings) {
      $('.flexslider').bind('start', function(e, slider) {
        // Clears the interval.
        slider.stop();

        slider.vars.slideshowSpeed = $(slider.slides[slider.currentSlide]).data('duration') * 1000;

        // Start the interval.
        slider.play();
      });

      $('.flexslider').bind('after', function(e, slider) {
        //Clears the interval.
        slider.stop();
        // Grab the duration to show this slide.
        slider.vars.slideshowSpeed = $(slider.slides[slider.currentSlide]).data('duration') * 1000;

        // Start the interval.
        slider.play();
      });
    }
  };
}(jQuery));
