# Streaming Statistical Analysis of Discrete-Time Signals

This project demonstrates how basic statistical properties of a signal
(mean, variance, and standard deviation) can be computed incrementally
from a stream of samples without storing the entire dataset in memory.

Each value in the input file is treated as a discrete-time signal sample.
Statistical measures are updated incrementally as each new sample is processed,
reflecting a streaming computation model suitable for real-time
Digital Signal Processing (DSP) applications.

The input files used in the project are located in the `data` folder.
`random.txt` contains randomly generated samples in the range (-100.0, 100.0),
`sine.txt` contains sinusoidal samples generated as sin((i * pi) / 10),
and `binary.txt` contains alternating zero and one samples.

The streaming approach is chosen because it provides O(1) memory usage,
is suitable for sensor data, and supports real-time processing.
