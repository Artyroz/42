<?php
session_start();

require_once("../config/database.php");
require_once("../config/fonction.php");
require_once("../config/define.php");
require_once("../config/class.php");
require_once("../config/pages.php");
require_once("../traitement/main.php");

if (!check($_SESSION['user']['id']))
	redirection(URL, 0);

if (check($_POST['data'])) {
	$img = $_POST['data'];
	$cadre = $_POST['id'];
	if ($cadre > 2 || $cadre < 1)
		$cadre = 1;
	$img = str_replace('data:image/png;base64,', '', $img);
	$img = str_replace(' ', '+', $img);
	$data = base64_decode($img);
	$file = UPLOAD_TMP . uniqid() . '.png';
	$final = UPLOAD_DIR . uniqid() . '.png';
	$success = file_put_contents($file, $data);

	$cadre = UPLOAD_CAD.$cadre.".png";
	$source = imagecreatefrompng($cadre);
	$destination = imagecreatefrompng($file);
	$largeur_source = imagesx($source);
	$hauteur_source = imagesy($source);
	$largeur_destination = imagesx($destination);
	$hauteur_destination = imagesy($destination);
	$destination_x = 0;
	$destination_y = 0;
	$img = imagecreatetruecolor($largeur_destination, $hauteur_destination);
	
	imagecopyresampled($img, $destination, 0, 0, 0, 0, $largeur_destination, $hauteur_destination, $largeur_destination, $hauteur_destination);
	imagedestroy($destination);
	imagecopyresampled($img, $source, $destination_x, $destination_y, 0, 0, $largeur_source, $hauteur_source, $largeur_source, $hauteur_source);
	imagedestroy($source);
	imagepng($img, $final);
	
	unlink($file);
	Images::add_img($_SESSION['user']['id'], $final);
	require_once("./slides.php");
}
?>