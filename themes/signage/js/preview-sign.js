(function ($) {
  Drupal.behaviors.previewSign = {
    attach: function (context, settings) {
      $('#preview-button', context).once('preview-button', function () {
        $('body').addClass('preview-off');

        $('#preview-button').bind('click', function(e) {
          $('body').toggleClass("preview-off preview-on");
          $('#preview-button').children('.fa').toggleClass("fa-eye fa-eye-slash");
          e.preventDefault();
        });
      });
    }
  };
})(jQuery);
