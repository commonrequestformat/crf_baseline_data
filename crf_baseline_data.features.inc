<?php
/**
 * @file
 * crf_baseline_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crf_baseline_data_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function crf_baseline_data_node_info() {
  $items = array(
    'baseline_data' => array(
      'name' => t('Baseline Data'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
