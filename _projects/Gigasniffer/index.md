---
layout: post
title: "GigaSniffer: Portable Produce Freshness Detector"
description:  New York City generates nearly 4 million tons of food waste annually, much of it edible at the time of disposal. A major contributor is uncertainty around food freshness, driven by unreliable expiration dates that fail to account for storage conditions. GigaSniffer is a portable device designed to reduce household food waste by detecting early-stage spoilage in produce through gas emissions rather than printed dates. Inspired by the way fruit flies detect rotting fruit through airborne chemicals, GigaSniffer measures carbon dioxide (CO₂) and ethanol emissions to infer freshness and alert users when produce is nearing spoilage.
skills: 
  - Arduino Programming
  - Gaseous Sensor Calibration
  - Multisensor Interfacing
  - Real-Time Sensor Data Visualization
  - Laser Cutting
  - Breadboard Prototyping

main-image: /IMG_20241219_132228564_HDR.jpg
---
**The Best Team Ever:** Allen Punnoose, Ahikara Sandrasagra, Christopher Sgambati, Somin Lee, Zehra Girgin, Zeshui Song<br>
**Course:** EID 101B<br>
**Duration:** Sep–Dec 2024

---
# How it works
GigaSniffer is a sensor-based freshness indicator that evaluates produce condition by monitoring changes in CO₂ and ethanol concentrations within an enclosed chamber. By tracking deviations from baseline levels, the device categorizes produce as fresh, nearing spoilage, or spoiled.
# Engineering and Design

## Bio-inspiration:
- Modeled after fruit fly olfactory systems that respond to ethanol and CO₂ from decaying fruit.

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
[Full Arduino Code](https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/main/_projects/Gigasniffer/Gigasniffer%20Code.ino)
# Data
The prototype was tested on pears, raspberries, and bananas over eight days, with daily measurements of CO₂ and ethanol. As the fruits decayed, the amount of CO₂ and ethanol generally increased. Thresholds of 25 ppm CO₂ and 165 ppm ethanol were set based on observed trends to indicate when produce was no longer fresh (based on visual inspection).
{% include image-gallery.html images="CO2.png, Ethanol.png" height="300" %}
# My role and reflections
In this project, I focused on developing both the hardware and software for the device, while my teammates conducted experiments and collected data. Overall, the final prototype successfully measured CO₂ and ethanol levels in correlation to fruit freshness. However, testing revealed the challenge of obtaining reliable data, requiring long exposure durations and careful interpretation of the multiple sensor outputs. Throughout the process, our team learned the importance of collaboration, iterative design, and extensive testing.
<div style="display: flex; justify-content: center;">
  {% include image-gallery.html images="Best team.jpg" height="300" %}
</div>
[Download Final Report](EID101B_Team4_FinalReport.pdf)
[Download Final Documentation](EID101B_Team4_FinalDocumentation.pdf)