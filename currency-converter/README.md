# Currency Converter (React + Vite)

A small React app that converts money between currencies using live exchange rates
from the free `open.er-api.com` API (no API key needed).

## Run it

1. Install Node.js (version 18 or newer) from https://nodejs.org
2. Open a terminal inside this folder and run:

```
npm install
npm run dev
```

3. Open the link shown in the terminal (usually http://localhost:5173).

## Folder structure

```
currency-converter/
  index.html                      page shell with the #root div
  package.json                    dependencies and scripts
  vite.config.js                  Vite + React plugin setup
  src/
    main.jsx                      entry point, mounts <App />
    App.jsx                       main component (state + layout)
    App.css                       all styling, light and dark theme
    components/CurrencySelect.jsx reusable dropdown component
    hooks/useExchangeRates.js     custom hook that fetches rates
  EXPLANATION.md                  line-by-line explanation of every file
```

## Syllabus topics used

- Components, props, and component reuse (`CurrencySelect`)
- `useState` (amount, currencies, theme)
- `useEffect` and a custom hook (`useExchangeRates`)
- Fetching data from an API with loading and error states
- List rendering with `map()`
- Event handling (onChange, onClick)
- `react-icons` library
- CSS variables, Flexbox, and a dark/light theme switcher
