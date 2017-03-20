<?php
/**
 * @file
 * BETA - Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top-left']: Content in the top row.
 *   - $content['top-right']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-beta clearfix panel-display container-fluid <?php if(empty($content['right'])){ print "right-no-right-sidebar";} ?> <?php if(empty($content['left'])){ print "left-no-left-sidebar";} ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top-left'] || $content['top-right']): ?>
    <div class="row top-wrapper" id="top-wrapper">
      <?php if ($content['top-left']): ?>
        <div class="panel-col-top-left panel-panel col-md-8">
          <div class="inside"><?php print $content['top-left']; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($content['top-right']): ?>
        <div class="panel-col-top-right panel-panel col-md-4">
          <div class="inside"><?php print $content['top-right']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="row center-wrapper" id="center-wrapper">
      <?php if ($content['left']): ?>
        <div class="panel-col-left panel-panel col-md-8">
          <div class="inside"><?php print $content['left']; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($content['right']): ?>
        <div class="panel-col-right panel-panel col-md-4">
          <div class="inside"><?php print $content['right']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

  <?php if ($content['bottom']): ?>
    <div class="row bottom-wrapper" id="bottom-wrapper">
      <div class="panel-col-bottom panel-panel col-md-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div><!--end row -->
  <?php endif; ?>

</div>
