<div id="sl7-slider" class="owl-carousel" data-style="<?php print $slider_settings['designStyle']; ?>">
  <?php foreach ($slides as $i => $values): ?>
      <?php if (!empty($values['link'])): ?>
        <a href="<?php print $values['link']; ?>" target="<?php print $values['link_target']; ?>">
      <?php endif; ?>
      <div class="slide-item">
        <img class="lazyOwl" data-src="<?php print file_create_url(file_load($values['fid'])->uri); ?>" />
        <?php if (isset($values['title'])): ?>
          <span class="title"><?php print $values['title'];?></span>
        <?php endif; ?>
        <?php if (isset($values['description'])): ?>
          <span class="description"><?php print check_markup($values['description']['value'], $values['description']['format']);?></span>
        <?php endif; ?>
      </div>
      <?php if (!empty($values['link'])): ?>
        </a>
      <?php endif; ?>
  <?php endforeach; ?>
</div>