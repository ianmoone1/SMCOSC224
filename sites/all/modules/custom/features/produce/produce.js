/*
	Version: 1.0
	Author: Ian Field, Jerad Mason
	Date: March 6, 2014
*/
(function ($) {
  Drupal.behaviors.produce = {
    attach: function (context, settings) {
			var URL = "";
	  	function update() {
			var allVals = new Array();
	    	var values;
			URL = "http://api.yummly.com/v1/api/recipes?_app_id=0471e0f5&_app_key=65fc767cfb1f236750b675bb1d022f9d&requirePictures=true&";
	     	$('.view-content :checked').each(function() {
	       		allVals.push($(this).val());
	     	});
			for (var i = 0; i < allVals.length; i++){
				URL += "allowedIngredient[]=" + allVals[i].toLowerCase() + "&";
			}
	  	}
	 	$(function() {
	   		$('input').click(update);
	   		update();
	 	});

		$('#button').click(function() {
			document.cookie = "query = " + URL;
			window.location ="/recipes";
		});
	$('.produce-holder').toggle(
       function(event) {
         $(this).find('input').attr('checked', true);
         $(this).children("img").addClass( 'border' );
       },
       function(event) {
         $(this).find('input').attr('checked', false);
         $(this).children("img").removeClass( 'border' );
       }
     );

    }
  };
}(jQuery));