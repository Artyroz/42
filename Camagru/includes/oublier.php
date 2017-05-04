<?php
if (check($_GET['em']) && check($_GET['vl'])) {
	$email = securiter($_GET['em']);
	$valide = securiter($_GET['vl']);
	?>
	<div id="oublier">
		<?php
		if (check($er_reini))
			echo "<p class='erreur'>".$er_reini."</p>";
		if (check($ok_reini)) {
			echo "<p class='sucess'>".$ok_reini."</p>";
			redirection(URL, 5);
		}
		?>
		<form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]) ?>?pg=4&em=<?= $email; ?>&vl=<?= $valide; ?>" method="POST">
			<table align="center">
				<tr>
					<td>Password : </td>
					<td><input class="co_input" name="passe" type="password" /></td>
				</tr>
				<tr>
					<td>Valider Password : </td>
					<td><input class="co_input" name="re_passe" type="password" /></td>
				</tr>
				<tr>
					<td colspan="2"><input class="co_submit" name="reini" type="submit" value="Valider le Password" /></td>
				</tr>
			</table>
		</form>
	</div>
	<?php
}
else {
	?>
	<div id="oublier">
		<?php
		if (check($er_oublier))
			echo "<p class='erreur'>".$er_oublier."</p>";
		if (check($ok_oublier))
			echo "<p class='sucess'>".$ok_oublier."</p>";
		?>
		<form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]) ?>?pg=4" method="POST">
			<table align="center">
				<tr>
					<td>Email : </td>
					<td><input class="co_input" name="email" type="email" /></td>
				</tr>
				<tr>
					<td colspan="2"><input class="co_submit" name="oublier" type="submit" value="Réinitialiser mot de passe" /></td>
				</tr>
			</table>
		</form>
	</div>
	<?php
}
?>