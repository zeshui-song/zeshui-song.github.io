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
## Hardware:
- CO₂ and ethanol gas sensors
- Arduino Mega (upgraded from Uno due to memory constraints)
- Laser-cut acrylic and wood enclosure for controlled sensing
- Integrated display for real-time feedback
{% include image-gallery.html images="Diagram.png, Fruit Chamber.jpg" height="400" %}

## Software:
- Rolling-average algorithm using the 10 most recent samples to smooth noisy signals and minimize false positives and outliers

<small><em>Maintains a circular buffer of recent readings to compute rolling averages and smooth sensor noise.</em></small>
```c
// Update rolling buffer with latest readings
co2Readings[bufferIndex] = co2Value;
alcoholReadings[bufferIndex] = alcoholValue;
bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
```

- Threshold-based spoilage detection (25 ppm CO₂, 165 ppm ethanol)

<small><em>Triggers alerts only when recent readings deviate significantly from the rolling average, reducing false positives.</em></small>
```c
// Check for significant deviations and print alerts
float co2Difference = abs(co2Readings[lastIndex] - co2Average);
float alcoholDifference = abs(alcoholReadings[lastIndex] - alcoholAverage);

 if (co2Difference > CO2_DIFFERENCE_THRESHOLD) {
   Serial.print("Hi CO2: ");
   Serial.print(co2Readings[lastIndex]);
   Serial.print(" ppm\n");
}

if (alcoholDifference > ALCOHOL_DIFFERENCE_THRESHOLD) {
   Serial.print("Hi Alco: ");
   Serial.print(alcoholReadings[lastIndex]);
   Serial.print("\n");
}
```

<small><em>Implements a freshness classification algorithm using CO₂ and alcohol deviation thresholds, with CO₂ rising first as an early spoilage indicator </em></small>
```c
bool fresh = true; 
bool soon = true; 
bool rot = true; 
if(alcoholDifference > ALCOHOL_DIFFERENCE_THRESHOLD){
   fresh = false;  
   soon = false; 
   rot = true; 
}
else if((co2Difference > CO2_DIFFERENCE_THRESHOLD)&&(alcoholDifference < ALCOHOL_DIFFERENCE_THRESHOLD)){
   fresh = false;
   soon = true; 
   rot = false; 
}
else{ 
   fresh = true; 
   soon = false; 
   rot = false; 
}
```
- Provides real-time visual feedback via RGB LED and graphical display to indicate freshness in real time

```c
// Control the LED based on the state
if (rot) {
   display.setTextSize(4); 
   display.setCursor(10, 350);
   rgb.on(255, 0, 0); // Red for rotten
   display.setTextColor(RED); 
   Serial.println("Rotten: Red LED On");
   display.print("Rotten: Red LED On");
} 
else if (soon) {
   display.setTextSize(4); 
   display.setCursor(10, 300);
   rgb.on(255, 255, 0);
   display.setTextColor(YELLOW); 
   Serial.println("Soon: Yellow LED On");
   display.print("Soon: Yellow LED On");
} 
else if (fresh) {
   display.setTextSize(4); 
   display.setCursor(10, 300);
   rgb.on(0, 255, 0); // Green for fresh
   display.setTextColor(GREEN); 
   Serial.println("Fresh: Green LED On");
   display.print("Fresh: Green LED On");
} 
else {
   rgb.off();
}
```
[Full Arduino Code](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/Gigasniffer/Gigasniffer%20Code.ino) 
# Data
The prototype was tested on pears, raspberries, and bananas over eight days, with daily measurements of CO₂ and ethanol. As the fruits decayed, the amount of CO₂ and ethanol generally increased. Thresholds of 25 ppm CO₂ and 165 ppm ethanol were set based on observed trends to indicate when produce was no longer fresh (based on visual inspection).
{% include image-gallery.html images="CO2.png, Ethanol.png" height="300" %}
# My role and reflections
In this project, I focused on developing both the hardware and software for the device, while my teammates conducted experiments and collected data. Overall, the final prototype successfully measured CO₂ and ethanol levels in correlation to fruit freshness. However, testing revealed the challenge of obtaining reliable data, requiring long exposure durations and careful interpretation of the multiple sensor outputs. Throughout the process, our team learned the importance of collaboration, iterative design, and extensive testing.
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="Best team.jpg" height="300" %}
</div>
[Final Report](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/Gigasniffer/EID101B_Team4_FinalReport.pdf)<br>
[Final Documentation](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/Gigasniffer/EID101B_Team4_FinalDocumentation.pdf)