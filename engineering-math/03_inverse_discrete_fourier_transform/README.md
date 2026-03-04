# Inverse Discrete Fourier Transform (IDFT)

## Project Scope
The Inverse Discrete Fourier Transform (IDFT) reconstructs a discrete-time signal from its frequency-domain representation. Given the complex Fourier coefficients of a signal, the IDFT combines the frequency components to recover the original time-domain signal. This project implements the IDFT directly from its mathematical definition in order to demonstrate how frequency-domain information can be transformed back into a time-domain signal.

---

## Input Format
The program expects the number of samples **N** and then **N complex frequency-domain coefficients** $X[k]$ where $k = 0,1,\dots,N-1$. These coefficients represent the spectral components of the signal and are used to reconstruct the corresponding time-domain samples.

---

## Code Implementation
The implementation follows a modular design in which each function performs a single task. Dynamic memory allocation allows the program to operate on signals of arbitrary length, complex numbers are represented using a structured data type, and separate helper functions are implemented for complex arithmetic operations such as addition and multiplication. The inverse transform itself is implemented directly from the mathematical summation formula using nested loops.

The IDFT is defined as

$$
x[n] = \frac{1}{N}\sum_{k=0}^{N-1} X[k] e^{j\frac{2\pi}{N}kn}
$$

| Symbol | Description |
|------|-------------|
| $X[k]$ | Frequency-domain coefficients |
| $x[n]$ | Reconstructed time-domain signal |
| $N$ | Number of samples |
| $k$ | Frequency-domain index |
| $n$ | Time-domain index |

Using Euler's identity

$$ 
e^{j\theta} = \cos(\theta) + j\sin(\theta) 
$$

---

## Pseudo Code

```text
Read N  

Create spectrum array X[k]  
Create signal array x[n]  

for n = 0 to N-1  
    x[n] ← 0  

    for k = 0 to N-1  
        θ ← 2πkn / N  
        W ← cos(θ) + j sin(θ)  

        x[n] ← x[n] + X[k] * W  
    end for  

    x[n] ← x[n] / N  

end for  

Print signal x[n]

```

## Computational Complexity

The direct implementation of the IDFT requires two nested loops over the signal length N.

$T(N) = O(N^2)$

Each output sample is computed as a sum of N complex exponential terms, resulting in quadratic computational complexity.

## References
1. G. James, Advanced Modern Engineering Mathematics, Pearson Education, 2007.
2. MIT OpenCourseWare — The Discrete Fourier Transform
3. Stanford University Lecture Notes — Fourier Analysis


