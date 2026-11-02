import { useState } from "react";
import { FaExchangeAlt, FaMoon, FaSun } from "react-icons/fa";
import CurrencySelect from "./components/CurrencySelect.jsx";
import useExchangeRates from "./hooks/useExchangeRates.js";

function App() {
  const [amount, setAmount] = useState(100);
  const [from, setFrom] = useState("USD");
  const [to, setTo] = useState("INR");
  const [dark, setDark] = useState(false);

  const { rates, loading, error } = useExchangeRates(from);

  const currencies = Object.keys(rates).length > 0 ? Object.keys(rates) : ["USD", "INR"];
  const rate = rates[to];
  const result = rate ? amount * rate : 0;

  function swapCurrencies() {
    setFrom(to);
    setTo(from);
  }

  return (
    <div className={dark ? "page dark" : "page"}>
      <div className="card">
        <div className="header">
          <h1>Currency converter</h1>
          <button
            className="icon-btn"
            onClick={() => setDark(!dark)}
            aria-label="Toggle theme"
          >
            {dark ? <FaSun /> : <FaMoon />}
          </button>
        </div>

        <div className="field">
          <label htmlFor="amount">Amount</label>
          <input
            id="amount"
            type="number"
            min="0"
            value={amount}
            onChange={(e) => setAmount(e.target.value)}
          />
        </div>

        <div className="row">
          <CurrencySelect label="From" value={from} onChange={setFrom} currencies={currencies} />
          <button className="icon-btn swap" onClick={swapCurrencies} aria-label="Swap currencies">
            <FaExchangeAlt />
          </button>
          <CurrencySelect label="To" value={to} onChange={setTo} currencies={currencies} />
        </div>

        <div className="result">
          {loading && <p>Loading rates...</p>}
          {error && <p className="error">{error}</p>}
          {!loading && !error && rate && (
            <>
              <p className="small">
                {amount || 0} {from} =
              </p>
              <p className="big">
                {result.toLocaleString(undefined, {
                  minimumFractionDigits: 2,
                  maximumFractionDigits: 2,
                })}{" "}
                {to}
              </p>
              <p className="small">
                1 {from} = {rate.toFixed(4)} {to}
              </p>
            </>
          )}
        </div>
      </div>
    </div>
  );
}

export default App;
