# Streaming Calculation of Average and Variance

## Overview

This project demonstrates how basic statistical properties of a signal (mean, variance, and standard deviation) can be computed incrementally from a stream of samples without storing the entire dataset in memory.

Each value in the input file is treated as a discrete-time signal sample. Statistical measures are updated incrementally as each new sample is processed, reflecting a streaming computation model suitable for real-time Digital Signal Processing (DSP) applications.

---

## Code Implementation

The aim of this project is to compute the mean and variance of samples obtained from a signal in a single pass (streaming manner). When classical variance formulas are examined, it can be observed that they involve the subtraction of large and closely valued numbers. In floating-point arithmetic, such operations may lead to the amplification of rounding errors and a loss of numerical precision. This phenomenon is known in the literature as catastrophic cancellation.

For this reason, classical approaches based on running sums and sums of squares may pose risks in terms of numerical stability. Instead, a more robust method has been preferred. Due to its constant memory usage (O(1)), single-pass operation, and superior numerical stability, the Welford Algorithm was selected.

In the Welford algorithm, neither large cumulative sums nor sums of squares are maintained. Instead, computations are performed using small deviations from the current mean. As each new sample arrives, the mean and variance are updated incrementally based on these small differences. This eliminates subtraction operations between large numbers, minimizes rounding errors, and significantly improves numerical stability. This approach aims not only to produce correct results, but also to preserve numerical reliability when processing long data streams, making it well suited for streaming and real-time signal processing applications.

---

## Input Format

The input is provided as a **text file** in which each line contains **a single numerical sample**. The samples are read sequentially and treated as discrete-time signal values. Example input files include `noise.txt`, which contains random samples in the range (-100, 100), `sin.txt`, which contains sinusoidal samples generated as sin((i * pi) / 10), and `binary.txt`, which consists of alternating binary values (0 and 1).

---
---
## Pseudo-code

```text

Initialize:
    sampleCount          ← 0
    runningMean          ← 0
    sumSquaredDeviations ← 0

While there is a new sample x:
    sampleCount ← sampleCount + 1

    differenceFromMean ← x - runningMean
    runningMean ← runningMean + differenceFromMean / sampleCount
    differenceFromUpdatedMean ← x - runningMean

    sumSquaredDeviations ← sumSquaredDeviations
                            + differenceFromMean * differenceFromUpdatedMean

    If sampleCount > 1:
        variance ← sumSquaredDeviations / (sampleCount - 1)
        standardDeviation ← sqrt(variance)


```

### Requirements

- GNU g++
- GNU make
- C++11 compatible compiler

---

## References

- B. P. Welford, “Note on a Method for Calculating Corrected Sums of Squares and Products,” Technometrics, 1962.
- D. E. Knuth, The Art of Computer Programming, Vol. 2: Seminumerical Algorithms.
- S. W. Smith, The Scientist and Engineer’s Guide to Digital Signal Processing.
- Alchemmist, “Welford Algorithm – Online Variance Estimation,” https://alchemmist.xyz/articles/welford-algorithm/

