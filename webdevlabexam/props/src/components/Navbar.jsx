import { useEffect, useRef } from 'react'

const Navbar = (props) => {
  const isFirstRender = useRef(true)

  useEffect(() => {
    // Skip the alert on the first load, only fire when color changes
    if (isFirstRender.current) {
      isFirstRender.current = false
      return
    }
    alert("COLOR WAS CHANGED")
  }, [props.color])

  return (
    <div style={{ backgroundColor: props.color, padding: '10px' }}>
      I am a navbar of color {props.color}
      <ul>
        <li>Home</li>
        <li>Contact</li>
        <li>Email</li>
      </ul>
    </div>
  )
}

export default Navbar