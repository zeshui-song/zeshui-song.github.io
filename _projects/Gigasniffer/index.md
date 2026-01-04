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

---
## How it works
GigaSniffer is a sensor-based freshness indicator that evaluates produce condition by monitoring changes in CO₂ and ethanol concentrations within an enclosed chamber. By tracking deviations from baseline levels, the device categorizes produce as fresh, nearing spoilage, or spoiled.
## Engineering and Design

### Bio-inspiration:
- Modeled after fruit fly olfactory systems that respond to ethanol and CO₂ from decaying fruit.

### Hardware:
- CO₂ and ethanol gas sensors
- Arduino Mega (upgraded from Uno due to memory constraints)
- Laser-cut acrylic and wood enclosure for controlled sensing
- Integrated display for real-time feedback
{% include image-gallery.html images="Diagram.png" height="400" %}

### Software:
- Rolling-average algorithm using the 10 most recent samples to smooth noisy signals and minimize false positives and outliers
```c
// Update rolling buffer with latest readings
co2Readings[bufferIndex] = co2Value;
alcoholReadings[bufferIndex] = alcoholValue;
bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
```

- Threshold-based spoilage detection (25 ppm CO₂, 165 ppm ethanol)
- Drives RGB LED and graphical display to indicate freshness in real time
Uses a circular buffer of recent readings to compute rolling averages and smooth sensor noise.

<figure>
<pre><code class="language-python">
print("Hello, world!")
</code></pre>
<figcaption>
<span style="font-size: 10px;">Listing 1: Example Python code</span>
</figcaption>
</figure>



<br>

## Adding a hozontal line
---

## Starting a new line
leave two spaces "  " at the end or enter <br>

## Adding bold text
this is how you input **bold text**

## Adding italic text
Italicized text is the *cat's meow*.

## Adding ordered list
1. First item
2. Second item
3. Third item
4. Fourth item

## Adding unordered list
- First item
- Second item
- Third item
- Fourth item

## Adding code block
```ruby
def hello_world
  puts "Hello, World!"
end
```

```python
def start()
  print("time to start!")
```


## Adding table 

| Header 1 | Header 2 |
|----------|----------|
| Row 1, Col 1 | Row 1, Col 2 |
| Row 2, Col 1 | Row 2, Col 2 |

make sure to leave aline betwen the table and the header


