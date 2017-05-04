<?php
session_start();

require_once("../config/database.php");
require_once("../config/fonction.php");
require_once("../config/define.php");
require_once("../config/class.php");
require_once("../config/pages.php");
require_once("../traitement/main.php");

if ($_SESSION['user']['rank'] == 1) {
	?>
	LOGUES DU SITE : (<a href="http://localhost:8080" >Le site</a>)<hr/>
	<?php
    $id = 0;
    $comm = Admin::aff();
   	while ($comm[$id]) {
   		if ($comm[$id]['priorite'] == 1)
   			echo "<span style='background-color:orange; color:white'>".$comm[$id]['message']."</span> ".$comm[$id]['time']."<br/><br/>";
   		else if ($comm[$id]['priorite'] == 2)
   			echo "<span style='background-color:green; color:white'>".$comm[$id]['message']."</span> ".$comm[$id]['time']."<br/><br/>";
   		else if ($comm[$id]['priorite'] == 3)
   			echo "<span style='background-color:red; color:white'>".$comm[$id]['message']."</span> ".$comm[$id]['time']."<br/><br/>";
        $id++;
    }
}
else
	redirection(URL, 0);
?>