# Fast Fourier Transform (FFT)

## Project Scope
The Fast Fourier Transform (FFT) is an algorithm that efficiently computes the Discrete Fourier Transform (DFT) of a discrete-time signal. While the DFT converts a signal from the time domain into the frequency domain by computing complex Fourier coefficients, its direct implementation requires a large number of computations.

The FFT improves this process by exploiting the mathematical structure and symmetry of the DFT. The algorithm divides the signal into **even-indexed and odd-indexed samples**, computes smaller Fourier transforms for these subsequences, and combines the results using the **butterfly operation**.

This project implements the **Butterfly algorithm** in order to demonstrate how the computation of the DFT can be reorganized into a more efficient recursive structure.

---

## Input Format

The program expects the number of samples **N** followed by **N discrete-time signal values** \(x[n]\) where  

\(n = 0,1,...,N-1\)

For the radix-2 FFT implementation, the number of samples must be a **power of two**

\[
N = 2^m
\]

These values represent the input signal in the time domain and are used to compute the corresponding frequency-domain coefficients.

---

## Code Implementation

The implementation follows a modular design in which each function performs a single task. Complex numbers are represented using a structured data type, and separate functions are defined for complex addition, subtraction, and multiplication.

The FFT algorithm is implemented recursively using a **divide-and-conquer strategy**. In each recursion step the signal is divided into **even-indexed samples** and **odd-indexed samples**

The Fourier transforms of these subsequences are computed recursively and then combined using the **butterfly operation** with the complex exponential factor

$$
W_N = e^{-j\frac{2\pi}{N}}
$$

The FFT computation can be expressed as

$$
X[k] =
\sum_{n=0}^{\frac{N}{2}-1} x[2n] W_{N/2}^{nk}
+
W_N^k
\sum_{n=0}^{\frac{N}{2}-1} x[2n+1] W_{N/2}^{nk}
$$

which leads to the butterfly combination

$$
X(k) = E(k) + W_N^k O(k)
$$

$$
X(k + N/2) = E(k) - W_N^k O(k)
$$

where

| Symbol | Description |
|------|-------------|
| \(x[n]\) | Input signal in the time domain |
| \(X[k]\) | Frequency-domain coefficients |
| \(N\) | Number of samples |
| \(E(k)\) | Fourier transform of even-indexed samples |
| \(O(k)\) | Fourier transform of odd-indexed samples |
| \(W_N\) | Twiddle factor \(e^{-j2\pi/N}\) |


## Pseudo Code

```text
Read N  

Create signal array x[n]

FFT(x, N)

if N ≤ 1  
    return

half ← N / 2

Create arrays even[half], odd[half]

for k = 0 to half−1
    even[k] ← x[2k]
    odd[k]  ← x[2k+1]

FFT(even, half)
FFT(odd, half)

for k = 0 to half−1

    W ← e^(−j2πk/N)

    t ← W × odd[k]

    x[k] ← even[k] + t
    x[k + half] ← even[k] − t

end for

```
---
## Referneces

