import { useEffect, useRef } from "react";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";
import issIcon from "../assets/iss_icon.png";

const TEXTURE = "https://threejs.org/examples/textures/planets/earth_atmos_2048.jpg";

const toVec = (lat, lng, r = 1) => {
  const phi = ((90 - lat) * Math.PI) / 180;
  const theta = ((lng + 180) * Math.PI) / 180;
  return new THREE.Vector3(-r * Math.sin(phi) * Math.cos(theta), r * Math.cos(phi), r * Math.sin(phi) * Math.sin(theta));
};

// 3D Earth. Pass `position` ([lat, lng]) to show the ISS, `path` for its orbit line, `spin` to auto-rotate.
export default function Globe({ position, path = [], spin = false }) {
  const mount = useRef(null);
  const s = useRef({});

  useEffect(() => {
    const el = mount.current;
    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(45, el.clientWidth / el.clientHeight, 0.1, 100);
    camera.position.set(0, 0.6, 3.6);
    const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
    renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
    renderer.setSize(el.clientWidth, el.clientHeight);
    el.appendChild(renderer.domElement);

    scene.add(new THREE.AmbientLight(0x8899bb, 1.1));
    const sun = new THREE.DirectionalLight(0xffffff, 1.6);
    sun.position.set(5, 2, 4);
    scene.add(sun);

    const world = new THREE.Group();
    scene.add(world);

    // Earth falls back to a plain blue ball if the texture can't load.
    const mat = new THREE.MeshPhongMaterial({ color: 0x1d4f91, shininess: 12 });
    new THREE.TextureLoader().load(TEXTURE, (t) => {
      t.colorSpace = THREE.SRGBColorSpace;
      mat.map = t; mat.color.set(0xffffff); mat.needsUpdate = true;
    });
    world.add(new THREE.Mesh(new THREE.SphereGeometry(1, 64, 64), mat));

    // Glowing atmosphere
    scene.add(new THREE.Mesh(
      new THREE.SphereGeometry(1.14, 64, 64),
      new THREE.ShaderMaterial({
        vertexShader: "varying vec3 vN; void main(){ vN = normalize(normalMatrix * normal); gl_Position = projectionMatrix * modelViewMatrix * vec4(position,1.0); }",
        fragmentShader: "varying vec3 vN; void main(){ float i = pow(0.62 - dot(vN, vec3(0.0,0.0,1.0)), 3.0); gl_FragColor = vec4(0.3,0.6,1.0,1.0) * i; }",
        side: THREE.BackSide, blending: THREE.AdditiveBlending, transparent: true, depthWrite: false,
      })
    ));

    // ISS marker + orbit line
    new THREE.TextureLoader().load(issIcon, (t) => { sprite.material.map = t; sprite.material.needsUpdate = true; });
    const sprite = new THREE.Sprite(new THREE.SpriteMaterial({ color: 0xffffff }));
    sprite.scale.set(0.3, 0.22, 1);
    sprite.visible = false;
    world.add(sprite);
    const line = new THREE.Line(new THREE.BufferGeometry(), new THREE.LineBasicMaterial({ color: 0xffd166 }));
    world.add(line);

    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true; controls.enablePan = false;
    controls.minDistance = 1.8; controls.maxDistance = 6;

    const calm = matchMedia("(prefers-reduced-motion: reduce)").matches;
    let raf;
    const loop = () => {
      if (spin && !calm) world.rotation.y += 0.002;
      if (s.current.target) {
        camera.position.lerp(s.current.target, 0.08);
        if (camera.position.distanceTo(s.current.target) < 0.02) s.current.target = null;
      }
      controls.update();
      renderer.render(scene, camera);
      raf = requestAnimationFrame(loop);
    };
    loop();

    const ro = new ResizeObserver(() => {
      camera.aspect = el.clientWidth / el.clientHeight; camera.updateProjectionMatrix();
      renderer.setSize(el.clientWidth, el.clientHeight);
    });
    ro.observe(el);

    s.current = { sprite, line, target: null, first: true };
    return () => {
      cancelAnimationFrame(raf); ro.disconnect(); controls.dispose();
      renderer.dispose(); el.removeChild(renderer.domElement);
    };
  }, [spin]);

  const center = () => {
    const { sprite } = s.current;
    if (sprite?.visible) s.current.target = sprite.position.clone().normalize().multiplyScalar(3.2);
  };

  useEffect(() => {
    const { sprite, line } = s.current;
    if (!sprite) return;
    if (position) {
      sprite.position.copy(toVec(position[0], position[1], 1.08));
      sprite.visible = true;
      if (s.current.first) { s.current.first = false; center(); }
    }
    if (path.length) line.geometry.setFromPoints(path.map(([la, lo]) => toVec(la, lo, 1.08)));
  }, [position, path]);

  return (
    <div className="globe" ref={mount}>
      {position && <button className="globe-btn" onClick={center}>Center on ISS</button>}
    </div>
  );
}
