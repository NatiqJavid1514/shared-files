import { useState } from 'react'
import './App.css'
import Navbar from './components/Navbar'

function App() {
  const [color, setColor] = useState("green")

  return (
    <>
      <Navbar color={color} />
      <div>
        <h1>Hello I am here</h1>
        <button onClick={() => setColor(color === "green" ? "red" : "green")}>
          Change color
        </button>
      </div>
    </>
  )
}

export default App