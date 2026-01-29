# Streaming Calculation of Average and Variance

## Overview

This project demonstrates how basic statistical properties of a signal (mean, variance, and standard deviation) can be computed incrementally from a stream of samples without storing the entire dataset in memory.

Each value in the input file is treated as a discrete-time signal sample. Statistical measures are updated incrementally as each new sample is processed, reflecting a streaming computation model suitable for real-time Digital Signal Processing (DSP) applications.

---

## Objective

The main objective of this study is to compute the mean, variance, and standard deviation of a signal by processing samples **one by one** in a streaming manner. Instead of batch processing, each incoming sample contributes to the update of the statistical values, allowing the algorithm to operate without keeping all previous samples in memory. As a result, the implementation achieves **constant memory complexity (O(1))**, making it appropriate for real-time and resource-constrained environments.

---

## Input Format

The input is provided as a **text file** in which each line contains **a single numerical sample**. The samples are read sequentially and treated as discrete-time signal values. Example input files include `noise.txt`, which contains random samples in the range (-100, 100), `sin.txt`, which contains sinusoidal samples generated as sin((i * pi) / 10), and `binary.txt`, which consists of alternating binary values (0 and 1).

---

## Streaming Computation Model

Each input sample is processed sequentially. Let `x_n` denote the current sample and `n` the total number of processed samples.

---

### Incremental Mean Calculation

The mean value is updated using the following recursive formula:

`μ_n = ((n - 1) * μ_(n-1) + x_n) / n`

This formulation allows the mean to be updated efficiently without storing previous samples.

---

### Variance Calculation

The sample variance is calculated using the following expression:

`σ² = (1 / (n - 1)) * ( Σ(x_i²) - (1 / n) * (Σ(x_i))² )`

Where `Σ(x_i)` represents the sum of the samples and `Σ(x_i²)` represents the sum of the squared samples.

---

### Standard Deviation

The standard deviation is obtained by taking the square root of the variance:

`σ = sqrt(σ²)`


---


## Pseudo-code

```text
initialize:
    n = 0
    sum = 0
    sum_sq = 0
    mean = 0

while sample exists:
    read x
    n = n + 1
    sum = sum + x
    sum_sq = sum_sq + x*x

    mean = ((n - 1) * mean + x) / n
    variance = (sum_sq - (sum * sum) / n) / (n - 1)
    std = sqrt(variance)

    output(mean, variance, std)
```

### Requirements

- GNU g++
- GNU make
- C++11 compatible compiler



