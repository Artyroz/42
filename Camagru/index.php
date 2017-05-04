<?php
session_start();

require_once("./config/database.php");
require_once("./config/fonction.php");
require_once("./config/define.php");
require_once("./config/class.php");
require_once("./config/pages.php");
require_once("./traitement/main.php");

$nbr_photo = Images::stat_img();

?>
<!DOCTYPE html>
<html>
<head>
	<meta name="viewport" content="width=device-width" />
	<link rel="stylesheet" type="text/css" href="./styles/main.css">
	<script type="text/javascript" src="./js/main.js"></script>
	<meta name="description" content="<?= $_SESSION['page']['description']; ?>" />
	<title><?= $_SESSION['page']['titre']; ?></title>
</head>
<body onresize="len_windows()">
<div id="header">
	<div id="mobil"><a href="javascript:afficher_menu()">&equiv;</a></div>
	<div class="logo">Camagru</div>
	<div class="stat"><?= $nbr_photo; ?> Photos en ligne</div>
</div>
<div id="menu">
	<?php require_once("./includes/menu.php"); ?>
</div>
<div id="main">
	<?php require_once("./includes/connect.php"); ?>
	<?php require_once("./includes/".$_SESSION['page']['include'].""); ?>
</div>
<div id="footer">
	dpollet &copy; 2016 Camagru
</div>
</body>
</html>