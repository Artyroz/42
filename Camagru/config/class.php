<?php

// Connection Bdd
class Bdd {
	private static $connexion = NULL;
	public static function connectBdd() {
		try {
			if(!self::$connexion) {
				self::$connexion = new PDO(DSN, USER, PASSE);
				self::$connexion->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			}
			return self::$connexion;
		}
		catch(PDOException $e) {
			echo "Connection failed : ".$e->getMessage();
		}
	}
}

// Cryptage de mot de passe
class Cryptage {
	public static function crypter($login, $passe) {
		$chaine = str_split($login);
		$i = 0;
		while ($chaine[$i])
		{
			$as = ord($chaine[$i]);
			$as++;
			$chaine[$i] = chr($as);
			$i++;
		}
		$sel = implode($chaine);
		$cript = md5($passe);
		$crypt = sha1($cript, $sel);
		return $crypt;
	}
}

// administration
class Admin {
	// GESTION DES LOGUES
	// 1 = Erreur banal
	// 2 = Success
	// 3 = Erreur Critique
	public static function logue($message, $priorite) {
		$timest = date("Y-m-d H:i:s");
		$resultat = Bdd::connectBdd()->prepare(INSERT.ADMINS.LOGUE);
		$resultat->bindParam(':time', $timest);
		$resultat->bindParam(':message', $message, PDO::PARAM_STR);
		$resultat->bindParam(':priorite', $priorite, PDO::PARAM_INT);
		$resultat->execute();
	}

	// Affichage des logues
	public static function aff() {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.ADMIN.ORDER);
		$resultat->execute();
		$id = 0;
		$row = $resultat->rowCount();
		while ($row) {
			$donnee[$id] = $resultat->fetch(PDO::FETCH_ASSOC);
			$id++;
			$row--;
		}
		return ($donnee);
	}
}

// traitement des infos du Membre
class Membre {
	// connection du membre
	public static function connect($login, $passe) {
		$passe = Cryptage::crypter($login, $passe);
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.LOGIN);
		$resultat->bindParam(':login', $login, PDO::PARAM_STR, 50);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		if ($passe == $donnee['passe']) {
			if ($donnee['active'] == 1) {
				$_SESSION['user'] = array();
				$_SESSION['user']['id'] = $donnee['id'];
				$_SESSION['user']['login'] = $donnee['login'];
				$_SESSION['user']['email'] = $donnee['email'];
				$_SESSION['user']['valide'] = $donnee['valide'];
				$_SESSION['user']['rank'] = $donnee['rank'];
			}
			else {
				$message = $login." a essayer de se connecter sans valider son compte.";
				Admin::logue($message, 1);
				return "Votre compte n'a pas été valider. Merci de valider votre compte par email.";
			}
		}
		return "Le groupe Login / Password n'est pas valide.";
	}

	// check si le login ou l'adrese email existe dans la Bdd
	public static function chr_log_eml($login, $email) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.LOGIN);
		$resultat->bindParam(':login', $login, PDO::PARAM_STR, 50);
		$resultat->execute();
		if ($resultat->rowCount() != 1) {
			$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.EMAIL);
			$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
			$resultat->execute();
			if ($resultat->rowCount() != 1) {
				return false;
			}
			else {
				$message = $login." a essayer de se creer un compte avec l'adresse email ".$email." qui existe déjà.";
				Admin::logue($message, 1);
				return "Cette adresse email est déjà enregistrer.";
			}
		}
		else 
			return "Ce login existe déjà.";
	}

	// enregistrement des nouveaux membres
	public static function inscrire($login, $passe, $email) {
		$passe = Cryptage::crypter($login, $passe);
		$valide = alea();
		$timest = date("Y-m-d H:i:s");
		$resultat = Bdd::connectBdd()->prepare(INSERT.MEMBRES.PROFIL);
		$resultat->bindParam(':login', $login, PDO::PARAM_STR, 50);
		$resultat->bindParam(':passe', $passe, PDO::PARAM_STR, 50);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->bindParam(':valide', $valide, PDO::PARAM_STR, 15);
		$resultat->bindParam(':time', $timest);
		$resultat->execute();
		validation($login, $email, $valide);
		$message = $login." s'est inscris avec l'email ".$email." et la valdation ".$valide.".";
		Admin::logue($message, 2);
		return "Votre inscription est pris en compte. Merci de valider dans votre adresse email.";
	}

	// recherche si la validation existe
	public static function chr_valide($login, $valide) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.LOGIN);
		$resultat->bindParam(':login', $login, PDO::PARAM_STR, 50);
		$resultat->execute();
		if ($resultat->rowCount() == 1) {
			$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
			if ($donnee['valide'] == $valide)
				return false;
			else {
				$message = $login." a essayer de valider avec la validation (".$valide.") Validation incorrecte.";
				Admin::logue($message, 3);
				return "Problème de validation.";
			}
		}
		else {
			$message = $login." a essayer de valider avec la validation (".$valide.") login incorrecte.";
			Admin::logue($message, 3);
			return "Problème de validation.";
		}
	}

	// valide le compte
	public static function validation($login) {
		$active = 1;
		$resultat = Bdd::connectBdd()->prepare(UPDATE.MEMBRES.VALIDE.LOGIN);
		$resultat->bindParam(':active', $active);
		$resultat->bindParam(':login', $login, PDO::PARAM_STR, 50);
		$resultat->execute();
		$message = $login."a valider sont compte.";
		Admin::logue($message, 2);
		return "Votre compte a été valider.";
	}

	// recherche si l'email existe
	public static function chr_email($email) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.EMAIL);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->execute();
		if ($resultat->rowCount() == 1)
			return false;
		else {
			$message = $email." a demander une réinitialisation de son mot de passe. Email inexistante.";
			Admin::logue($message, 1);
			return "Adresse email inexistante.";
		}
	}

	// changement des elements pour reinitialisation Mots de passe
	public static function oublier_email($email) {
		$valide = alea();
		$active = 0;
		$resultat= Bdd::connectBdd()->prepare(UPDATE.MEMBRES.VALIDE_ACTIVE.EMAIL);
		$resultat->bindParam(':valide', $valide, PDO::PARAM_STR, 15);
		$resultat->bindParam(':active', $active);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->execute();
		oublier($email, $valide);
		$message = $email." a demander une réinitialisation de son mot de passe.";
		Admin::logue($message, 2);
		return "Une demande de confirmation vous a été envoyer par email.";
	}

	// rechecher si l'email et la validation existe
	public static function chr_eml_val($email, $valide) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.EMAIL);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		if ($donnee['valide'] == $valide)
			return false;
		else {
			$message = $email." a essayer de modifier le mot de passe sans la bonne clé de validation.";
			Admin::logue($message, 3);
			return "Une erreur est survenu. Merci de contacter l'administrateur.";
		}
	}

	// modification du mot de passe par le nouveau.
	public static function modif_passe($email, $passe) {
		$active = 1;
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.EMAIL);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		$passe = Cryptage::crypter($donnee['login'], $passe);
		$resultat = Bdd::connectBdd()->prepare(UPDATE.MEMBRES.ACTIVE_PASSE.EMAIL);
		$resultat->bindParam(':email', $email, PDO::PARAM_STR, 255);
		$resultat->bindParam(':passe', $passe, PDO::PARAM_STR, 50);
		$resultat->bindParam(':active', $active);
		$resultat->execute();
		$message = $donnee['login']." a changer son mot de passe avec la clé et l'email ".$email.".";
		Admin::logue($message, 2);
		return "Votre nouveau mot de passe est pris en compte.";
	}

	// information sur l'utilisateur
	public static function info_usr($login) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.ID);
		$resultat->bindParam(':id', $login);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		return $donnee;
	}

}

// traitement des images
class Images {
	// ajout image
	public static function add_img($user, $img) {
		$timest = date("Y-m-d H:i:s");
		$resultat = Bdd::connectBdd()->prepare(INSERT.IMGS.ADD_IMG);
		$resultat->bindParam(':user', $user, PDO::PARAM_INT);
		$resultat->bindParam(':image', $img, PDO::PARAM_STR, 255);
		$resultat->bindParam(':time', $timest);
		$resultat->execute();
		$message = "L'utilisateur (".$user.") a ajouter une image à sa galerie.";
		Admin::logue($message, 2);
	}

	// affichage des images utilisateur
	public static function affiche($id) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.IMG.ID_USER.ORDER.LIMIT.PS);
		$resultat->bindParam(':id', $id, PDO::PARAM_INT);
		$resultat->execute();
		$id = 0;
		$row = $resultat->rowCount();
		while ($row) {
			$donnee[$id] = $resultat->fetch(PDO::FETCH_ASSOC);
			$id++;
			$row--;
		}
		return ($donnee);
	}

	// statistiques des photos en lignes
	public static function stat_img() {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.IMG);
		$resultat->execute();
		$row = $resultat->rowCount();
		return $row;
	}

	// afficher galerie
	public static function aff_galerie($min, $max) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.IMG." ORDER BY time DESC LIMIT ".$min.", ".$max);
		$resultat->execute();
		$id = 0;
		$row = $resultat->rowCount();
		while ($row) {
			$donnee[$id] = $resultat->fetch(PDO::FETCH_ASSOC);
			$id++;
			$row--;
		}
		return ($donnee);
	}

	// supprimer image
	public static function sup_img($id) {
		$resultat = Bdd::connectBdd()->prepare(DELETE.IMG.ID);
		$resultat->bindParam(':id', $id);
		$resultat->execute();
		$message = $id." a ete supprimer.";
		Admin::logue($message, 2);
	}

}

// Commentaire et Like / Dislike
class Comment {
	// ajout commentaire
	public static function add_com($message, $id, $id_img) {
		//insert le commentaire
		$resultat = Bdd::connectBdd()->prepare(INSERT.COMS.AD_COM);
		$resultat->bindParam(':id_user', $id);
		$resultat->bindParam(':texte', $message);
		$resultat->bindParam(':id_img', $id_img);
		$resultat->execute();
		// recup l'id du createur
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.IMG.ID);
		$resultat->bindParam(':id' , $id_img);
		$resultat->execute();
		$createur = $resultat->fetch(PDO::FETCH_ASSOC);
		// recuperation de l'email du createur
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.ID);
		$resultat->bindParam(':id', $createur['user_id']);
		$resultat->execute();
		$mail_cre = $resultat->fetch(PDO::FETCH_ASSOC);
		// recup login de l'envoyeur
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.MEMBRE.ID);
		$resultat->bindParam(':id', $id);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		mail_comment($mail_cre['email'], $donnee['login'], $message);
		$message = $donnee['login']." a poster un nouveau commentaire sur l'image ".$id_img;
		Admin::logue($message, 2);
	}

	// afficher les commentaires
	public static function aff_com($id_img) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.COM.ID_IMG.ORDER);
		$resultat->bindParam(':id_img', $id_img);
		$resultat->execute();
		$id = 0;
		$row = $resultat->rowCount();
		while ($row) {
			$donnee[$id] = $resultat->fetch(PDO::FETCH_ASSOC);
			$id++;
			$row--;
		}
		return ($donnee);
	}

	// Like ou Dislike ?!
	public static function text_like($id_img, $id_usr) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.AIME.IDANDUSER);
		$resultat->bindParam(':id_img', $id_img);
		$resultat->bindParam(':id_user', $id_usr);
		$resultat->execute();
		if ($resultat->rowCount() == 1)
			return true;
		else
			return false;
	}

	// like ou dislike si deja existant
	public static function like_mod($id_img, $id_user) {
		if (!($test = Comment::text_like($id_img, $id_user))) {
			$resultat = Bdd::connectBdd()->prepare(INSERT.AIMES.TEXTLIKE);
			$resultat->bindParam(':id_img', $id_img);
			$resultat->bindParam(':id_user', $id_user);
			$resultat->execute();
			$message = $id_img." cette image a ete liker par ".$id_user.".";
			Admin::logue($message, 2);
		}
		else {
			$resultat = Bdd::connectBdd()->prepare(DELETE.AIME.IDANDUSER);
			$resultat->bindParam(':id_img', $id_img);
			$resultat->bindParam(':id_user', $id_user);
			$resultat->execute();
			$message = $id_img." cette image a ete dislike par ".$id_user.".";
			Admin::logue($message, 2);
		}
	}

	// nbr de like
	public static function nbr_like($id_img) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.AIME.ID_IMG);
		$resultat->bindParam(':id_img', $id_img);
		$resultat->execute();
		return $resultat->rowCount();
	}
}

// Referencement
class Ref {
	// gestion des pages
	public static function pages($id) {
		$resultat = Bdd::connectBdd()->prepare(SELECT.ALL.REF.ID);
		$resultat->bindParam(':id', $id, PDO::PARAM_INT);
		$resultat->execute();
		$donnee = $resultat->fetch(PDO::FETCH_ASSOC);
		$_SESSION['page']['include'] = $donnee['include'];
		$_SESSION['page']['description'] = $donnee['description'];
		$_SESSION['page']['titre'] = $donnee['titre'];
	}
}

// class de creation
class Install {
    public static function inst_mysql() {
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `admin` (`id` int(11) NOT NULL, `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, `message` varchar(255) NOT NULL, `priorite` int(11) NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `aime` (`id` int(11) NOT NULL, `id_user` int(11) NOT NULL, `id_img` int(11) NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `comentaire` (`id` int(11) NOT NULL, `id_user` int(11) NOT NULL, `texte` text NOT NULL, `id_img` int(11) NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `images` (`id` int(11) NOT NULL, `user_id` int(11) NOT NULL, `image` varchar(255) NOT NULL, `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `membre` (`id` int(11) NOT NULL, `login` varchar(50) NOT NULL, `passe` varchar(50) NOT NULL, `email` varchar(255) NOT NULL, `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, `valide` varchar(15) NOT NULL, `rank` int(11) NOT NULL, `active` int(11) NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("CREATE TABLE `referencement` (`id` int(11) NOT NULL, `include` varchar(255) NOT NULL, `description` varchar(550) NOT NULL, `titre` varchar(255) NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=latin1");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("INSERT INTO `referencement` (`id`, `include`, `description`, `titre`) VALUES (1, 'home.php', 'page d''accuel', 'Camagru'), (2, 'inscription.php', 'veuillez vous inscrire', 'Inscription'), (3, 'validation.php', 'valider votre compte', 'Pages de validation'), (4, 'oublier.php', 'changer de mots de passe', 'Password Oublier ?!'), (5, 'deconnexion.php', 'page de deconnexion', 'Deconnexion'), (6, 'montage.php', 'montage de vos propres photos', 'Montage'), (7, 'galerie.php', 'Regarder la galerie', '..:: Galerie ::..')");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `admin` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `aime` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `comentaire` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `images` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `membre` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `referencement` ADD PRIMARY KEY (`id`)");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `admin` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `aime` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `comentaire` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `images` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `membre` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT");
        $resultat->execute();
        $resultat = Bdd::connectBdd()->prepare("ALTER TABLE `referencement` MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8");
        $resultat->execute();
        return "BDD Creer !!";
    }
}

?>