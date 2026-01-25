# Digital Signal Processing (DSP) 
---

## Basic Concepts

**Statistics and Probability Concepts**
Mean:
Variance:
Standart Deviation:
PDF:
CDF:
---

### Continuous Signal
A signal that is continuous in time and can take any value at any moment.  
Example: Audio waveform, analog temperature sensor output.

### Discrete Signal
A discrete signal is a sequence of values obtained by **sampling a continuous signal at uniform intervals in time**. Each sample represents the amplitude of the signal at that specific time. Discrete signals are typically processed digitally using algorithms such as **DFT (Discrete Fourier Transform)**, filters, or difference equations.

<img width="200" height="350" alt="fig001" src="https://github.com/user-attachments/assets/136651b1-a197-4364-b323-d3fe5a886dfa" />

<img width="200" height="350" alt="fig002" src="https://github.com/user-attachments/assets/0cfa3f61-e735-4546-aa5b-9cc040e6c211" />


**Summary:**  
A discrete signal is simply a **sequence of sampled values from a continuous signal** and should not be confused with specific analysis techniques applied to it.


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


## Digitization of Continuous Signals

A continuous signal is digitized by passing it through an **ADC (Analog-to-Digital Converter)**, allowing real-world data to be transferred into the digital domain.

The discretization of the continuous signal from the ADC occurs along the **x** and **y** axes:

- **Sampling**: Discretization along the x-axis (time axis).  
- **Quantization**: Discretization along the y-axis (amplitude axis).

In the digital conversion process:

- Losses along the x-axis are called **sampling noise** or **aliasing**.  
- Losses along the y-axis are called **noise** or **quantization error**.

To reduce these losses, the number of samples should be increased. However, while increasing the number of samples up to a certain point improves conversion quality, excessive sampling can lead to **inefficiency** and **higher costs**.


  
---

**Convulation**


## References

- Oppenheim, A. V., & Schafer, R. W. *Discrete-Time Signal Processing*.  
- Smith, S. W. *The Scientist and Engineer's Guide to DSP*.  
- Online DSP Tutorials: [https://www.dspguide.com](https://www.dspguide.com)











