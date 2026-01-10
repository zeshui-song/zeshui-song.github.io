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
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Linear%20Actuation.png" height="300"%}
</div>

<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Tow1.png" height="400"%}
</div>

# Engineering and Design

## Linear Rail System:
Dual MGN12 linear rails provide low-friction, high-precision guidance for the moving gantry. The rails are mounted directly to 8020 aluminum extrusion, allowing vertical loads to be transferred into the frame without introducing bending or localized failure points. This configuration improves stiffness and minimizes deflection under load. To prevent twisting and ensure alignment, the rails are attached using drop-in M3 T-nuts spaced at 75 mm intervals. This mounting approach provides a strong connection while remaining adjustable during assembly.

<small><em>Linear rail and gantry connection via MGN12 linear bearings.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Tow%20Tank/Gantry%20Rail.png" height="300"%}
</div>
