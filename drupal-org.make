; signage make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++
projects[crumbs][version] = "2.5"
projects[crumbs][subdir] = "contrib"

projects[ctools][version] = "1.9"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.9"
projects[date][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.7"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[entityreference_prepopulate][version] = "1.6"
projects[entityreference_prepopulate][subdir] = "contrib"

projects[escape_admin][version] = "1.2"
projects[escape_admin][subdir] = "contrib"

projects[features][version] = "2.10"
projects[features][subdir] = "contrib"

projects[field_group][version] = "1.5"
projects[field_group][subdir] = "contrib"

projects[file_entity][version] = '2.0-beta2'
projects[file_entity][subdir] = "contrib"

projects[flexslider][version] = '2.0-rc1'
projects[flexslider][subdir] = "contrib"
projects[flexslider][patch][] = "https://www.drupal.org/files/issues/flexslider_include_object_in_callback-1580902-40.patch"

projects[ief_dialog][version] = '1.0'
projects[ief_dialog][subdir] = "contrib"

projects[inline_entity_form][version] = '1.6'
projects[inline_entity_form][subdir] = "contrib"
projects[inline_entity_form][patch][] = "https://www.drupal.org/files/issues/1872316-ief-bundle-selection-erv-22_0.patch"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[media][version] = "2.0-beta1"
projects[media][subdir] = "contrib"
projects[media][patch][] = "https://www.drupal.org/files/issues/media-browser_opens_twice-2534724-35.patch"

projects[node_clone][version] = "1.0"
projects[node_clone][subdir] = "contrib"

projects[og][version] = "2.9"
projects[og][subdir] = "contrib"

projects[ogfile][version] = "1.0-beta1"
projects[ogfile][subdir] = "contrib"

projects[og_extras][version] = "1.2"
projects[og_extras][subdir] = "contrib"

projects[og_subgroups][version] = "2.0-beta5"
projects[og_subgroups][subdir] = "contrib"

projects[override_node_options][version] = "1.13"
projects[override_node_options][subdir] = "contrib"

projects[panelizer][version] = "3.4"
projects[panelizer][subdir] = "contrib"
projects[panelizer][patch][] = https://www.drupal.org/files/issues/panelizer-save-as-custom-2470996-3.patch

projects[panels][version] = "3.7"
projects[panels][subdir] = "contrib"

projects[pathauto][version] = "1.3"
projects[pathauto][subdir] = "contrib"

projects[redirect][version] = "1.0-rc3"
projects[redirect][subdir] = "contrib"

projects[references_dialog][subdir] = "contrib"
projects[references_dialog][download][type] = git
projects[references_dialog][download][url] = http://git.drupal.org/project/references_dialog.git
projects[references_dialog][download][branch] = 7.x-1.x
projects[references_dialog][download][commit] = faf64b7b620746adafde56d2721155961e040df0

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][subdir] = "contrib"

projects[transliteration][version] = "3.2"
projects[transliteration][subdir] = "contrib"

projects[views][version] = "3.14"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_tree][version] = "2.0"
projects[views_tree][subdir] = "contrib"

projects[views_xml_backend][version] = "1.0-alpha4"
projects[views_xml_backend][subdir] = "contrib"

; +++++ Libraries +++++

; Flexslider
libraries[flexslider][directory_name] = "flexslider"
libraries[flexslider][type] = library
libraries[flexslider][destination] = "libraries"
libraries[flexslider][download][type] = git
libraries[flexslider][download][url] = https://github.com/woothemes/FlexSlider.git
libraries[flexslider][download][branch] = master
libraries[flexslider][download][tag] = version/2.5.0
