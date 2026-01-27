# Digital Signal Processing (DSP)

Digital Signal Processing (DSP) is an engineering field concerned with converting signals obtained from the analog world into digital form and applying mathematical and algorithmic operations to these signals.

DSP is the collection of mathematics, algorithms, and techniques used to process signals once they have been converted into digital form. The foundations of DSP are rooted in mathematics, probability theory, system theory, and electronics. The breadth of the field arises from its application to many disciplines such as telecommunications, audio processing, image processing, radar–sonar systems, and biomedical applications, each of which has developed a deep DSP technology with its own specific algorithms, mathematics, and specialized techniques. The depth of DSP stems from the specialized algorithms, transforms, and statistical models developed for each of these application domains.

The main application areas in which DSP methods are used are listed below.

---

## 1. Telecommunications

Telecommunications deals with the transfer of information from one location to another. In order for information to be transmitted, a channel is required between two locations. This channel may be a pair of wires, a radio signal, an optical fiber, etc. While telecommunications companies generate revenue by carrying customers’ information, they incur costs to build and maintain these channels. DSP has transformed telecommunications in many ways. In this section, three examples are considered: multiplexing, compression, and echo control.

### 1.1 Multiplexing

There are approximately one billion telephones worldwide. By pressing a few buttons, switching networks allow any of these devices to be connected to another within a few seconds. Traditionally, each connection required a dedicated physical channel.

Thanks to DSP, audio signals are sampled, digitized, and converted into separable data streams; this provides increased capacity and cost advantages in communication systems.

The economic advantage of digital transmission is significant: cables and analog switches are expensive, whereas digital logic gates are inexpensive.

### 1.2 Compression

Digital audio signals contain a high degree of redundancy between neighboring samples. DSP-based data compression algorithms reduce this redundancy, thereby lowering the bit rate required for transmission and storage. As the compression ratio increases, perceived audio quality decreases; however, depending on the application, this loss may be acceptable.

### 1.3 Echo Control

Echo control is the process of modeling delayed returning audio signals in communication systems using DSP and canceling the echo by generating an appropriate antisignal. This technique is used to improve communication quality in long-distance telephone connections and speakerphone systems.

---

## 2. Echo Location

Echo location enables the extraction of location and structural information by analyzing the time and amplitude characteristics of reflected waves. DSP plays a central role in separating and interpreting echoes in this process. Radar (Radio Detection and Ranging), sonar, and reflection seismology fall into this category.

A common way to obtain information about a distant object is to transmit a wave toward it and analyze the reflected signal. For example, radar systems transmit radio wave pulses and examine echoes returned from aircraft. In sonar, sound waves are transmitted into water to detect submarines and other underwater objects. Geophysicists have long studied the Earth’s crust by generating explosions and listening to echoes returning from deep underground layers. Although these applications share a common principle, each has its own specific problems and requirements.

The operating range of a radar system depends on two parameters: the amount of energy contained in the transmitted pulse and the noise level of the receiver. Increasing pulse energy generally requires increasing pulse duration, which reduces time measurement accuracy. As a result, a fundamental trade-off arises between long-range detection and precise distance estimation.

### 2.1 Sonar (SOund NAvigation and Ranging)

Sonar systems are divided into two categories: active and passive. In active sonar, sound pulses in the range of 2 kHz to 40 kHz are transmitted into water, and the returning echoes are detected and analyzed. Active sonar is used for underwater object detection and localization, navigation, communication, and seabed mapping. Typical maximum operating ranges are between 10 and 100 kilometers. Passive sonar, on the other hand, only listens to underwater sounds such as natural turbulence, marine life, and mechanical noise from vessels. Since passive sonar does not emit energy, it is ideal for covert operations.

DSP has revolutionized sonar in ways similar to radar, including pulse generation, pulse compression, and filtering. Due to the irregular and unstable underwater environment, sonar problems are often more challenging. Sonar systems typically use arrays of transmitters and receivers, enabling beam steering and direction-of-arrival estimation.

### 2.3 Radar (Radio Detection and Ranging)

Radar determines the range and direction of objects by transmitting radio-frequency pulses and processing the returned echoes. Distance is computed from the time delay between transmission and reception, while antenna orientation determines angular position.

Radar performance is primarily limited by pulse energy and receiver noise. Longer ranges require higher-energy and longer-duration pulses, but increasing pulse duration reduces range resolution, creating a fundamental range–resolution trade-off.

DSP overcomes this trade-off through pulse compression, digital filtering, and waveform optimization. Modern radar systems often operate at sampling rates close to radio frequency, making DSP both an algorithmic and high-speed hardware design challenge.

### 2.2 Reflection Seismology

Reflection seismology analyzes waves reflected from subsurface layers. Multiple reflections complicate real-world signals. DSP enables separation of primary and secondary echoes, allowing reliable modeling of subsurface structures and enabling oil exploration in difficult regions.

---

## 3. Medicine

In medical imaging, DSP enables separation of overlapping structures, enhancement of tissue contrast, and extraction of physiological information. Computed tomography and magnetic resonance imaging produce diagnostically valuable cross-sectional images through DSP.

---

## 4. Space

In space applications, DSP improves degraded images, corrects spatial distortions, and combines multiple images to produce meaningful visual information, enabling remote sensing and planetary analysis.

---

## 5. Image Processing

DSP models images as discrete digital signals over spatial domains, enabling filtering, frequency analysis, noise suppression, and compression. This approach forms the mathematical foundation of modern image and video processing.

---

## 6. Music Processing

DSP enables processing of multi-channel music signals through filtering, addition, subtraction, and time–frequency domain operations. Artificial echo and reverberation effects are based on digital modeling of acoustic environments.

---

## 7. Speech Generation & Recognition

Speech generation aims to digitally synthesize human voice signals. DSP achieves this by processing prerecorded speech or modeling the vocal tract with digital filters. Speech recognition relies on feature extraction and feature matching, using time–frequency analysis as a foundation.

---

## Statistics, Probability and Noise

Statistics and probability are used in DSP to describe signals and their generating processes. One primary goal of DSP is reducing noise, interference, and unwanted components in acquired data. These components may arise from the signal itself, data acquisition imperfections, or unavoidable side effects of DSP operations.

### Signal and Graph Terminology

A signal describes how one parameter varies with respect to another, such as voltage varying with time in analog electronics.

### Mean and Standard Deviation

The mean of a signal is defined as:

$$
\mu = \frac{1}{N} \sum_{n=0}^{N-1} x[n]
$$

The standard deviation measures the spread around the mean:

$$
\sigma = \sqrt{\frac{1}{N} \sum_{n=0}^{N-1} (x[n] - \mu)^2}
$$

### The Histogram, PMF and PDF

The probability density function of the normal (Gaussian) distribution is given by:

$$
f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}
$$

---

## ADC and DAC

Analog-to-digital conversion (ADC) allows continuous-time, continuous-amplitude signals to be processed digitally through sampling and quantization.

Sampling discretizes the time axis, while quantization discretizes the amplitude axis. These processes introduce sampling noise (aliasing) and quantization noise.

### Quantization

Quantization maps sampled analog amplitudes to a finite set of digital levels. The resulting quantization error is bounded by:

$$
\pm \frac{1}{2} \text{LSB}
$$

### The Sampling Theorem

A signal can be perfectly reconstructed from its samples if:

$$
f_s \geq 2 f_{\text{max}}
$$

If this condition is violated, aliasing occurs and information loss is irreversible.
