// import useShowMessage from "./useShowMessage";

// function Layout() {
//   const { message, visible, toggle } = useShowMessage("Natiq is cool");

//   return (
//     <div>
//       <h1>Custom Hook Demo</h1>
//       <h2>{message}</h2>
//       <button onClick={toggle}>
//         {visible ? "Hide Message" : "Show Message"}
//       </button>
//     </div>
//   );
// }

// export default Layout;

import { useState } from "react";

function Layout() {
  const [theme, setTheme] = useState("light");
  const [layout, setLayout] = useState("list");

  return (
    <div className={`app ${theme}`}>
      <h1>Theme and Layout Switcher</h1>

      <button onClick={() => setTheme(theme === "light" ? "dark" : "light")}>
        Switch to {theme === "light" ? "Dark" : "Light"} Mode
      </button>

      <button onClick={() => setLayout(layout === "list" ? "grid" : "list")}>
        Switch to {layout === "list" ? "Grid" : "List"} Layout
      </button>

      <div className={`container ${layout}`}>
        <div className="box">Box 1</div>
        <div className="box">Box 2</div>
        <div className="box">Box 3</div>
        <div className="box">Box 4</div>
        <div className="box">Box 5</div>
        <div className="box">Box 6</div>
      </div>
    </div>
  );
}

export default Layout;