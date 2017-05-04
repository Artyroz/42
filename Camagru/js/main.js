function afficher_menu() {
	var el = document.getElementById("menu");

	if (el.style.display == "block")
		el.style.display = "none";
	else
		el.style.display = "block";
}

function len_windows() {
	var w = window.outerWidth;

	if (w > 700)
		document.getElementById("menu").style.display = "block";
	else
		document.getElementById("menu").style.display = "none";
}