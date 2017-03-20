; signage make file for local development
core = "7.x"
api = "2"

projects[drupal][version] = "7.50"
; include the d.o. profile base
includes[] = "drupal-org.make"

;;; Custom Modules ;;;

;;; Libraries ;;;

libraries[jquery.marquee][directory_name] = "jquery.marquee"
libraries[jquery.marquee][type] = library
libraries[jquery.marquee][destination] = "libraries"
libraries[jquery.marquee][download][type] = file
libraries[jquery.marquee][download][url] = http://www.givainc.com/labs/downloads/jquery.marquee.zip
