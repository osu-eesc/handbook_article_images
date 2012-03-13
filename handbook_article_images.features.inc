<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function handbook_article_images_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function handbook_article_images_imagecache_default_presets() {
  $items = array(
    'image_lightbox' => array(
      'presetname' => 'image_lightbox',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '500',
            'height' => '500',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'image_on_page' => array(
      'presetname' => 'image_on_page',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '210',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function handbook_article_images_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function handbook_article_images_views_api() {
  return array(
    'api' => '2',
  );
}
