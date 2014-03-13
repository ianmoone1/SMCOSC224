<?php
/**
 * @file
 * helppage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function helppage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_help:help
  $menu_links['main-menu_help:help'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'help',
    'router_path' => 'help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_help:help',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Help');


  return $menu_links;
}
