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
{% include image-gallery.html images="Initial.png, Initial1.png" height="300" %}
