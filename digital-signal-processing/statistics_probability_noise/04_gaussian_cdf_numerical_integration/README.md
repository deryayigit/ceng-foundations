# Gaussian CDF Calculation

## Objective and Project Description

Cumulative Distribution Function (CDF) of a Gaussian Distribution Using Trapezoidal Integration from the Probability Density Function (PDF) for a Single Value  
(Gauss CDF Trapezoidal Calculation)

This project demonstrates how the **Cumulative Distribution Function (CDF)** of a **Gaussian (Normal) distribution** can be computed numerically using the **trapezoidal integration method** applied to the **Probability Density Function (PDF)**.

---

## Overview

The Gaussian distribution is one of the fundamental probability distributions used to model random variations observed in nature and engineering systems. When a quantity is influenced by a large number of small, independent random effects, the resulting distribution approaches a Gaussian distribution according to the **Central Limit Theorem**. Measurement errors, sensor noise, thermal noise, and quantization errors are common physical processes that follow this behavior.

Due to its strong ability to model real-world signals and its well-defined mathematical properties, the Gaussian distribution is widely used as a reference distribution in digital signal processing and statistical analysis.

---

## Code Implementation

Computers do not evaluate integrals analytically; instead, they approximate integral values numerically within a controllable error margin. In numerical integration, the primary goal is not to select the most complex algorithm, but to choose an appropriate and reliable method for the given problem.

In this project, the **Trapezoidal Integration Method** is used to obtain the CDF from the Gaussian PDF. This method approximates the integral by sampling the function at discrete points and summing the areas of trapezoids formed between consecutive samples. As the number of iterations increases, the step size decreases and the numerical result converges toward the theoretical integral value.

The project is implemented in the **C programming language** to maintain full control over low-level numerical computations. The Gaussian PDF calculation, trapezoidal integration, and CDF evaluation are implemented as separate modular functions, improving clarity, correctness, and maintainability.

---

## Methodology

### Gaussian PDF

The Probability Density Function of the Gaussian distribution is defined as:

$$
PDF(x) = \frac{1}{\sigma \sqrt{2\pi}}
\exp\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)
$$

This function is implemented manually in C without relying on external statistical libraries.

---

### Numerical Integration (Trapezoidal Method)

The CDF value is computed by numerically integrating the PDF using the trapezoidal rule:

$$
\int_{a}^{b} f(x)\,dx \approx
\sum_{i=0}^{N-1}
\frac{f(x_i) + f(x_{i+1})}{2} \cdot \Delta x
$$

The integration interval is divided into \(N\) subintervals, and the total integral is approximated by summing the areas of the trapezoids formed at each step. Increasing the number of iterations improves numerical accuracy.

---

### Finite Integration Limits

Instead of infinite bounds, the following interval is used:

$$
[\mu - 6\sigma,\; \mu + 6\sigma]
$$

This range covers nearly the entire probability mass of a Gaussian distribution.  
If \(X < \mu - 6\sigma\), the CDF value is assumed to be 0.  
If \(X > \mu + 6\sigma\), the CDF value is assumed to be 1.  

In these cases, numerical integration is skipped.

---

## Observations

Increasing the number of iterations reduces the step size in the trapezoidal method, resulting in higher numerical accuracy for the CDF calculation. The ±6σ boundary provides a practical and sufficiently precise approximation of the infinite integration limits. Throughout the implementation, no built-in probability or statistics libraries are used; all computations are performed manually.

---

## Pseudo Code

```text
Initialize:
    mean                ← input mean value
    standardDeviation   ← input standard deviation
    X                   ← input evaluation point
    iterationCount      ← optional input (default value if not provided)

Compute integration limits:
    lowerLimit ← mean − 6 × standardDeviation
    upperLimit ← mean + 6 × standardDeviation

Check boundary conditions:
    If X ≤ lowerLimit:
        return CDF = 0
    If X ≥ upperLimit:
        return CDF = 1

Initialize numerical integration:
    stepSize ← (X − lowerLimit) / iterationCount
    totalArea ← 0

For i from 0 to iterationCount − 1:
    xLeft  ← lowerLimit + i × stepSize
    xRight ← xLeft + stepSize

    pdfLeft  ← GaussianPDF(xLeft)
    pdfRight ← GaussianPDF(xRight)

    trapezoidArea ← (pdfLeft + pdfRight) / 2 × stepSize
    totalArea ← totalArea + trapezoidArea

Return:
    CDF(X) ← totalArea

```
---
## References

1. Oppenheim, A. V., & Schafer, R. W. *Discrete-Time Signal Processing*, 3rd Edition. Pearson Education, 2010.

2. Devore, J. L. *Probability and Statistics for Engineering and the Sciences*, 8th Edition. Cengage Learning, 2012.

3. Burden, R. L., & Faires, J. D. *Numerical Analysis*, 9th Edition. Brooks/Cole, Cengage Learning, 2011.

4. Weisstein, E. W. “Normal Distribution.” *MathWorld – A Wolfram Web Resource*.  
   https://mathworld.wolfram.com/NormalDistribution.html

5. “Trapezoidal rule.” Wikipedia (en).  
   https://en.wikipedia.org/wiki/Trapezoidal_rule
