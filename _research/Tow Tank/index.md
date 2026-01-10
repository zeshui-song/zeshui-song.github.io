---
order: 1
layout: post
title: "Tow Tank (Work in Progress)"
description:  The goal of this project is to design a tow tank capable of moving a wing smoothly through water at a range of controlled speeds, enabling precise measurements of hydrodynamic forces acting on it. The setup must maintain a constant velocity for a sufficient duration while minimizing twisting and vibrations in the moving components. Additionally, it should be scalable to accommodate additional hardware such as mounted cameras and sensors.
skills:
  - Experimental Rig Design & Fabrication
  - Precision Linear Motion Systems
  - 3D Printing (FDM)
  - Stepper Motor Control
  - Modular Structural Framing (80/20)
  - Power Supply and Motor Driver Selection
  - Timing Belt and Pulley System
  - Belt Tensioners
main-image: /Tow - Copy.jpg
---
**Duration:** Ongoing (Started July 2025)

---
# How it Works
The system utilizes a linear actuation setup where a moving gantry is driven along linear rails by a NEMA 23 stepper motor and a timing belt pulley system. This set up ensures precise control over position, speed, and acceleration while maintaining a constant velocity and minimizing twisting and vibration in the structural framing.

<small><em>Overview of the linear actuation system.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Linear%20Actuation.png" height="450"%}
</div>

<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Tow1.png" height="400"%}
</div>

# Engineering and Design

## Linear Rail System:
Dual MGN12 linear rails provide low-friction, high-precision guidance for the moving gantry. The rails are mounted directly to 8020 aluminum extrusion, allowing vertical loads to be transferred into the frame without introducing bending or localized failure points. This configuration improves stiffness and minimizes deflection under load. To prevent twisting and ensure alignment, the rails are attached using drop-in M3 T-nuts spaced at 75 mm intervals. This mounting approach provides a strong connection while remaining adjustable during assembly.

<small><em>Linear rail and gantry connection via MGN12 linear bearings.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Gantry%20Rail.png" height="400"%}
</div>

<small><em>Linear rail and T-nut assembly.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/T-nut%201.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/T-nut%202.png" height="300"%}
</div>

Several alternative linear motion solutions were considered. V-slot wheels offered a lower-cost option but lacked sufficient vertical load capacity and required a stiff metal backplate that was difficult to source. Round shaft rails were also evaluated, but their looser tolerances introduced excessive play in the bearings, reducing precision and increasing vibration. Linear rails were ultimately selected for their superior stiffness, tighter tolerances, and improved dynamic performance.

<small><em>V-slot (left) and round shaft rail (right).</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/V%20slot.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Round.png" height="300"%}
</div>

The gantry consists of a 10-inch piece of 80/20 aluminum extrusion mounted directly onto the linear rails, providing stiffness and structural integrity while allowing for flexible mounting along its extrusion profiles via T-nuts.

<small><em>Moving gantry assembly.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Gantry.png" height="400"%}
</div>

## Power System
A NEMA 23 stepper motor drives the gantry through a GT2 timing belt system. This setup enables precise control of motion parameters while maintaining smooth translation over long distances. An idler pulley at the opposite end of the system maintains belt tension and alignment, ensuring consistent performance during operation. Initial testing revealed that additional belt tensioning was required for reliable performance. A modified version of a belt tensioner design by [Cahorton](https://www.thingiverse.com/thing:181349) was used initially, with plans to develop a custom tensioner integrated directly into the gantry timing-belt mount.

<small><em>NEMA 23 (left) and idler pulley assembly (right).</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Stepper.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Pulley.png" height="400"%}
</div>

## Structural Frame Design
The structural framework was engineered to minimize reliance on friction-based joints for supporting vertical loads from the moving gantry. To ensure long-term stability and precision, I utilized a design where vertical struts carry the majority of the load, with four-hole corner gussets serving primarily to maintain alignment and contact between the 80/20 extrusions.

<small><em>Full tow tank frame assembly.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Frame.png" height="400"%}
</div>

<small><em>This joint relies on the vertical strut for all its vertical load support, while the corner bracket’s role is to maintain contact between the two pieces of 80/20 extrusion.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Frame1.png" height="300"%}
</div>

<small><em>While this joint could use a similar stacking arrangement, I chose to rely primarily on the shear strength of the screws to support the rails, allowing for easier alignment of the moving gantry and pulley system.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Frame2.png" height="300"%}
</div>