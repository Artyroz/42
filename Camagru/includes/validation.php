<?php
if (check($er_validation))
	echo "<span class='erreur'>".$er_validation."</span>";
if (check($ok_validation))
	echo "<span class='sucess'>".$ok_validation."</span>";

redirection(URL, 5);
?>