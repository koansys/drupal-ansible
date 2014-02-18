  <!-- use <li><a href="/earth-science/">Earth</a></li>
   to get node ids for aliases.
  -->
  <style type="text/css">
  a.c6 {background-image: url(<?php print base_path() . path_to_theme(); ?>/img/home_astro_off_on.jpg)}
  a.c5 {background-image: url(<?php print base_path() . path_to_theme(); ?>/img/home_planets_off_on.jpg)}
  a.c4 {background-image: url(<?php print base_path() . path_to_theme(); ?>/img/home_helio_off_on.jpg)}
  a.c3 {background-image: url(<?php print base_path() . path_to_theme(); ?>/img/home_earth_off_on.jpg)}
  li.c2 {width:180px;}
  li.c1 {width:178px;}
  </style>

  <div id="container">
    <div id="header">
      <div id="nasa">
        <a href="http://www.nasa.gov/"><span class="hide">Header</span></a>
      </div>

      <div id="header_links">
        <ul>
          <li><a href="http://www.nasa.gov" title="NASA.gov">Visit NASA.gov</a></li>
          <li><a href="/connect/">Connect</a></li>
          <li><a href="/contact-us/">Contact Us</a></li>
        </ul>
        <ul>
          <li><a href="/glossary/">Glossary</a></li>
          <li><a href="/sitemap/">Site Map</a></li>
        </ul>
      </div>

      <div id="search">
        <form id="searchform" name="searchform" action="/search/">
          <div class="LSBox">
            <label for="searchGadget" class="hiddenStructure">Search
            Site</label><input autocomplete="off" name="q" size="18" title=
            "NASA Science Live Search" accesskey="4" id="searchGadget" type="text" class=
            "clear_on_focus" /><button class="searchButton" type="submit">Go!</button>

            <div id="LSResult"></div>
          </div>
        </form>
      </div>
    </div>

    <div id="nav_global">
      <ul>
        <li class="first"><a href="/" class="selected">Home</a></li>
        <li><a href="/big-questions/">Big Questions</a></li>
        <li><a href="/earth-science/">Earth</a></li>
        <li><a href="/heliophysics/">Heliophysics</a></li>
        <li><a href="/planetary-science/">Planets</a></li>
        <li><a href="/astrophysics/" title="">Astrophysics</a></li>
        <li><a href="/missions/">Missions</a></li>
        <li><a href="/technology/">Technology</a></li>
        <li class="last"><a href="/science-news/">Science News</a></li>
      </ul>

      <div id="banner" class="clear">
        <div id="flashcontent"><img src="../img/hp_banner_fallback.jpg" id= "hp_banner" 
             height="70" width="612" alt="NASA Science Banner" name="hp_banner" />
        </div>
        <script type="text/javascript">
        //<![CDATA[
           swfobject.embedSWF("<?php print base_path() . path_to_theme(); ?>/img/hp_banner.swf", "hp_banner", "612", "70", "9.0.0");
        //]]>
        </script>
      </div>

      <div id="news_banner">
        <a class="title" href="/science-news/">Science News</a>
        <?php print render($page['homepage-science-news-pod']); ?>
      </div>

      <ul id="nav_secondary">
        <li><a href="/science-committee/">NAC Science Committee</a></li>

        <li class="dropdown1 c1">
          <a>NASA Science for ...</a>
          <ul>
            <li><a href="/researchers/">Researchers</a></li>
            <li><a href="/citizen-scientist/">Citizen Scientists</a></li>
            <li><a href="/educators/">Educators</a></li>
            <li><a href="http://missionscience.nasa.gov">Teens</a></li>
            <li><a href="http://spaceplace.nasa.gov/">Kids</a></li>
          </ul>
        </li>

        <li class="dropdown1 c2">
          <a>NASA Celebrates ...</a>
          <ul>
            <li><a href="/chemistry/">International Year of Chemistry</a></li>
            <li><a href="http://solarsystem.nasa.gov/yss/">Solar System</a></li>
            <li><a href="http://science.nasa.gov/venus-transit/">Venus Transit</a></li>
            <li><a href="http://www.nasa.gov/topics/earth/earthday/index.html">NASA Earth Day 2012</a></li>
            <li><a href="http://www.nasa.gov/topics/earth/agu/index.html">NASA AGU</a></li>
          </ul>
        </li>

        <li><a href="/about-us/">About Us</a></li>
      </ul>
    </div>

    <div id="content_box">
      <div id="content">
          <!-- carousel is in page content -->
          <?php print render($page['content']); ?>

          <div id="home_boxes">
          <div id="iotd">
            <h5>Image of the Day</h5><a href=
            "http://www.nasa.gov/multimedia/imagegallery/image_feature_2523.html">
              <img src="/media/imageoftheday/753131main_752715main_potw1321a_516-387.jpg"
            alt="Cosmic Collision Between Galaxies" height="110" width="150" /></a>

            <p><a href=
            "http://www.nasa.gov/multimedia/imagegallery/image_feature_2523.html"><strong>
            June 4, 2013</strong></a></p>

            <p>This image from the NASA/ESA Hubble Space Telescope captures an ongoing
            cosmic collision between two galaxies &acirc;&euro;&rdquo; a spiral galaxy
            ...</p>

            <p><a href="http://www.nasa.gov/multimedia/imagegallery/iotd.html">Image of
            the Day Gallery</a></p>
          </div>

          <div id="iSatSatelliteTracker">
            <h5>Interactive Satellite Tracker</h5><a href="/iSat/" class=
            "thumb"><img alt="iSat" src="/media/medialibrary/2013/03/07/iSAT.jpg.jpeg"
            align="left" height="110" width="150" /></a>

            <p>Interactive Satellite Tracker (iSat) is a browser based application that
            allows you to track all NASA Science Satellite Missions, as well as other
            satellites. Enjoy this free tool at home or in the classroom!</p>

            <p><a href="/iSat/"><strong>Watch in real time!</strong></a></p>
          </div>

          <div id="BigAsteroidFlyby">
            <h5>Latest ScienceCast</h5><a href=
            "http://www.youtube.com/watch?v=ssYnC90U0mM" class="thumb"><img alt=
            "Big Asteroid Flyby YouTube Video" src=
            "/media/medialibrary/2013/05/30/106_BigAsteroidFlyby-poster150.jpg" align=
            "left" height="110" width="150" /></a>

            <p>NASA is tracking a large near-Earth asteroid as it passes by the
            Earth-Moon system on May 31st.</p>

            <p><a href="http://www.youtube.com/watch?v=ssYnC90U0mM"><strong>Watch our
            latest ScienceCast: Big Asteroid Flyby</strong></a></p>
          </div>
        </div>
      </div>
    </div>
    <div id="footer">
      <div>
        <ul>
          <li><a href="http://www.hq.nasa.gov/office/pao/FOIA/agency/">Freedom of
          Information Act</a></li>

          <li><a href="http://www.nasa.gov/about/budget/index.html">Budgets, Strategic
          Plans and Accountability Reports</a></li>

          <li><a href=
          "http://www.whitehouse.gov/sites/default/files/national_space_policy_6-28-10.pdf">
          National Space Policy (PDF)</a></li>

          <li><a href="http://www.nasa.gov/about/highlights/HP_Privacy.html">Privacy
          Policy and Important Notices</a></li>

          <li><a href="http://www.hq.nasa.gov/office/oig/hq/hotline.html">Inspector
          General Hotline</a></li>
        </ul>
      </div>

      <div>
        <ul>
          <li><a href="http://www.hq.nasa.gov/office/codee/nofear.html">Equal Employment
          Opportunity Data Posted Pursuant to the No Fear Act</a></li>

          <li><a href=
          "http://www.nasa.gov/about/contact-us/information_inventories_schedules.html">Information-Dissemination
          Priorities and Inventories</a></li>

          <li><a href="http://www.usa.gov/">USA.gov</a></li>

          <li><a href="http://www.whitehouse.gov/omb/expectmore/">ExpectMore.gov</a></li>
        </ul>
      </div>

      <div class="page_info">
        <a href="http://www.nasa.gov" class="nasalogo"><span class="hide">National
        Aeronautics and Space Administration</span></a> NASA Official: <span id=
        "nasa-official">Ruth Netting</span><br />
        <a href="/contact-us/">Send us your comments!</a><br/>

        <ul>
          <li><a href="/glossary/">Glossary</a></li>
          <li><a href="/sitemap/">Site Map</a></li>
          <li><a href= "http://www.adobe.com/products/acrobat/readstep2.html?promoid=BUIGO">Adobe Reader</a></li>
        </ul>
      </div>
    </div>

    <div id="footer_bottom"></div>

    <div id="footer_links" class="clear">
      <a href="/">Home</a>
      <a href="/big-questions/">Big Questions</a>
      <a href= "/earth-science/">Earth</a>
      <a href="/heliophysics/">Heliophysics</a>
      <a href= "/planetary-science/">Planets</a>
      <a href="/astrophysics/">Astrophysics</a>
      <a href= "/missions/">Missions</a>
      <a href="/technology/">Technology</a>
      <a href= "/science-news/">Science News</a><br />
      <a href="/researchers/">For Researchers</a>
      <a href="/educators/">For Educators</a>
      <a href="http://spaceplace.nasa.gov/">For Kids</a>
      <a href="/citizen-scientist/">Citizen Scientists</a>
      <a href="/ask-a-scientist/">Ask a Scientist</a><br />
      <br />
    </div>
  </div>
