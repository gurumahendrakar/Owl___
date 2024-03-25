"use client";
import Image from "next/image";
import { useState } from "react";
import ShoeIntroBox from "./UI-Templates/ShoeIntroBox";
import Shoe1  from "../../public/shoe-1.jpeg";
import Shoe2  from "../../public/shoe-2.jpeg";
import Shoe3  from "../../public/shoe-3.jpeg";

export default function Home() {
  return (
      <>
        <main>
            <section className="ShoesCollections">
              <h2>Shoes Collections</h2>
                <ShoeIntroBox
                  ImagePath={Shoe1.src}
                  flexOrder={2}
                />
                 <ShoeIntroBox
                  ImagePath={Shoe2.src}
                  flexOrder={1}
                />
                 <ShoeIntroBox
                  ImagePath={Shoe3.src}
                  flexOrder={2}
                />
            </section>
        </main>
      </>
  );
}

