# Line-by-line explanation

How the app works in one paragraph: `main.jsx` mounts `App`. `App` keeps the amount, the two currencies and the theme in state. It calls the custom hook `useExchangeRates(from)`, which fetches rates for the "from" currency. `App` multiplies the amount by the rate for the "to" currency and shows the result. `CurrencySelect` is a reusable dropdown used twice.

---

## 1. index.html

| Line | Explanation |
|---|---|
| `<!doctype html>` | Tells the browser this is a modern HTML5 page. |
| `<html lang="en">` | Root element; `lang` helps screen readers and translators. |
| `<meta charset="UTF-8" />` | Lets the page show all characters correctly. |
| `<meta name="viewport" ... />` | Makes the page scale properly on phones (responsive). |
| `<title>Currency Converter</title>` | Text shown on the browser tab. |
| `<div id="root"></div>` | Empty box. React puts the whole app inside it. |
| `<script type="module" src="/src/main.jsx">` | Loads the JavaScript entry file. `type="module"` allows `import` statements. |

---

## 2. package.json

| Line | Explanation |
|---|---|
| `"name"` | Project name. |
| `"private": true` | Prevents accidentally publishing the project to npm. |
| `"version"` | Project version number. |
| `"type": "module"` | Lets `.js` files use `import`/`export` (ES6 modules). |
| `"scripts"` | Shortcuts you run with `npm run <name>`. |
| `"dev": "vite"` | Starts the development server with live reload. |
| `"build": "vite build"` | Creates the optimized production version in `dist/`. |
| `"preview": "vite preview"` | Serves the built version locally to test it. |
| `"dependencies"` | Packages needed when the app runs. |
| `"react"` | The React library itself. |
| `"react-dom"` | Connects React to the browser DOM. |
| `"react-icons"` | Icon library (we use the swap, moon and sun icons). |
| `"devDependencies"` | Packages needed only while developing. |
| `"@vitejs/plugin-react"` | Lets Vite understand JSX. |
| `"vite"` | The build tool and dev server. |

---

## 3. vite.config.js

| Line | Explanation |
|---|---|
| `import { defineConfig } from "vite";` | Helper that gives auto-complete for config options. |
| `import react from "@vitejs/plugin-react";` | Imports the React plugin. |
| `export default defineConfig({` | Exports the configuration object. |
| `plugins: [react()],` | Turns on React/JSX support. |
| `});` | Ends the config. |

---

## 4. src/main.jsx (entry point)

| Line | Explanation |
|---|---|
| `import React from "react";` | Imports React. |
| `import ReactDOM from "react-dom/client";` | Imports the function that renders React into the page. |
| `import App from "./App.jsx";` | Imports our main component. |
| `import "./App.css";` | Loads the CSS so it applies to the whole app. |
| `ReactDOM.createRoot(document.getElementById("root"))` | Finds the `#root` div from index.html and makes it the React root. |
| `.render(` | Draws the given component inside that root. |
| `<React.StrictMode>` | Development helper that warns about common mistakes. It runs effects twice in dev, which is why the hook has a cleanup. |
| `<App />` | Our main component. |
| `</React.StrictMode>` | Closes StrictMode. |
| `);` | Ends the render call. |

---

## 5. src/hooks/useExchangeRates.js (custom hook)

A custom hook is a normal function whose name starts with `use` and which uses other hooks. It lets us keep the fetching logic out of `App`.

| Line | Explanation |
|---|---|
| `import { useState, useEffect } from "react";` | Imports the two hooks we need. |
| `export default function useExchangeRates(base) {` | Hook that receives the base currency code, like `"USD"`. |
| `const [rates, setRates] = useState({});` | State holding the rates object. Starts empty. |
| `const [loading, setLoading] = useState(true);` | State telling if a download is in progress. |
| `const [error, setError] = useState("");` | State holding an error message (empty means no error). |
| `useEffect(() => {` | Runs code after render. Used for side effects like fetching. |
| `let cancelled = false;` | Flag used to ignore results from outdated requests. |
| `async function loadRates() {` | Async function so we can use `await`. |
| `setLoading(true);` | Show "Loading rates..." while fetching. |
| `setError("");` | Clear any old error. |
| `try {` | Start of code that might fail. |
| `const response = await fetch(\`https://open.er-api.com/v6/latest/${base}\`);` | Calls the API. The template string inserts the base currency into the URL. `await` waits for the reply. |
| `if (!response.ok) {` | `ok` is false for HTTP errors like 404 or 500. |
| `throw new Error("Server returned an error");` | Jumps to the `catch` block. |
| `const data = await response.json();` | Converts the reply text into a JavaScript object. |
| `if (data.result !== "success") {` | The API puts `"success"` in `result` when everything is fine. |
| `throw new Error("Could not read exchange rates");` | Treat unexpected data as an error. |
| `if (!cancelled) { setRates(data.rates); }` | Save the rates, but only if this request is still wanted. |
| `} catch (err) {` | Runs if anything above failed (no internet, bad reply, etc.). |
| `setError("Couldn't load exchange rates. ...")` | Store a friendly message to show the user. |
| `} finally {` | Runs after try or catch, always. |
| `setLoading(false);` | Hide the loading message either way. |
| `loadRates();` | Actually starts the download. |
| `return () => { cancelled = true; };` | Cleanup function. React calls it before the effect re-runs or when the component is removed. It marks the old request as cancelled. |
| `}, [base]);` | Dependency array: re-run the effect only when `base` changes. |
| `return { rates, loading, error };` | The hook gives these three values back to the component. |

---

## 6. src/components/CurrencySelect.jsx

| Line | Explanation |
|---|---|
| `function CurrencySelect({ label, value, onChange, currencies }) {` | A component. The `{ ... }` is object destructuring: it pulls the four props out of the props object. |
| `<div className="field">` | Wrapper box. We write `className`, not `class`, in JSX. |
| `<label htmlFor={label}>{label}</label>` | Text label. `htmlFor` (not `for`) connects it to the select with the same id. |
| `<select id={label} value={value} onChange={(e) => onChange(e.target.value)}>` | Dropdown. `value` makes it a controlled input (React decides what is shown). On change, we call the parent's function with the chosen code. |
| `{currencies.map((code) => (` | Loops over the array and returns one `<option>` per currency (list rendering). |
| `<option key={code} value={code}>` | One dropdown item. `key` helps React track list items efficiently. |
| `{code}` | Text shown in the item, like `INR`. |
| `</option>` and `))}` | Close the option and the `map`. |
| `</select>` and `</div>` | Close the dropdown and wrapper. |
| `export default CurrencySelect;` | Makes the component importable in other files. |

---

## 7. src/App.jsx (main component)

### Imports

| Line | Explanation |
|---|---|
| `import { useState } from "react";` | Hook for storing values that change. |
| `import { FaExchangeAlt, FaMoon, FaSun } from "react-icons/fa";` | Three icons from the Font Awesome set in react-icons. |
| `import CurrencySelect from "./components/CurrencySelect.jsx";` | Our reusable dropdown. |
| `import useExchangeRates from "./hooks/useExchangeRates.js";` | Our custom hook. |

### State and calculations

| Line | Explanation |
|---|---|
| `function App() {` | The main component. |
| `const [amount, setAmount] = useState(100);` | Amount typed by the user. Starts at 100. |
| `const [from, setFrom] = useState("USD");` | Currency being converted from. |
| `const [to, setTo] = useState("INR");` | Currency being converted to. |
| `const [dark, setDark] = useState(false);` | `true` means dark theme. |
| `const { rates, loading, error } = useExchangeRates(from);` | Calls our hook. Every time `from` changes, it fetches fresh rates. |
| `const currencies = Object.keys(rates).length > 0 ? Object.keys(rates) : ["USD", "INR"];` | `Object.keys(rates)` gives all currency codes. If rates haven't loaded yet, use a small fallback list so the dropdowns are never empty. |
| `const rate = rates[to];` | Rate for the target currency, for example 83. |
| `const result = rate ? amount * rate : 0;` | Converted amount. If no rate yet, show 0. |

### Functions

| Line | Explanation |
|---|---|
| `function swapCurrencies() {` | Runs when the swap button is clicked. |
| `setFrom(to);` | New "from" is the old "to". |
| `setTo(from);` | New "to" is the old "from". Both lines use the old values from this render, so the swap is correct. |

### JSX (what is displayed)

| Line | Explanation |
|---|---|
| `return (` | JSX starts here. |
| `<div className={dark ? "page dark" : "page"}>` | Adds the class `dark` when dark mode is on. CSS variables change with it. |
| `<div className="card">` | The white card in the middle. |
| `<h1>Currency converter</h1>` | Heading. |
| `<button className="icon-btn" onClick={() => setDark(!dark)} aria-label="Toggle theme">` | Theme button. Clicking flips `dark` between true and false. `aria-label` describes an icon-only button for screen readers. |
| `{dark ? <FaSun /> : <FaMoon />}` | Conditional rendering: shows a sun in dark mode, a moon in light mode. |
| `<input id="amount" type="number" min="0" value={amount} onChange={(e) => setAmount(e.target.value)} />` | Number box. It's controlled: its value comes from state and every keystroke updates state. |
| `<CurrencySelect label="From" value={from} onChange={setFrom} currencies={currencies} />` | Dropdown for the source currency. We pass data and the setter as props. |
| `<button ... onClick={swapCurrencies}><FaExchangeAlt /></button>` | Swap button with an icon. |
| `<CurrencySelect label="To" ... />` | Same component reused for the target currency. |
| `{loading && <p>Loading rates...</p>}` | `&&` shows the paragraph only while loading. |
| `{error && <p className="error">{error}</p>}` | Shows the error message if there is one. |
| `{!loading && !error && rate && (` | Only show the result when everything is ready. |
| `<> ... </>` | Fragment: groups elements without adding an extra div. |
| `{amount \|\| 0} {from} =` | Shows "100 USD =". If the box is empty, shows 0. |
| `result.toLocaleString(undefined, {...})` | Formats the number with commas and exactly two decimals. |
| `1 {from} = {rate.toFixed(4)} {to}` | Shows the unit rate with 4 decimals. |
| `export default App;` | Exports the component for `main.jsx`. |

---

## 8. src/App.css

| Rule | Explanation |
|---|---|
| `* { box-sizing: border-box; }` | Padding and border are included in an element's width, which makes sizing predictable. |
| `body { margin: 0; font-family: ... }` | Removes the default page margin and sets a clean system font. |
| `.page { --bg: ...; --card: ...; ... }` | Defines CSS variables (custom properties) for the light theme colors. |
| `min-height: 100vh;` | Page is at least as tall as the screen. |
| `display: flex; align-items: center; justify-content: center;` | Flexbox centers the card vertically and horizontally. |
| `background: var(--bg); color: var(--text);` | Uses the variables. |
| `.page.dark { ... }` | Same variable names with dark colors. Adding the class `dark` switches the whole theme. |
| `.card { max-width: 460px; ... }` | Card with a width limit, border, rounded corners and padding. `width: 100%` lets it shrink on phones. |
| `.header { display: flex; justify-content: space-between; }` | Title on the left, theme button on the right. |
| `h1 { margin: 0; font-size: 22px; }` | Heading size. |
| `.field { display: flex; flex-direction: column; gap: 6px; flex: 1; margin-bottom: 16px; }` | Stacks label above input with a small gap. `flex: 1` lets two fields share a row equally. |
| `label { font-size: 13px; color: var(--muted); }` | Small grey labels. |
| `input, select { height: 42px; ... }` | Same look for inputs and dropdowns. |
| `input:focus, select:focus { outline: 2px solid var(--accent); }` | Visible blue outline when selected (good for accessibility). |
| `.row { display: flex; align-items: flex-end; gap: 10px; }` | Puts From, swap button and To on one line. |
| `.icon-btn { ... }` | Square button that centers its icon. |
| `.icon-btn:hover { background: var(--accent-bg); }` | Highlight on hover. |
| `.swap { margin-bottom: 16px; }` | Lines the swap button up with the dropdowns. |
| `.result { ... background: var(--accent-bg); }` | Blue box that shows the answer. |
| `.result p { margin: 0; }` | Removes default paragraph spacing. |
| `.small`, `.big` | Smaller and larger text sizes inside the result. |
| `.error { color: #dc2626; }` | Red error text. |
| `@media (max-width: 420px) { ... }` | Applies only on narrow phone screens: dropdowns wrap onto separate lines and the swap button is centered. This makes the app responsive. |

---

## Viva quick answers

- **Why a custom hook?** It separates data-fetching from the UI and can be reused.
- **Why `[base]` in useEffect?** So rates are re-fetched only when the "from" currency changes.
- **Why the `cancelled` flag?** If you change currency quickly, an older slow request could overwrite newer data. The cleanup prevents that.
- **What is a controlled input?** An input whose value is stored in React state and updated through `onChange`.
- **Why `key` in `map()`?** It lets React identify each list item and update the list efficiently.
- **Props vs state?** Props are passed down from a parent and read-only; state is data a component owns and can change.
