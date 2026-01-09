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
The mechanical system supports the water tank and provides smooth, guided vertical motion with minimal vibration. Several approaches for varying water level were evaluated, including using a DC motor–driven pump and physically translating the tank. It was determined that vertically actuating the tank allowed for better control over immersion rate and little to none disturbance of the water. The actuation system is mounted on an optical breadboard and constrained to vertical motion with 2 linear motion shafts. Most components were designed for 3D printing and assembled using heat-set inserts and interference fits. However, select parts will be replaced with 80/20 aluminum framing to improve stiffness and structural robustness.

<small><em>Preliminary mechanical design.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_research/Vertical%20Actuator%20Tank/Actuator.png" height="400"%}
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