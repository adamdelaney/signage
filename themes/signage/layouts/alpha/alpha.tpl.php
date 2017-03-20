<?php
/**
 * @file
 * ALPHA - Template for a 1 column panel layout.
 *
 * This template provides a one column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top-left']: Content in the top row.
 *   - $content['top-right']: Content in the top row.
 *   - $content['middle']: Content in the middle column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-alpha clearfix panel-display container-fluid" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

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

  <?php if ($content['middle']): ?>
    <div class="row center-wrapper" id="center-wrapper">
      <?php if ($content['middle']): ?>
        <div class="panel-col-middle panel-panel col-md-12">
          <div class="inside"><?php print $content['middle']; ?></div>
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
