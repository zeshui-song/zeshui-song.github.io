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
main-image: /Sus.png
---
**Team members:** Zeshui Song, Roy He, Ryan Lee<br>
**Course:** ME 200<br>
**Duration:** Nov-Dec 2025

---
# How it works
The project objective was to characterize the dynamic response of the Cooper Union FSAE car's front suspension. We modeled the system as a four-bar linkage consisting of the upper control arm, pushrod, and shock mount, with the chassis serving as the fixed ground link. By applying a geometric solution to the linkage kinematics and solving for rigid-body static equilibrium, we derived a nonlinear effective spring constant (k<sub>eff</sub>​). This variable stiffness was then integrated into a second-order ordinary differential equation (ODE) to simulate the car's free oscillation as a spring mass system after being released from a compressed state.

# Modeling Approach

## Suspension Geometry & Kinematics
The front suspension was simplified to a planar four-bar linkage consisting of the upper control arm, pushrod, shock mount, and chassis ground. Rather than relying on vector loop equations, linkage positions were solved geometrically using circle–circle intersections, allowing the system configuration to be computed directly from an input arm angle. This approach simplified implementation while remaining numerically robust across the range of motion.

<small><em>Comparison of the full suspension system and a simplified four-bar linkage model. The model represents the suspension using the upper control arm ( $l_1$ ), pushrod ( $l_2$ ), and shock mount ( $l_3$ and $l_5$ ), with the chassis ( $l_4$ ) acting as the fixed ground link.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Initial.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/Mechanical%20Motion%20Rectifier/Initial1.png" height="200"%}
</div>

$$
\sigma = \frac{F}{A}
$$