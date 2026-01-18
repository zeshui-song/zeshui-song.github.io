---
featured: "true"
date: 2020-06-20
academic_level: "High School"
academic_period: "Freshman"

project_logo: "_projects/Solar Car/logooo.png"

layout: post
title: "BTHS Solar Car Team"
description: >
  Over the course of my freshman year, I led the formation of a student-run solar car program, coordinating a team of 30+ members across mechanical, electrical, programming, and operations divisions. The work focused on translating high-level competition requirements into viable engineering systems, building external industry and nonprofit partnerships, and developing internal structures for peer-led technical learning. As a team, we secured over $30,000 in technical sponsorships and established a 501(c)(3) partnership to support long-term funding and operations.
skills: 
  - Project Management & Leadership
  - CAD (Autodesk Inventor)
  - CFD analysis
  - Technical Documentation
  - Mechanical Evaluation
  - Systems Integration
  - Sponsorship Outreach
  - Resource Acquisition

main-image: /Team - Copy.png
---
**Core Team Members:** Zeshui Song (Founder/Team Captain), Simon Gura (Operations Lead), Jacob Koziej (Technical Lead)<br>
**Duration:** June 2020 - July 2021

---
# Project Overview
In June 2020, I founded the first-ever Solar Car Team at Brooklyn Technical High School during the height of the COVID-19 pandemic. The goal was to build a multidisciplinary, student-led engineering organization capable of designing and eventually racing a road-legal solar electric vehicle in the <a href="https://www.solarcarchallenge.org/challenge/" target="_blank">Solar Car Challenge</a>, while using the project as a opportunity to gain hands-on experience and knowledge in engineering.

<small><em>On alternating years, the Solar Car Challenge consists of a lapped race around the Texas Motor Speedway or a cross-country race. Shown here is the 2025 group photo.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/scc2025_orig.jpg" height="500"%}
</div>

Starting as an incoming freshman without access to school facilities, I led the formation of a 36-member, student-run engineering team organized into four technical and operational divisions: Mechanical, Electrical, Programming (Telemetry), and Operations. We established a strategic partnership with the Staten Island Green Technology Club (501(c)(3)) and built a robust technical advisory network by securing mentorship from collegiate solar car teams at MIT, the University of Toronto, the University of Michigan, and the University of Illinois, as well as seeking advice from other high school teams, including Staten Island Solar and Okemos, to guide engineering decisions and systems design.
<br><br>
As Team Captain, I was responsible for coordinating work across mechanical, electrical, and software subteams while contributing directly to design and iterative development throughout the project. I participated hands-on in CAD development, simulation, electrical system planning, and telemetry system planning, while leading design reviews and guiding system-level integration decisions. This role required balancing technical trade-offs across disciplines, aligning team efforts with competition requirements, and developing broad working knowledge across systems to understand the bigger picture and ensure cohesive vehicle integration.

# Team & Division Structure
To manage complexity and enable parallel progress, the team was reorganized into four semi-autonomous divisions, each led by student division heads and coordinated through weekly executive meetings.
<br><br>
**Mechanical:** Chassis, suspension, aerodynamics, and structural safety
<br><br>
**Electrical:** Battery pack, solar array, motor selection, and power systems
<br><br>
**Programming:** Data acquisition, telemetry architecture, storage, and UI
<br><br>
**Operations:** Fundraising, logistics, branding, and sponsorship management

---

# Mechanical Division
The mechanical division focused on deepening our understanding of solar car design and developing components such as the aero-shell, tube frame chassis, and battery cooling systems, drawing primary inspiration from Kogakuin University's 2017 solar car.

<small><em>Kogakuin University's 2017 solar car, named Wing. Images from <a href="https://www.kogakuin.ac.jp/solar/cars.html" target="_blank">Kogakuin University</a> </em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Kogakuin.jpg, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Kogakuin1.jpg" height="300"%}
</div>

## Aerodynamic Shell (Aero-shell) Design
We wanted our design to prioritize maximizing solar array area while maintaining aerodynamic stability within regulations. Two design directions were considered: a bullet design based on the University of Michigan’s 2017 solar car, Novum, and Kogakuin University’s 2017 solar car. Through a team-wide debate, we decided that although the bullet design offered strong aerodynamic performance, it constrained array dimensions, requiring us to be highly efficient with energy losses, and expanding it would have negated its aerodynamic advantages. We ultimately based the design on the Kogakuin architecture, which allowed us to fully maximize array area while allowing us greater flexibility with chassis and suspension design.

<small><em>University of Michigan's 2017 solar car, Novum. Images from <a href="https://www.flickr.com/people/umsolar/" target="_blank">University of Michigan</a> </em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Mich.jpg, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Mich1.jpg" height="300"%}
</div>

<small><em>First iteration of aero shell (by Stanley).</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Shell%201.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Shell%201.1.png" height="300"%}
</div>

<small><em>Next iteration of aero shell with CFD visualization.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/111.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Prius.gif" height="300"%}
</div>

## Vehicle Architecture
Following the Kogakuin design direction, we established a three-wheel configuration with two front wheels and one rear wheel, an overall length of approximately 3.5 m, and an overall width of about 1.0 m. Stability was prioritized through the largest feasible wheelbase and a 0.7 m track width. The vehicle uses 18-inch front wheels and a 17-inch rear driven motorcycle wheel to optimize the balance between rolling resistance and traction. The suspension system was designed with a double wishbone (double A-arm) front suspension and a swing arm rear suspension. A forward steering system was implemented with a steering radius adjustable via ball joint end rods, while braking is handled by hydraulic disc brakes mounted on the forward wheels. 

<small><em>Initial iterations of front suspension system.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Sus.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Suss.png" height="300"%}
</div>

<small><em>Initial iterations of rear suspension system.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Car.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Rear%20v1.png" height="300"%}
</div>

<small><em>Revisions to the first iteration of rear suspension (left) and next iteration (right).</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Rear%20edits%20to%20V1.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Rear%20V3.png" height="300"%}
</div>

<small><em>Initial concept of rear suspension joint.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Rear%20Joints.png" height="300"%}
</div>

<small><em>Initial visualization of front steering geometry.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Steering%201.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Steering.png" height="300"%}
</div>

<small><em>Initial visualization of brakes.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Brakes.png" height="300"%}
</div>


## Chassis and Roll Cage
The frame was designed to be safe and fully regulation-compliant, capable of passing the Advanced Division’s scrutineering requirements. Multiple tube-frame iterations were explored before converging on a simplified chromoly steel frame to optimize strength-to-weight ratio and weldability. In accordance with safety regulations, the roll cage was designed with a minimum outside diameter of 1.9 cm and maintained a 5 cm safety clearance envelope around the driver. The main roll bar was specified as a single-piece 5 cm diameter tube with a 1.0 mm wall thickness, welded directly to the frame.

<small><em>Iteration 1 (by Nikita): Preliminary full-scale draft that exposed major compliance issues, including a multi-piece welded roll bar instead of a single continuous tube, poorly defined driver space, and an undefined 5 cm safety envelope.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/V1.png" height="300"%}
</div>

<small><em>Iteration 2: Tube frame revision with a stabilized overall shape, but bulkhead dimensions remained overly wide, adding unnecessary mass and limiting driver-side entry; this prompted narrowing the track width toward 0.7 m.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/V2.png" height="300"%}
</div>

<small><em>Iteration 3: Frame layout adjusted to accommodate battery box and Omni Powertrain motor mounting points, with a simplified structure, uniform front driver compartment width, an overall length set to 3.5 m, and an enlarged rear compartment based on manufacturer CAD.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/V3.1.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/V3.png" height="300"%}
</div>

<small><em>Iteration 4: Simplified frame design to reduce weight and cost by removing redundant cross members identified through finite element analysis, improving structural efficiency without unnecessary complexity.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Final.png" height="300"%}
</div>

---

# Electrical Division
The electrical division focused on developing a first-generation, competition-ready electrical system covering the motor, battery, solar array, and supporting electronics. With limited access to hardware during the pandemic, the team focused on deciding how power would flow through the car, comparing and selecting key components, and planning how all parts would connect and fit together, using guidance from established solar car teams like MIT and the University of Toronto.

## System Voltage and Architecture
A foundational decision for the vehicle was the selection of a 96 V system targeting approximately 52 Ah, corresponding to a total energy capacity of roughly 5 kWh. University of Toronto confirmed that operating at this energy scale was feasible, and MIT shared that their current vehicle operates at a higher voltage of 120 V at a similar total energy capacity, reinforcing that higher-voltage architectures are viable but introduce additional insulation, safety, and compliance complexity. Given the team’s experience level and emphasis on reliability and safety, the 96 V configuration was selected.

## Motor Selection
The drivetrain architecture was defined around a single powered rear wheel in a three-wheel, rear-wheel-drive (RWD) configuration. This decision reduced both electrical and mechanical complexity and aligned with the team’s budget constraints. Industry-standard Mitsuba hub motors were identified as the performance benchmark in solar racing, but their cost, typically between $9,000 and $16,000, placed them beyond the team’s feasible budget. As a result, the team evaluated QS brushless DC hub motors as a lower-cost alternative commonly used by newer solar car teams.
<br><br>
In parallel, the team collaborated with Omni Powertrain to customize a Motor Generator Unit (MGU) and Motor Control Unit (MCU) based on the Magelec axial flux motor, tailored to our vehicle’s specific dynamics. The design targeted a 200 kg Gross Vehicle Weight and an optimized aerodynamic profile with a Coefficient of Drag of 0.15.
<br><br>
To ensure that the motor would perform under race conditions, we defined a target cruise speed of 49 mph and a maximum speed of 53 mph, with the ability to handle a 6% gradient. The electrical interface was designed for a 1:1 direct-drive axle ratio using 17-inch wheels (0.25m rolling radius). A critical part of this integration was matching the motor controller to our battery's voltage swing, specifically targeting a nominal 100.8V with an operating range between 75.6V and 117.6V. Additionally, we also ensured the hub motor was compatible with our rear suspension.

## Battery Pack Design
To optimize the weight-to-power ratio, we chose to design and build a custom DIY lithium-ion battery pack rather than purchasing a pre-made unit. Pre-made packs were rejected due to their excessive mass and rigid form factors that did not fit our streamlined chassis. The proposed configuration specified Panasonic NCR18650GA cells (3.6 V, 3500 mAh), with approximately 400 cells arranged to achieve a nominal 96 V, 52 Ah output. Design work focused on series–parallel configurations, battery enclosure geometry, and space allocation within the chassis. The team also began investigating spot-welding techniques, modular pack architectures, and battery safety practices. Commercial Battery Management Systems were evaluated, with Orion BMS identified as a strong candidate due to its CAN bus communication protocol, which allows compatibility with future telemetry integration. Thermal studies on the battery pack produced mixed results: while simulations ran successfully, temperatures were higher than desired, likely due to restricted airflow or incomplete data on the thermal output of individual cells.

<small><em>Battery pack schematic draft.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Battery%20Schem.png" height="300"%}
</div>

<small><em>Initial sketch for battery box placement and cooling system.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Initial%20cooling%20plan.png" height="300"%}
</div>

<small><em>Revised battery pack placement for lower center of mass and more compact.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Battery%20Placement.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/0.png" height="300"%}
</div>

<small><em>Revised battery pack cooling system, with side inlets and back exhaust.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Battery%20Box%20Ext.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Battery%20Box.png" height="300"%}
</div>

<small><em>Initial battery pack thermal simulations in SimScale showed that the pack center overheated tremendously, potentially due to incorrect fan speed or inaccurate cell thermal output inputs.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/Battery%20Sim.png" height="300"%}
</div>

## Solar Array
Solar array design focused on minimizing electrical losses and system mass while maintaining flexibility during early vehicle layout. We opted for Sunpower cells (sourced via SBM Solar), known for their high efficiency. To manage power conversion, we selected AERL RaceMax 600B Maximum Power Point Trackers (MPPTs). A key learning from our research was the necessity of these trackers to prevent the lowest-current cell bottleneck; without them, shaded panels could force the entire array output down to match the battery voltage, resulting in a loss of over 400 watts. To further reduce mass and resistance, we replaced standard MC4 connectors with direct soldered interconnects.

## Wiring Standards and Traceability
During technical scrutineering, every wire needed to be traceable from start to finish. To ensure this, we plan to document all electrical systems in KiCAD and adopt a standard wire color code: red for positive, black or blue for negative, and grey for ground.

---

# Programming Division
The programming division, led by Jacob, worked on building a system to track the car’s state of charge and performance in real-time. Our goal was to create a way for both the driver and the pit crew to see exactly what was happening with the sensors at any moment. Following the "UNIX philosophy," we designed the system to be broken into small, simple parts that talk to each other through standard inputs and outputs (STDOUT/STDIN). This makes it easy to add or remove sensors without breaking the whole setup.

## System Design and Scribby
Because we had limited access to hardware during the pandemic, we focused on the software side of how data would flow. We developed a central daemon called Scribby. Its job is to take raw data from the car's sensors, log it locally, and then format it into SQL tables so it can be sent to our remote database. By using an SSH tunnel over an LTE connection (SIM card) instead of just standard radio, we planned for a system that could handle connection drops more reliably. If the signal cuts out, the connection handler is designed to keep the data safe until the link is back up.

<small><em>High-Level Telemetry System Overview.</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/High%20Level%20Abstraction%20on%20Telemetry%20System.png" height="400"%}
</div>

## Sensors and Data Collection
We identified several key data points we wanted to collect to from the car during operation:

<small><em>Draft of sensor hardware and collected data</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Solar%20Car/telem.png" height="400"%}
</div>

In terms of microcontrollers, we planned to use Arduino Uno Rev3 for prototyping, and ATmega328P or ATtiny85 chips for the final versions to save space and power. Raspberry Pis will be used as the main computers (SBCs) to run the Linux environment.
<br><br>
<a href="https://github.com/bthssolar" target="_blank">BTHS Solar Car Github</a>

## Feedback from MIT and Toronto on Telemetry
Talking to teams like MIT and the University of Toronto helped us refine our plans for the telemetry system:
<br><br>
**MIT Feedback**

- **Design Philosophy:** Their core advice was "smaller, lighter, simpler" and focused on fixing everything that breaks.
- **Telemetry:** They warned against overdesigning and stated the system must be able to be debugged within 5 minutes.
- **Battery Management:** They recommended using an Orion BMS for safety-critical systems and ensuring the BMS uses EEPROM memory to retain the battery's state of charge.
- **Communication:** For data transmission, they utilize RFD900+ radios for their high 3–4 mile range.
- **Strategy:** They suggested experimentally finding the "energy neutral" optimal speed and monitoring weather conditions closely.

**University of Toronto Feedback**

- **Hardware Redundancy:** They emphasized implementing redundancy for the battery by monitoring currents and voltages at multiple points.
- **Critical Data Points:** The most important data to collect includes cell temperatures for safety, motor RPM for speed, and array gain/loss to understand power characteristics.
- **Mapping & Strategy:** They recommended using GPS coordinates combined with online resources to map out elevation data for the race route.
- **User Interface:** Their driver UI is streamlined to display only the most essential metrics: cell temperature, state of charge, and speed.

---

# Operations Division
The operations division, led by Simon, focused on securing the financial, institutional, and material resources necessary to transform the solar car project from a student concept into a fully funded racing team.

## Sponsorship Strategy and Structure

To incentivize corporate support, the operations team developed a structured, tiered sponsorship model:

- **Tiered Benefits:** Sponsorship levels were defined as Silver ($100–$499), Gold ($500–$999), Platinum ($1,000–$4,999), and Diamond ($5,000+).

- **Incentives:** Benefits offered to partners included tiered logo placement on the car shell, team uniforms, and the website, as well as custom laser-engraved sponsorship plaques.

- **Legal Framework:** The team established a 501(c)(3) tax-deductible status through a collaboration with the Staten Island Tech Green Technology Club and the BTHS Alumni Foundation, allowing for formal corporate donations.

## Fundraising and Institutional Support

A critical process for the division was securing official recognition and long-term funding within the Brooklyn Tech community:

- **Administrative Approval:** Operations successfully navigated the school’s club application process, securing Mr. David Adams as a faculty advisor and achieving official club status in October 2020.

- **Institutional Funding:** Through meetings with Principal David Newman and the BTHS Alumni Foundation, the team identified roughly $25,000 in potential support, including a $15,000 faculty grant and $10,000 in direct foundation funding.

- **Corporate Cash Sponsorship:** The team secured its first official cash sponsorship from Ponce Bank, which was processed through the Alumni Foundation.

## In-Kind Strategic Partnerships

Given the high cost of specialized solar car components, the operations team focused on securing "in-kind" donations of hardware and software:

- **Powertrain:** A major result was a partnership with Omni Powertrain to provide a custom-developed motor and prototype motor controller (valued at approximately $20,000) for free.

- **Composites:** The team secured over 100 yards of high-grade carbon fiber from manufacturers like Chomarat and Boston Materials, as well as honeycomb structures from Argosy International.

- **Design Software:** Altium provided the team with professional PCB design software and offered tours of their local facilities to bridge the technical gap for the electrical division.

## Branding and Public Relations

To maintain public engagement and transparency with sponsors, the division managed all external-facing materials:

- **Visual Identity:** A custom team logo was designed to emphasize technical precision, incorporating gear motifs and the "Btech" name to ensure memorability among sponsors.

- **Web Presence:** Operations launched the official team website (bthssolar.org) to host a "Meet the Team" page, project blogs, and documentation for potential recruiters.

- **Social Media:** The team implemented "Solar Sundays," a weekly Instagram campaign aimed at educating the student body and potential sponsors about renewable energy and the Solar Car Challenge.







---

# Education

---

# My Role and Reflections 
My primary responsibility was the founding and high-level management of the organization. I spent significant time learning advanced engineering topics independently so I could effectively teach and lead the team. A major turning point was transitioning from a centralized management style to a delegated leadership model, giving division leads autonomy over their technical domains. This allowed me to focus on overcoming massive administrative hurdles, such as a 10-month search for a teacher advisor. The project eventually faced insurmountable logistical constraints. Following the pandemic, my transition to homeschooling created a communication gap while the team returned to in-person instruction, significantly slowing progress. Furthermore, despite our success in securing thousands of dollars in sponsored materials, we lacked the physical space at the school to store components or begin full-scale fabrication. These challenges ultimately led to the project's conclusion after my sophomore year. This experience taught me that engineering success is not just about technical data, but also about managing the physical and logistical infrastructure required to bring a vision to life.