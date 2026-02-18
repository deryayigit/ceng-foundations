# Fourier Series Visualization

## Project Scope

This project aims to visualize the Fourier Series using user-defined Fourier coefficients \( a_n \) and \( b_n \).

Each harmonic component is calculated individually and plotted separately. Then, at a given time \( t \), these harmonic values are summed to generate:

- The partial sum of the Fourier series
- The complete (up to N) Fourier approximation

This allows a visual demonstration of the **superposition principle**, showing how independent harmonic components combine to form a complex waveform.

---

## Input Format

In this application, the user specifies the number of harmonics \( N \), the period \( T \), and the constant term \( a_0 \). The Fourier coefficients \( a_n \) and \( b_n \) for \( n = 1, 2, ..., N \) are entered manually through the interface table. Based on these inputs, the program constructs the truncated Fourier series and performs the numerical evaluation over the defined time interval.

---

## Code Implementation

---

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

