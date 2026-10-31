import { Routes, Route } from "react-router-dom";
import Starfield from "./components/Starfield.jsx";
import HomeScreen from "./screens/HomeScreen.jsx";
import IssLocationScreen from "./screens/IssLocationScreen.jsx";
import MeteoroidScreen from "./screens/MeteoroidScreen.jsx";

export default function App() {
  return (
    <>
      <Starfield />
      <Routes>
        <Route path="/" element={<HomeScreen />} />
        <Route path="/iss-location" element={<IssLocationScreen />} />
        <Route path="/meteors" element={<MeteoroidScreen />} />
      </Routes>
    </>
  );
}
