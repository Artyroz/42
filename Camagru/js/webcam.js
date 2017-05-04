(function() {
	var streaming = false,
	video = document.querySelector('#video'),
	cover = document.querySelector('#cover'),
	canvas = document.querySelector('#canvas'),
	startbutton = document.querySelector('#startbutton'),
	el = document.getElementById('ajout');
	width = 320,
	height = 0;

	navigator.getMedia = (navigator.getUserMedia || 
							navigator.webkitGetUserMedia ||
							navigator.mozGetUserMedia ||
							navigator.msGetUserMedia);

	navigator.getMedia (

		{
		video: true,
		audio: false
		},

		function(stream) {
			if (navigator.mozGetUserMedia) {
				video.mozSrcObject = stream;
			}
			else {
				var vendorURL = window.URL || window.webkitURL;
				video.src = vendorURL.createObjectURL(stream);
			}
			video.play();
		},

		function(err) {
			console.log("An error occured! " + err);
		}
	);

	video.addEventListener('canplay', function(ev) {
		if (!streaming) {
			height = video.videoHeight / (video.videoWidth/width);
			canvas.setAttribute('width', width);
			canvas.setAttribute('height', height);
			streaming = true;
		}
	}, false);

	function takepicture() {
		canvas.width = width;
		canvas.height = height;
		canvas.getContext('2d').drawImage(video, 0, 0, width, height);
		var data = canvas.toDataURL("image/png");
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
			if (xhttp.readyState == 4 && xhttp.status == 200) {
				document.getElementById("slide").innerHTML = xhttp.responseText;
			}
		};
		xhttp.open("POST", "../includes/creation.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("data=" + data + "&id=" + el.value);
	}

	startbutton.addEventListener('click', function(ev) {
		takepicture();
		ev.preventDefault();
	}, false);
}) ();

function test_valeur() {
	var el = document.getElementById('ajout');
	if (el.value == 0) {
		document.getElementById('startbutton').disabled = 'disabled';
		document.getElementById('calque').style.backgroundImage = "";
	}
	else if (el.value == 1) {
		document.getElementById('startbutton').disabled = '';
		document.getElementById('calque').style.backgroundImage = "url('../images/cadres/1.png')";
	}
	else if (el.value == 2) {
		document.getElementById('startbutton').disabled = '';
		document.getElementById('calque').style.backgroundImage = "url('../images/cadres/2.png')";
	}
}

function EL(id) { return document.getElementById(id); }

function readFile() {
	if (this.files && this.files[0]) {
		var FR = new FileReader();
		FR.onload = function(e) {
		EL("img").src = e.target.result;
		var xhttp = new XMLHttpRequest();
		var el = document.getElementById('ajout');
		xhttp.onreadystatechange = function() {
			if (xhttp.readyState == 4 && xhttp.status == 200) {
				document.getElementById("slide").innerHTML = xhttp.responseText;
			}
		};
		xhttp.open("POST", "../includes/creation.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("data=" + EL("img").src + "&id=" + el.value);
		};
	FR.readAsDataURL( this.files[0] );
	}
}

EL("inp").addEventListener("change", readFile, false);