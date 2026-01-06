---
order: 1
layout: post
title: "FSAE Suspension Dynamics Modeling"
description:  Characterized the dynamic response of the Cooper Union FSAE car’s front suspension by developing a four-bar linkage kinematic model and validating simulated free oscillation against experimental video tracking data.
skills:
- Kinematic Modeling
- 4-Bar Linkage Analysis
- Python (SciPy/solve_ivp)
- Static Equilibrium Analysis
- Video Tracking & Validation
main-image: \Suspension.png
---
**Team members:** Zeshui Song, Roy He, Ryan Lee<br>
**Course:** ME 200<br>
**Duration:** Nov-Dec 2025

---
# How it works
The project objective was to characterize the dynamic response of the Cooper Union FSAE car's front suspension. We modeled the system as a four-bar linkage consisting of the upper control arm, pushrod, and shock mount, with the chassis serving as the fixed ground link. By applying a geometric solution to the linkage kinematics and solving for rigid-body static equilibrium, we derived a nonlinear effective spring constant (k<sub>eff</sub>​). This variable stiffness was then integrated into a second-order ordinary differential equation (ODE) to simulate the car's free oscillation as a spring mass system after being released from a compressed state.

$$
\sigma = \frac{F}{A}
$$