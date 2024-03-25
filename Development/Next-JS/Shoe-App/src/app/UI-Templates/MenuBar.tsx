"use client"
import React, { SetStateAction } from 'react'

function MenuBar({setSlide} : {setSlide : React.Dispatch<SetStateAction<boolean>>}) {
  return (
    <div className='MobileMenuBarDiv' onClick={()=>{
        setSlide((value : boolean)=>!value);
    }}>
        <span className="bar"></span>
        <span className="bar"></span>
        <span className="bar"></span>
    </div>
  )
}

export default MenuBar