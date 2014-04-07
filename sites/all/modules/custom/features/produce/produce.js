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
			URL = "http://api.yummly.com/v1/api/recipes?_app_id=0471e0f5&_app_key=65fc767cfb1f236750b675bb1d022f9d&requirePictures=true&maxResult=08&start=00&";
	     	$('.view-content :checked').each(function() {
	       		allVals.push($(this).val());
	     	});
			for (var i = 0; i < allVals.length; i++){
				URL += "allowedIngredient[]=" + allVals[i].toLowerCase() + "&";
			}
	  	}

	  	function replaceString(){
		
			var dairy = "allowedAllergy[]=396^Dairy-Free"
			var egg = "allowedAllergy[]=397^Egg-Free"
			var gluten = "allowedAllergy[]=393^Gluten-Free"
			var peanut = "allowedAllergy[]=394^Peanut-Free"
			var seafood = "allowedAllergy[]=398^Seafood-Free"
			var sesame = "allowedAllergy[]=399^Sesame-Free"
			var soy = "allowedAllergy[]=400^Soy-Free"
			var sulfite = "allowedAllergy[]=401^Sulfite-Free"
			var treenut = "allowedAllergy[]=395^Tree Nut-Free"
			var wheat = "allowedAllergy[]=392^Wheat-Free"
			
				var str = URL;
				str = str.replace("Dairy Free",dairy);
				str = str.replace("Egg Free",egg);
				str = str.replace("Gluten Free",gluten);
				str = str.replace("Peanut Free",peanut);
				str = str.replace("Seafood Free",seafood);
				str = str.replace("Sesame Free",sesame);
				str = str.replace("Soy Free",soy);
				str = str.replace("Sulfite Free",sulfite);
				str = str.replace("Treenut Free",treenut);
				str = str.replace("Wheat Free",wheat);
				
			var vegan = "allowedDiet[]=386^Vegan"
			var lactoVeg = "allowedDiet[]=388^Lacto%20vegetarian"
			var vegetarian = "allowedDiet[]=389^Ovo%20vegetarian"
			var pescetarian = "allowedDiet[]=390^Pescetarian"
			var ovoVeg = "allowedDiet[]=389^Ovo%20vegetarian"
			
			str = str.replace("vegan",vegan);
			str = str.replace("Vegetarian",vegetarian);
			str = str.replace("Pescetarian",pescetarian);
			str = str.replace("Ovo Vegetarian",ovoVeg);
			str = str.replace("Lacto Vegetarian",lactoVeg);
			
				URL=str;
		}
	 	$(function() {
	   		$('input').click(update);
	   		update();
	 	});

        $('.pane-dietary-preferences').hide();
        $('.pane-food-allergies').hide();
        
		$('#button').click(function() {
		    replaceString();
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

       $('#showdp').click(function(){
        
       $('.pane-dietary-preferences').toggle();
        });	
    
         $('#showfa').click(function(){
        
       $('.pane-food-allergies').toggle();
        });	
    }
  };

	   
  
  
}(jQuery));


