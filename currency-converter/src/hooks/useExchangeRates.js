import { useState, useEffect } from "react";

// Custom hook: downloads exchange rates for a base currency.
export default function useExchangeRates(base) {
  const [rates, setRates] = useState({});
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState("");

  useEffect(() => {
    let cancelled = false;

    async function loadRates() {
      setLoading(true);
      setError("");
      try {
        const response = await fetch(`https://open.er-api.com/v6/latest/${base}`);
        if (!response.ok) {
          throw new Error("Server returned an error");
        }
        const data = await response.json();
        if (data.result !== "success") {
          throw new Error("Could not read exchange rates");
        }
        if (!cancelled) {
          setRates(data.rates);
        }
      } catch (err) {
        if (!cancelled) {
          setError("Couldn't load exchange rates. Check your internet and try again.");
        }
      } finally {
        if (!cancelled) {
          setLoading(false);
        }
      }
    }

    loadRates();

    // Cleanup: ignore the result if the base changes before the fetch ends.
    return () => {
      cancelled = true;
    };
  }, [base]);

  return { rates, loading, error };
}
