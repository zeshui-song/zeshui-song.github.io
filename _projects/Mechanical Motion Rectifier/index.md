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

<small><em>Pulley Subsystem Systems Diagram.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Subsystem.png" height="300"%}
</div>
