# Digital Signal Processing (DSP) 
---

## Basic Concepts

### Continuous Signal
A signal that is continuous in time and can take any value at any moment.  
Example: Audio waveform, analog temperature sensor output.

### Discrete Signal
A signal obtained by measuring the continuous signal at specific intervals and converting it to digital form.  
Example: Audio sampled by an ADC.

### Mean (μ)
Represents the central value of a dataset.

\[
\mu = \frac{1}{N} \sum_{i=1}^{N} x_i
\]

### Variance (σ²)
Indicates how much the data deviates from the mean.

\[
\sigma^2 = \frac{1}{N} \sum_{i=1}^{N} (x_i - \mu)^2
\]

### Standard Deviation (σ)
The square root of the variance; used to understand data spread.

\[
\sigma = \sqrt{\sigma^2}
\]

---

## ADC and Digitization

- **Sampling:** Taking the signal at specific intervals along the time axis (x-axis).  
- **Quantization:** Rounding the signal to specific levels along the amplitude axis (y-axis).  
- **Alias (Sampling Noise):** High-frequency components appearing as low-frequency due to insufficient sampling.  
- **Quantization Error / Noise:** Errors created during amplitude discretization.

💡 Increasing the number of samples improves quality, but increases cost and data size.

---

## Example Project Ideas

## DFT (Discrete Fourier Transform)

Discrete Fourier Transform (DFT) is used to analyze the frequency components of a discrete signal.

---

## Additional Concepts

- **Aliasing:** Misrepresentation of a signal at the wrong frequency due to insufficient sampling.  
- **Noise:** Signal error caused by ADC or environmental effects.  
- **Butterworth Filter:** A signal filter that passes frequencies within a specific range.  
- **Gray Scale Transform:** Converting color image data to grayscale in image processing.

---

## References

- Oppenheim, A. V., & Schafer, R. W. *Discrete-Time Signal Processing*.  
- Smith, S. W. *The Scientist and Engineer's Guide to DSP*.  
- Online DSP Tutorials: [https://www.dspguide.com](https://www.dspguide.com)
