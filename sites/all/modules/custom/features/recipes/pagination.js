// (function ($) {
//   Drupal.behaviors.recipes = {
//     attach: function (context, settings) {
// 			var query;
// 			$(function() {
// 				var name = "query=";
// 				var ca = document.cookie.split(';');
// 				for(var i=0; i<ca.length; i++) 
// 				{
// 					var c = ca[i].trim();
// 					if (c.indexOf(name)==0) 
// 						query = c.substring(name.length,c.length);
// 				}
// 				if (query.search('start=0') >= 0){
// 					document.getElementById('prev').style.backgroundPosition = '-536px -414px';
// 					document.getElementById('prev').onmouseover=function(){document.getElementById('prev').style.cursor = 'default';};
// 				}
// 			});
// 		$('#prev').click(function() {
// 			var s = query.search('start=');
// 			s += 6;
// 			var page = parseInt(query.substring(s, s + 2));
// 			if (query.search('start=0') >= 0){
// 			}
// 			else{
// 				var sub;
// 				sub = query.substring(0, query.search('start=')) + 'start=' + (page-8) + '&' + query.substring((s+2));
// 				document.cookie = "query=" + sub;
// 				location.reload();
// 				window.scrollTo(0,0);
// 			}
// 		});
		
// 		$('#next').click(function() {
// 			var s = query.search('start=');
// 			s += 6;
// 			var page = parseInt(query.substring(s, s + 2));
// 			var sub;
// 			sub = query.substring(0,query.search('start=')) + 'start=' + (page+8) + '&' + query.substring((s+2));
// 			document.cookie= "query=" + sub;
// 			location.reload();
// 			window.scrollTo(0,0);
// 		});
//     }
//   };
// }(jQuery));