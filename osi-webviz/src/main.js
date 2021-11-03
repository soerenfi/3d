import * as THREE from "https://cdn.skypack.dev/three@0.132.2";
import { OrbitControls } from "https://cdn.skypack.dev/three@0.132.2/examples/jsm/controls/OrbitControls.js";

var scene, renderer, camera;
var cube;
var controls;

init();
animate();

function init() {
	renderer = new THREE.WebGLRenderer({ antialias: false });
	var width = window.innerWidth;
	var height = window.innerHeight;
	renderer.setSize(width, height);
	document.body.appendChild(renderer.domElement);

	scene = new THREE.Scene();

	var cubeGeometry = new THREE.BoxGeometry(10, 10, 10);
	var cubeMaterial = new THREE.MeshBasicMaterial({ color: 0x1ec876 });
	cube = new THREE.Mesh(cubeGeometry, cubeMaterial);

	cube.position.set(0, 0, 10);
	scene.add(cube);

	camera = new THREE.PerspectiveCamera(50, width / height, 1, 1000);
	camera.position.x = -100;
	camera.position.z = 100;
	camera.up.set(0, 0, 1);
	camera.lookAt(new THREE.Vector3(0, 0, 0));

	controls = new OrbitControls(camera, renderer.domElement);

	var grid = new THREE.GridHelper(100, 10);
	grid.geometry.rotateX(Math.PI / 2);
	scene.add(grid);

}

function animate() {
	controls.update();
	requestAnimationFrame(animate);
	renderer.render(scene, camera);
}
