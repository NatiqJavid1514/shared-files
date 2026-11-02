// Reusable dropdown. Used twice in App: once for "From", once for "To".
function CurrencySelect({ label, value, onChange, currencies }) {
  return (
    <div className="field">
      <label htmlFor={label}>{label}</label>
      <select id={label} value={value} onChange={(e) => onChange(e.target.value)}>
        {currencies.map((code) => (
          <option key={code} value={code}>
            {code}
          </option>
        ))}
      </select>
    </div>
  );
}

export default CurrencySelect;
