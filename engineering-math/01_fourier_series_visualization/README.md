# Fourier Series Visualization

Using the Fourier coefficients \(a_n\) and \(b_n\) entered by the user, each harmonic component is calculated separately and plotted graphically. Subsequently, the values of these components at the same time \(t\) are summed to generate the partial and complete Fourier series approximations. In this way, the **superposition principle of harmonics** is visually demonstrated.

---

## Mathematical Model

The implemented Fourier series corresponds to the trigonometric representation

$$
f(t) =
\frac{a_0}{2}
+
\sum_{n=1}^{N}
\left[
a_n \cos\left(\frac{2\pi n t}{T}\right)
+
b_n \sin\left(\frac{2\pi n t}{T}\right)
\right]
$$

| Symbol | Description |
|------|-------------|
| \(T\) | Period of the signal |
| \(a_0\) | Constant (DC) component |
| \(a_n\) | Fourier cosine coefficients |
| \(b_n\) | Fourier sine coefficients |
| \(N\) | Number of harmonics used in the approximation |

---

## Input Format

In this application, the user specifies the parameters of the Fourier series through the graphical interface. The user provides the number of harmonics \(N\), the signal period \(T\), and the constant term \(a_0\). In addition, the Fourier cosine coefficients \(a_n\) and sine coefficients \(b_n\) are entered manually. These coefficients are supplied as comma-separated lists corresponding to the harmonic indices \(n = 1,2,\dots,N\). Based on these inputs, the program constructs the truncated Fourier series and performs the numerical evaluation over the selected time interval.


---

## Code Implementation


### Pseudo Code

```text
Read N
Read period T
Read coefficients a0, an, bn

Compute fundamental frequency

w0 = 2π / T

Generate time samples

for each time t

    sum = a0/2

    for n=1..N
        sum += an*cos(n*w0*t)
        sum += bn*sin(n*w0*t)

    store (t,sum)

Plot results

```
---

## Key Observations from Implementation

Each harmonic component behaves independently and corresponds to a specific multiple of the fundamental frequency. As the number of harmonics \( N \) increases, the Fourier approximation converges toward the target waveform. When square wave coefficients are used, oscillations near discontinuities become visible, illustrating the **Gibbs phenomenon**. Overall, the implementation clearly demonstrates the linearity and superposition principle of the Fourier Series.

---

## Example Results

---

## References

Glyn James, *Advanced Modern Engineering Mathematics*, Fourth Edition  

locogame, *Coding a Fourier Transform in C*




