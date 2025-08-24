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

<img width="146" height="101" alt="image" src="https://github.com/user-attachments/assets/47be30b8-a3d5-41db-b894-03ce82a6514d" />

### Variance (σ²)
Indicates how much the data deviates from the mean.

<img width="205" height="85" alt="image" src="https://github.com/user-attachments/assets/460367f4-ba71-445a-a45c-89758a0d3c10" />


### Standard Deviation (σ)
The square root of the variance; used to understand data spread.

<img width="108" height="51" alt="image" src="https://github.com/user-attachments/assets/ffc3d60a-b6db-41f7-a391-366d20bf7607" />


---

# Digital Signal Processing (DSP) Overview

## Signal Digitization

A continuous signal is digitized by passing it through an **ADC (Analog-to-Digital Converter)**, transferring real-world data into the digital domain. The discretization occurs in both **time** and **amplitude**:

- **Sampling (Time Discretization / x-axis)**: The process of converting a continuous-time signal into a discrete-time signal by taking measurements at regular time intervals.
- **Quantization (Amplitude Discretization / y-axis)**: The process of mapping a continuous amplitude signal to discrete levels.

### Errors and Noise

- **Aliasing**: Errors that occur during time discretization when the sampling rate is insufficient.
- **Quantization Error**: Errors introduced during amplitude discretization due to the finite resolution of the ADC.

### Improving Conversion Quality

To minimize errors and improve digital signal quality:

- Increase the **sampling rate** (number of samples per unit time).
- Balance the number of samples to avoid excessive processing cost and efficiency loss.

  
---


## References

- Oppenheim, A. V., & Schafer, R. W. *Discrete-Time Signal Processing*.  
- Smith, S. W. *The Scientist and Engineer's Guide to DSP*.  
- Online DSP Tutorials: [https://www.dspguide.com](https://www.dspguide.com)


