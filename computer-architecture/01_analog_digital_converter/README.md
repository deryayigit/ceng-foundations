# Analog-to-Digital Conversion (ADC)

Analog-to-Digital Converters (ADCs) are electronic systems that transform continuous analog signals into discrete digital representations. They serve as a fundamental bridge between the physical world and digital processing systems.

In modern computing systems, particularly in embedded environments, most real-world data is obtained through sensors. These sensors measure physical quantities such as temperature, pressure, light intensity, or distance and convert them into electrical signals, typically in the form of voltage or current. These signals are inherently analog in nature.

However, digital systems such as microprocessors and microcontrollers can only process discrete digital data. Therefore, analog signals must be converted into digital form before they can be processed, stored, or transmitted. This transformation is performed by ADC systems.

---

## Fundamental ADC Operations  

The operation of an ADC can be described as a three-stage process. First, the continuous-time analog signal is sampled at discrete time intervals. Then, each sampled value is mapped to the nearest level within a finite set of discrete values, a process known as quantization. Finally, the quantized value is encoded as a binary number so that it can be processed by digital systems.

This process can be summarized as:

**Sample → Quantize → Encode**

<p align="center">
  <img src="https://raw.githubusercontent.com/deryayigit/ceng-foundations/main/computer-architecture/images/ADC-scheme.png" width="800"/>
  <br/>
  <em>ADC Conversion Process: Sampling → Quantization → Encoding</em>
</p>

---

## Resolution  

The resolution of an ADC refers to its ability to distinguish small changes in the input signal. It is directly determined by the number of bits used in the digital output. An n-bit ADC produces \(2^n\) discrete levels, meaning that increasing the number of bits results in finer granularity and improved precision.

Although higher resolution reduces quantization error, practical limitations such as noise and non-linearity in the system prevent achieving ideal precision in real-world applications.

---

## Quantization Step (Quantum Level)

The quantization step size \( q \) represents the smallest change in the input signal that can be detected by the ADC. It is determined by the range of the input signal and the resolution of the converter.

$$
q = \frac{V_{max} - V_{min}}{2^n - 1}
$$

A smaller value of \( q \) indicates higher resolution and allows the analog signal to be represented more accurately in digital form.

---

## Sampling  

Analog signals are continuous in time, meaning that they have a value at every instant. Capturing every possible value is neither practical nor necessary, so the signal is sampled at discrete time intervals. The sampling frequency plays a critical role in accurately representing the original signal and must satisfy the Nyquist criterion to avoid aliasing effects.

---

## Quantization  

Quantization is the process of mapping sampled values to the nearest discrete level. This process inherently introduces an error because the exact analog value cannot always be represented precisely. This error is known as quantization error and is defined as the difference between the original analog value and its quantized representation.

---

## ADC Types  

### Ramp (Counter-Type) ADC  

In a ramp ADC, a staircase signal is generated and continuously compared with the input signal. The digital counter increments step by step until the generated signal exceeds the input value. Although this method is simple to implement, it has a relatively slow conversion speed because it performs a linear search across all possible levels.

---

### Successive Approximation ADC  

The successive approximation ADC operates using a binary search approach. Instead of testing all levels sequentially, it starts with the most significant bit and progressively refines the result by testing each bit. This method significantly reduces the number of steps required to reach the final value, making it much faster than the ramp ADC. It typically utilizes a comparator, a digital-to-analog converter (DAC), and a successive approximation register (SAR).

---

## Experimental Implementation  

In this experiment, the fundamental processes of analog-to-digital conversion are modeled and analyzed using Python. The implementation includes signal sampling, quantization behavior, and the operation of both ramp and successive approximation ADC methods. These simulations provide a step-by-step understanding of how analog signals are converted into digital form at a low level.

---

## Observations  

Increasing the resolution significantly reduces quantization error, resulting in a more accurate digital representation of the analog signal. The successive approximation ADC demonstrates much faster convergence compared to the ramp method, highlighting the efficiency of binary search techniques in hardware design. Although quantization error cannot be completely eliminated, it can be minimized by increasing the number of bits. Additionally, the sampling frequency has a direct impact on how accurately the original signal can be represented.

---

## Conclusion  

Analog-to-digital conversion is a fundamental process that enables digital systems to interact with the physical world. Understanding the internal operation of ADC systems provides deeper insight into how real-world signals are captured, approximated, and processed within modern computing systems.

## References

1. Steven W. Smith – *The Scientist and Engineer’s Guide to Digital Signal Processing*, Second Edition  
   https://www.dspguide.com/
   
2. Karadeniz Technical University, Computer Organization Laboratory Documentation.

3. https://github.com/yildiz-busra/Organizasyon-Lab
