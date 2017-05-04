<?php

// GESTION DES PAGES
// 1 = Index
// 2 = Inscription
// 3 = Validation
// 4 = Oublier
// 5 = Déconnexion
// 6 = Montage
// 7 = Galerie

// si session existe pas on le creer
if (!check($_SESSION['page']))
	$_SESSION['page'] = array();

// si pg exite on stocke sinon default page d'index 1
if (check($_GET['pg']))
	$_SESSION['page']['id'] = securiter($_GET['pg']);
else
	$_SESSION['page']['id'] = 1;

// verification si la page demander existe
if ($_SESSION['page']['id'] < 1 || $_SESSION['page']['id'] > 7)
	$_SESSION['page']['id'] = 1;

// redirection spécial si connecter
if ($_SESSION['page']['id'] == 2 && check($_SESSION['user']['id']))
	redirection(URL, 0);
else if ($_SESSION['page']['id'] == 3 && check($_SESSION['user']['id']))
	redirection(URL, 0);
else if ($_SESSION['page']['id'] == 4 && check($_SESSION['user']['id']))
	redirection(URL, 0);
else if ($_SESSION['page']['id'] == 5 && !check($_SESSION['user']['id']))
	redirection(URL, 0);

// recuperation des valeurs pour le referencement
if (check($_SESSION['page']['id']))
	Ref::pages($_SESSION['page']['id']);

?>