"use client"
import React from 'react'
import Image from 'next/image'


function ShoeIntroBox(props  : {
  ImagePath : string
  flexOrder : number

}) {
  return (
    <div className='ShoeIntroBox'>
        <div className='ShoeIntroImgDiv'>
          <Image
             src={props.ImagePath}
             alt='ShoeImage'
             width={400}
             height={400} 
             className={"ShoeIntroImg"}
             loading='lazy'
          />     
        </div>

        <div className='ShoeIntroDescriptionDiv'
          style={
            {order : props.flexOrder}
          }
        >
          <h2>LightWeight</h2>
          <p>Upper mesh material provides proper ventilation and reduction in the weight of the shoes.</p>
        </div>
    </div>       
  )
}

export default ShoeIntroBox