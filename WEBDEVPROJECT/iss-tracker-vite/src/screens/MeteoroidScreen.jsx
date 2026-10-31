import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import axios from "axios";

const KEY = import.meta.env.VITE_NASA_API_KEY || "DEMO_KEY";

export default function MeteoroidScreen() {
  const [meteors, setMeteors] = useState(null);
  const [error, setError] = useState("");

  useEffect(() => {
    axios.get(`https://api.nasa.gov/neo/rest/v1/feed?api_key=${KEY}`)
      .then((res) => {
        const all = Object.values(res.data.near_earth_objects).flat().map((m) => {
          const d = m.estimated_diameter.kilometers;
          const ap = m.close_approach_data[0];
          const diameter = (d.estimated_diameter_min + d.estimated_diameter_max) / 2;
          const miss = Number(ap.miss_distance.kilometers);
          return {
            id: m.id, name: m.name.replace(/[()]/g, ""), diameter, miss,
            threat: (diameter / miss) * 1e9,
            hazardous: m.is_potentially_hazardous_asteroid,
            date: ap.close_approach_date_full || ap.close_approach_date,
            speed: Number(ap.relative_velocity.kilometers_per_hour),
          };
        });
        setMeteors(all.sort((a, b) => b.threat - a.threat));
      })
      .catch((err) => setError(err.message));
  }, []);

  const maxD = meteors ? Math.max(...meteors.map((m) => m.diameter)) : 1;

  return (
    <main className="screen">
      <header className="topbar">
        <Link to="/" className="back">Back</Link>
        <h1>Meteors</h1>
        <span />
      </header>

      {error && <p className="notice">Couldn’t load meteor data: {error}</p>}
      {!meteors && !error && <p className="notice">Loading…</p>}
      {meteors && <p className="sub">{meteors.length} asteroids pass Earth in the next 7 days, ranked by threat score.</p>}

      {meteors && (
        <ul className="meteor-list">
          {meteors.map((m) => (
            <li key={m.id}>
              <div className="m-head">
                <strong>{m.name}</strong>
                {m.hazardous && <em>Flagged hazardous by NASA</em>}
              </div>
              <span>Closest approach: {m.date}</span>
              <span>Misses Earth by {Math.round(m.miss).toLocaleString()} km</span>
              <span>Speed {Math.round(m.speed).toLocaleString()} km/h</span>
              <div className="bar" title={`${m.diameter.toFixed(3)} km wide`}>
                <i style={{ width: `${Math.max(4, (m.diameter / maxD) * 100)}%` }} />
              </div>
              <span className="dim">{m.diameter.toFixed(3)} km wide · threat score {m.threat.toFixed(2)}</span>
            </li>
          ))}
        </ul>
      )}
    </main>
  );
}
