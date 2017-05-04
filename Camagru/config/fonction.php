<?php
// check si sa existe et si ces pas vide
function check($var) {
	if (isset($var) && !empty($var))
		return true;
	else
		return false;
}

// securiter des variables passer en parametre
function securiter($var) {
	if (intval($var))
		return $var;
	else {
		$var = trim($var);
		$var = stripslashes($var);
		$var = htmlspecialchars($var);
		return $var;
	}
}

// chaine aleatoire pour validation
function alea() {
	$char = 'abcdefghijklmnopqrstuvwxyz1234567890';
	$aleatoir = str_shuffle($char);
	$aleatoir = substr($aleatoir, 0, 10);
	return $aleatoir;
}

// email de validation
function validation($login, $email, $valide) {
	$message = "Bienvenue sur Camagru, ".$login." !! <br/>Merci d'activer votre compte en cliquant ici :<br/><a href='".URL."/index.php?pg=3&vd=".$valide."&lg=".$login."' >".URL."/index.php?pg=3&vd=".$valide."&lg=".$login." </a>";
	$sujet = "Validation comnpte Camagru";
	$header = "";
	$header = "From: Webmaster Site <webmater@camagru.fr>\n";
	$header = $header."Content-type: text/html; charset=iso-8859-1\n";
	if (!mail($email, $sujet, $message, $header)) {
		$erreur = "L'email a ".$login." (".$email.") n'a pas pu etre envoyer.";
		Admin::logue($erreur, 3);
	}
}

// email oublier
function oublier($email, $valide) {
	$message = "Vous avez demandez une reinitialisation du mot de passe merci de suivre ce lien.<br/><a href='".URL."/index.php?pg=4&em=".$email."&vl=".$valide."' >".URL."/index.php?pg=4&em=".$email."&vl=".$valide." </a>";
	$sujet = "Mots de passe oublier";
	$header = "";
	$header = "From: Webmaster Site <webmater@camagru.fr>\n";
	$header = $header."Content-type: text/html; charset=iso-8859-1\n";
	if (!mail($email, $sujet, $message, $header)) {
		$erreur = "L'email a ".$email." avec la validation (".$valide.") n'a pas pu etre envoyer.";
		Admin::logue($erreur, 3);
	}
}

// email commentaire
function mail_comment($email, $log, $message) {
	$message = $log." a poster un mouveau commentaire sur votre image : <br/>".$message;
	$sujet = "Nouveau commentaire.";
	$header = "";
	$header = "From: Webmaster Site <webmater@camagru.fr>\n";
	$header = $header."Content-type: text/html; charset=iso-8859-1\n";
	if (!mail($email, $sujet, $message, $header)) {
		$erreur = "L'email a ".$email." avec le commentaire n'a pas pu etre envoyer.";
		Admin::logue($erreur, 3);
	}
}

// redirection en Url et Temps
function redirection($url, $time=0) {
	if (!headers_sent()) {
		header("refresh: $time;url=$url"); 
		exit;
	}
	else
		echo '<meta http-equiv="refresh" content="',$time,';url=',$url,'">';
}
?>