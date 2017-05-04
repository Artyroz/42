<div id="inscription">
	<?php
	if (check($er_inscription))
		echo "<p class='erreur'>".$er_inscription."</p>";
	if (check($ok_inscription)) {
		echo "<p class='sucess'>".$ok_inscription."</p>";
		redirection(URL, 5);
	}
	?>
	<form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]) ?>?pg=2" method="POST">
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
				<td>Valider Password : </td>
				<td><input class="co_input" name="re_passe" type="password" /></td>
			</tr>
			<tr>
				<td>Email : </td>
				<td><input class="co_input" name="email" type="email" /></td>
			</tr>
			<tr>
				<td colspan="2"><input class="co_submit" name="inscription" type="submit" value="S'inscrire" /></td>
			</tr>
		</table>
	</form>
</div>