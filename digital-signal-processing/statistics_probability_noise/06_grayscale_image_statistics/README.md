\section*{Grayscale Image Histogram, Mean and Variance}

\subsection*{Assignment}
Using the C language, compute the histogram of a grayscale image. Then, using the histogram values, compute the mean and variance of the image.

\subsection*{Histogram Computation}
For an 8-bit grayscale image, intensity values are in the range $0$--$255$.  
The histogram is defined as a 256-bin frequency array, where $h(i)$ represents the number of pixels whose intensity value equals $i$.

The histogram is computed by scanning all pixels once and incrementing the corresponding histogram bin:

\[
h(i) = \#\{\, p \mid I(p) = i \,\}, \quad i \in [0,255]
\]

In the implementation, all histogram bins are initialized to zero. For each pixel with intensity value $v$, the value of $h(v)$ is incremented by one.

The total number of pixels in the image is given by:

\[
N = \text{width} \times \text{height} = \sum_{i=0}^{255} h(i)
\]

\subsection*{Mean and Variance (Histogram-Based)}
The mean intensity value of the grayscale image is computed using the histogram as:

\[
\mu = \frac{1}{N} \sum_{i=0}^{255} i \cdot h(i)
\]

The variance of the image intensity values is computed as:

\[
\sigma^2 = \frac{1}{N} \sum_{i=0}^{255} (i - \mu)^2 \cdot h(i)
\]

\subsection*{Compilation and Execution}
The program is compiled using the following command:
\[
\texttt{gcc -O2 -Wall -Wextra -o pgm\_stats pgm\_histogram\_stats.c -lm}
\]

The program is executed as follows:
\[
\texttt{./pgm\_stats image.pgm}
\]
