# Digital Signal Processing (DSP)

## Repository Structure
This repository was created as part of a university-level Digital Signal Processing (DSP) course and contains course projects, applied assignments, and conceptual coding studies developed throughout the course.

The primary objective of this repository is to demonstrate how theoretical knowledge in the field of Digital Signal Processing is translated into practical implementations through a project-based approach. Each folder within the repository contains either an independent course project or a set of implementations focused on a specific DSP concept.

Each folder represents a standalone DSP concept.
Detailed explanations, mathematical background, and implementation details
are provided in the README files within each project directory.

---

## Purpose of This Repository
This repository was created to support the understanding of core Digital Signal Processing (DSP) concepts through practical implementations. Rather than relying directly on high level DSP libraries, the projects emphasize the underlying algorithms, their numerical behavior, and their effects on signals. The implementations are developed with an educational focus, aiming to reinforce the mathematical foundations of the applied methods and to enable meaningful interpretation of the statistical and temporal characteristics of signals.

---

## Key Observations from Implementations
As a result of the implementations carried out in this repository, it has been observed that histogram based PMF analyses tend toward a Gaussian like distribution as multiple independent images are summed together, which clearly demonstrates how the statistical behavior of image pixel values changes under accumulation. It has also been observed that variance and standard deviation computed using a streaming approach prevent numerical instability compared to classical naive methods and produce more reliable results for long data streams. In addition, increasing the sampling frequency improves the digital representation of a signal only up to a certain point, beyond which further increases in the sampling rate do not introduce new information and merely increase computational load. These observations highlight the importance of consciously selecting both statistical methods and sampling and quantization parameters in digital signal processing systems.

---

## Definition
Digital Signal Processing (DSP) is an engineering discipline concerned with converting signals obtained from the analog world into digital form and applying mathematical and algorithmic operations to these signals. DSP encompasses the collection of mathematical methods, algorithms, and techniques used to process signals once they have been digitized.

The foundations of DSP are rooted in mathematics, probability theory, system theory, and electronics. The breadth of the field arises from its application to a wide range of disciplines such as telecommunications, audio processing, image processing, radar–sonar systems, and biomedical applications. Each of these areas has developed its own specialized algorithms, mathematical models, and techniques. The depth of DSP stems from advanced signal processing algorithms, transforms, and statistical models developed specifically for these application domains.


### 1. Telecommunications

  Telecommunications deals with the transfer of information from one location to another. In order for information to be transmitted, a channel is required between two locations. This channel may be a pair of wires, a radio signal, an optical fiber, etc. While telecommunications companies generate revenue by carrying customers’ information, they incur costs to build and maintain these channels. DSP has transformed telecommunications in many ways. In this section, three examples are considered: multiplexing, compression, and echo control.

#### 1.1 Multiplexing

  Thanks to DSP, audio signals are sampled, digitized, and converted into separable data streams; this provides increased capacity and cost advantages in communication systems.
  he economic advantage of digital transmission is significant: cables and analog switches are expensive, whereas digital logic gates are inexpensive.

#### 1.2 Compression

  Digital audio signals contain a high degree of redundancy between neighboring samples. DSP-based data compression algorithms reduce this redundancy, thereby lowering the bit rate required for transmission and storage. As the compression ratio increases, perceived audio quality decreases; however, depending on the application, this loss may be acceptable.

#### 1.3 Echo Control

  Echo control is the process of modeling delayed returning audio signals in communication systems using DSP and canceling the echo by generating an appropriate antisignal. This technique is used to improve communication quality in long-distance telephone connections and speakerphone systems.


### 2. Echo Location

  Echo location enables the extraction of location and structural information by analyzing the time and amplitude characteristics of reflected waves. DSP plays a central role in separating and interpreting echoes in this process. Radar (Radio Detection and Ranging), sonar, and reflection seismology fall into this category.

  A common way to obtain information about a distant object is to transmit a wave toward it and analyze the reflected signal. For example, radar systems transmit radio wave pulses and examine echoes returned from aircraft. In sonar, sound waves are transmitted into water to detect submarines and other underwater objects. Geophysicists have long studied the Earth’s crust by generating explosions and listening to echoes returning from deep underground layers. Although these applications share a common principle, each has its own specific problems and requirements.

  The operating range of a radar system depends on two parameters: the amount of energy contained in the transmitted pulse and the noise level of the receiver. Increasing pulse energy generally requires increasing pulse duration, which reduces time measurement accuracy. As a result, a fundamental trade-off arises between long-range detection and precise distance estimation.

#### 2.1 Sonar (SOund NAvigation and Ranging)

  Sonar systems are divided into two categories: active and passive. In active sonar, sound pulses in the range of 2 kHz to 40 kHz are transmitted into water, and the returning echoes are detected and analyzed. Active sonar is used for underwater object detection and localization, navigation, communication, and seabed mapping. Typical maximum operating ranges are between 10 and 100 kilometers. Passive sonar, on the other hand, only listens to underwater sounds such as natural turbulence, marine life, and mechanical noise from vessels. Since passive sonar does not emit energy, it is ideal for covert operations.

  DSP has revolutionized sonar in ways similar to radar, including pulse generation, pulse compression, and filtering. Due to the irregular and unstable underwater environment, sonar problems are often more challenging. Sonar systems typically use arrays of transmitters and receivers, enabling beam steering and direction-of-arrival estimation.

#### 2.2 Radar (Radio Detection and Ranging)

  Radar determines the range and direction of objects by transmitting radio-frequency pulses and processing the returned echoes. Distance is computed from the time delay between transmission and reception, while antenna orientation determines angular position.

  Radar performance is primarily limited by pulse energy and receiver noise. Longer ranges require higher-energy and longer-duration pulses, but increasing pulse duration reduces range resolution, creating a fundamental range–resolution trade-off.

  DSP overcomes this trade-off through pulse compression, digital filtering, and waveform optimization. Modern radar systems often operate at sampling rates close to radio frequency, making DSP both an algorithmic and high-speed hardware design challenge.

#### 2.3 Reflection Seismology

  Reflection seismology analyzes waves reflected from subsurface layers. Multiple reflections complicate real-world signals. DSP enables separation of primary and secondary echoes, allowing reliable modeling of subsurface structures and enabling oil exploration in difficult regions.


### 3. Medicine

  In medical imaging, DSP enables separation of overlapping structures, enhancement of tissue contrast, and extraction of physiological information. Computed tomography and magnetic resonance imaging produce diagnostically valuable cross-sectional images through DSP.


### 4. Space

  In space applications, DSP improves degraded images, corrects spatial distortions, and combines multiple images to produce meaningful visual information, enabling remote sensing and planetary analysis.


### 5. Image Processing

  DSP models images as discrete digital signals over spatial domains, enabling filtering, frequency analysis, noise suppression, and compression. This approach forms the mathematical foundation of modern image and video processing.


### 6. Music Processing

  DSP enables processing of multi-channel music signals through filtering, addition, subtraction, and time–frequency domain operations. Artificial echo and reverberation effects are based on digital modeling of acoustic environments.


### 7. Speech Generation & Recognition

  Speech generation aims to digitally synthesize human voice signals. DSP achieves this by processing prerecorded speech or modeling the vocal tract with digital filters. Speech recognition relies on feature extraction and feature matching, using time–frequency analysis as a foundation.

---

## Statistics, Probability and Noise

  In Digital Signal Processing (DSP), statistics and probability are used to understand the processes that generate signals and the behavior of these processes. Signals obtained from the real world are not ideal; measurement systems have inherent limitations. In addition, environmental effects are present, and the measured quantities often contain randomness. Therefore, one of the fundamental objectives of DSP is to suppress interference, noise, and other undesired components in the acquired data, or at least to characterize them accurately. These disturbing components may originate from the nature of the signal itself, from imperfections in the measurement system, or may arise as an unavoidable consequence of applied DSP operations. Statistics and probability provide the theoretical foundation necessary to make these irregularities measurable, comparable, and meaningful, and to develop methods for effectively dealing with undesired components.


  Signal is a function that carries information and represents variations in a physical or quantitative quantity as a function of one or more independent variables. Signals can be classified as continuous or discrete from a mathematical perspective, and as analog or digital according to their physical realization. In general, continuous signals are encountered in nature, while discrete (digitized) signals exist within computers and digital systems. However, exceptions exist for both cases.

  A signal is defined by the relationship between an independent variable and the corresponding dependent variable. Amplitude represents the numerical value of the physical quantity conveyed by the signal and reflects the magnitude or intensity of the information it carries. In graphical representations, amplitude is shown on the y-axis (dependent variable) and is also referred to as the ordinate, amplitude, or dependent variable. The x-axis represents the independent variable of the signal and is referred to as the abscissa. This independent variable is most commonly time, but depending on the application, it may also represent frequency, distance, or sample index. While the independent variable determines when or under what conditions the samples are taken, the dependent variable represents the measured quantity itself.

## Mean and Standard Deviation

Mean, variance, standard deviation, and standard error are fundamental concepts in statistics and engineering mathematics used for data analysis and interpretation. These measures provide quantitative information about the central tendency, variability, and spread of a dataset.

In engineering applications, these concepts play a crucial role in evaluating measurement results, analyzing noise, understanding signal behavior, and interpreting system performance.

---

### Mean (Average)

The mean is a basic measure of the central tendency of a dataset. It is obtained by summing all data values and dividing the result by the total number of samples. The mean represents the overall level of the data; however, by itself, it does not provide information about how the data are distributed around this central value.

$$
\mu = \frac{1}{N} \sum_{i=0}^{N-1} x_i
$$


### Variance

Variance is a measure of how far the values in a dataset deviate from the mean. It quantitatively describes the variability of the data around the central value.

Variance is calculated by taking the average of the squared differences between each data point and the mean. Squaring the differences ensures that positive and negative deviations do not cancel each other.

$$
\sigma^2 = \frac{1}{N - 1} \sum_{i=0}^{N-1} (x_i - \mu)^2
$$

*Note:* The term \( N - 1 \) is known as **Bessel’s correction**.


*Note:* The term \( N - 1 \) in the denominator is known as **Bessel’s correction** and provides an unbiased estimate of the population variance when using sample data.

### Standard Deviation

Standard deviation is defined as the square root of the variance and expresses the spread of the data in the same units as the original measurements. This makes it more intuitive and easier to interpret than variance.

Standard deviation indicates how far, on average, the data values lie from the mean and is widely used in engineering and scientific applications.

$$
\sigma = \sqrt{\frac{1}{N - 1} \sum_{i=0}^{N-1} (x_i - \mu)^2}
$$

#### Expanded Form

$$
\sigma =
\sqrt{
\frac{
(x_0 - \mu)^2 +
(x_1 - \mu)^2 +
\cdots +
(x_{N-1} - \mu)^2
}{
N - 1
}
}
$$


This form explicitly shows that the standard deviation is based on the deviations of all samples from the mean.

### Relationship Between Mean, Variance, and Standard Deviation

Mean, variance, and standard deviation are closely related measures that together provide a complete statistical description of a dataset. The mean determines the central value around which the data are distributed and represents the overall level of the dataset. Variance quantifies how much the data values deviate from this central value and therefore measures the degree of variability present in the data. Since variance is expressed in squared units, its direct interpretation may be unintuitive. Standard deviation resolves this issue by expressing the variability in the same units as the original data, making it easier to interpret. In this context, the mean indicates where the data are centered, variance describes how variable the data are, and standard deviation conveys how widely the data values are spread around the mean in a practical and interpretable manner.


### Standard Error of the Mean

The standard error of the mean is a measure used to evaluate how accurately the sample mean estimates the population mean. It reflects uncertainty due to the sampling process rather than the variability of the data itself.

As the number of samples increases, the standard error decreases, indicating a more reliable estimate of the population mean.

$$
\mathrm{SE}_{\mu} = \frac{\sigma}{\sqrt{N}}
$$


While standard deviation is a descriptive statistic, standard error is an inferential measure related to sampling uncertainty.

---

## The Histogram, PMF and PDF

The probability density function of the normal (Gaussian) distribution is given by:

$$
f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}
$$

---

## ADC and DAC

  Analog-to-digital conversion (ADC) enables a continuous-time and continuous-amplitude signal to be processed by digital systems. This process consists of the stages of sampling and quantization. A continuous signal is digitized by passing it through an ADC, thereby allowing real-world data to be transferred into the digital domain.
  The discretization of a continuous signal passing through an ADC occurs along both the x-axis and the y-axis. Discretization along the x-axis, that is, the time axis, is called sampling.Discretization along the y-axis, that is, the amplitude axis, is called quantization.
  During the digitization process, losses inevitably occur due to the conversion itself, since it is never possible to achieve a 100% efficient analog-to-digital conversion. These losses have two categorization Discretization along the x-axis results in sampling distortion, also known as aliasing, other one is Discretization along the y-axis is referred to as noise or quantization error.

  To reduce the losses occurring along the x-axis, that is, sampling distortion, the number of samples must be increased.
  Increasing the sampling rate up to a certain limit improves conversion quality and enables a more accurate representation of the signal; however, excessive sampling leads to inefficiency without further improvement.

| ADC | DAC |
|-----|-----|
| <img src="https://github.com/user-attachments/assets/e5950948-d115-43f6-a788-c259983ccae5" width="450"/> | <img src="https://github.com/user-attachments/assets/20e9648c-bf85-4f7d-b614-67df946b88d4" width="450"/> |


### Quantization

  Quantization is the process by which the amplitude values of a sampled analog signal are mapped from a continuous range to a finite set of discrete digital levels. In an ADC, quantization is performed by rounding the true analog amplitude of each sample to the nearest digital value within predefined quantization intervals. During this process, the dependent variable of the analog signal (for example, voltage) is converted from a continuous form to a discrete one, and an unavoidable loss of information occurs because different analog values that fall within the same quantization interval are represented by a single digital code. This difference is referred to as quantization error, which in an ideal ADC is bounded within ±½ LSB for each sample.

  When the signal is sufficiently varying or already contains natural analog noise, the quantization error appears with small magnitude and varying sign across samples; therefore, in practice, quantization error can be modeled as a random noise component with zero mean and limited amplitude. Quantization resolution depends on the number of bits: as the bit depth increases, the least significant bit (LSB) becomes smaller, resulting in a finer digital representation. However, if the intrinsic noise level of the analog signal exceeds the quantization step size, increasing the bit depth cannot reveal new information that is not already present in the signal; it merely provides a more detailed digital representation of the existing analog noise.

  Quantization is therefore regarded as a fundamental and limiting mechanism that determines the amount of information an ADC can transfer from the analog signal.

### The Sampling Theorem
  The Sampling Theorem defines the conditions under which a continuous-time signal can be reconstructed uniquely and completely from its samples. According to the theorem, an analog signal is correctly sampled only if it contains no frequency components higher than half of the sampling frequency, known as the Nyquist frequency. When this condition is satisfied, no information is lost, even if the samples appear sparse or insufficient, because sampling implicitly encodes the complete frequency content of the analog signal, not merely its instantaneous values.

  Theoretically, sampling is modeled as the multiplication of a continuous-time signal by an impulse train in the time domain. This operation causes periodic replications of the signal spectrum at integer multiples of the sampling frequency in the frequency domain. When the sampling frequency satisfies the Nyquist criterion, these spectral replicas do not overlap, and the information in the baseband is preserved. Consequently, the original analog signal can be perfectly and uniquely reconstructed from its samples using an ideal low-pass filter.

  When the spectral replicas are properly separated below the Nyquist frequency, the information is preserved. However, if the analog signal contains frequency components above the Nyquist limit, these replicas overlap, resulting in aliasing. In the presence of aliasing, different analog frequencies produce the same digital frequency component, and even phase information may be inverted. As a result, the sampled data can no longer be uniquely associated with the original analog signal, leading to irreversible information loss. Therefore, the Sampling Theorem defines not only the lower bound on the sampling rate but also the necessity of anti-aliasing filtering and serves as the central theoretical foundation of analog-to-digital conversion in digital signal processing.

$$
f_s \geq 2 f_{\text{max}}
$$

If this condition is violated, aliasing occurs and information loss is irreversible.

---

## DSP Software


---

## Linear Systems

---

## Convolution

---

## Fourier Transform

---

## Digital Filters

---

## References

1. Steven W. Smith – *The Scientist and Engineer’s Guide to Digital Signal Processing*, Second Edition  
   https://www.dspguide.com/
  
2. Hackatronic – *Analog to Digital Converter (ADC): Block Diagram, Working, Types and Applications*  
   https://hackatronic.com/analog-to-digital-converter-adc-block-diagram-working-types-applications/

3. Predictable Designs – *Introduction to Analog-to-Digital Converters (ADC)*  
   https://predictabledesigns.com/introduction-to-analog-to-digital-converters-adc/

4. Arrow Electronics – *Engineering Resource: Basics of Analog-to-Digital Converters*  
   https://www.arrow.com/en/research-and-events/articles/engineering-resource-basics-of-analog-to-digital-converters

6. D. E. Knuth, *The Art of Computer Programming, Vol. 2: Seminumerical Algorithms*

7. https://github.com/ertugrulkalkan/digital-signal-processing

8. University of Southampton Library – *Variance, Standard Deviation and Standard Error*  
https://library.soton.ac.uk/variance-standard-deviation-and-standard-error  

9. GeeksforGeeks – *Mean, Variance and Standard Deviation* 
---

## Acknowledgments

The assignments and implementations included in this repository were prepared within the scope of the Digital Signal Processing (DSP) course offered by the Department of Computer Engineering at Karadeniz Technical University. I would like to thank Dr. Sedat Görmüş, the instructor of the Digital Signal Processing course, for his lectures, guidance, and contributions that helped shape an engineering-oriented perspective.


