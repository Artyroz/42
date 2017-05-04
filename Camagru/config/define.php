<?php
// Base du site
define('DSN', $DB_DSN);
define('USER', $DB_USER);
define('PASSE', $DB_PASSWORD);
define('URL', 'http://localhost:8080');

// Base de la requete
define('SELECT', 'SELECT ');
define('UPDATE', 'UPDATE ');
define('INSERT', 'INSERT INTO ');
define('DELETE', 'DELETE ');
define('ALL', '*');
define('ORDER', ' ORDER BY id DESC');
define('LIMIT', ' LIMIT');

// Table avec From
define('MEMBRE', ' FROM membre');
define('REF', ' FROM referencement');
define('IMG', ' FROM images');
define('COM', ' FROM comentaire');
define('AIME', ' FROM aime');
define('ADMIN', ' FROM admin');

// Table sans From
define('MEMBRES', 'membre');
define('ADMINS', 'admin');
define('IMGS', 'images');
define('COMS', 'comentaire');
define('AIMES', 'aime');

// Variable de la Bdd
define('LOGIN', ' WHERE login=:login');
define('EMAIL', ' WHERE email=:email');
define('PROFIL', ' (id, login, passe, email, time, valide, rank, active) VALUES ("", :login, :passe, :email, :time, :valide, "0", "0")');
define('ID', ' WHERE id=:id');
define('LOGUE', ' (id, time, message, priorite) VALUES ("", :time, :message, :priorite)');
define('VALIDE', ' SET active=:active');
define('VALIDE_ACTIVE', ' SET valide=:valide, active=:active');
define('ACTIVE_PASSE', ' SET active=:active, passe=:passe');
define('ADD_IMG', ' (id, user_id, image, time) VALUES ("", :user, :image, :time)');
define('ID_USER', ' WHERE user_id=:id');
define('AD_COM', ' (id, id_user, texte, id_img) VALUES ("", :id_user, :texte, :id_img)');
define('ID_IMG', ' WHERE id_img=:id_img');
define('IDANDUSER', ' WHERE id_img=:id_img AND id_user=:id_user');
define('TEXTLIKE', ' (id, id_user, id_img) VALUES ("", :id_user, :id_img)');

// Images / Webcam
define('UPLOAD_TMP', '../images/tmp/');
define('UPLOAD_DIR', '../images/webcam/');
define('UPLOAD_CAD', '../images/cadres/');

// LIMIT
define('PS', ' 5');

?>