# Differential Equations

A **differential equation** is an equation involving an unknown function and its derivatives.

Understanding differential equations is crucial for analyzing many types of phenomena such as fluid flow, electric currents in circuits, heat transfer in solids, seismic wave propagation, population dynamics, and many other natural processes.

Differential equations serve as mathematical models of physical processes. The main purpose of solving them is to gain insight into the system being modeled. Understanding complex processes often starts with simplifying them, and that begins with simpler cases.

An **ordinary differential equation (ODE)** involves a function with only one independent variable. If the function depends on multiple variables, it's called a **partial differential equation (PDE)**.

The **order** of a differential equation refers to the highest derivative involved.

---

# Notation

The expressions \( y' \), \( y'' \), \( y''' \), \( y^{(4)} \), …, \( y^{(n)} \) represent the 1st, 2nd, 3rd, 4th, …, nth derivatives of \( y \) with respect to its independent variable.

For example:
- \( y'' = \frac{d^2y}{dx^2} \) when the variable is \( x \)
- \( y'' = \frac{d^2y}{dp^2} \) when the variable is \( p \)

When the variable is time \( t \), prime notation is replaced with dots:
- \( \dot{y} = \frac{dy}{dt} \), \( \ddot{y} = \frac{d^2y}{dt^2} \), \( \dddot{y} = \frac{d^3y}{dt^3} \)

---

# History of Differential Equations

Differential equations began in the 17th century with **Isaac Newton** and **Gottfried Wilhelm Leibniz**. Newton developed classification of first-order equations and series solutions. Leibniz introduced the notation for derivatives and integrals and the method of separation of variables.

**The Bernoulli family** applied and expanded the theory in fluid mechanics. **Euler** contributed integrating factors, general linear solutions, and numerical methods. **Lagrange** enhanced the theoretical foundation, and **Laplace** introduced equations central to physics.

By the 19th century, existence and uniqueness theorems were formalized. In the 20th century, numerical methods and computers allowed the study of nonlinear systems. Today, geometry and topology give qualitative insights.

---

# Fundamental Concepts in Differential Equations

## 1. Order

The **order** is the highest derivative appearing in the equation.

**Examples:**

- \( y'' + 3y' - 2y = 0 \) → 2nd order  
- \( y^{(4)} - x y' = \sin x \) → 4th order  
- \( \left( \frac{dy}{dx} \right)^3 + y = 0 \) → 1st order  

---

## 2. Degree

The **degree** is the power of the highest derivative (only defined when the equation is polynomial in derivatives).

**Examples:**

- \( (y'')^2 + y = x \) → 2nd degree  
- \( y' + xy = 0 \) → 1st degree  
- \( \frac{dy}{dx} + \sqrt{y''} = 0 \) → degree undefined  

---

## 3. Linear Differential Equation

General form:

\[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
\]

**Conditions for linearity:**
- \( y \) and its derivatives appear only to the first power
- No products of \( y \), \( y' \), \( y'' \), etc.
- No \( \log(y) \), \( \sqrt{y} \), \( \sin(y') \), etc.

**Examples:**

- Linear: \( y'' + 3y' + 2y = e^x \)  
- Nonlinear: \( (y')^2 + y = 0 \)

---

## 4. Homogeneous vs. Non-Homogeneous Linear Equations

\[
a_n y^{(n)} + \dots + a_0 y = g(x)
\]

- Homogeneous if \( g(x) = 0 \)  
- Non-homogeneous if \( g(x) \neq 0 \)

---

## 5. Separable Equation

\[
\frac{dy}{dx} = f(x) g(y) \quad \Rightarrow \quad \frac{1}{g(y)} dy = f(x) dx
\]

---

## 6. Exact Equation

Form:

\[
M(x,y) + N(x,y) \frac{dy}{dx} = 0
\]

**Exactness condition:**

\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]

If true, a potential function \( \Phi(x, y) \) exists such that \( \nabla \Phi = (M, N) \)

---

## 7. Integrating Factor

Used for solving linear 1st-order equations:

\[
y' + P(x)y = Q(x) \quad \Rightarrow \quad \mu(x) = e^{\int P(x) dx}
\]

---

## 8. Homogeneous Equation (in the ODE sense)

\[
\frac{dy}{dx} = F\left( \frac{y}{x} \right)
\Rightarrow y = ux, \quad y' = u + x \frac{du}{dx}
\]

---

## 9. Bernoulli Equation

\[
y' + P(x)y = Q(x)y^n \quad \Rightarrow \quad v = y^{1-n}
\]

---

## 14. General and Particular Solutions

- **General solution** contains arbitrary constants  
- **Particular solution** is obtained by applying initial/boundary conditions

---

## 15. Reduction of Order (Substitution Techniques)

Common substitutions:

\[
v = y', \quad y = ux, \quad v = \frac{y}{x}
\]

---

## 16. 2nd-Order Linear Equation

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
\]

---

## 17. 2nd-Order Homogeneous Equation

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0 \quad \Rightarrow \quad y = C_1 y_1(x) + C_2 y_2(x)
\]

---

## 18. Constant-Coefficient 2nd-Order Linear Homogeneous Equation

\[
ay'' + by' + cy = 0
\Rightarrow ar^2 + br + c = 0
\]

### Solution Types:

- **Distinct real roots:**  
  \[
  y = C_1 e^{r_1 x} + C_2 e^{r_2 x}
  \]

- **Repeated root:**  
  \[
  y = (C_1 + C_2 x)e^{r x}
  \]

- **Complex roots:**  
  \[
  y = e^{\alpha x} \left( C_1 \cos(\beta x) + C_2 \sin(\beta x) \right)
  \]
