---
order: 1
layout: post
title: "Tow Tank (Work in Progress)"
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

<small><em>Mechanical diagram of the scale.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/HX711%20Scale/Mech.png" height="600"%}
</div>

# Engineering and Design

## Electrical Design:
The load cell was wired directly to an HX711 amplifier module via soldered connections to minimize noise and signal loss. The HX711 communicates with an Arduino microcontroller, which processes the amplified signal. Two push buttons mounted on a breadboard provide user input for tare and unit conversion. Measured values are output to the serial monitor.

<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/HX711%20Scale/Electrical.png" height="300"%}
</div>

## Algorithm Design:
The system reads raw load cell data through the HX711, applies calibration factors, and computes mass values in grams or ounces depending on the selected mode. The tare button zeros the scale by storing the current reading as an offset, while the unit-conversion button toggles between measurement units. Measurements are continuously updated and displayed in real time.

<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/HX711%20Scale/Algorithm.png" height="600"%}
</div>

# Results
Across the tested range of 2 g to 2000 g, the scale demonstrated excellent linearity and repeatability. The measured mass closely matched the actual mass, with a linear fit slope of 0.9988 and an R² value of 1.0, indicating near-ideal proportional response. Repeatability testing using a 100 g mass yielded a standard deviation of 0.2614 g over 44 measurements taken at 2-second intervals, confirming stable and consistent performance.
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/HX711%20Scale/Data.png" height="400"%}
</div>

# My Role and Reflections
Overall, this was a rather simple and straightforward project. However, figuring out the validity of our data was interesting, since we only had enough time to calibrate our scale a limited number of times and temperature variations tended to affect the load cell output. As a result, determining our confidence level could only be done through statistical analysis using a decently large dataset.
<div style="display: flex; justify-content: center; align-items: flex-start; gap: 20px; height: 500px; width: 100%;">
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content; height: 100%;">
    {% include youtube-video.html 
        id="PGNhLCem6JA" 
        format="normal" 
        autoplay="false"
        loop="false"
    %}
  </div>  
</div>

[Arduino Code](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/HX711%20Scale/Scale%20Code.ino)<br>
[Final Report](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/HX711%20Scale/Measurements%20Lab%20Final%20Report.pdf)<br>
[Onshape CAD](https://cad.onshape.com/documents/879e940bb85becdcbd9707af/w/ac66949ea51a3570c61e25d7/e/4072b7e2dbef1a2713dcaf1b?renderMode=0&uiState=695c722bf032d6fc4be294bb)