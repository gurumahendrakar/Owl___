"use client"
import MenuBar from './MenuBar'
import React, { useState } from 'react'

function Nav() {
    const [Slide,setSlide] = useState(false);
  return (
    <nav onChange={()=>{
        console.log("resizeing")
    }}>
    <a href="#" id="LOGO">Shoe</a>
    <MenuBar setSlide={setSlide} />
    <ul className="NavigationLinksUL" style={{
        left : Slide ? "0%" : "-50%"
    }}>
        <li className="__home">HOME</li>
        <li className="__sneakers">SNEAKERS</li>
        <li className="__players">PLAYERS</li>
    </ul>
</nav>
    )
}

export default Nav