# Differential Equations

A **differential equation** is an equation involving an unknown function and its derivatives.

Differential equations model various real-world phenomena such as:

- fluid flow  
- electric circuits  
- heat transfer  
- seismic activity  
- population dynamics  
- and more.

---

## Notation

- \( y' \), \( y'' \), \( y''' \), \( y^{(4)} \), ..., \( y^{(n)} \): nth derivative of \( y \)
- \( \dot{y} = \frac{dy}{dt} \), \( \ddot{y} = \frac{d^2y}{dt^2} \), \( \dddot{y} = \frac{d^3y}{dt^3} \): derivatives w.r.t. time
- \( \frac{dy}{dx} \): derivative of \( y \) w.r.t. \( x \)

---

# Fundamental Concepts

## 1. Order

The order of a differential equation is the highest derivative present.

**Examples:**

- \( y'' + 3y' - 2y = 0 \) → 2nd order  
- \( y^{(4)} - x y' = \sin x \) → 4th order  
- \( \left( \frac{dy}{dx} \right)^3 + y = 0 \) → 1st order  

---

## 2. Degree

The degree is the power of the highest derivative (only defined if polynomial in derivatives).

**Examples:**

- \( (y'')^2 + y = x \) → 2nd degree  
- \( y' + xy = 0 \) → 1st degree  
- \( \frac{dy}{dx} + \sqrt{y''} = 0 \) → undefined  

---

## 3. Linear Differential Equation

A linear differential equation has the form:

\[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
\]

- **Linear example:** \( y'' + 3y' + 2y = e^x \)  
- **Nonlinear example:** \( (y')^2 + y = 0 \)

---

## 4. Homogeneous vs. Non-Homogeneous

- **Homogeneous:** \( g(x) = 0 \)
- **Non-Homogeneous:** \( g(x) \ne 0 \)

\[
a_n y^{(n)} + \dots + a_0 y = g(x)
\]

---

## 5. Separable Equation

\[
\frac{dy}{dx} = f(x)g(y) \quad \Rightarrow \quad \frac{1}{g(y)}dy = f(x)dx
\]

---

## 6. Exact Equation

\[
M(x, y) + N(x, y)\frac{dy}{dx} = 0
\]

It is **exact** if:

\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]

Then, a potential function \( \Phi(x, y) \) exists.

---

## 7. Integrating Factor

For linear 1st-order:

\[
y' + P(x)y = Q(x)
\Rightarrow \mu(x) = e^{\int P(x)dx}
\]

---

## 8. Homogeneous ODE (by substitution)

\[
\frac{dy}{dx} = F\left(\frac{y}{x}\right)
\quad \text{Use } y = ux, \quad \Rightarrow y' = u + x\frac{du}{dx}
\]

---

## 9. Bernoulli Equation

\[
y' + P(x)y = Q(x)y^n
\quad \text{Let } v = y^{1-n}
\]

---

## 10. General vs. Particular Solution

- **General solution:** contains constants (e.g., \( C_1, C_2 \))  
- **Particular solution:** satisfies initial condition(s)

---

## 11. Reduction of Order (Substitution Techniques)

Used for simplification:

- \( v = y' \)  
- \( y = ux \)  
- \( v = \frac{y}{x} \)

---

## 12. Second Order Linear Equation

\[
a_2(x)y'' + a_1(x)y' + a_0(x)y = g(x)
\]

---

## 13. Homogeneous 2nd-Order Linear Equation

\[
a_2(x)y'' + a_1(x)y' + a_0(x)y = 0
\Rightarrow y = C_1y_1(x) + C_2y_2(x)
\]

---

### 14. Constant Coefficient 2nd-Order Linear Equation

$$
ay'' + by' + cy = 0 \quad \text{Characteristic: } ar^2 + br + c = 0
$$

**Case 1: Distinct Real Roots**

$$
y = C_1 e^{r_1 x} + C_2 e^{r_2 x}
$$

**Case 2: Repeated Roots**

$$
y = (C_1 + C_2 x)e^{r x}
$$

**Case 3: Complex Roots**

$$
y = e^{\alpha x} \left( C_1 \cos(\beta x) + C_2 \sin(\beta x) \right)
$$




