---
order: 2
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
# How it Works
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

## Water Subsystem  
The Archimedes screw uses rotational motion to lift water from the bottom to the upper reservoir, which flows through a tube to drive a water wheel. The water wheel rotates a 5 mm shaft via an M3 screw, spinning an output disk. Multiple iterations of the screw improved water transport efficiency, modularity for 3D printing, and leak prevention.

<small><em>Archimedes Screw Support: The lower mount, consisting of a 3d printed bracket and a laser cut acrylic piece, reduces shaft wobble and vibration, ensuring smoother operation.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Arch%20Screw.png" height="400"%}
</div>

<small><em>Muji containers were made into reservoirs, with the upper reservoir drilled to guide water to the water wheel and maintain a constant outflow. A small acrylic guide prevents spillage onto the breadboard.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Reservior.png" height="300"%}
</div>

<small><em>Final water wheel iteration (left) with 9 fins is fitted for a 5 mm shaft with a 25 mm radius. Its support (right) positions the shaft close to the main reservoir, ensuring stability while avoiding interference with the rubber band.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/WaterWheel.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/WaterWheelSupp.png" height="300"%}
</div>

# Completed System and Results
<small><em>Oblique, side, front, and top views of the full assembly, in that order, showing the overall system layout.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Full.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Side.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Front.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Top.png" height="300"%}
</div>

<div style="display: flex; justify-content: center; align-items: flex-start; gap: 20px; height: 500px; width: 100%;">
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content;">
  {% include youtube-video.html 
      id="o6Od8IpsKps" 
      format="shorts" 
      autoplay="true"
      loop="true"
  %}
  </div>
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content;">
  {% include youtube-video.html 
      id="t_QB27qpTKk" 
      format="shorts" 
      autoplay="true"
      loop="true"
  %}
  </div>  
</div>

Data collected at 7.5 V show that the input gear’s angular velocity varies sinusoidally between 16.16 and 26.4 rad/s, while the output gear’s angular velocity ranges from 4.2 to 9.37 rad/s, demonstrating that the rectifier reduces fluctuations and produces a more constant output speed. Accumulated angle analysis confirms this: the input gear shows varying slope, whereas the output gear maintains a nearly constant slope (R² = 1.00).

<small><em>Plots comparing angular position (θ) and angular velocity (ω) of the input and output gears at 7.5 V, showing that the rectifier reduces output fluctuations and produces a more constant rotational speed.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Input%20q.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Output%20q.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Input%20w.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Output%20w.png" height="300"%}
</div>

# My Role and Reflections
During this project, I was responsible for most of the CAD design in Onshape. As a team, we collaborated on manufacturing and assembling the system’s iterations, while other members handled data analysis and recording. Overall, the Archimedes screw pumped water effectively, but the output wheel was not fully constant. One major problem was that surface tension caused water droplets to cling to the water wheel buckets, increasing the effective moment of inertia and creating imbalances in the wheel. Future improvements could include smoothing surfaces, using hydrophobic coatings, or resin printing to reduce friction and optimize torque. This project taught me the “nonlinear path” of engineering, where parts that seem perfect in CAD often behave differently in the real world due to factors like tolerances and physical forces.
<div style="display: flex; justify-content: center; align-items: flex-start; gap: 20px; height: 500px; width: 100%;">
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content; height: 100%;">
    {% include youtube-video.html 
        id="mN5z6ZzOAVA" 
        format="normal" 
        autoplay="true"
        loop="true"
    %}
  </div>  
</div>

## Extra

<small><em>Collection of scrap pieces and old iterations.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Scraps.jpg" height="300"%}
</div>

<small><em>End of year showcase.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Showcase.jpg" height="500"%}
</div>

[Final Report](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/Mechanical%20Motion%20Rectifier/EID103%20Final%20Report.pdf)<br>
[Onshape CAD](https://cad.onshape.com/documents/7a2f53f5851927828ad4b1ab/w/d7a775bbe256ee246480effd/e/acfc0676ad124d315c4e56da?renderMode=0&uiState=695c356802bd79dd4a4d0af6)