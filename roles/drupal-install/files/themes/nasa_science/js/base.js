/*
 We want to label external links:
    1. "external" is defined as not nasascience.nasa.gov or science.nasa.gov
    2. We want to ignore anything which has an image as the first child
       since that breaks things like thumbnails
*/
jQuery("#content_box a[href^=http]:not([href*=science.nasa.gov]):not(:has(img:only-child))").addClass("external");
jQuery("#news_banner a[href^=http]:not([href*=science.nasa.gov])").addClass("external");

jQuery('<span class="close">Close</span>').click(function() { $("#alert").slideUp("slow"); }).prependTo("#alert");

/* Set a default auto-clear text for email fields on forms */
jQuery('#id_email[value=]').attr("title", "email address").addClass("clear_on_focus");

/* .clear_on_focus elements will get a default value set from their title and will remove it on focus */
jQuery("input.clear_on_focus").each(function(i, e) {
    var e$ = jQuery(e);

    if (!e.value && e.title) {
        e$.val(e.title).addClass("no_value");
    } else {
        e$.removeClass("no_value");
    }

    jQuery(e.form).submit(function() {
        e.value = e.value.replace(e.title, "");
    });

    jQuery(e).focus(function() {
        e.value = e.value.replace(e.title, "");
        e$.removeClass("no_value");
    });

    jQuery(e).blur(function() {
        if (!e.value && e.title) {
            e$.val(e.title).addClass("no_value");
        } else {
            e$.removeClass("no_value");
        }
    });
});

jQuery("#searchGadget").each(function(i, e) {
    var queryCache = {};

    var LSResult = jQuery("#LSResult").hide();
    jQuery('<span class="close">Close</span>')
        .click(function() { LSResult.fadeOut(); })
        .appendTo(LSResult);

    var LSResultList = jQuery("<ul>");
    LSResult.append(LSResultList);

    var searchGadget = this;

    function displayResults(results) {
        if (results.length < 1) {
            LSResult.hide();
            return;
        }
        for (var i=0; i < results.length; i++) {
            jQuery("<li>")
                .append(
                    jQuery("<a>").attr({"href": results[i][0]}).text(results[i][1])
                )
                .appendTo(LSResultList);
        };

        LSResult.show();
    }


    jQuery(this).keyup(function(evt) {
        LSResultList.empty();

        if (evt.keyCode == 27) {
            LSResult.hide();
            return;
        }

        var v = jQuery.trim(this.value);

        if (!v || v.length < 4) {
            LSResult.hide();
            return;
        }

        if (v in queryCache && queryCache[v] != null) {
            displayResults(queryCache[v]);
        } else {
            queryCache[v] = null; /* Set a placeholder to avoid duplicate searches */

            jQuery.getJSON("/search/autocomplete/", {"q": v}, function(data, textStatus) {
                if (data.q != jQuery.trim(searchGadget.value)) return;

                /* Cache the results so we can avoid a request in the future if the user changes their query */
                queryCache[data.q] = data.results;

                displayResults(data.results);
            });
        }
    });
});

// iOS Hover Event Class Fix
if((navigator.userAgent.match(/iPhone/i)) || (navigator.userAgent.match(/iPod/i)) || (navigator.userAgent.match(/iPad/i))) {
    $("#nav_secondary li a").mouseover(function(){  // Update class to point at the head of the list
});
}
