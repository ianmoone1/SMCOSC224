<?php
/**
 * @file
 * recipes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function recipes_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'recipes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recipes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: JSON to PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'JSON to PHP';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
/*
	Version: 1.3
	Author: Daniel Mason, Jerad Mason
	Date: March 18, 2014

	The following code reads in the yummly returned json file and translates it to PHP then prints it.
	*/
if (isset($_COOKIE["query"])){
    $url = $_COOKIE["query"];
    $url = str_replace( \' \', \'%20\', $url);
    $jsonData = @file_get_contents( $url ); 
    if($jsonData == FALSE) { echo \'Our Recipe functionality is currently down, please try again later\'; }
    else{
	$json = json_decode($jsonData, true);
        echo $json[\'attribution\'][\'html\'];
	$output = "\\n\\n<table border=\'0\' style=\'border-collapse:collapse;background-color:white;cellspacing=\'0\'\'>";
	foreach($json[\'matches\'] as $m){
	    $output .= "<tr>"."<th colspan = \'2\' style=\'background-image: linear-gradient(to right, #770a35, #9f5371)\'>"."<a style=\'color:white\' href = \'https://www.yummly.com/recipe/".$m[\'id\']."\'>".$m[\'recipeName\']."</a>"."</th>"."</tr>";
            $output .= "<tr>"."<td>"."<img src =".$m[\'imageUrlsBySize\'][\'90\'].">"."</td>";
            $output .= "<td>"."<b>Ingredients: </b>".implode(", ", $m[\'ingredients\']);
            $check = 0;
            if (@$m[\'flavors\'][\'sour\'] > 0)
               $check=1;
            if (@$m[\'flavors\'][\'salty\'] > 0)
               $check=1;
            if (@$m[\'flavors\'][\'sweet\'] > 0)
               $check=1;
            if (@$m[\'flavors\'][\'meaty\'] > 0)
               $check=1;
            if (@$m[\'flavors\'][\'bitter\'] > 0)
               $check=1;
            if ($check != 0) {
            $output .= "<br> <b>Flavors:</b> Sour: "."<meter value=".@$m[\'flavors\'][\'sour\'].">".intval(@$m[\'flavors\'][\'sour\']*100)."%</meter>"." "."Salty: "."<meter value=".@$m[\'flavors\'][\'salty\'].">".intval(@$m[\'flavors\'][\'salty\']*100)."%</meter>"." ";
            $output .= "Sweet: "."<meter value=".@$m[\'flavors\'][\'sweet\'].">".intval(@$m[\'flavors\'][\'sweet\']*100)."%</meter>"." "."Savory: "."<meter value=".@$m[\'flavors\'][\'meaty\'].">".intval(@$m[\'flavors\'][\'meaty\']*100)."%</meter>"." ";
            $output .= "Bitter: "."<meter value=".@$m[\'flavors\'][\'bitter\'].">".intval(@$m[\'flavors\'][\'bitter\']*100)."%</meter>";
            }
            else
                 $output .= "<br> <i>No flavor data available.</i>";
            $output .= "</td>"."</tr>"."<tr>"."<td colspan = \'2\'>". "Rating: ";
            $rated = intval($m[\'rating\']);
        for ($i = 0; $i < 5; $i++){
            if ($rated == 0){
                $output .= "<span>☆<span>";
            }
            else{
                $output .= "<span style=\'color:#CC6600\'>★<span>";
                $rated = $rated - 1;
            } 
        }
            $output .= "</td>"."</tr>";
	}
	$output .="</table>";
    echo $output;
    
}
}
else
    echo "<h4>Please select a recipe and make sure cookies is enabled.</h4>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recipes' => 'recipes',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['recipes'] = $view;

  return $export;
}
