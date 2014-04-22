<?php
/**
 * @file
 * cern_ft_donateboxes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cern_ft_donateboxes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cern_ft_donateboxes_node_info() {
  $items = array(
    'donation_amount_boxes' => array(
      'name' => t('Donation amount boxes'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Administrative title'),
      'help' => '',
    ),
  );
  return $items;
}
