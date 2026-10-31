// import { useState } from "react";
// import "./App.css";

// // ---------- Custom hook (defined outside the component) ----------
// function useShowMessage(text) {
//   const [visible, setVisible] = useState(false);

//   const toggle = () => setVisible(!visible);
//   const message = visible ? text : "";

//   return { message, visible, toggle };
// }

// // ---------- Main component ----------
// function App() {
//   // 1. Counter
//   const [count, setCount] = useState(0);
//   const increment = () => {
//     if (count < 20) setCount(count + 1);
//   };
//   const decrement = () => {
//     if (count > 0) setCount(count - 1);
//   };
//   const reset = () => setCount(0);

//   // 2. Message updater
//   const [message, setMessage] = useState("Hello, World!");
//   const changeMessage = () => {
//     setMessage(message === "Hello, World!" ? "Natiq is cool" : "Hello, World!");
//   };

//   // 3. Theme switcher
//   const [theme, setTheme] = useState("light");

//   // 4. Layout switcher
//   const [layout, setLayout] = useState("list");

//   // 5. Custom hook
//   const { message: hookMessage, visible, toggle } = useShowMessage("Natiq is cool");

//   return (
//     <div className={`app ${theme}`}>
//       <h1>All Programs in One</h1>

//       {/* Counter */}
//       <div className="section">
//         <h2>Counter Application</h2>
//         <h3>Count: {count}</h3>
//         <button onClick={increment}>Increment</button>
//         <button onClick={decrement}>Decrement</button>
//         <button onClick={reset}>Reset</button>
//       </div>

//       {/* Message updater */}
//       <div className="section">
//         <h2>Message Updater</h2>
//         <h3>{message}</h3>
//         <button onClick={changeMessage}>Change Message</button>
//       </div>

//       {/* Theme switcher */}
//       <div className="section">
//         <h2>Theme Switcher</h2>
//         <h3>Current theme: {theme}</h3>
//         <button onClick={() => setTheme(theme === "light" ? "dark" : "light")}>
//           Switch to {theme === "light" ? "Dark" : "Light"} Mode
//         </button>
//       </div>

//       {/* Layout switcher */}
//       <div className="section">
//         <h2>Layout Switcher</h2>
//         <h3>Current layout: {layout}</h3>
//         <button onClick={() => setLayout(layout === "list" ? "grid" : "list")}>
//           Switch to {layout === "list" ? "Grid" : "List"} Layout
//         </button>

//         <div className={`container ${layout}`}>
//           <div className="box">Box 1</div>
//           <div className="box">Box 2</div>
//           <div className="box">Box 3</div>
//           <div className="box">Box 4</div>
//           <div className="box">Box 5</div>
//           <div className="box">Box 6</div>
//         </div>
//       </div>

//       {/* Custom hook */}
//       <div className="section">
//         <h2>Custom Hook Demo</h2>
//         <h3>{hookMessage}</h3>
//         <button onClick={toggle}>
//           {visible ? "Hide Message" : "Show Message"}
//         </button>
//       </div>
//     </div>
//   );
// }

// export default App;

// import React, { useState, useEffect } from 'react';

// function HookLifecycle() {
//     const [count, setCount] = useState(0);

//     useEffect(() => {
//         console.log("Component mounted or updated");

//         return () => {
//             console.log("Component will unmount");
//         };
//     }, [count]); // runs when 'count' changes

//     return (
//         <div>
//             <h3>Hook Lifecycle Example</h3>
//             <p>Count: {count}</p>
//             <button onClick={() => setCount(count + 1)}>
//                 Increment
//             </button>
//         </div>
//     );
// }

// export default HookLifecycle;
import React, { useEffect, useState } from 'react';

function App() {
    const [user, setUser] = useState(null);

    useEffect(() => {
        fetch("https://jsonplaceholder.typicode.com/users/1")
            .then((response) => response.json())
            .then((data) => setUser(data))
            .catch((error) => console.error("Error", error));
    }, []);

    if (!user) return <p>loading ...</p>;

    return (
        <div>
            <h2>{user.name}</h2>
            <p>Email: {user.email}</p>
        </div>
    );
}

export default App;