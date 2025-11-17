# Differential Equations

A differential equation is an equation involving an unknown function and its derivatives.

Understanding differential equations is essential for analyzing many types of problems such as fluid motion, electric current in circuits, heat transfer in solid objects, detection of seismic waves, population growth or decline, and many similar natural phenomena.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to gain insight into these models. Understanding a complex natural process often requires reducing it to its simplest form. Hence, to comprehend the equations that describe these models and their solutions, one must first be familiar with simpler cases.

An ordinary differential equation (ODE) involves a function with only one independent variable. If the unknown function depends on two or more independent variables, the equation is called a partial differential equation (PDE).

The order of a differential equation is the order of the highest derivative appearing in the equation.

---

# Notation

The expressions \( y', y'', y''', y^{(4)}, \ldots, y^{(n)} \) represent the first, second, third, fourth, …, nth derivatives of \( y \) with respect to the independent variable.

Thus, \( y'' \) means \( \frac{d^2y}{dx^2} \) when the independent variable is \( x \), but \( \frac{d^2y}{dp^2} \) when the variable is \( p \).

Parentheses in \( y^{(n)} \) distinguish it from the nth power \( y^n \).

If the independent variable is time \( t \), primes are replaced by dots. Thus, \( \dot{y}, \ddot{y}, \dddot{y} \) represent \( \frac{dy}{dt}, \frac{d^2y}{dt^2}, \frac{d^3y}{dt^3} \).

---

# History of Differential Equations

The study of differential equations began in the seventeenth century with Isaac Newton and Gottfried Wilhelm Leibniz. Newton classified first-order equations and developed series solution methods, while Leibniz introduced derivative and integral notation and the method of separation of variables.

The Bernoulli family expanded the field through new methods and applications to fluid mechanics. Leonhard Euler made fundamental contributions such as integrating factors, general solutions for linear equations, and numerical methods. Joseph-Louis Lagrange improved the theoretical basis with the variation of parameters method and the structure of higher-order solutions. Pierre-Simon Laplace introduced equations central to mathematical physics and the Laplace transform.

In the nineteenth century existence and uniqueness theorems were established, and in the twentieth century numerical analysis and computers increased the ability to study nonlinear systems. Today geometric and topological methods provide deeper insight into the qualitative behavior of solutions.

**In short:** Differential equations grew from Newton and Leibniz, developed by Euler, Bernoulli, Lagrange, and Laplace, formalized in the nineteenth and twentieth centuries, and expanded greatly in the modern era with computational tools.

---

# Fundamental Concepts in Differential Equations

## 1. Order
The order of a differential equation is the degree of the highest derivative.  
Examples:  
- \( y'' + 3y' - 2y = 0 \) → 2nd order  
- \( y^{(4)} - x y' = \sin x \) → 4th order  
- \( \left(\frac{dy}{dx}\right)^3 + y = 0 \) → 1st order  

---

## 2. Degree
If the equation is polynomial in derivatives, the degree is the power of the highest derivative. If derivatives appear inside roots, logarithms, or trigonometric functions, the degree is undefined.  
Examples:  
- \( (y'')^2 + y = x \) → 2nd degree  
- \( y' + xy = 0 \) → 1st degree  
- \( \frac{dy}{dx} + \sqrt{y''} = 0 \) → undefined degree  

---

## 3. Linear Differential Equation
General form:  


\[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
\]



Conditions for linearity: \( y \) and its derivatives must appear to the first power, not multiplied together, and not inside logarithmic, root, or trigonometric functions.  

- Linear example: \( y'' + 3y' + 2y = e^x \)  
- Nonlinear example: \( (y')^2 + y = 0 \)  

---

## 4. Linear – Homogeneous / Non-Homogeneous


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
Form:  


\[
M(x,y) + N(x,y) y' = 0
\]



Condition for exactness:  


\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]



If satisfied, there exists a potential function \( \Phi(x,y) \).

---

## 7. Integrating Factor
First-order linear equation:  


\[
y' + P(x) y = Q(x)
\]



Integrating factor:  


\[
\mu(x) = e^{\int P(x) dx}
\]



---

## 8. Homogeneous ODE


\[
\frac{dy}{dx} = F\left(\frac{y}{x}\right)
\]



Substitution: \( y = ux \), \( y' = u + x u' \).  
This reduces the equation to a separable form.

---

## 9. Bernoulli Equation


\[
y' + P(x) y = Q(x) y^n
\]



Transformation: \( v = y^{1-n} \).  
The equation becomes linear.

---

## 14. General and Particular Solution
- General solution contains arbitrary constants.  
- Particular solution is obtained when initial conditions are applied.  

---

## 15. Reduction of Order – Substitution Techniques
Common substitutions:  
- \( v = y' \)  
- \( y = ux \)  
- \( v = y/x \)  

---

## 16. Second-Order Linear Equation


\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
\]



---

## 17. Second-Order Linear Homogeneous Equation


\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0
\]



General solution:  


\[
y = C_1 y_1(x) + C_2 y_2(x)
\]



---

## 18. Second-Order Constant Coefficient Linear Homogeneous Equation


\[
a y'' + b y' + c y = 0
\]



Characteristic equation:  


\[
a r^2 + b r + c = 0
\]



- Real distinct roots: \( y = C_1 e^{r_1 x} + C_2 e^{r_2 x} \)  
- Repeated root: \( y = (C_1 + C_2 x) e^{rx} \)  
- Complex roots: \( y = e^{\alpha x} \left( C_1 \cos(\beta x) + C_2 \sin(\beta x) \right) \)  
