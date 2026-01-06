---
order: 3
layout: post
title: "HX711 Scale"
description:  The goal of this project was to design and build a $30 digital scale capable of accurately measuring mass while mechanically isolating the load cell from external, non-normal forces. The system includes tare and unit-conversion (grams to ounces) functions and employs a pulley-based decoupling mechanism to improve measurement precision.
skills:
  - Mechanical Design
  - 3D Printing (FDM)
  - Arduino Programming
  - Signal Conditioning (HX711)
  - Load Cells
  - Soldering
main-image: /Scale.jpg
---
**Team members:** Zeshui Song, Roy He, Aleksander Szetela<br>
**Course:** ME 104<br>
**Duration:** April-May 2025

---
# How it Works
The scale uses a 10 kg load cell mounted to a 3D-printed support platform, with one end fixed and the sensing end free to respond to applied loads. To isolate the load cell from non-normal forces, a pulley-based system was selected over alternatives such as linear rails and hinged arms; a mass basket is suspended from a rope routed over a 3D-printed pulley mounted on an 8 mm shoulder screw, ensuring that only tensile force aligned with gravity is transmitted to the load cell. The mass basket incorporates a circular retaining wall and four attachment points to maintain stability and prevent tipping under off-center loads, and the entire assembly was clamped to the table to eliminate motion and ensure accurate force measurement.
# Engineering and Design

## Electrical Design:
The load cell was wired directly to an HX711 amplifier module via soldered connections to minimize noise and signal loss. The HX711 communicates with an Arduino microcontroller, which processes the amplified signal. Two pushbuttons mounted on a breadboard provide user input for tare and unit conversion. Measured values are output to the serial monitor.

