
# 📘 Differential Equations

A **differential equation** is an equation involving an unknown function and its derivatives. These equations are fundamental in modeling physical phenomena such as:

- Fluid dynamics
- Electrical circuits
- Heat conduction
- Seismic activity
- Population changes

Solving a differential equation helps us gain insight into the behavior of these systems.

---

## 🧠 Basic Concepts

### 1. Order

The **order** of a differential equation is the highest derivative involved.

Examples:

- $$ y'' + 3y' - 2y = 0 \quad 	ext{(2nd order)} $$
- $$ y^{(4)} - x y' = \sin x \quad 	ext{(4th order)} $$
- $$ \left( \frac{dy}{dx} \right)^3 + y = 0 \quad 	ext{(1st order)} $$

---

### 2. Degree

The **degree** is the highest power of the highest derivative (only when in polynomial form).

Examples:

- $$ (y'')^2 + y = x \quad 	ext{(2nd degree)} $$
- $$ y' + x y = 0 \quad 	ext{(1st degree)} $$
- $$ \frac{dy}{dx} + \sqrt{y''} = 0 \quad 	ext{(undefined degree)} $$

---

### 3. Linear Differential Equation

A general linear form:

$$
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
$$

Examples:

- Linear: $$ y'' + 3y' + 2y = e^x $$
- Nonlinear: $$ (y')^2 + y = 0 $$

---

### 4. Homogeneous vs. Nonhomogeneous

Form:

$$
a_n y^{(n)} + \dots + a_0 y = g(x)
$$

- Homogeneous: $$ g(x) = 0 $$
- Nonhomogeneous: $$ g(x) \neq 0 $$

---

### 5. Separable Equation

$$
\frac{dy}{dx} = f(x) g(y)
$$

Rewritten as:

$$
\frac{1}{g(y)} dy = f(x) dx
$$

---

### 6. Exact Equation

Form:

$$
M(x, y) + N(x, y) y' = 0
$$

Condition for exactness:

$$
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
$$

---

### 7. Integrating Factor

Standard form:

$$
y' + P(x)y = Q(x)
$$

Integrating factor:

$$
\mu(x) = e^{\int P(x) dx}
$$

---

### 8. Homogeneous ODE (by variable type)

$$
\frac{dy}{dx} = F\left( \frac{y}{x} \right)
$$

Substitution:

$$
y = ux \Rightarrow y' = u + x \frac{du}{dx}
$$

---

### 9. Bernoulli Equation

$$
y' + P(x)y = Q(x)y^n
$$

Substitution:

$$
v = y^{1-n}
$$

---

### 10. General and Particular Solution

- **General solution** includes arbitrary constants.
- **Particular solution** is obtained when initial conditions are applied.

---

### 11. Reduction of Order

Typical substitutions:

- $$ v = y' $$
- $$ y = ux $$
- $$ v = \frac{y}{x} $$

---

### 12. Second-Order Linear Equation

General form:

$$
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
$$

---

### 13. Second-Order Homogeneous Equation

$$
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0
$$

General solution:

$$
y = C_1 y_1(x) + C_2 y_2(x)
$$

---

### 14. Constant Coefficient Second-Order Homogeneous Equation

$$
a y'' + b y' + c y = 0
$$

Characteristic equation:

$$
a r^2 + b r + c = 0
$$

#### Solutions:
- **Real, distinct roots**:
  $$ y = C_1 e^{r_1 x} + C_2 e^{r_2 x} $$
- **Repeated roots**:
  $$ y = (C_1 + C_2 x) e^{r x} $$
- **Complex roots**:
  $$ y = e^{\alpha x}(C_1 \cos(\beta x) + C_2 \sin(\beta x)) $$

---

### 📌 Note on Notation

- Prime notation: $$ y', y'', y^{(3)} $$
- Dot notation (if independent variable is time): $$ \dot{y}, \ddot{y}, \dddot{y} $$
- Parentheses in superscripts: $$ y^{(n)} $$ means the nth derivative, while $$ y^n $$ is a power.

---

> This file is LaTeX-enabled and optimized for platforms like Jupyter Notebook, Obsidian, or any renderer with MathJax support.
