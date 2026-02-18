# Fourier Series Visualization

Using the Fourier coefficients (a_n and b_n) entered by the user, each harmonic component will be calculated separately and plotted graphically. Subsequently, the values of these components at the same time t will be summed to create partial and complete sum graphs of the Fourier series. Thus, the superposition principle of harmonics will be visually demonstrated. 

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

---

## References

Glyn James, *Advanced Modern Engineering Mathematics*, Fourth Edition  

locogame, *Coding a Fourier Transform in C*


