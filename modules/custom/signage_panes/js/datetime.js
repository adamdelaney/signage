/**
 * @file
 * Javascript for the signage panes module.
 */

 // Namespace jQuery to avoid conflicts.
(function($) {
  // Define the behavior.
  Drupal.dateTime = function() {

    // Call updateDateTime every 10 seconds.
    setInterval(Drupal.dateTime.updateDateTime, 10000);
  };

  // Attach dateTime behavior.
  Drupal.behaviors.dateTime = {
    attach: function(context, settings) {
      $('.pane-date-time', context).once('dateTime', function() {
        Drupal.dateTime.updateDateTime();
        Drupal.dateTime();
      });
    }
  };

  // Update date and time on the page.
  Drupal.dateTime.updateDateTime = function() {
    var datestr = "";
    var timestr = "";
    var datetimestr = "";
    var fullweekdayarray = new Array("Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday");
    var weekdayarray = new Array("Sun","Mon","Tue","Wed","Thu","Fri","Sat");
    var fullmontharray = new Array("January","February","March","April","May","June","July","August","September","October","November","December");
    var montharray = new Array("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");

    var currentTime = new Date;
    var weekday = weekdayarray[currentTime.getDay()];
    var day = currentTime.getDate();
    var month = montharray[currentTime.getMonth()];
    var year = currentTime.getFullYear();
    var hours = currentTime.getHours();
    var minutes = currentTime.getMinutes();
    var ampm = hours < 12 ? "AM" : "PM";
    hours = hours > 12 ? hours - 12 : hours;
    hours = hours == 0 ? 12 : hours;
    minutes = (minutes < 10 ? "0" : "") + minutes;

    datestr += weekday + ", " + month + " " + day;
    datetimestr += weekday + ", " + month + " " + day + " ";
    timestr += hours + ":" + minutes + " " + ampm;
    datetimestr += timestr;

    $('#datespan').text(datestr);
    $('#timespan').text(timestr);
  };

})(jQuery);
