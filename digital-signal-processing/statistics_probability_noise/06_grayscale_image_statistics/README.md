# Grayscale Image Histogram, Mean and Variance 

## Project
Using the C language, compute the histogram of a grayscale image. Then, using the histogram values, compute the mean and variance of the image.

## Histogram Computation
For an 8-bit grayscale image, intensity values are in the range 0–255. The histogram is a 256-bin frequency array where h(i) denotes the number of pixels whose intensity equals i.

The histogram is computed by scanning all pixels once and incrementing the corresponding bin:

h(i) = number of pixels such that I(p) = i ,   i ∈ [0,255]

In code logic, the histogram is obtained by initializing all histogram bins to zero and incrementing h(v) for each pixel with intensity value v.

The total number of pixels is given by:

N = width × height = Σ h(i),   i = 0..255

## Mean and Variance (Histogram-Based)
The mean intensity value of the image is computed using the histogram as:

μ = (1 / N) × Σ [ i × h(i) ],   i = 0..255

The variance is computed as:

σ² = (1 / N) × Σ [ (i − μ)² × h(i) ],   i = 0..255

## Compilation and Execution
To compile the program:
gcc -O2 -Wall -Wextra -o pgm_stats pgm_histogram_stats.c -lm

To run the program:
./pgm_stats image.pgm
