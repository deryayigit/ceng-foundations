# Differential Equations

This repository was created to demonstrate why differential equations—one of the fundamental pillars of engineering—are essential, how they are classified, and how their solution methods can be implemented using programming languages.

In engineering, natural sciences, and even social sciences, many phenomena are modeled mathematically through **differential equations**.

Differential equations express numerous physical laws and relationships in mathematical form. They serve as the core model used when transitioning from a physical situation to a *mathematical model*. Any quantity in a system that changes over time velocity, temperature, current, voltage, population, position, energy, interaction, oscillation can only be described through derivatives and differential equations.
Thus, they are the fundamental tool for translating real-world problems into mathematics.

With these principles in mind, this repository explains differential equation types and provides their code implementations. 

This repository focuses on the solution of differential equations. In engineering applications, the solutions of such equations often cannot be obtained in closed form, which makes numerical methods the only practically viable approach. For this reason, the solutions of differential equations in this study are addressed through numerical methods in a way that can be computed in a computer environment.

## Why Numerical Methods Are Necessary

Computers do not solve integrals analytically, instead, they divide a given integral into small pieces by sampling the function at specific points and calculate the result approximately by summing the contributions of these pieces. In real-world systems, the goal is often to obtain a reliable and accurate numerical value for a specific input rather than a symbolic expression. Therefore, numerical methods such as the trapezoidal method, Simpson's method, and Runge–Kutta are used as fundamental tools that transform continuous mathematics into computable algorithms. These methods offer a controlled approximation rather than a ‘full solution,’ and accuracy can be systematically improved by increasing the number of steps or using higher-order methods. 

---
# Definition

A differential equation is any equation that contains derivatives—either ordinary derivatives or partial derivatives. Differential equations describe how a system changes with respect to a quantity such as time, position, temperature, or pressure, and they express the relationship between a function and its derivatives.

For example, the equation that relates an object's position to its velocity and acceleration is a differential equation.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to understand the behavior of a physical system through its mathematical model. Understanding complex natural processes often requires reducing them to simpler forms; thus, to comprehend these models and their solutions, one must first become familiar with simpler types of differential equations.

An ordinary differential equation (ODE) is a differential equation in which the unknown function depends on only one independent variable.
A partial differential equation (PDE) is used when the unknown function depends on two or more independent variables.

The order of a differential equation is the order of the highest derivative appearing in the equation.

---

# Notation

The expressions `y'`, `y''`, `y'''`, `y^(4)`, …, `y^(n)` are often used to represent, respectively, 
the first, second, third, fourth, …, nth derivatives of `y` with respect to the independent variable 
under consideration. 

Thus, `y''` represents `d^2y/dx^2` if the independent variable is `x`, but `d^2y/dp^2` if the independent 
variable is `p`. 

Parentheses in `y^(n)` are used to distinguish it from the nth power `y^n`.  

If the independent variable is time, usually denoted by `t`, primes are often replaced by dots.  
Thus, `ẏ`, `ÿ`, and `y⃛` represent `dy/dt`, `d^2y/dt^2`, and `d^3y/dt^3`, respectively.

---

### 🔹 Order of a Differential Equation

The **order** of a differential equation is the order of the **highest derivative** that appears in the equation.

## Examples

1. $y'' + 3y' - 2y = 0$  
  → **2nd order**

2. $y^{(4)} - x y' = \sin x$  
  → **4th order**

3. $\left( \dfrac{dy}{dx} \right)^3 + y = 0$  
  Highest derivative: $y'$  
  → **1st order**


---

### 🔹 Degree of a Differential Equation

The **degree** of a differential equation is the power (exponent) of the **highest-order derivative**, *provided that the equation is polynomial in its derivatives*.

#### Attention ❗

- If a derivative appears inside a **root**, **logarithm**, **exponential**, or **trigonometric** function,  
  → the **degree is undefined**.

- The degree is defined **only when the equation is polynomial in derivatives**.

## Examples

1. $(y'')^2 + y = x$  
   Highest derivative: $y''$, exponent $2$  
   → **2nd degree**

2. $y' + xy = 0$  
   Highest derivative exponent: $1$  
   → **1st degree**

3. $\dfrac{dy}{dx} + \sqrt{y''} = 0$  
   Since the derivative appears inside a square root  
   → **Degree is undefined**

---

# History of Differential Equations

The study of differential equations began in the seventeenth century with Isaac Newton and Gottfried Wilhelm Leibniz. Newton classified first-order equations and developed series methods for solutions, while Leibniz introduced the derivative and integral notation and the method of separation of variables.

The Bernoulli family expanded the field: Jakob and Johann contributed new methods and solved important problems such as the brachistochrone, while Daniel Bernoulli applied partial differential equations to fluid mechanics.

Leonhard Euler made fundamental contributions, including integrating factors, general solutions for linear equations with constant coefficients, and numerical methods. Joseph-Louis Lagrange advanced the theory with the variation of parameters method and showed how higher-order solutions are combinations of independent solutions. Pierre-Simon Laplace introduced equations central to mathematical physics and the Laplace transform.

In the nineteenth century, existence and uniqueness theorems were established, and partial differential equations became central to physics. In the twentieth century, numerical methods gained importance, and with the rise of computers, nonlinear systems could be studied more effectively. Modern approaches also include geometric and topological perspectives to understand the qualitative behavior of solutions.


### In Short

Differential equations began with Newton and Leibniz, were developed by the Bernoulli family, Euler, Lagrange, and Laplace, enriched in the nineteenth and twentieth centuries with theoretical and numerical methods, and in the modern era have reached far wider applications thanks to computers.

---
# Code Implementation

Programming languages solve differential equations by relying on the core mathematical operations involved in these equations—namely **derivatives** and **integrals**. To compute these operations numerically, various **Numerical Analysis Methods** are used. Simpson’s rule and Runge–Kutta methods are examples of these numerical techniques.

There are many libraries designed for solving differential equations, and they generally fall into two main categories:



## 1. Symbolic (Analytical) Solvers

Symbolic solvers attempt to analyze the structure of a differential equation and provide **closed-form (analytical)** solutions.

Examples include:  
- **SymPy (Python)**  
- **Maple**  
- **Mathematica (Wolfram)**  

However, all symbolic solvers have limitations. Even the most advanced systems clearly state that not every differential equation can be solved symbolically:

> “SymPy can only solve certain classes of ODEs. Not all ODEs are solvable symbolically.”  
> — *SymPy Documentation*

> “DSolve cannot find solutions for all differential equations.”  
> — *Mathematica Documentation*

> “The dsolve command can handle many ODEs, but not all.”  
> — *Maple Documentation*

Symbolic solvers cannot handle many nonlinear or complex differential equation types.



## 2. Numerical Solvers

Numerical solvers provide **approximate** solutions when an equation is given in the form.
These solvers do **not** classify the equation, interpret expressions, or determine the structure of the differential equation. They simply compute the numerical result based on the given function and initial conditions.

Examples include:  
- **SciPy.integrate (Python)**  
- **GSL – GNU Scientific Library (C)**  
- **SUNDIALS (C/C++)**  
- **Boost ODEINT (C++)**

Numerical solvers:  
- do not parse user-provided string equations,  
- do not determine the type of the differential equation,  
- do not produce closed-form solutions.  

They strictly generate numerical approximations.

### Proposed Approach

This project follows a **two-stage implementation strategy** for solving ordinary differential equations.

### 1. Python and C++ Based Analytical & Prototyping Stage

The application follows the workflow below:

This repository includes both Python and C++ implementations to demonstrate how the process of solving differential equations is handled at different levels of abstraction.

In the first stage, the user is assumed to know the type of the differential equation and provides inputs to the system accordingly. Based on the selected type, the required functions, coefficients, or initial conditions are obtained, and the equation is solved using an appropriate analytical or numerical method.

Python is used for prototyping solution algorithms, clearly expressing mathematical reasoning, and validating solution steps.

C++ implementations, on the other hand, emphasize low-level numerical computation and system-oriented design. This approach is chosen with performance-oriented and system-level scenarios in mind.

By implementing the same differential equation categories in both languages, this repository aims to demonstrate how numerical methods and solution strategies vary across abstraction levels, and how mathematical models are transformed into algorithms under different programming paradigms.

### 2. Parser-Based Numerical Solver (C++)

In the second stage, the system shifts to a more **automated and low-level approach**:

- The differential equation type is **detected automatically** from the user-provided equation.
- The equation is parsed syntactically using a **custom-written expression parser**.
- Solutions are obtained primarily through **numerical methods**, without relying on high-level symbolic libraries.


Overall, this repository serves as a comprehensive study intended to understand differential equation solution techniques from an engineering perspective and to develop their algorithmic counterparts.


---

# Types of Differential Equations & Solutions & Code Implementation

### 1) First-Order Differential Equations

#### 🔹1.1) Differential Equations Separable by Variables

**Definition:**

$$
y' = f(x, y)
$$

For a differential equation to be separable, f(x,y) must be expressible as a product
or ratio of a function of x and a function of y.

Possible Forms:

$$
f(x, y) = f(x)
$$

$$
f(x, y) = f(y)
$$

$$
f(x, y) = g(x)\.h(y)
$$

$$
f(x, y) = \frac{g(x)}{h(y)} = g(x)\.\frac{1}{h(y)}
$$

If the function f(x, y) can be written as the product of a function of \( x \) and a function of \( y \),
then the equation is called a **Differential Equation Separable by Variables**.

#### Solution Method:

$$
y' = g(x)\.h(y)
$$

1. The equation is rearranged:

$$
\frac{dy}{dx} = g(x)\.h(y)
$$

2. The terms involving x are collected on one side and the terms involving y on the other:

$$
\frac{1}{h(y)}\.dy = g(x)\.dx
$$

3. Integrate both sides:

$$
\int \frac{1}{h(y)}\.dy = \int g(x)\.dx
$$

4. General implicit solution:

$$
H(y) = G(x) + C
$$



#### 🔗 Code Implementation:
👉 [separable_ode](1.1_separable_ode.py)

---


### 🔹1.2) Homogeneous Differential Equations

**Definition:**

$$
y' = f(x, y)
$$

An equation of the above form that can be written in this way and satisfies the following condition for any real number 𝜆 is called a *Homogeneous Differential Equation*:

$$
f(x, y) = F\left(\frac{y}{x}\right)
$$

$$
f(\lambda x, \lambda y) = f(x, y)
$$


#### Solution Method: 

1. The transformation y = u(x) is performed.
NOTE: y = u(x).x, meaning u is a variable dependent on x.
   
$$
u = \frac{y}{x}
$$

$$
y = u(x)\.x
$$

2. Substitute these expressions into the differential equation:

$$
y' = f(x, ux) =u'(x)\.x + u(x)
$$

3. The expressions y = u.x and y' = x.(du/dx) + u are substituted into the equation y' = f(x, y), and the equation is transformed into separable form.

$$
y = ux \Rightarrow \frac{dy}{dx} = x\frac{du}{dx} + u
$$

4. The equation is solved to find u = u(x), and u = y/x is written.

#### 🔗 Code Implementation
👉 [homogeneous_ode](1.2_homogeneous_ode.py)

---

### 🔹1.3) Substitution Method

#### Definition:
$$
y' = f(x, y)
$$

If the equation can be written in the form:

$$
\frac{dy}{dx} = F(ax + by + c)
$$

then the substitution

$$
u = ax + by + c
$$

is applied.

Differentiate both sides with respect to \( x \):

$$
\frac{du}{dx} = a + b\frac{dy}{dx}
$$

Thus we get:

$$
u' = a + b\.y'
$$


$$
\frac{du}{dx} = a + b\frac{dy}{dx}
$$

Isolate the derivative:

$$
\frac{dy}{dx} = \frac{1}{b}\left( \frac{du}{dx} - a \right)
$$

This substitution transforms the original equation into a new equation involving only \( u \) and \( x \), which is usually separable.



### 🔗 Code Implementation
👉 

---

#### 🔹1.4) Exact Differential Equations


#### 🔗 Code Implementation
👉 
---

#### 🔹1.5) Linear Differential Equations

**Definition:**
A first-order differential equation is **linear** if it can be written in the form:

$$
y' + p(x)\.y = q(x)
$$

The process begins by finding p(x) and q(x) from this equation.

*The Integral Multiplier (Integrating Factor) is:*

$$
\mu(x) = e^{\int p(x)\.dx}
$$

#### Solution Method

1) Multiply the entire differential equation by the integrating factor:

$$
e^{\int p(x)\,dx} \left( y' + p(x)\.y \right) = q(x)\.e^{\int p(x)\.dx}
$$

2) The left-hand side becomes a total derivative:

$$
\frac{d}{dx}\left( e^{\int p(x)\.dx}\.y \right) = q(x)\.e^{\int p(x)\.dx}
$$

3) Rewrite the equation:

$$
\frac{d}{dx}\left( e^{\int p(x)\,dx}\.y \right)
= q(x)\.e^{\int p(x)\.dx}
$$

4) Integrate both sides:

$$
e^{\int p(x)\.dx}\.y
= \int q(x)\.e^{\int p(x)\.dx}\.dx + C
$$

5) Solve for \( y \):

$$
y = \frac{\int q(x)\.e^{\int p(x)\.dx}\.dx + C}{e^{\int p(x)\.dx}}
$$

#### 🔗 Code Implementation
👉 [linear_dif_equation](linear_dif_equation.py)

---

#### 🔹1.6) Bernoulli Differential Equations


#### 🔗 Code Implementation
👉 
---

### 2) Second-Order Differential Equations

    2.1) Second-Order Linear Differential Equations
    2.2) Second-Order Linear Homogeneous Differential Equations
        a) Distinct Real Roots  
        b) Repeated Roots  
        c) Complex Roots

    2.3) Second-Order Constant-Coefficient Homogeneous Linear Differential Equations
    2.4) Non-Homogeneous Constant-Coefficient Equations
        a) Method of Undetermined Coefficients  
        b) Method of Variation of Parameters

### 3) Applications of Differential Equations

    3.1) Newton's Law of Cooling  
    3.2) Population  
    3.3) Mechanical Vibrations  
    3.4) Electric Circuits

### 4) First-Order Constant Coefficient Homogeneous Linear Differential Equation Systems



### 5) Laplace Transforms

    5.1) Laplace Transform
    5.2) Inverse Laplace Transform
    5.3) Solving Differential Equations Using Laplace Transforms
    5.4) Laplace Transforms for Polynomial Coefficient Differential Equations
    5.5) Heaviside Step Function


---
## References

[1] C. H. Edwards and D. E. Penney, *Differential Equations and Boundary Value Problems: Computing and Modeling*, 5th ed. Boston, MA: Pearson, 2014.


[2] R. Bronson and G. Costa, *Schaum's Outline of Differential Equations*, 4th ed. New York, NY: McGraw-Hill, 2010. 

[3] https://tutorial.math.lamar.edu/

[4] J.Sundnes, *Solving Ordinary Differential Equations in Python*, 2023.

[5] İ. Ören, *Differential Equations – Lecture Notes*, Karadeniz Technical University, 2023–2025.

[6] B. Ö, Güler, "Differential Equations – Lectures" Karadeniz Technical University, 2021


