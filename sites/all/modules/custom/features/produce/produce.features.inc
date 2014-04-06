<?php
/**
 * @file
 * produce.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function produce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function produce_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function produce_node_info() {
  $items = array(
    'dietary_preferences_' => array(
      'name' => t('Dietary Preferences'),
      'base' => 'node_content',
      'description' => t('Yummly supported dietary preferences. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'food_allergies_' => array(
      'name' => t('Food Allergies'),
      'base' => 'node_content',
      'description' => t('A collection of Yummly recognized food allergies.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'produce' => array(
      'name' => t('Produce'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
