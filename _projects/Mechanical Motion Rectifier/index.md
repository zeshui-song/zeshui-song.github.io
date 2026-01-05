---
layout: post
title: "Wales: A Water-Based Physical Motion Rectifier"
description:  Design a system that turns a variable-speed rotational input into a constant-speed rotational output. It must fit on an 8” × 8” breadboard and be set up or removed in under 5 minutes. The system should connect to the supplied motor shaft, include a gear for the encoder, and measure input and output speeds over time. The output drives a 1”–3” disc that reaches steady state within 10 seconds, and will be tested at 1 Hz, 0.5 Hz, and 0.25 Hz. No part should spin beyond safe limits.
skills:
  - Iterative Design & Prototyping
  - FDM 3D Printing
  - Onshape CAD
  - Pulley & Bevel Gear Design
  - Archimedes Screw & Fluid Systems
  - 3D Printing Tolerancing
  - Shaft & Bearing Mount Design
  - Design Documentation & System Diagrams
main-image: /Motion Rectifier.jpg
---
**Team members:** Nora Gallion, Zehra Girgin, Bertrand Juan, Zeshui Song<br>
**Course:** EID 103<br>
**Duration:** Jan–May 2025

---
# How it works
Wales is a mechanical motion rectifier that decouples a variable input from its output by using water as an external energy buffer. A variable-speed motor drives an Archimedes screw, lifting water from a lower reservoir to an upper reservoir. The upper reservoir stores potential energy and releases water at a constant rate through gravity to drive a water wheel. Constant pressure in the upper reservoir is maintained via an overflow outlet. By converting fluctuating mechanical input into stable potential energy, the system produces a steady rotational output independent of input speed.
# Engineering and Design
The system is composed of three primary mechanical subsystems: the pulley, bevel gear transmission, and the water subsystems.
## Pulley Subsystem:
Transfers power from the motor to an 8 mm main shaft using crowned pulleys, which self-centers the rubber drive belt and prevents slipping. Multiple pulley geometries were tested to identify the optimal configuration for reliable power transmission.

<small><em>The initial motor gear had a hexagonal section to mount a gear meshing with the encoder gear and a recessed center to guide the rubber band. However, the band frequently slipped to the side, causing jams in the motor.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Initial.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Initial1.png" height="200"%}
</div>

<small><em>Various motor gear designs were tested to prevent rubber band slipping, including ribbed and concave surfaces, but only crowned pulleys with a smaller motor gear radius kept the band centered and improved the gear ratio for the Archimedes screw.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Rib.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Concave.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Convex.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Convex1.png" height="200"%}
</div>

## Bevel Gear Transmission Subsystem:
Due to the 8" × 8" breadboard’s spatial constraints, the Archimedes screw was angled at 55° and driven from the top. Power was transmitted via a pair of 45° bevel gears mounted on a custom angled support. Early prototypes experienced significant shaft wobble, which was eliminated by replacing a single-point support with an integrated bearing housing. This rigid design locked the gear mesh in place, enabling smooth power transfer even at peak motor velocity.

<small><em>Comparison of initial bevel gear support (left) and final consolidated bevel gear support (right).</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Bevel%20Sup%201.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Bevel%20Sup%202.png" height="300"%}
</div>

<small><em>The 8 mm shaft gear (left) uses a set screw and flange to engage only the bearing’s inner race, while the Archimedes screw gear (center) secures to a 3 mm shaft and the screw via symmetric set screws. A cross-sectional view (right) shows the 3 mm shaft connection and the Archimedes screw interface.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Bevel1.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Bevel2.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Bevel3.png" height="300"%}
</div>

<small><em>Full bevel gear transmission.</em></small>
<div style="display: flex; justify-content: center; align-items: flex-start; gap: 20px; height: 500px; width: 100%;">
  <div style="flex: 0 0 auto; width: fit-content;">
    {% include image-gallery.html 
        images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Final%20Bevel.png" 
        height="500" 
    %}
  </div>
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content;">
  {% include youtube-video.html 
      id="iat7Izz4NXc" 
      format="shorts" 
      autoplay="true"
      loop="true"
  %}
  </div>  
</div>
