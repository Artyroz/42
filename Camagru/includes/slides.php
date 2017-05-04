Vos 5 dernières photos&nbsp;: <hr/>
<?php
if (!check($_SESSION['user']['id']))
	redirection(URL, 0);

$donnee = Images::affiche($_SESSION['user']['id']);
$id = 0;
while ($donnee[$id])
{
	echo "<img src='".$donnee[$id]['image']."' width='100%'/>";
	$id++;
}
?>