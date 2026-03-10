# Discrete Fourier Transform (DFT)

## Project Scope
The Discrete Fourier Transform (DFT) converts a discrete-time signal into its frequency-domain representation by computing complex Fourier coefficients. Each coefficient represents the contribution of a specific frequency component in the signal. This project implements the DFT directly from its mathematical definition in order to illustrate how a time-domain signal can be decomposed into its frequency components.

---

## Input Format

The program expects the number of samples **N** and then **N discrete-time signal values** $x[n]$ where $n = 0,1,...,N-1$. These values represent the input signal in the time domain and are used to compute the corresponding frequency-domain coefficients.

---

## Code Implementation
The implementation follows a modular design in which each function performs a single task. Dynamic memory allocation is used to support signals of arbitrary length, complex numbers are represented using a structured data type, and separate functions are defined for complex addition and multiplication. The Discrete Fourier Transform itself is implemented directly from its mathematical summation formula using nested loops.

The DFT is defined as

$$
X[k] = \sum_{n=0}^{N-1} x[n]\,e^{-j\frac{2\pi}{N}kn}
$$

| Symbol | Description |
|------|-------------|
| \(x[n]\) | Input signal in the time domain |
| \(X[k]\) | Frequency-domain coefficients |
| \(N\) | Number of samples |
| \(n\) | Time-domain index |
| \(k\) | Frequency-domain index |

Using Euler's identity

$$
e^{-j\theta} = \cos(\theta) - j\sin(\theta)
$$

---

## Pseudo Code

```text
Read N  

Create signal array x[n]  
Create spectrum array X[k]  

for k = 0 to N-1  
    X[k] ← 0  

    for n = 0 to N-1  
        θ ← -2πkn / N  
        W ← cos(θ) - j sin(θ)  

        X[k] ← X[k] + x[n] * W  
    end for  

end for  

Print spectrum X[k]

```
---

## Computational Complexity
The direct implementation of the DFT requires two nested loops over the signal length **N**.

$$ T(N) = O(N²) $$

Each frequency coefficient requires summing **N** complex terms, resulting in a quadratic computational complexity.

---

## References
1. G. James, *Advanced Modern Engineering Mathematics*, Pearson Education, 2007.  
2. MIT OpenCourseWare — *The Discrete Fourier Transform*  
3. Stanford University Lecture Notes — *Fourier Analysis*



