# Grayscale Image Histogram, Mean and Variance

## Project

Using the C language, compute the **histogram** of a grayscale image.  
Then, using the histogram values, compute the **mean** and **variance** of the image.

---

## Histogram Computation

For an 8-bit grayscale image, intensity values are in the range **0–255**.  
The histogram is a 256-bin frequency array:

- \( h(i) \): number of pixels whose intensity equals \( i \)

It is computed by scanning all pixels once and incrementing the corresponding bin:

\[
h(i) = \#\{\, p \mid I(p)=i \,\}, \quad i \in [0,255]
\]

In code logic:

- initialize \( h(0..255)=0 \)
- for each pixel intensity value \( v \): increment \( h(v) \)

Total pixel count:

\[
N = \text{width} \times \text{height} = \sum_{i=0}^{255} h(i)
\]

---

## Mean and Variance (Histogram-Based)

Mean intensity:

\[
\mu = \frac{1}{N}\sum_{i=0}^{255} i \cdot h(i)
\]

Variance:

\[
\sigma^2 = \frac{1}{N}\sum_{i=0}^{255}(i-\mu)^2 \cdot h(i)
\]

---

## Build and Run

### Compile
```bash
gcc -O2 -Wall -Wextra -o pgm_stats pgm_histogram_stats.c -lm
