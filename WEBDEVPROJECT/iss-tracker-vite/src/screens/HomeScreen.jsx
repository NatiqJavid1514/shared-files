import { useNavigate } from "react-router-dom";
import Globe from "../components/Globe.jsx";
import issIcon from "../assets/iss_icon.png";
import meteorIcon from "../assets/meteor_icon.png";
import rocketIcon from "../assets/rocket_icon.png";

const routes = [
  { label: "ISS location", note: "Live position on a 3D globe", icon: issIcon, to: "/iss-location" },
  { label: "Meteors", note: "Asteroids passing Earth this week", icon: meteorIcon, to: "/meteors" },
  { label: "Updates", note: "Coming soon", icon: rocketIcon, to: null },
];

// Cards tilt in 3D toward the mouse
const tilt = (e) => {
  const r = e.currentTarget.getBoundingClientRect();
  e.currentTarget.style.setProperty("--ry", `${((e.clientX - r.left) / r.width - 0.5) * 12}deg`);
  e.currentTarget.style.setProperty("--rx", `${-((e.clientY - r.top) / r.height - 0.5) * 12}deg`);
};
const untilt = (e) => { e.currentTarget.style.setProperty("--rx", "0deg"); e.currentTarget.style.setProperty("--ry", "0deg"); };

export default function HomeScreen() {
  const navigate = useNavigate();
  return (
    <main className="screen">
      <div className="hero"><Globe spin /></div>
      <h1 className="home-title">ISS Tracker</h1>
      <div className="cards">
        {routes.map((r) => (
          <button key={r.label} className="route-card" disabled={!r.to}
            onMouseMove={tilt} onMouseLeave={untilt} onClick={() => r.to && navigate(r.to)}>
            <span className="route-text">{r.label}<small>{r.note}</small></span>
            <img src={r.icon} alt="" />
          </button>
        ))}
      </div>
    </main>
  );
}
