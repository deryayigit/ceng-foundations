# Differential Equations

This repository was created to demonstrate why differential equations—one of the fundamental pillars of engineering—are essential, how they are classified, and how their solution methods can be implemented using programming languages.

In engineering, natural sciences, and even social sciences, many phenomena are modeled mathematically through **differential equations**.

Differential equations express numerous physical laws and relationships in mathematical form. They serve as the core model used when transitioning from a physical situation to a *mathematical model*. Any quantity in a system that changes over time—velocity, temperature, current, voltage, population, position, energy, interaction, oscillation—can only be described through derivatives and differential equations.
Thus, they are the fundamental tool for translating real-world problems into mathematics.

With these principles in mind, this repository explains differential equation types and provides their code implementations. The programming structure is designed such that the **type of the differential equation is known by the user**, and the program receives the required expressions as inputs accordingly.

The implementation follows this approach:

1. The user first identifies the type of the differential equation (order, degree, linearity, homogeneity, etc.).  
2. The program then requests the necessary functions, coefficients, or initial values based on the selected type.  
3. Finally, the equation is solved using the appropriate analytical or numerical method.

Due to the need for low-level control and precision in numerical computations, **C and C++** were chosen, while **Python** was additionally used for flexibility and ease of testing.

Overall, this repository serves as a comprehensive study intended to understand differential equation solution techniques from an engineering perspective and to develop their algorithmic counterparts.


---

A differential equation is any equation that contains derivatives—either ordinary derivatives or partial derivatives. Differential equations describe how a system changes with respect to a quantity such as time, position, temperature, or pressure, and they express the relationship between a function and its derivatives.

For example, the equation that relates an object's position to its velocity and acceleration is a differential equation.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to understand the behavior of a physical system through its mathematical model. Understanding complex natural processes often requires reducing them to simpler forms; thus, to comprehend these models and their solutions, one must first become familiar with simpler types of differential equations.

An ordinary differential equation (ODE) is a differential equation in which the unknown function depends on only one independent variable.
A partial differential equation (PDE) is used when the unknown function depends on two or more independent variables.

The order of a differential equation is the order of the highest derivative appearing in the equation. order of a differential equation is the order of the highest derivative appearing in the equation.

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

- $y'' + 3y' - 2y = 0$  
  → **2nd order**

- $y^{(4)} - x y' = \sin x$  
  → **4th order**

- $\left( \dfrac{dy}{dx} \right)^3 + y = 0$  
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

---

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

---

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

---

## The Approach I Followed in My Implementation

To correctly solve a differential equation, it is crucial to:

1. **Identify the type of the equation** (order, degree, linear/nonlinear, homogeneous/nonhomogeneous, etc.),  
2. And then apply the appropriate mathematical or numerical method.

Because of this, in my implementation I designed the system so that **the user specifies the type of the differential equation**, and depending on this classification, the program takes the necessary inputs and applies the relevant solution method.

---

# Types of Differential Equations & Solutions & Code Implementation

### 1) First-Order Differential Equations

#### 🔹1.1) Differential Equations Separable by Variables

**Definition:**

For an equation of the form

$$
y' = f(x, y)
$$

to be **separable**, the expression \( f(x, y) \) must be expressible as:

- functions of only **x**
- functions of only **y**
- a product of a function of **x** and a function of **y**


**Possible Forms:**

$$ f(x, y) = f(x) $$
$$ f(x, y) = f(y) $$
$$ f(x, y) = g(x)\.h(y) $$
$$ f(x, y) = \frac{g(x)}{h(y)} = g(x)\.\frac{1}{h(y)} $$

If the function \( f(x, y) \) can be written as the product of a function of \( x \) and a function of \( y \),  
then the equation is called a **Differential Equation Separable by Variables**.


**Solution of the Equation**

Given:

$$ y' = g(x) \cdot h(y) $$

Rewrite as:

$$ \frac{dy}{dx} = g(x) \cdot h(y) $$

Separate variables:

$$ \frac{1}{h(y)}\,dy = g(x)\,dx $$

Integrate both sides:

$$ \int \frac{1}{h(y)}\.dy = \int g(x)\.dx $$

General implicit solution:

$$ H(y) = G(x) + C $$


### 🔗 Code Implementation
👉 Code file for solving this system of equations: [separable_dif_eq](separable_dif_eq)

---


#### 🔹1.2) Homogeneous Differential Equations

**Definition:**

In the differential equation:

$$
y' = f(x, y)
$$

if the function \( f(x,y) \) can be rewritten as:

$$
f(x,y) = f\left(\frac{y}{x}\right)
$$

and if for any real number λ (lambda):

$$
f(\lambda x, \lambda y) = f(x,y)
$$

then the equation is called a **Homogeneous Differential Equation**.

**Solution of the Equation**

Given:

$$
y' = f(x,y)
$$

Make the substitution:

$$
u = \frac{y}{x}
$$

which implies:

$$
y = ux
$$

Differentiate using the product rule:

$$
y' = u + x\frac{du}{dx}
$$

Substitute into the original equation:

$$
u + x \frac{du}{dx} = f(x, ux)
$$

$$
u = \frac{y}{x}
$$

to obtain the final solution.

### 🔗 Code Implementation
👉  Code file for solving this system of equations: [homogeneous](homogeneous.c)

---

#### 🔹1.3) Substitution Method

Consider the differential equation:

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


### 🔗 Code Implementation
👉 
---

#### 🔹1.5) Linear Differential Equations


### 🔗 Code Implementation
👉 Python Implementation: [linear_dif_equation](linear_dif_equation.py)
---

#### 🔹1.6) Bernoulli Differential Equations


### 🔗 Code Implementation
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




---
## References

[1] C. H. Edwards and D. E. Penney, *Differential Equations and Boundary Value Problems: Computing and Modeling*, 5th ed. Boston, MA: Pearson, 2014.


[2] R. Bronson and G. Costa, *Schaum's Outline of Differential Equations*, 4th ed. New York, NY: McGraw-Hill, 2010. 

[3] https://tutorial.math.lamar.edu/

[4] İ. Ören, *Differential Equations – Lecture Notes*, Karadeniz Technical University, 2023–2025.

[5] B. Ö, Güler, "Differential Equations – Lectures" Karadeniz Technical University, 2021



