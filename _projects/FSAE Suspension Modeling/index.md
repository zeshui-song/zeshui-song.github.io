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
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Sus%20full.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Kinematics1.png" height="400"%}
</div>

To define the system geometrically, we first define the positions of the known pivots $A$ and $C$ and the vector $\vec{d}$ connecting them:

$$\begin{align*}
    \vec{A} &= \langle l_1 \cos \theta_1, l_1 \sin \theta_1 \rangle \\
    \vec{C} &= \langle 0, l_4 \rangle \\
    \vec{d} &= \vec{C} - \vec{A}, \quad d = \|\vec{d}\|
\end{align*}$$

We solve for point $B$ by viewing $\triangle ABC$ as two right triangles sharing a height $h$. The projection $a$ of link $l_2$ onto vector $\vec{d}$ and the orthogonal height $h$ are:

$$a = \frac{l_2^2 - l_3^2 + d^2}{2d}, \quad h = \sqrt{l_2^2 - a^2}$$

Point $B$ is located by traversing distance $a$ along the unit vector $\hat{d}$ and distance $h$ along the perpendicular vector $\hat{d}_\perp$:

$$\vec{B} = \vec{A} + a \hat{d} + h \hat{d}_\perp \quad \text{where} \quad \hat{d}_\perp = \left\langle -\frac{d_y}{d}, \frac{d_x}{d} \right\rangle$$

With coordinates for $A$, $B$, and $C$ known, vectors $\vec{l_2}$ and $\vec{l_3}$ are fully defined. Point $D$ is then found using the normal vector of $\vec{l_3}$ and using the length $l_5$. With points $D$ and $E$, we have fully defined the system and can find all the angles using trigonometry.

<small><em>Geometry of the linkage variables.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Geometry.png" height="400"%}
</div>

<small><em>Code for generating a complete array of point coordinates from a set of discrete angle inputs.</em></small>

```py
# Geometry Solver for Four-Bar Linkage
for i, t1 in enumerate(theta1):
A[i] = O + np.array([l_1*np.cos(t1), l_1*np.sin(t1)]) # Point A position
d = np.linalg.norm(C - A[i]) # Distance AC
        
# Using law of cosines to find intersection P and height h
a = (l_2**2 - l_3**2 + d**2) / (2*d)
h = np.sqrt(l_2**2 - a**2)
P = A[i] + a*(C - A[i]) / d

B[i,0] = P[0] + h*(C[1] - A[i,1]) / d # Point Bx
B[i,1] = P[1] - h*(C[0] - A[i,0]) / d # Point By
        
# Solve for Point D (perpendicular to link 3)
v3 = C - B[i]
n_hat = np.array([v3[1] / np.linalg.norm(v3), -v3[0] / np.linalg.norm(v3)])
D[i] = C + l_5 * n_hat
 ```

## Suspension Load Calculations
Assuming a massless suspension, static equilibrium equations were written for each link to solve for reaction forces. We specifically solved for the normal reaction force N acting on the pushrod to calculate the effective wheel rate.
