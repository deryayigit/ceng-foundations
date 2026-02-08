# Grayscale Image Histogram Analysis

## Project Description

In this assignment, the objective is to compute the histogram of an **8-bit grayscale image** using the **C programming language**, and then calculate the **mean** and **variance** values of the image using the histogram data.

---

## Code Implementation

A histogram represents the frequency of occurrence of each intensity value in an 8-bit grayscale image. All pixels in the image are read sequentially, and for each pixel, the corresponding histogram frequency for its grayscale intensity value is incremented. As a result, the number of pixels belonging to each grayscale level is obtained.

The total number of pixels is equal to the product of the image width and height, and it is also equal to the sum of all histogram elements:

\[
N = \text{width} \times \text{height}
\]

\[
N = h(0) + h(1) + \dots + h(255)
\]

Here, \( h(i) \) denotes the number of pixels with intensity value \( i \).

---

## Mean and Variance Calculation

The **mean grayscale value** of the image is computed using the histogram representation. The mean is obtained by multiplying each intensity level by its corresponding histogram frequency, summing these values, and dividing by the total number of pixels:

\[
\mu = \frac{1}{N} \sum_{i=0}^{255} i \cdot h(i)
\]

Where:
- \( \mu \) : mean grayscale value of the image  
- \( i \) : grayscale intensity level  
- \( h(i) \) : histogram frequency of intensity \( i \)  
- \( N \) : total number of pixels  

---

The **variance** measures how much the pixel intensity values deviate from the mean. In histogram-based variance computation, the squared difference between each intensity level and the mean is multiplied by the corresponding histogram frequency. These values are summed over all intensity levels and divided by the total number of pixels:

\[
\sigma^2 = \frac{1}{N} \sum_{i=0}^{255} (i - \mu)^2 \cdot h(i)
\]

Using this approach, the statistical properties of the image are computed **directly from the histogram** rather than from individual pixel values. This method reduces memory usage and provides a structured and efficient way to analyze grayscale image statistics.
