<div id="container">
<div id="header">
    <div id="nasa">
		<a href="http://www.nasa.gov"><span class="hide">Header</span></a>
	</div>
    <div id="header_links">
      <ul>
        <li><a href="http://www.nasa.gov" title="NASA.gov">Visit NASA.gov</a></li>
        <li><a href="/connect/">Connect</a></li>
        <li><a href="/contact/">Contact Us</a></li>
      </ul>
      <ul>
        <li><a href="/glossary/">Glossary</a></li>
        <li><a href="/sitemap/">Site Map</a></li>
      </ul>
    </div>
    <div id="search">
        <form id="searchform" name="searchform" action="/search/">
            <div class="LSBox">
                <label for="searchGadget" class="hiddenStructure">Search Site</label>
                <input autocomplete="off" name="q" size="18" title="NASA Science Live Search" accesskey="4" id="searchGadget" type="text" class="clear_on_focus" />
                <button class="searchButton" type="submit">Go!</button>
                <div id="LSResult"></div>
            </div>
        </form>
    </div>
    <span class="clear"></span>
</div>

<div id="nav_global">
    <ul>
        <li class="first"><a href="/">Home</a></li>
        <li><a href="/big-questions/">Big Questions</a></li>
        <li><a href="/earth-science/">Earth</a></li>
        <li><a href="/heliophysics/">Heliophysics</a></li>
        <li><a href="/planetary-science/">Planets</a></li>
        <li><a href="/astrophysics/">Astrophysics</a></li>
        <li><a href="/missions/">Missions</a></li>
        <li><a href="/technology/">Technology</a></li>
        <li class="last"><a href="/science-news/">Science News</a></li>
    </ul>
    <div id="banner" class="clear"><a href="/">block banner_text</a></div>
    <ul id="nav_secondary">
		<li><a href="/science-committee/">NAC Science Committee</a></li>
		<!-- flatblock "audiences_dropdown" -->
		<li class="dropdown1" style="width:178px;"><a>NASA Science for ...</a>
		      <ul>
		          <li><a href = "/researchers/">Researchers</a></li>
		          <li><a href = "/citizen-scientists/">Citizen Scientists</a></li>
		          <li><a href = "/educators/">Educators</a></li>
		          <li><a href = "http://missionscience.nasa.gov">Teens</a></li>
		          <li><a href = "http://spaceplace.nasa.gov/">Kids</a></li>
		      </ul>
        </li>
        <!-- flatblock "year_of_dropdown" -->
        <li class="dropdown1" style="width:180px;"><a>NASA Celebrates ...</a>
		      <ul>
		          <li><a href = "/chemistry/">International Year of Chemistry</a></li>
		          <li><a href = "http://solarsystem.nasa.gov/yss/">Solar System</a></li>
		          <li><a href = "/venus-transit/">Venus Transit</a></li>
		          <li><a href = "http://www.nasa.gov/topics/earth/earthday/index.html">NASA Earth Day 2012</a></li>
		          <li><a href = "/nasa-agu/">NASA AGU</a></li>
		      </ul>
        </li>
		<li><a href="/about-us/">About Us</a></li>
    </ul>
    <span class="clear"></span>
</div>

<div id="menu">
  <!-- ?php
    print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); 
  ? -->
</div>

<div id="content_box">
   <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
   <div id="content-header">
      <div id="breadcrumbs">
            <?php print $breadcrumb; ?>
      </div>
      <?php if ($page['highlight']): ?>
        <div id="highlight"><?php print render($page['highlight']) ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print render($page['help']); ?>
      <?php if ($tabs): ?>
        <div class="tabs">
          <?php print render($tabs); ?>
        </div>
      <?php endif; ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
    </div> <!-- /#content-header -->
    <?php endif; ?>

    <!-- block content_body -->

    <div id="content">
        <!-- block content -->
        <?php print render($page['content']); ?>
        <!-- endblock content -->
    </div>

    <div id="nav_local">
         <div id="block-book-navigation">
           <?php 
               if ($page['left_sidebar_navigation']) {
                   if ( isset($node->book['bid'])) {
                     $bookid = $node->book['bid'];
                     $topbook = node_load($bookid);
                     echo "<h2 class='local'><a href='#'>" . $topbook->title . "</a></h2>";
                   }
                   print render($page['left_sidebar_navigation']); 
               }
           ?>
           <?php  
               if( $page['left_sidebar_science_news_navigation'])
                    print render($page['left_sidebar_science_news_navigation']); 
           ?>
         </div>
         <div class="bottom"> </div> 
         <div id="nav_local_related">
           <?php print render($page['left_sidebar_related']); ?>
         </div>
    </div>
    <!-- endblock content_body -->

    <span class="clear"></span>
</div>

<div id="footer">
    <!- block footer -->
    <div>
        <ul>
            <li><a href="http://www.hq.nasa.gov/office/pao/FOIA/agency/">Freedom of Information Act</a></li>
            <li><a href="http://www.nasa.gov/about/budget/index.html">Budgets, Strategic Plans and Accountability Reports</a></li>
            <li><a href="http://www.whitehouse.gov/sites/default/files/national_space_policy_6-28-10.pdf">National Space Policy</a> (PDF)</li>
            <li><a href="http://www.nasa.gov/about/highlights/HP_Privacy.html">Privacy Policy and Important Notices</a></li>
            <li><a href="http://www.hq.nasa.gov/office/oig/hq/hotline.html">Inspector General Hotline</a></li>
        </ul>
    </div>
    <div>
        <ul>
            <li><a href="http://www.hq.nasa.gov/office/codee/nofear.html">Equal Employment Opportunity Data Posted Pursuant to the No Fear Act</a></li>
            <li><a href="http://www.nasa.gov/about/contact/information_inventories_schedules.html">Information-Dissemination Priorities and Inventories</a></li>
            <li><a href="http://www.usa.gov/">USA.gov</a></li>
            <li><a href="http://www.whitehouse.gov/omb/expectmore/">ExpectMore.gov</a></li>
        </ul>
    </div>
    <div class="page_info">
        <!-- block page_info -->
        <!-- flatblock "page_info" -->
        <a href="http://www.nasa.gov" class="nasalogo">
          <span class="hide">National Aeronautics and Space Administration</span>
        </a>
        NASA Official: <span id="nasa-official">Ruth Netting</span><br />
        <a href="/contact/">Send us your comments!</a><br />
        <!-- if $last_modified -->
        Last Updated: <?php if( isset($node) ) echo date( "F j, Y",$node->changed); ?> <br />
        <!-- endif -->
        <ul>
          <li><a href="/glossary/">Glossary</a></li>
          <li><a href="/sitemap/">Site Map</a></li>
          <li><a href="http://www.adobe.com/products/acrobat/readstep2.html?promoid=BUIGO">Adobe Reader</a></li>
        </ul>
        <!-- endblock page_info -->
        <span class="clear"></span>
    </div>
    <!-- endblock footer -->
</div>
<div id="footer_bottom"></div>

<div id="footer_links" class="clear">
    <!-- flatblock "footer_links" -->
    <a href="/">Home</a><a href="/big-questions/">Big Questions</a>
    <a href="/earth-science/">Earth</a>
    <a href="/heliophysics/">Heliophysics</a>
    <a href="/planetary-science/">Planets</a>
    <a href="/astrophysics/">Astrophysics</a>
    <a href="/missions/">Missions</a><a href="/technology/">Technology</a>
    <a href="/technology/">Technology</a>
    <a href="/science-news/">Science News</a><br />
    <a href="/researchers/">For Researchers</a>
    <a href="/educators/">For Educators</a><a href="/kids/">For Kids</a>
    <a href="http://spaceplace.nasa.gov/">For Kids</a>
    <a href="/citizen-scientists/">Citizen Scientists</a>
    <a href="/ask-a-scientist/">Ask a Scientist</a><br /><br />
</div>
</div> <!-- root -->
