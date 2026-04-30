# Integer Square Root Calculation using Newton-Raphson Method  

---

## Definition  

This experiment focuses on implementing an integer square root algorithm at the microprocessor level using assembly language. The implementation demonstrates how numerical methods can be mapped onto low-level instruction execution within the Intel 80286 architecture.

---

## Purpose  

The purpose of this experiment is to implement an iterative algorithm for computing the square root of a number using the Newton-Raphson method in assembly language. Additionally, it aims to demonstrate how numerical methods and iterative algorithms can be realized at the microprocessor level.  

---

## Working Principle, Formula  

Numerical methods are widely used to obtain approximate solutions for complex mathematical problems that are difficult or impossible to solve analytically. These methods are essential in engineering applications such as root finding, optimization, differential equations, and interpolation.  

### Newton-Raphson Method Formulation  

The Newton-Raphson method is used to find the roots of a function and is defined by the following iterative formula:

$$
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
$$

For square root calculation, the function is defined as:

$$
f(x) = x^2 - N
$$

Its derivative is:

$$
f'(x) = 2x
$$

Substituting into the Newton-Raphson formula gives the iteration:

$$
x_{n+1} = \frac{x_n + \frac{N}{x_n}}{2}
$$

---

## Pseudo Code, Algo  

```text
START

Read N
Choose initial guess x

LOOP:
    new_x = (x + N / x) / 2

    IF |new_x - x| is sufficiently small:
        OUTPUT new_x
        EXIT LOOP

    x = new_x
    GO TO LOOP

END

```

## Code  

The program is implemented in assembly language using the 80286 instruction set. The algorithm relies on integer arithmetic operations such as division, addition, and shifting.  

At each iteration:  

- The current estimate is used to divide the number $N$  
- The result is added to the current estimate  
- The sum is divided by 2 to obtain a new approximation  

Since floating-point operations are limited at this level, calculations are typically performed using integers or scaled values.  

---

## Newton-Raphson Iterative Process  

To illustrate the convergence behavior, consider computing $\sqrt{10}$ with an initial guess $x_0 = 3$:  

$$
x_1 = \frac{3 + \frac{10}{3}}{2} \approx 3.1667
$$

$$
x_2 = \frac{3.1667 + \frac{10}{3.1667}}{2} \approx 3.1623
$$

$$
x_3 = \frac{3.1623 + \frac{10}{3.1623}}{2} \approx 3.1622
$$

The sequence rapidly converges to the actual value:  

$$
\sqrt{10} \approx 3.1622
$$

This demonstrates the efficiency of the Newton-Raphson method.  

---

## Observations  

The experiment shows that the Newton-Raphson method provides fast convergence for root-finding problems. With a reasonable initial guess, the solution can be obtained in only a few iterations.  

Implementing this method in assembly language is more complex compared to high-level languages, but it offers deeper insight into how iterative numerical algorithms operate at the hardware level.  

It is also observed that careful handling of division operations, overflow conditions, and precision limitations is necessary when working with integer-based arithmetic in microprocessor systems.  

## References
1. Karadeniz Technical University, Computer Organization Laboratory Documentation.

2. https://github.com/yildiz-busra/Organizasyon-Lab
