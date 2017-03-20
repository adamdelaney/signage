<?php
/**
* @file
* Views hooks for the signage_news_panes module.
*/

function signage_slides_views_views_query_alter(&$view, &$query) {
  if ($view->name == 'slides_slideshows') {
    // Traverse through the 'where' part of the query.
    foreach ($query->where as &$condition_group) {

      foreach ($condition_group['conditions'] as $condition) {
        // If this is the part of the query filtering by day of the week, add
        // one for today.
        if ($condition['field'] == 'field_data_field_slide_day.field_slide_day_value') {
          // Our new query.
          $condition_group['conditions'][] = array(
            'field' => 'field_data_field_slide_day.field_slide_day_value',
            'value' => strtolower(date('l')),
            'operator' => '=',
          );
        }
      }
    }
  }
}
