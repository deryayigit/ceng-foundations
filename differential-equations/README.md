# Differential Equations

A differential equation is an equation involving an unknown function and its derivatives.

Understanding differential equations is essential for analyzing many types of problems such as fluid motion, electric current in circuits, heat transfer in solid objects, detection of seismic waves, population growth or decline, and many similar natural phenomena.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to gain insight into these models. Understanding a complex natural process often requires reducing it to its simplest form. Hence, to comprehend the equations that describe these models and their solutions, one must first be familiar with simpler cases.

An ordinary differential equation (ODE) involves a function with only one independent variable. If the unknown function depends on two or more independent variables, the equation is called a partial differential equation (PDE).

---

## Notation

The expressions \( y', y'', y''', y^{(4)}, \ldots, y^{(n)} \) represent the first, second, third, fourth, …, nth derivatives of \( y \) with respect to the independent variable.

- \( y'' \) means \( \frac{d^2y}{dx^2} \) when the independent variable is \( x \), but \( \frac{d^2y}{dp^2} \) when the variable is \( p \).
- Parentheses in \( y^{(n)} \) distinguish it from the nth power \( y^n \).
- If the independent variable is time \( t \), primes are replaced by dots:  
  \( \dot{y}, \ddot{y}, \dddot{y} \) represent \( \frac{dy}{dt}, \frac{d^2y}{dt^2}, \frac{d^3y}{dt^3} \)

---

## History of Differential Equations

The study of differential equations began in the 17th century with **Isaac Newton** and **Gottfried Wilhelm Leibniz**.

- Newton classified first-order equations and developed series solution methods.
- Leibniz introduced derivative and integral notation and the method of separation of variables.
- **The Bernoulli family** applied new methods to fluid mechanics.
- **Euler** contributed integrating factors, general solutions, and numerical methods.
- **Lagrange** improved the structure of higher-order solutions.
- **Laplace** introduced equations and transforms central to physics.

In the 19th century, **existence and uniqueness theorems** were formalized. In the 20th century, **numerical analysis** and **computers** advanced the study of nonlinear systems. Today, **geometric and topological methods** offer deeper insights.

**Summary**: From Newton and Leibniz to modern computation, differential equations have evolved into powerful tools in science and engineering.

---

## 🔢 Fundamental Concepts in Differential Equations

### 1. Order

The **order** of a differential equation is the order of the highest derivative.

**Examples:**

- \( y'' + 3y' - 2y = 0 \) → 2nd order  
- \( y^{(4)} - x y' = \sin x \) → 4th order  
- \( \left( \frac{dy}{dx} \right)^3 + y = 0 \) → 1st order  

---

### 2. Degree

The **degree** is the exponent of the highest order derivative, **if** the equation is polynomial in derivatives.

**Examples:**

- \( (y'')^2 + y = x \) → 2nd degree  
- \( y' + xy = 0 \) → 1st degree  
- \( \frac{dy}{dx} + \sqrt{y''} = 0 \) → undefined degree  

---

### 3. Linear Differential Equation

**General form:**

\[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
\]

**Linearity Conditions:**

- \( y \) and its derivatives appear to the first power  
- No product of \( y \) terms or derivatives  
- Not inside log, trig, root, etc.

**Examples:**

- ✅ Linear: \( y'' + 3y' + 2y = e^x \)  
- ❌ Nonlinear: \( (y')^2 + y = 0 \)

---


---

## 4. Linear – Homogeneous / Non-Homogeneous

**Form:**

\[
a_n y^{(n)} + \dots + a_0 y = g(x)
\]

- Homogeneous: \( g(x) = 0 \)  
- Non-homogeneous: \( g(x) \neq 0 \)  

---

## 5. Separable Equation

\[
\frac{dy}{dx} = f(x) g(y)
\]

Can be rearranged as:

\[
\frac{1}{g(y)} dy = f(x) dx
\]

---

## 6. Exact Equation

**Form:**

\[
M(x,y) + N(x,y) y' = 0
\]

**Condition:**

\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]

If satisfied, a potential function \( \Phi(x,y) \) exists.

---

## 7. Integrating Factor

For linear first-order:  
\[
y' + P(x) y = Q(x)
\]

**Integrating factor:**

\[
\mu(x) = e^{\int P(x)\, dx}
\]

---

## 8. Homogeneous ODE

\[
\frac{dy}{dx} = F\left( \frac{y}{x} \right)
\]

**Substitution:**

- Let \( y = ux \), then \( y' = u + x u' \)

Reduces to separable form.

---

## 9. Bernoulli Equation

\[
y' + P(x) y = Q(x) y^n
\]

**Transformation:**

- Let \( v = y^{1-n} \)

Reduces to linear equation.

---

## 10. General and Particular Solution

- **General Solution**: Includes arbitrary constants.  
- **Particular Solution**: Found by applying initial conditions.

---

## 11. Reduction of Order – Substitution Techniques

Useful for simplifying higher-order ODEs.

**Common substitutions:**

- \( v = y' \)  
- \( y = ux \)  
- \( v = \frac{y}{x} \)  

---

## 12. Second-Order Linear Equation

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
\]

---

## 13. Second-Order Linear Homogeneous Equation

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0
\]

**General solution:**

\[
y = C_1 y_1(x) + C_2 y_2(x)
\]

---

## 14. Second-Order Constant Coefficient Linear Homogeneous Equation

\[
a y'' + b y' + c y = 0
\]

**Characteristic equation:**

\[
ar^2 + br + c = 0
\]

### Solutions:

- **Real distinct roots** \( r_1, r_2 \):  
  \( y = C_1 e^{r_1 x} + C_2 e^{r_2 x} \)

- **Repeated root** \( r \):  
  \( y = (C_1 + C_2 x) e^{rx} \)

- **Complex roots** \( \alpha \pm \beta i \):  
  \( y = e^{\alpha x} \left( C_1 \cos(\beta x) + C_2 \sin(\beta x) \right) \)

---
---

## References

[1] R. Bronson and G. Costa, *Schaum's Outline of Differential Equations*, 4th ed. New York, NY: McGraw-Hill, 2010.

[2] C. H. Edwards and D. E. Penney, *Differential Equations and Boundary Value Problems: Computing and Modeling*, 5th ed. Boston, MA: Pearson, 2014.

