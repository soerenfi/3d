import * as THREE from "https://cdn.skypack.dev/three@0.132.2";
import { OrbitControls } from "https://cdn.skypack.dev/three@0.132.2/examples/jsm/controls/OrbitControls.js";

var scene, renderer, camera;
var cube;
var controls;

init();
animate();

function init() {
	renderer = new THREE.WebGLRenderer({ antialias: true });
	var width = window.innerWidth;
	var height = window.innerHeight;
	renderer.setSize(width, height);
	document.body.appendChild(renderer.domElement);

	scene = new THREE.Scene();

	var cubeGeometry = new THREE.BoxGeometry(10, 10, 10);
	var cubeMaterial = new THREE.MeshBasicMaterial({ color: 0x1ec876 });
	cube = new THREE.Mesh(cubeGeometry, cubeMaterial);

	cube.position.set(0, 0, 0);
	scene.add(cube);

	camera = new THREE.PerspectiveCamera(45, width / height, 1, 10000);
	camera.position.y = 160;
	camera.position.z = 400;
	camera.lookAt(new THREE.Vector3(0, 0, 0));

	controls = new OrbitControls(camera, renderer.domElement);

	var gridXZ = new THREE.GridHelper(100, 10);
	scene.add(gridXZ);

}

function animate() {
	controls.update();
	requestAnimationFrame(animate);
	renderer.render(scene, camera);
}
