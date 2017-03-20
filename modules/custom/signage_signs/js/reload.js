/**
 * @file
 * Reload signage signs.
 */

 // Namespace jQuery to avoid conflicts.
(function($) {
  // Fix to hide AJAX error alert messages.
  // http://drupal.org/node/1232416#comment-6667014
  window.alert = function(arg) { if (window.console && console.log) { console.log(arg);}};
  // Define the behavior.
  Drupal.reload = function() {
    // Call updateAvailability every ten minutes.
    setInterval(Drupal.reload.updateWindow, Drupal.settings.signageSign.reloadValue);
  };

  function hostReachable(location) {
    if (!location) {
      location = window.location.hostname + "/";
    }
    // Handle IE and more capable browsers
    var xhr = new ( window.ActiveXObject || XMLHttpRequest )( "Microsoft.XMLHTTP" );
    var status;

    // Open new request as a HEAD to the root hostname with a random param to bust the cache
    xhr.open( "HEAD", "//" + location + "?rand=" + Math.floor((1 + Math.random()) * 0x10000), false );

    // Issue request and handle response
    try {
      xhr.send();
      return ( xhr.status >= 200 && xhr.status < 300 || xhr.status === 304 );
    } catch (error) {
      return false;
    }

  }

  // Attach reload behavior.
  Drupal.behaviors.reload = {
    attach: function(context, settings) {
      $('html', context).once('reload', function() {
        Drupal.reload();
      });
    }
  };

  // Update all Availability on the page.
  Drupal.reload.updateWindow = function() {
    if (hostReachable(window.location.hostname + Drupal.settings.basePath)) {
      document.location.reload(true);
    }
    else {
    }
  };

})(jQuery);
