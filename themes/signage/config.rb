##
## This file is only needed for Compass/Sass integration. If you are not using
## Compass, you may safely ignore or delete this file.
##
## If you'd like to learn more about Sass and Compass, see the sass/README.txt
## file for more information.
##

# Location of the theme's resources.
css_dir = "stylesheets"
sass_dir = "sass"
images_dir = "images"
generated_images_dir = images_dir + "/generated"
javascripts_dir = "js"

# Require any additional compass plugins installed on your system.
require 'toolkit'
require 'breakpoint'
require 'singularitygs'
require 'sass-globbing'
require 'compass-normalize'

relative_assets = true
line_comments = false
debug_info = false
output_style = :nested
sass_options = {:sourcemap => true}
