---
date: 2025-11-17
academic_level: "College"
academic_period: "Sophomore Fall"

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
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Sus%20full%20edit.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Kinematics1.png" height="400"%}
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
Assuming a massless suspension, we established a system of 9 static equilibrium equations based on the sum of forces and moments for the disassembled components (shock mount, upper control arm, and pushrod). We specifically solved for the normal reaction force N acting on the pushrod to calculate the effective wheel rate.

<small><em>FBDs of disassembled suspension components. Where $N$ is the normal reaction force on the pushrod, and $F_s$ is the force from the shock absorber.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/FBD.png" height="400"%}
</div>

Sum of forces and moments in the shock mount:

$$\sum F_x = F_s cos\theta_5 +C_x -B_x = 0$$

$$\sum F_y = F_s sin\theta_5 +C_y -B_y = 0$$

$$\sum M_C = l_5F_s sin (\theta_5 - \theta_4) - l_3 B_y cos\theta_3 +L_3B_x sin\theta_3 = 0$$

Sum of forces and moments in the upper control arm ($l_1$):

$$\sum F_x = O_x + A_x =0$$

$$\sum F_y = O_y + A_y =0$$

$$\sum M_O = -l_1 A_x sin\theta_1 + l_1 A_y cos\theta_1 =0$$

Sum of forces and moments in the pushrod ($l_2$):

$$\sum F_x = B_x - A_x =0$$

$$\sum F_y = B_y - A_y + N =0$$

$$\sum M_B = -l_2 B_x sin\theta_2 + l_2 B_y cos\theta_2 =0$$

<small><em>Code for solving the system of 9 equations for each linkage position.</em></small>

```py
# -----------------------------
# Solution arrays
n = len(th1_arr)

# Positions
Ax_arr, Ay_arr = np.zeros(n), np.zeros(n)
Bx_arr, By_arr = np.zeros(n), np.zeros(n)
Cx_arr, Cy_arr = np.zeros(n), np.zeros(n)
Ox_arr, Oy_arr = np.zeros(n), np.zeros(n)

# Normal force
N_arr = np.zeros(n)
# -----------------------------

def build_linear_system(th1, th2, th3, th4, th5, Fs):
    """
    Builds 9x9 linear system M*X = b for the linkage problem
    """
    M = np.zeros((9, 9))
    b = np.zeros(9)

    # Force components
    M[0, 2:6:3] = [-1, 1]  # Fx eq
    b[0] = -Fs * np.cos(np.radians(th5))

    M[1, 3:6:3] = [-1, 1]  # Fy eq
    b[1] = -Fs * np.sin(np.radians(th5))

    # Moment about link 3
    M[2, 2:4] = [l_3*np.sin(np.radians(th3)), -l_3*np.cos(np.radians(th3))]
    b[2] = -l_5 * Fs * np.sin(np.radians(th5 - th4))

    # Geometric constraints
    M[3, 0:4:2] = [-1, 1]
    b[3] = 0

    M[4, 1:6:3] = [-1, 1]
    M[4, 8] = 1
    b[4] = 0

    M[5, 2:4] = [-l_2*np.sin(np.radians(th2)), l_2*np.cos(np.radians(th2))]
    b[5] = 0

    M[6, [0, 6]] = [1, 1]
    b[6] = 0

    M[7, [1, 7]] = [1, 1]
    b[7] = 0

    # Link 1 moment
    M[8, 0:2] = [-l_1*np.sin(np.radians(th1)), l_1*np.cos(np.radians(th1))]
    b[8] = 0

    return M, b

# -----------------------------
# Solve system for each set of angles
for i in range(n):
    M, b = build_linear_system(th1_arr[i], th2_arr[i], th3_arr[i],
                               th4_arr[i], th5_arr[i], Fs[i])
    
    X = np.linalg.solve(M, b)

    # Unpack solution into arrays
    Ax_arr[i], Ay_arr[i], \
    Bx_arr[i], By_arr[i], \
    Cx_arr[i], Cy_arr[i], \
    Ox_arr[i], Oy_arr[i], \
    N_arr[i] = X
 ```
## Numerical Simulation
Since the suspension geometry changes with wheel displacement, the system does not obey a linear Hooke's Law ($F=ky$). Instead, we calculate the effective spring constant as the derivative of the vertical force ($N$) with respect to vertical displacement of the wheel ($dN/dy$).

<small><em>Normal reaction force $N$ on the pushrod and effective spring constant $k_{eff} = dN/dy$ as a function of wheel displacement.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/N%20Plot.png, https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Keff.png" height="400"%}
</div>

Knowing the effective spring constant as a function of wheel displacement, we can simulate the free oscillation of the car chassis as a mass-spring system using the ODE:

$$
m \frac{d^2 y}{dt^2} + c \frac{dy}{dt} + k_{\rm eff}(y) \, (y - y_{\rm eq}) = 0
$$

The initial conditions were determined from video analysis of the actual suspension oscillation:

$$
y(0) = -0.0233 \, \mathrm{m}, \quad
y'(0) = 0 \, \mathrm{m/s}, \quad
y_{\rm eq} = -0.0295 \, \mathrm{m}
$$

We numerically solved this ODE using Python's <span style="color: #333333; font-family: monospace;">solve_ivp</span> function. The mass and damping coefficient were tuned to best fit the experimental data, resulting in:

$$
m = 1000 \, \mathrm{kg}, \quad
c = 4000 \, \mathrm{N \cdot s/m}
$$

<small><em>Code for numerically solving the effective spring constant and ODE.</em></small>

```py
# -----------------------------
# y coordinate (vertical position of point A)
# -----------------------------
y = A[:, 1]
y = y - y[0]

# -----------------------------
# Direct stiffness: dN/dy
# -----------------------------
k_eff = np.gradient(N_arr, y)
k_interp = interp1d(y, k_eff, fill_value="extrapolate")

# ---- Simulation parameters ----
m = 1000 #66.904875    # sprung mass [kg]
c = 4000       # damping [N·s/m] (lower for visible oscillation)
x_init = -0.023394191990219634   # Positive is downward from equilibrium
x_eq = -0.0295  # equilibrium position
v_init = 0.0    # small initial velocity optional
t_final = 3    # seconds
dt = 0.001

# ---- Nonlinear spring-mass-damper ODE ----
def spring_mass(t, state, m, c):
    x, v = state
    k_local = k_interp(x)        # wheel-rate at current displacement
    F_ext = 0.0                  # no external force
    F_spring = k_local * (x - x_eq) # spring force relative to equilibrium position
    a = (F_ext - c*v - F_spring) / m
    return [v, a]

# ---- Solve ODE ----
t_eval = np.arange(0, t_final, dt)
ic = [x_init, v_init]
sol = solve_ivp(spring_mass, [0, t_final], ic, args=(m, c), t_eval=t_eval, rtol=1e-6, atol=1e-8)
 ```

<small><em>The simulation models the vertical displacement of the car chassis ($y$) over time.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Simulation.png" height="400"%}
</div>

<small><em>Comparison of simulated and experimental suspension oscillation.</em></small>
<div style="width: fit-content; margin: 0 auto;">
{% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/zeshui-song.github.io/refs/heads/main/_projects/FSAE%20Suspension%20Modeling/Validation.png" height="400"%}
</div>

<small><em>Ground truth video showing shock absorbers decompressing and oscillating after the applied load is removed.</em></small>
<div style="display: flex; justify-content: center; align-items: flex-start; gap: 20px; height: 500px; width: 100%;">
  <div class="youtube-wrapper" style="flex: 0 0 auto; width: fit-content; height: 100%;">
    {% include youtube-video.html 
        id="Dv6SuCOE8nw" 
        format="normal" 
        autoplay="true"
        loop="true"
    %}
  </div>  
</div>

# Conclusion
The simulation successfully modeled the exponential decay of the suspension's amplitude. By mapping the simulated chassis displacement $y(t)$ back to the equivalent spring displacement, we validated the model against experimental video tracking data. While the frequency matched, the simulation required a tuned mass of 1000 kg, roughly four times the actual car mass. This discrepancy suggests our simplified model overestimated the real suspension stiffness, likely due to neglected internal reaction forces from tires and the lower control arm.

# My Role and Reflections
I was mainly responsible for the simulation code, data analysis, and setting up the kinematics and statics equations. While we got a working simulation, we ran into many conceptual hurdles, particularly with determining how to determine the effect of the suspension linkage on the effective spring constant used to model the car as a spring mass system. Additionally, validating our results and analyzing the discrepancies in how we simplified the model proved to be more challenging than expected. Overall, thinking about engineering and modeling through these sanity checks really puts into perspective the reality of these physical behaviors.

## Extra
<small><em>Animation of suspension linkage motion, note that the actual range of motion is actually much smaller (10-12 deg) instead of the range shown (0-30 deg)</em></small>
<div style="width: fit-content; margin: 0 auto;">
  {% include image-gallery.html images="https://raw.githubusercontent.com/zeshui-song/LaTex/refs/heads/main/Fall%202025%20Notes/Dynamics/Project/four_bar_linkage_NEW.gif" height="500"%}
</div>

[Animation Code](https://github.com/zeshui-song/LaTex/blob/main/Fall%202025%20Notes/Dynamics/Project/gif%20export.ipynb)<br>
[Full Python Code](https://github.com/zeshui-song/zeshui-song.github.io/blob/main/_projects/FSAE%20Suspension%20Modeling/Suspension%20Simulation.ipynb)<br>
[Final Report](/_projects/FSAE%20Suspension%20Modeling/main.pdf)