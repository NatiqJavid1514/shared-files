import { useEffect, useRef } from "react";
import * as THREE from "three";

// Fixed 3D star background behind every screen. Moves slowly and shifts with the mouse.
export default function Starfield() {
  const ref = useRef(null);
  useEffect(() => {
    const el = ref.current;
    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(60, innerWidth / innerHeight, 1, 2000);
    const renderer = new THREE.WebGLRenderer({ alpha: true });
    renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
    renderer.setSize(innerWidth, innerHeight);
    el.appendChild(renderer.domElement);

    const N = 1800, pos = new Float32Array(N * 3);
    for (let i = 0; i < N; i++) {
      const r = 300 + Math.random() * 700, a = Math.random() * Math.PI * 2, b = Math.acos(2 * Math.random() - 1);
      pos.set([r * Math.sin(b) * Math.cos(a), r * Math.cos(b), r * Math.sin(b) * Math.sin(a)], i * 3);
    }
    const geo = new THREE.BufferGeometry();
    geo.setAttribute("position", new THREE.BufferAttribute(pos, 3));
    const stars = new THREE.Points(geo, new THREE.PointsMaterial({ color: 0xcfd8ff, size: 1.6, sizeAttenuation: false, transparent: true, opacity: 0.85 }));
    scene.add(stars);

    const calm = matchMedia("(prefers-reduced-motion: reduce)").matches;
    let mx = 0, my = 0, raf;
    const onMove = (e) => { mx = e.clientX / innerWidth - 0.5; my = e.clientY / innerHeight - 0.5; };
    const onResize = () => { camera.aspect = innerWidth / innerHeight; camera.updateProjectionMatrix(); renderer.setSize(innerWidth, innerHeight); };
    addEventListener("mousemove", onMove); addEventListener("resize", onResize);
    const loop = () => {
      if (!calm) stars.rotation.y += 0.0004;
      camera.rotation.y += (-mx * 0.15 - camera.rotation.y) * 0.03;
      camera.rotation.x += (-my * 0.15 - camera.rotation.x) * 0.03;
      renderer.render(scene, camera);
      raf = requestAnimationFrame(loop);
    };
    loop();
    return () => {
      cancelAnimationFrame(raf);
      removeEventListener("mousemove", onMove); removeEventListener("resize", onResize);
      renderer.dispose(); geo.dispose(); el.removeChild(renderer.domElement);
    };
  }, []);
  return <div className="starfield" ref={ref} aria-hidden="true" />;
}
