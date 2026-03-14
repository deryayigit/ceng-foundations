# Fourier Series Visualization

This project demonstrates the graphical visualization of a Fourier series constructed from user-defined harmonic coefficients.

---

## Objective

The objective of this project is to numerically evaluate and visualize a Fourier series using user-provided Fourier coefficients. The program allows the user to define the number of harmonics and the corresponding sine and cosine coefficients, and then computes the resulting signal over a specified time interval. The graphical output illustrates how harmonic components combine to form the final waveform.

---
## Mathematical Model

The implemented Fourier series corresponds to the trigonometric representation

$$
f(t) = \frac{a_0}{2} + \sum_{n=1}^{N} \left( a_n \cos(n\omega_0 t) + b_n \sin(n\omega_0 t) \right)
$$

| Symbol | Description |
|------|-------------|
| $T$ | Period of the signal |
| $a_0$ | Constant (DC) component |
| $a_n$ | Fourier cosine coefficients |
| $b_n$ | Fourier sine coefficients |
| $N$ | Number of harmonics used in the approximation |
| $\omega_0$ | Fundamental angular frequency |
| $\omega_0 = \frac{2\pi}{T}$ | Relation between angular frequency and the signal period |

---

## Input Format

In this application, the user specifies the parameters of the Fourier series through a graphical interface. The user manually enters the number of harmonics $N$, the signal period $T$, and the constant coefficient $a_0$, while the Fourier cosine coefficients $a_n$ and sine coefficients $b_n$ for 
$n = 1,2,\dots,N$ are entered as comma-separated values. Based on these parameters, the program constructs a truncated Fourier series and computes the signal values over a discrete set of time samples.

---

## Code Implementation

## Code Implementation

The program is implemented in C++ using the Windows Forms framework and the 
`.NET System.Windows.Forms.DataVisualization.Charting` library for graphical 
visualization. The implementation is structured into two main components: the 
numerical evaluation of the Fourier series and the graphical representation of 
the resulting signal.

User input is obtained through a graphical interface that allows the user to 
specify the constant coefficient $a_0$, the number of harmonics $N$, and the 
Fourier coefficients $a_n$ and $b_n$. The coefficients are entered as 
comma-separated values and parsed into numerical arrays that represent the 
harmonic parameters of the series.

For each time sample within the selected interval, the program evaluates the 
truncated Fourier series using the trigonometric representation

$$
f(t) = \frac{a_0}{2} + \sum_{n=1}^{N} \left( a_n \cos(n\omega_0 t) + b_n \sin(n\omega_0 t) \right).
$$

Each harmonic contribution is computed individually and added to the running 
sum representing the reconstructed signal. The program also stores the value 
of each harmonic component separately, allowing the visualization of both the 
individual harmonics and the final combined waveform.

The computed data points are then plotted using the `Chart` control provided 
by the Windows Forms charting library. Individual harmonic components are 
displayed as separate colored curves, while the reconstructed signal is drawn 
as a thicker line to emphasize the final result. This visualization clearly 
illustrates how harmonic components contribute to the overall signal 
structure.

### Pseudo Code

```text
Input N
Input period T
Input coefficients a0, an[], bn[]

Compute fundamental angular frequency

w0 = 2π / T

Generate time samples

for each time t:

    sum = a0 / 2

    for n = 1 to N:
        sum += an[n] * cos(n * w0 * t)
        sum += bn[n] * sin(n * w0 * t)

    store (t, sum)

Plot the resulting signal

```
---

## Key Observations from Implementation

Each harmonic component represents a sinusoidal signal with frequency $n\omega_0$, and the final waveform is obtained by summing these harmonic components. As the number of harmonics increases, the truncated Fourier series provides a progressively better approximation of the reconstructed signal. Lower-frequency harmonics primarily determine the global structure of the waveform, while higher-frequency components refine the detailed features of the signal. The graphical visualization produced by the program clearly demonstrates how individual harmonic components combine to form the final signal.

---

## Example Results

The animation below illustrates how the Fourier series approximation improves as the number of harmonics increases.

![Fourier Series Animation](fourier_series_animation.gif)

---

## References

Glyn James, *Advanced Modern Engineering Mathematics*, Fourth Edition  

locogame, *Coding a Fourier Transform in C*
