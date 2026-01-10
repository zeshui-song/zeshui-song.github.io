---
order: 2
layout: post
title: "Vertically Actuated Immersion Tank (Work in Progress)"
description:  The goal of this project is to design and build a vertically actuated immersion tank to study how tethered whirligig beetles behave as they transition from open air into an underwater environment. The system is designed to provide precise, repeatable control over immersion depth and rate while enabling controlled behavioral observation during air-to-water transitions.
skills:
  - Experimental Apparatus Design
  - Linear Actuation
  - 3D Printing (FDM)
  - Stepper Motor Control
  - 80/20 Aluminum Framing
  - Power Supply and Motor Driver Selection
main-image: /Media - Copy.jpg
---
**Duration:** Ongoing (Started July 2025)

---
# How it Works
The setup uses a vertically actuated mechanism to raise and lower the water tank, controlling the position of the water surface relative to a tethered beetle. The beetle is fixed above the tank, with a camera centered and focused on it. This configuration enables a consistent, repeatable air-to-water transition while allowing the immersion rate to be varied.

<small><em>Preliminary camera set up with tethered beetle.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Media.jpg, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Media%20(1).jpg" height="400"%}
</div>

# Engineering and Design

## Mechanical Design:
The mechanical system supports the water tank and provides smooth, guided vertical motion with minimal vibration. Several approaches for varying water level were evaluated, including using a DC motor–driven pump and physically translating the tank. It was determined that vertically actuating the tank allowed for better control over immersion rate and little to none disturbance of the water. The actuation system is mounted on an optical breadboard and constrained to vertical motion with 2 linear motion shafts. Most components were designed for 3D printing and assembled using heat-set inserts and interference fits. However, select parts will be replaced with 80/20 aluminum framing to improve stiffness and structural robustness. While the water load was estimated, the risk of tipping is negligible. The larger physical optical breadboard provides sufficient stability, so any failure would likely come from part shearing or breakage rather than tipping.

<small><em>Preliminary mechanical design.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Oblique.png" height="400"%}
</div>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Front.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Side.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Top.png" height="400"%}
</div>

## Actuation and Motion Control:
The vertical motion is generated using a linear actuator driven by a NEMA 17 stepper motor coupled to a lead screw. This configuration allows precise, programmable control of immersion depth and velocity, enabling systematic variation of experimental conditions. Stepper motor control was further developed in my tow tank project, using a TB6600 driver with GRBL on an Arduino Uno and Universal G-code Sender to operate the motors via standard G-code commands.

# Future Work
The actuator has not yet been built, so I plan to redesign the mechanical structure to incorporate 80/20 mounting hardware for improved stability and rigidity. Once complete, we will focus on data collection and configuring the camera to reliably record the beetle in both air and water.
