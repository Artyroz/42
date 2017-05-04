<?php
if (!check($_SESSION['user']['id'])) {
	echo "<p class='erreur'>Merci de vous connectez pour faire vos propres montages.</p>";
}
else {
	?>
	<div id="montage">
		<div id="cadre">
		Choix du calque : 
			<select id="ajout" onchange="test_valeur();" >
				<option value="0">none</option>
				<option value="1">Cadre</option>
				<option value="2">Sold Out</option>
			</select>
		</div>
		<div id="contenu">
			<div id="conteneur">
				<div id="calque"></div>
				<video id="video"></video>
			</div>
			<br/>
			<button id="startbutton" disabled>Prendre une photo</button>
			<canvas id="canvas"></canvas>
			<hr/>
			Format autoriser : PNG<br/>
			<input id="inp" type='file'>
			<p id="b64"></p>
			<img id="img">
		</div>
		<div id="slide">
			<?php require_once("slides.php"); ?>
		</div>
	</div>
	<script type="text/javascript" src="../js/webcam.js"></script>
	<?php
}
?>