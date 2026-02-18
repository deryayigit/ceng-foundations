# Fourier Series Visualization

## Project Scope

This project aims to visualize the Fourier Series using user-defined Fourier coefficients \( a_n \) and \( b_n \).

Each harmonic component is calculated individually and plotted separately. Then, at a given time \( t \), these harmonic values are summed to generate:

- The partial sum of the Fourier series
- The complete (up to N) Fourier approximation

This allows a visual demonstration of the **superposition principle**, showing how independent harmonic components combine to form a complex waveform.

---

## Input Format

The following parameters are provided by the user:

- Number of harmonics \( N \)
- Period \( T \)
- Constant coefficient \( a_0 \)
- Fourier coefficients \( a_n \) and \( b_n \) for \( n = 1, 2, ..., N \)

The coefficients are entered manually through the interface table.

---

## Code Implementation

The Fourier series of a periodic function is defined as:

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos(n\omega_0 t)+b_n \sin(n\omega_0 t)\right)
$$

Where:

- \( t \) → time variable  
- \( n \) → harmonic index  
- \( \omega_0 = \frac{2\pi}{T} \) → fundamental angular frequency  

In the implementation:

- The infinite summation is truncated at \( N \).
- Each harmonic is computed as:

$$
H_n(t)=a_n \cos(n\omega_0 t)+b_n \sin(n\omega_0 t)
$$

- The total signal is computed as:

$$
S_N(t)=\frac{a_0}{2}+\sum_{n=1}^{N} H_n(t)
$$

- A partial sum \( S_K(t) \) is also computed for \( K \leq N \) to demonstrate convergence behavior.

---

## Key Observations from Implementation

## Key Observations from Implementation

Each harmonic component behaves independently and corresponds to a specific multiple of the fundamental frequency. As the number of harmonics \( N \) increases, the Fourier approximation converges toward the target waveform. When square wave coefficients are used, oscillations near discontinuities become visible, illustrating the **Gibbs phenomenon**. Overall, the implementation clearly demonstrates the linearity and superposition principle of the Fourier Series.

---

## Example Results

When square wave coefficients are used:

- \( a_n = 0 \)
- \( b_n = \frac{4}{n\pi} \) for odd \( n \), and 0 otherwise

As \( N \) increases, the waveform approaches the shape of a square wave.

---

## References

Glyn James, *Advanced Modern Engineering Mathematics*, Fourth Edition  

locogame, *Coding a Fourier Transform in C*
