<?php
/**
 * @file
 * FULLSCREEN - Template for a 1 column panel layout with no header or footer.
 *
 * This template provides a one column panel display layout, without
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['middle']: Content in the middle column.
 */
?>
<div class="panel-fullscreen clearfix panel-display container-fluid" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['middle']): ?>
    <div class="row center-wrapper" id="center-wrapper">
      <?php if ($content['middle']): ?>
        <div class="panel-col-middle panel-panel col-md-12">
          <div class="inside"><?php print $content['middle']; ?></div>
        </div>
      <?php endif; ?>
    </div><!--end row -->
  <?php endif; ?>

</div>
