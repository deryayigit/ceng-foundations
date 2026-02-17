# Engineering Mathematics

The Engineering Mathematics course systematically covers the fundamental mathematical tools used in computer engineering. The course includes Fourier series, Discrete Fourier Transform (DFT), Fast Fourier Transform (FFT), convolution and correlation operations, matrix analysis, determinant computation, N-dimensional vector spaces, matrix rank, eigenvalue and eigenvector computation methods, and the numerical implementation of these concepts.

The goal is to transform abstract mathematical structures into applicable tools for solving engineering problems.

---

## Repository Structure

This repository has been prepared to study the fundamental concepts covered in the Engineering Mathematics course both theoretically and practically.

The content includes not only mathematical definitions but also how these structures are applied to engineering problems and implemented at the code level. Each folder represents an independent study focusing on a specific mathematical concept and its engineering application.

---

## Purpose of This Repository

The main purpose of this repository is to implement mathematical methods at a low level consciously and independently instead of relying on ready-made libraries.

The objective is to understand the structure behind mathematical formulas, convert these structures into algorithms, and observe system behavior directly through code. In this way, mathematics becomes not just theoretical knowledge but a direct component of engineering practice.

---

## Definition

Engineering Mathematics is the collection of methods that transform real-world physical processes into mathematical models in order to analyze, understand, and control systems through those models.

This discipline combines the theoretical structure of mathematics with engineering applications and serves as a fundamental tool in system modeling, analysis, and problem-solving processes.

At its core, Engineering Mathematics is an art of changing representation. Real-world systems are often too complex to analyze directly. Therefore, the engineer transforms the problem into a more suitable representation. For example, a signal that appears complex in the time domain may become much clearer when transformed into the frequency domain.

---

## Fourier Series

Joseph Fourier (1768–1830), while studying heat conduction problems, realized that expressing temperature distributions as sums of sine and cosine waves significantly simplified the solution of differential equations.

According to the Fourier Theorem, a periodic function that satisfies certain conditions can be expressed as the sum of sine and cosine functions. This corresponds to decomposing the function into its frequency components.

---

### General Form

For a periodic function with period $T$, the Fourier series is written as:

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos(n\omega t)+b_n \sin(n\omega t)\right)
$$

where the angular frequency is:

$$
\omega=\frac{2\pi}{T}
$$

---

### Periodic Function

A function is called periodic if:

$$
f(t+mT)=f(t)
$$

for any integer $m$.

The frequency is defined as:

$$
f=\frac{1}{T}
$$

and the angular frequency is:

$$
\omega=\frac{2\pi}{T}
$$

---

### Harmonics

A periodic function can also be written as:

$$
f(t)=A_0+A_1\sin(\omega t+\phi_1)+A_2\sin(2\omega t+\phi_2)+\dots
$$

The term $A_n\sin(n\omega t+\phi_n)$ is called the $n$-th harmonic.  
Its frequency is $n\omega$, which is $n$ times the fundamental frequency.

Using trigonometric identities:

$$
A_n\sin(n\omega t+\phi_n)=(A_n\cos\phi_n)\sin(n\omega t)+(A_n\sin\phi_n)\cos(n\omega t)
$$

which can be rewritten as:

$$
b_n\sin(n\omega t)+a_n\cos(n\omega t)
$$

where:

$$
b_n=A_n\cos\phi_n
$$

$$
a_n=A_n\sin\phi_n
$$

---

### Fourier Coefficients

The Fourier coefficients are computed as:

$$
a_n=\frac{2}{T}\int_{d}^{d+T} f(t)\cos(n\omega t)\,dt
$$

$$
b_n=\frac{2}{T}\int_{d}^{d+T} f(t)\sin(n\omega t)\,dt
$$

---

### Even and Odd Functions

If $f(t)=f(-t)$, the function is even and the sine terms vanish.

If $f(t)=-f(-t)$, the function is odd and the cosine terms vanish.

---

## References

## References

1. James, G. (2007). *Advanced Modern Engineering Mathematics* (4th ed.). Pearson Education.

2. Massachusetts Institute of Technology (MIT). (n.d.). *Chapter 4: Fourier Series and Integrals*.  
   Available at: https://math.mit.edu/~gs/cse/websections/cse41.pdf

3. MathOverflow. (2010). *Why sin and cos in the Fourier series?*  
   Available at: https://mathoverflow.net/questions/11761/why-sin-and-cos-in-the-fourier-series

4. Stanford University. (n.d.). *Chapter 5: Fourier Analysis* (Course Notes).  
   Available at: https://web.stanford.edu/class/nbio228-01/handouts/Ch5_Fourier_Analysis.pdf


---

## Acknowledgments

I would like to thank Prof. Dr. Murat Ekinci for fostering engineering awareness through his lectures and assignments.
