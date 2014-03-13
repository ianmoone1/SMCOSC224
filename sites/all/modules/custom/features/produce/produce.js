/*
	Version: 1.0
	Author: Ian Field
	Date: March 6, 2014

	This is the JQuery that gets produce values and sends the values to a php file to send the API query.


*/
(function ($) {
  Drupal.behaviors.produce = {
    attach: function (context, settings) {

	  	function update() {         
	    	var allVals = new Array();
	    	var values;
	     	$('.view-content :checked').each(function() {
	       		allVals.push($(this).val());
	     	});
	     	values = allVals.join('\n');
	     	console.log(values);
	  	}
	 	$(function() {
	   		$('input').click(update);
	   		update();
	 	});

	 	/*
			Sample Query to the API
	 			http://api.yummly.com/v1/api/recipes?_app_id=6794d508&_app_key=39b08096078bc715ee9020ddd49ba724&q=onion+soup&allowedIngredient[]=garlic&allowedIngredient[]=cognac
			
			You must pass the returned value returned from the selecting produce to PHP to populate the query to get the JSON file and build the recipe page from that.
			
			see https://drupal.org/node/304258 for reference to pass variables between JQuery and PHP
		*/
    }
  };
}(jQuery));