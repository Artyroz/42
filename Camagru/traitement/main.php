<?php
// formulaire de connection
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['connect'])) {
	$login = securiter($_POST['login']);
	$passe = securiter($_POST['passe']);
	$er_co = Membre::connect($login, $passe);
}

// formulaire d'inscription
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['inscription'])) {
	$login = securiter($_POST['login']);
	$passe = securiter($_POST['passe']);
	$re_passe = securiter($_POST['re_passe']);
	$email = securiter($_POST['email']);
	if (check($login) && check($passe) && check($re_passe) && check($email)) {
		if ($passe != $re_passe)
			$er_inscription = "Mots de passe sont diffèrents.";
		else {
			if (!($er_inscription = Membre::chr_log_eml($login, $email)))
				$ok_inscription = Membre::inscrire($login, $passe, $email);
		}
	}
	else
		$er_inscription = "Champs Manquants.";
}

// systeme de validation
if ($_SESSION['page']['id'] == 3) {
	if (($_SERVER["REQUEST_METHOD"] == "GET") && check($_GET['vd']) && check($_GET['lg'])) {
		$valide = securiter($_GET['vd']);
		$login = securiter($_GET['lg']);
		if (!($er_valdation = Membre::chr_valide($login, $valide)))
			$ok_validation = Membre::validation($login);
	}
	else
		redirection(URL, 0);
}

// formulaire de réinitialisation du mot de passe
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['oublier'])) {
	$email = securiter($_POST['email']);
	if (!($er_oublier = Membre::chr_email($email)))
		$ok_oublier = Membre::oublier_email($email);
}

// Validation du password
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['reini'])) {
	$email = securiter($_GET['em']);
	$valide = securiter($_GET['vl']);
	$passe = securiter($_POST['passe']);
	$re_passe = securiter($_POST['re_passe']);
	if ($passe != $re_passe)
		$er_reini = "Mots de passe sont diffèrents.";
	else {
		if (!($er_reini = Membre::chr_eml_val($email, $valide)))
			$ok_reini = Membre::modif_passe($email, $passe);
	}
}

// formulaire des commentaire
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['com'])) {
	if (check($_POST['texte']) && check($_GET['id'])) {
		$message = securiter($_POST['texte']);
		$id_img = securiter($_GET['id']);
		Comment::add_com($message, $_SESSION['user']['id'], $id_img);
	}
	else
		$er_com = "Merci de remplir les champs pour commenter.";
}

// formulaire des like
if (($_SERVER["REQUEST_METHOD"] == "POST") && check($_POST['like'])) {
	$id_img = securiter($_GET['id']);
	Comment::like_mod($id_img, $_SESSION['user']['id']);
}

// Supprimer une photo
if (check($_GET['sp'])) {
	$id = securiter($_GET['id']);
	Images::sup_img($id);
}

?>