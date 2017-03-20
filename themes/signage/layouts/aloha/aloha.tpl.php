<?php
/**
 * @file
 * Alhoa - Template for admin layouts.
 *
 * This template provides a three column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['row-one']: Content in the top row.
 *   - $content['row-two-left']: Content in row two left.
 *   - $content['row-two-right']: Content in row two right.
 *   - $content['row-three']: Content in row three.
 *   - $content['row-four-left']: Content in row four left.
 *   - $content['row-four-middle']: Content in row four middle.
 *   - $content['row-four-right']: Content in row four right.
 */
?>
<div class="panel-alhoa clearfix panel-display container-fluid>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['row-one']): ?>
    <div class="row row-one-wrapper" id="row-one-wrapper">
      <?php if ($content['row-one']): ?>
        <div class="panel-col-row-one panel-panel col-md-12">
          <div class="inside"><?php print $content['row-one']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

  <?php if ($content['row-two-left'] || $content['row-two-right']): ?>
    <div class="row row-two-wrapper" id="row-two-wrapper">
      <?php if ($content['row-two-left']): ?>
        <div class="panel-col-row-two-left panel-panel col-md-6">
          <div class="inside"><?php print $content['row-two-left']; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($content['row-two-right']): ?>
        <div class="panel-col-row-two-right panel-panel col-md-6">
          <div class="inside"><?php print $content['row-two-right']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

  <?php if ($content['row-three']): ?>
    <div class="row row-three-wrapper" id="row-three-wrapper">
      <?php if ($content['row-three']): ?>
        <div class="panel-col-row-three panel-panel col-md-12">
          <div class="inside"><?php print $content['row-three']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

  <?php if ($content['row-four-left'] || $content['row-four-middle'] || $content['row-four-right']): ?>
    <div class="row row-four-wrapper" id="row-four-wrapper">
      <?php if ($content['row-four-left']): ?>
        <div class="panel-col-row-four-left panel-panel col-md-4">
          <div class  ="inside"><?php print $content['row-four-left']; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($content['row-four-middle']): ?>
        <div class="panel-col-row-four-middle panel-panel col-md-4">
          <div class  ="inside"><?php print $content['row-four-middle']; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($content['row-four-right']): ?>
        <div class="panel-col-row-four-right panel-panel col-md-4">
          <div class  ="inside"><?php print $content['row-four-right']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

</div>
