<?php
if (check($_SESSION['user']['id'])) {
	?>
	<div id="connect">
		<?= $_SESSION['user']['login']; ?>
		<?php
		if ($_SESSION['user']['rank'] == 1)
			echo "(<a href='../admin/index.php'>Administration</a>)";
		?>
		<hr/><a href="index.php?pg=5">Déconnexion</a>
	</div>
	<?php
}
else {
	?>
	<div id="connect">
		<?php
		if (check($er_co))
			echo "<p class='erreur'>".$er_co."</p>";
		?>
		<form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]) ?>" method="POST">
			<table align="center">
				<tr>
					<td>Login : </td>
					<td><input class="co_input" name="login" type="text" /></td>
				</tr>
				<tr>
					<td>Password : </td>
					<td><input class="co_input" name="passe" type="password" /></td>
				</tr>
				<tr>
					<td colspan="2"><input class="co_submit" name="connect" type="submit" value="Se connecter" /></td>
				</tr>
				<tr>
					<td colspan="2"><span class="petit"><a href="index.php?pg=4">Mot de passe oublier ?!</a> | <a href="index.php?pg=2">Incription</a></span></td>
				</tr>
			</table>
		</form>
	</div>
	<?php
}
?>