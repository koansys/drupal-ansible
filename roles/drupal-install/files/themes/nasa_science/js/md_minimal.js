jQuery(function() {
	var $totalw = 50;
	var $totalcmw = 50;
	jQuery('#content-header a').each(function(){
		$totalw += jQuery(this).outerWidth();
	});
	jQuery('#comments div.links:first a').each(function(){
		$totalcmw += jQuery(this).outerWidth();
	});
	jQuery('#content-header div.tabs').width($totalw);
	jQuery('#comments div.links').width($totalcmw);
	
	jQuery('.node-teaser').hover(
		function () {
			jQuery(this).addClass('nodehover');
		}, 
		function () {
			jQuery(this).removeClass('nodehover');
		}
	);
	
});
