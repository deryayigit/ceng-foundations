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

#### Periodic Function

A function is called periodic if it repeats its values after a fixed interval $T$:

$$
f(t+mT)=f(t)
$$

| Concept | Description |
|---|---|
| Period (T) | Interval over which the function repeats |
| Frequency (f = 1/T) | Number of cycles per second |
| Angular Frequency (ω = 2π/T) | Frequency expressed in radians per second |

Fourier Series Representation:

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos(n\omega t)+b_n \sin(n\omega t)\right), \quad \omega=\frac{2\pi}{T}
$$

The Fourier Series expresses a periodic function as a linear combination of sine and cosine waves. 
Each term represents a harmonic component whose frequency is an integer multiple of the fundamental frequency.

### Fourier Theorem 

The Fourier Theorem states that a periodic function satisfying certain conditions can be expressed as the infinite sum of sinusoidal components. This means that a seemingly complex waveform actually consists of harmonic components with different amplitudes and phases. In other words, a periodic function satisfying certain conditions can be represented as the infinite sum of sine and cosine terms whose frequencies are integer multiples of the fundamental frequency.

That is, if $f(t)$ is a periodic function with period $T$:

$$
f(t)=A_0+A_1\sin(\omega t+\phi_1)+A_2\sin(2\omega t+\phi_2)+\dots+A_n\sin(n\omega t+\phi_n)+\dots, \quad \omega=\frac{2\pi}{T}
$$

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

#### 🔗 Projects Related to the Subject:
👉 [01_fourier_series_visualization](01_fourier_series_visualization)


---

### Discrete Fourier Transform (DFT)

$$
X[k] = \sum_{n=0}^{N-1} x[n]\ e^{-j\frac{2\pi}{N}kn}
$$


The **Discrete Fourier Transform (DFT)** is a mathematical transformation that converts a finite-length discrete-time signal, obtained with equal sampling intervals, from the time domain into the frequency domain. As a result of the DFT, \(N\) samples in the time domain produce \(N\) complex frequency coefficients, and these coefficients represent the amplitude and phase information of the frequency components contained in the signal.

The DFT numerically analyzes the frequency content of a signal known at \(N\) discrete instants separated by the sampling time \(T_s\), providing the discrete-frequency counterpart of the Continuous Fourier Transform. The operation essentially corresponds to the numerical computation of the Fourier Series representation under the assumption that the finite data sequence is periodic.

While frequency analysis in the Continuous Fourier Transform is performed using an integral operation, only a finite number of samples exist in a digital computing environment; therefore, this operation is reduced to a summation form and computed as a discrete transform. For this reason, the DFT can also be interpreted as a linear transformation expressible as the multiplication of a signal vector by a large matrix composed of complex exponential basis functions (sine and cosine).

#### Code Implementation
👉 [02_Discrete Fourier Transform](02_discrete_fourier_transform)

### Inverse Discrete Fourier Transform (IDFT)


$$
x[n] = \frac{1}{N}\sum_{k=0}^{N-1} X[k]\ e^{j\frac{2\pi}{N}kn}
$$


The **Inverse Discrete Fourier Transform (IDFT)** is a mathematical transformation that reconstructs the original discrete-time signal by converting discrete spectrum coefficients obtained in the frequency domain back into the time domain. In the IDFT process, the signal is resynthesized as a weighted sum of complex exponential basis functions with different frequencies using the \(N\) complex Fourier coefficients in the frequency domain, thereby perfectly recovering the \(N\) samples in the time domain.

This operation is the inverse of the frequency analysis performed during the DFT and enables reconstruction of the signal from its frequency components. Essentially, the process reconstructs the signal by properly combining the Fourier coefficients obtained in the Fourier Series representation.

Since the signal amplitude increases due to the summation operation performed during the DFT, normalization by the factor \(1/N\) is applied to ensure that the original time-domain samples are recovered without alteration.

Mathematically, the IDFT corresponds to applying the inverse of the Fourier matrix composed of complex exponential functions and can be expressed as a linear transformation in the form of a large matrix multiplication, providing a one-to-one transformation between the frequency and time domains.


#### Code Implementation
👉 [03 Inverse Discrete Fourier Transform](03_inverse_discrete_fourier_transform)


### Fast Fourier Transform (FFT)


FFT computes the DFT efficiently:

$$
X[k] =
\sum_{n=0}^{\frac{N}{2}-1} x_{2n} W_{N/2}^{nk}
+
W_N^k
\sum_{n=0}^{\frac{N}{2}-1} x_{2n+1} W_{N/2}^{nk}
$$


The **Fast Fourier Transform (FFT)** is an algorithm that efficiently computes the Discrete Fourier Transform (DFT) using fewer computational steps. The FFT converts \(N\) discrete signal samples in the time domain into the frequency domain and produces exactly the same \(N\) complex frequency coefficients as the DFT.

The fundamental idea is to divide the signal samples into even- and odd-indexed groups, compute smaller-sized DFTs, and combine these intermediate results using the structure known as the **Butterfly algorithm**. During this process, the large DFT problem is recursively decomposed into smaller DFT computations, and intermediate results are combined at each stage using complex phase coefficients (twiddle factors).

Thus, the direct \(N \times N\) Fourier matrix multiplication required in the DFT is decomposed into structured computational stages, significantly reducing computational cost. The FFT is therefore not a new transform but a computational method that produces the same mathematical result as the DFT much more efficiently.

## FFT Derivation Flow from DFT

| Step | Mathematical Expression |
|:---:|:---:|
| **Start from the DFT definition** | $$X[k] = \sum_{n=0}^{N-1} x[n] W_N^{nk}$$ <br> Twiddle Factor is $$W_N = e^{-j\frac{2\pi}{N}}$$ |
| ↓ | |
| **Separate samples into even and odd indices** | $$X[k] = \sum_{n=0}^{N/2-1} x[2n] W_N^{2nk} + \sum_{n=0}^{N/2-1} x[2n+1] W_N^{(2n+1)k}$$ |
| ↓ | |
| **Factor the odd term** | $$W_N^{(2n+1)k} = W_N^{2nk} W_N^k$$ |
| ↓ | |
| **Rewrite the equation** | $$X[k] = \sum_{n=0}^{N/2-1} x[2n] W_N^{2nk} + W_N^k \sum_{n=0}^{N/2-1} x[2n+1] W_N^{2nk}$$ |
| ↓ | |
| **Use the identity** | $$W_N^{2nk} = W_{N/2}^{nk}$$ |
| ↓ | |
| **Two DFTs of size \(N/2\)** | $$X[k] = \sum_{n=0}^{\frac{N}{2}-1} x_{2n} W_{N/2}^{nk} + W_N^k \sum_{n=0}^{\frac{N}{2}-1} x_{2n+1} W_{N/2}^{nk}$$ |
| ↓ | |
| **Define even and odd transforms** | $$E(k) = \sum_{n=0}^{N/2-1} x_{2n} W_{N/2}^{nk}$$ <br> $$O(k) = \sum_{n=0}^{N/2-1} x_{2n+1} W_{N/2}^{nk}$$ |
| ↓ | |
| **Butterfly combination** | $$X(k) = E(k) + W_N^k O(k)$$ <br> $$X(k+N/2) = E(k) - W_N^k O(k)$$ |
| ↓ | |
| **Fast Fourier Transform (FFT) algorithm is obtained** | Recursive computation using the butterfly structure  |


As a result, redundant computations present in the direct DFT are eliminated, and computational complexity is reduced from $O(N^2) \rightarrow O(N \log_2 N)$


#### Code Implementation
👉 [04 Fast Fourier Transform](04_fast_fourier_transform)


---

## Correlation & Convulution

#### Code Implementation
👉 [05 Correlation and Convulation](05_correlation_convulation)

---

## Matrices and Systems of Linear Equations

Mathematics is not only a theoretical discipline but also a powerful tool used to model real world problems. Many engineering and scientific problems can be expressed as systems of linear equations. Historically linear algebra developed from studying methods for solving such systems. This section introduces the structure of linear systems, the types of solutions, and the matrix method used to solve them.

A linear equation in two variables represents a straight line in the plane. The solution of a system of two linear equations is the intersection point of these lines. Three possibilities may occur. The system may have a unique solution, no solution, or infinitely many solutions.

### Types of Solutions

| Case | System | Interpretation | Result |
|------|--------|---------------|--------|
| Unique Solution | $$x+y=4$$ <br> $$x-y=2$$ | Lines have different slopes and intersect at one point | $$x=3,\ y=1$$ |
| No Solution | $$2x+y=3$$ <br> $$2x+y=7$$ | Lines are parallel and do not intersect | No solution |
| Infinitely Many Solutions | $$x+2y=6$$ <br> $$2x+4y=12$$ | Second equation is a multiple of the first. Same line | Infinitely many solutions |


For systems with three variables, each equation represents a plane instead of a line. For example

$$
x + y + z = 6
$$
$$
2x - y + z = 3
$$
$$
x + 2y - z = 3
$$

This system represents three planes. The solution corresponds to the intersection of these planes.

As the number of variables increases, the geometric interpretation becomes more difficult. While three dimensional systems can still be visualized, higher dimensional systems cannot be easily represented geometrically. For this reason algebraic and algorithmic methods are required to solve linear systems.

### What is a Matrix

A matrix is a rectangular array of numbers. The numbers in the array are called the elements of the matrix.

Matrices consist of rows and columns. Rows are labeled from the top and columns from the left. For example the following matrix has two rows and three columns

$$
A =
\begin{bmatrix}
2 & 1 & -3 \\
4 & 0 & 5
\end{bmatrix}
$$

This matrix is of size $2 \times 3$. The element in row 1 column 3 is $-3$.


#### Identity Matrix

An identity matrix is a square matrix whose diagonal elements are 1 and all other elements are 0.

$$
I_3 =
\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
$$

The identity matrix plays an important role in Gauss Jordan elimination because the goal is to transform the coefficient matrix into the identity matrix.


#### Coefficient Matrix

Given a system of linear equations

$$
x + y + z = 6
$$
$$
2x - y + z = 3
$$
$$
x + 2y - z = 3
$$

The coefficient matrix contains only the coefficients of the variables

$$
A =
\begin{bmatrix}
1 & 1 & 1 \\
2 & -1 & 1 \\
1 & 2 & -1
\end{bmatrix}
$$


#### Augmented Matrix

The augmented matrix is formed by combining the coefficient matrix with the constant terms

$$
[A|b] =
\begin{bmatrix}
1 & 1 & 1 & | & 6 \\
2 & -1 & 1 & | & 3 \\
1 & 2 & -1 & | & 3
\end{bmatrix}
$$

The augmented matrix completely represents the system of equations.

#### Code Implementation
👉 [Matrix Library](matrix-library)

### Gauss–Jordan Elimination Method

The Gauss–Jordan elimination method is a systematic matrix method used to solve systems of linear equations. This method can also be applied in situations where the number of equations differs from the number of unknowns. Thus, all possibilities—such as the system having a single solution, an infinite number of solutions, or no solution at all—can be analysed. The primary aim of the method is to transform the given system of linear equations into a simpler matrix form using row operations and to obtain the solution directly from this simplified form.

In this approach, the first step is to write the system of linear equations in augmented matrix form. Subsequently, elementary row operations are applied to the matrix to transform it into reduced row echelon form. Once this form is reached, the solution can be read directly from the last column of the matrix.


#### Reduced Row Echelon Form 

A matrix is in reduced row echelon form if:
1. All rows consisting entirely of zeros are at the bottom of the matrix.  
2. The first nonzero entry in each nonzero row is 1 (called a pivot or leading 1).  
3. Each pivot is to the right of the pivot in the row above it.  
4. Each pivot is the only nonzero entry in its column.  


| **Reduced Row Echelon Form (RREF)** | **Not in Reduced Row Echelon Form** |
|-------------------------------------|--------------------------------------|
| 1 0 8 <br> 0 1 2 <br> 0 0 0 | 1 2 0 4 <br> 0 0 0 0 <br> 0 0 3 1 |
| 1 0 0 7 <br> 0 1 0 3 <br> 0 0 1 9 | 1 2 0 3 0 <br> 0 0 3 4 0 <br> 0 0 0 0 1 |
| 1 4 0 0 <br> 0 0 0 1 <br> 0 0 0 0 | 1 0 0 2 <br> 0 0 1 4 <br> 0 0 0 0 |
| 1 2 3 0 <br> 0 0 0 1 <br> 0 0 0 0 | 1 7 0 8 <br> 0 1 0 3 <br> 0 0 1 2 <br> 0 0 0 0 |

### Gauss–Jordan Algorithm:
1. Write the augmented matrix of the system of linear equations.  
2. Use elementary row operations to convert the matrix into reduced row echelon form by creating pivots and zeros above and below each pivot.  
3. Write the corresponding system of equations.  
4. Read the solution directly from the last column.  

### Applications of Gauss–Jordan Elimination



#### Code Implementation
👉 [06 Gauss-Jordan Elimination](06_gauss_jordan_elimination)

---

## References

1) G. James, *Advanced Modern Engineering Mathematics*, 4th ed., Pearson Education, 2007.

2) G. Williams, *Linear Algebra with Applications*, 8th ed.

3) Massachusetts Institute of Technology,  
"Chapter 4: Fourier Series and Integrals."  
Available: https://math.mit.edu/~gs/cse/websections/cse41.pdf

4) MathOverflow,  
"Why sin and cos in the Fourier series?"  
Available: https://mathoverflow.net/questions/11761/why-sin-and-cos-in-the-fourier-series

5) Stanford University,  
"Chapter 5: Fourier Analysis," Course Notes.  
Available: https://web.stanford.edu/class/nbio228-01/handouts/Ch5_Fourier_Analysis.pdf

6) Z. Arief,  
*Interfacing with the Analog World*, Lecture Notes.  
Available: https://www.scribd.com/document/315114093/Interfacing-With-the-Analog-World

7) MIT OpenCourseWare,  
"Lecture 7: The Discrete Fourier Transform."  
Available: https://ocw.mit.edu

8) E. C. Ifeachor and B. W. Jervis,  
*Digital Signal Processing: A Practical Approach*, 2nd ed., Pearson Education, 2002.

9) W. H. Press, S. A. Teukolsky, W. T. Vetterling, and B. P. Flannery,  
*Numerical Recipes in C: The Art of Scientific Computing*, 2nd ed., Cambridge University Press, 1992.


## Acknowledgments 

I would like to thank Prof. Dr. Murat Ekinci for building a strong engineering mindset through his lectures and assignments, and for his insistence on analytical thinking.
