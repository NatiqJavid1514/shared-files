import { useEffect, useState, useCallback } from "react";
import { Link } from "react-router-dom";
import axios from "axios";
import Globe from "../components/Globe.jsx";
import refreshIcon from "../assets/refresh_icon.jpg";

const API = "https://api.wheretheiss.at/v1/satellites/25544";

export default function IssLocationScreen() {
  const [location, setLocation] = useState(null);
  const [path, setPath] = useState([]);
  const [error, setError] = useState("");

  const load = useCallback(() => {
    setError("");
    axios.get(API).then((r) => setLocation(r.data)).catch((e) => setError(e.message));
  }, []);

  useEffect(() => {
    load();
    const id = setInterval(load, 10000);
    return () => clearInterval(id);
  }, [load]);

  // Orbit line: 10 points from 20 minutes ago to 40 minutes ahead
  useEffect(() => {
    const now = Math.floor(Date.now() / 1000);
    const ts = Array.from({ length: 10 }, (_, i) => now + (i - 3) * 400);
    axios.get(`${API}/positions?timestamps=${ts.join(",")}`)
      .then((r) => setPath(r.data.map((p) => [p.latitude, p.longitude])))
      .catch(() => {});
  }, []);

  const position = location ? [location.latitude, location.longitude] : null;

  return (
    <main className="screen">
      <header className="topbar">
        <Link to="/" className="back">Back</Link>
        <h1>ISS location</h1>
        <button className="icon-btn" onClick={load} aria-label="Refresh position">
          <img src={refreshIcon} alt="" />
        </button>
      </header>

      {error && <p className="notice">Couldn’t load the ISS position: {error}. Press refresh to try again.</p>}
      {!position && !error && <p className="notice">Loading…</p>}

      <div className="globe-wrap"><Globe position={position} path={path} /></div>

      {location && (
        <div className="stats">
          <div><span>Position</span>{location.latitude.toFixed(2)}°, {location.longitude.toFixed(2)}°</div>
          <div><span>Speed</span>{Math.round(location.velocity).toLocaleString()} km/h</div>
          <div><span>Altitude</span>{Math.round(location.altitude)} km</div>
        </div>
      )}
    </main>
  );
}
