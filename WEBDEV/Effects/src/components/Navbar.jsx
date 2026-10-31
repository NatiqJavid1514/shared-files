import React from 'react'
import { useEffect } from 'react'

const Navbar = (props) => {
    useEffect(()=>{
        alert("COLOR WAS CHANGED")

    },[props.color])
    return(
        
        <div>
            I am a navbar of color {props.color}
            <ul>
                <li>
                    Home
                </li>
                <li>
                    contact
                </li>
                <li>
                    Email
                </li>
            </ul>

        </div>
    )
}
export default Navbar