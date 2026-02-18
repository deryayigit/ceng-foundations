# Engineering Mathematics

Engineering Mathematics is a structured framework that enables engineers to model, transform, analyse, and apply real-world systems through mathematical representations.  
The aim is to transform abstract mathematical structures into tools applicable to engineering problems.
This course includes Fourier series, Discrete Fourier Transform (DFT), Fast Fourier Transform (FFT), convolution and correlation operations, matrix analysis, determinant calculations, N-dimensional vector spaces, matrix rank, eigenvalue and eigenvector calculation methods, and the numerical applications of these concepts. 

## Repository Structure 

This repository has been prepared to examine the fundamental concepts covered in the Engineering Mathematics course both theoretically and practically. The content includes not only mathematical definitions but also how these structures are applied to engineering problems and implemented at the code level. Each folder represents an independent study focusing on the analysis of a specific mathematical concept and its engineering application.

## Purpose of This Repository 

The main purpose of this repository is to implement mathematical methods consciously at a low level instead of using ready-made libraries. The objective is to understand the structure behind mathematical formulas, convert this structure into algorithms, and observe system behavior through code. In this way, mathematics becomes not only theoretical knowledge but a direct part of engineering practice.

## Definition 

Engineering Mathematics is the collection of methods that transform real-world physical processes into mathematical models in order to analyze, understand, and control systems through those models. This discipline combines the theoretical structure of mathematics with engineering applications and serves as a fundamental tool in system modeling, analysis, and solution processes.  

At its core, Engineering Mathematics is an art of changing representation. Real-world systems are often too complex to be analyzed directly. Therefore, the engineer transforms the problem into a more suitable representation. A signal that appears complex in the time domain may become much clearer when transformed into the frequency domain.  For example, consider the transmission of sound to the other party via telephone. A complex time-domain signal such as sound can be decomposed into its frequency components, allowing filtering, compression, and transmission analysis in communication systems.

### Fourier Series 

Joseph Fourier, while attempting to solve heat transfer problems at the turn of the 19th century, realised that classical methods were insufficient for solving the heat equation, which models how the temperature distribution of a rod changes over time. He saw that the most effective way to solve the problem was to express the temperature distribution as the sum of sine and cosine waves thus, he succeeded in solving the differential equation in terms of frequency components.

Although the idea of expanding a function in this way had previously been used by Bernoulli, D'Alembert, and Euler in problems involving vibrating strings, it was Fourier who transformed this approach into a general and systematic framework.
According to Fourier's Theorem, a periodic function that satisfies certain conditions can be expressed as the sum of sine and cosine waves, which means that the function can be decomposed into different frequency components. The reason for choosing sine and cosine is that they provide a powerful mathematical structure for decomposing periodic functions into frequency components via orthogonal basis functions. Although originating from heat transfer problems, they are considered one of the most natural representations both theoretically and physically.

General form:

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos(n\omega t)+b_n \sin(n\omega t)\right)
$$

where  

$$
\omega=\frac{2\pi}{T}
$$

is the angular frequency.

#### Periodic Function  

A function is called periodic if for a given period $T$:

$$
f(t+mT)=f(t)
$$

for any integer $m$. The period is the interval over which the function repeats itself. The frequency is the reciprocal of the period:

$$
f=\frac{1}{T}
$$

The angular frequency is defined as:

$$
\omega=\frac{2\pi}{T}
$$

and its unit is radians per second.

### Fourier Theorem 

The Fourier Theorem states that a periodic function satisfying certain conditions can be expressed as the infinite sum of sinusoidal components. This means that a seemingly complex waveform actually consists of harmonic components with different amplitudes and phases. In other words, a periodic function satisfying certain conditions can be represented as the infinite sum of sine and cosine terms whose frequencies are integer multiples of the fundamental frequency.

That is, if $f(t)$ is a periodic function with period $T$:

$$
f(t)=A_0+A_1\sin(\omega t+\phi_1)+A_2\sin(2\omega t+\phi_2)+\dots+A_n\sin(n\omega t+\phi_n)+\dots
$$

Here $A_n$ are constants and  

$$
\omega=\frac{2\pi}{T}
$$

is the frequency of $f(t)$.

The term $A_1\sin(\omega t+\phi_1)$ is called the first harmonic (fundamental mode) and has the same frequency as $f(t)$.  
The term $A_n\sin(n\omega t+\phi_n)$ is called the $n$-th harmonic; its frequency is $n\omega$, which is $n$ times the fundamental frequency.

$A_n$ represents the amplitude of the $n$-th harmonic, and $\phi_n$ represents the phase angle, measuring the delay or advance relative to a pure sine wave of the same frequency.

Because:

$$
A_n\sin(n\omega t+\phi_n)=(A_n\cos\phi_n)\sin(n\omega t)+(A_n\sin\phi_n)\cos(n\omega t)
$$

$$
b_n\sin(n\omega t)+a_n\cos(n\omega t)
$$

where

$$
b_n=A_n\cos\phi_n
$$

$$
a_n=A_n\sin\phi_n
$$

the expansion can equivalently be written as a linear combination of cosine and sine terms.

### Fourier Coefficients 

According to Euler's formula, the Fourier coefficient calculation is as follows:

$$
a_n=\frac{2}{T}\int_{d}^{d+T} f(t)\cos(n\omega t)\,dt
$$

$$
b_n=\frac{2}{T}\int_{d}^{d+T} f(t)\sin(n\omega t)\,dt
$$


### Even and Odd Functions 

If a function satisfies $f(t)=f(-t)$, it is called an even function and its graph is symmetric with respect to the vertical axis. In this case, some Fourier coefficients become zero and the series simplifies. If $f(t)=-f(-t)$, the function is called an odd function and its graph is symmetric with respect to the origin. These symmetry properties significantly simplify Fourier series calculations.

### 🔗 Projects Related to the Subject:
👉 [01_fourier_series_visualization](01_fourier_series_visualization)

## References 

James, G. (2007). Advanced Modern Engineering Mathematics (4th ed.). Pearson Education.  

Massachusetts Institute of Technology (MIT). (n.d.). Chapter 4: Fourier Series and Integrals.  
Available at: https://math.mit.edu/~gs/cse/websections/cse41.pdf  

MathOverflow. (2010). Why sin and cos in the Fourier series?  
Available at: https://mathoverflow.net/questions/11761/why-sin-and-cos-in-the-fourier-series  

Stanford University. (n.d.). Chapter 5: Fourier Analysis (Course Notes).  
Available at: https://web.stanford.edu/class/nbio228-01/handouts/Ch5_Fourier_Analysis.pdf  

## Acknowledgments 

I would like to thank Prof. Dr. Murat Ekinci for building a strong engineering mindset through his lectures and assignments, and for his insistence on analytical thinking.



