# Grayscale Image Histogram Analysis

## Project Scope

Using the C programming language, the histogram of a grayscale image is computed. Then, using the values obtained from this histogram, the **mean** and **variance** of the image are calculated.

---

## Input Format

The input consists of a **single uncompressed 24-bit BMP image file**. The program opens the BMP file in **binary mode**, reads the header information, and processes the pixel data directly from memory.  
The input image may be either **color** or **grayscale**. For color images, pixel values are converted into a grayscale representation in order to perform histogram-based statistical analysis. All statistical computations are carried out using the resulting grayscale intensity values.

If the input file does not conform to the required format, the user is prompted to decide whether to provide another input file, and the program continues accordingly.

---

## Code Implementation

Since the image is in **24-bit BMP format**, each pixel consists of three 8-bit color channels. In the BMP format, these channels are stored in memory in **Blue, Green, and Red (BGR)** order. In the implementation, the values of these three channels are read directly from memory for each pixel.

In order to perform histogram-based statistical analysis, the color pixel information is converted into a grayscale representation. This conversion is performed using a **weighted sum** that reflects the sensitivity of the human visual system to different color channels. The grayscale value for each pixel is computed using the following formula:

$$
\text{Gray} = 0.299 \cdot R + 0.587 \cdot G + 0.114 \cdot B
$$

The resulting grayscale values are 8-bit integers in the range **0–255**. Using these values, a histogram array consisting of **256 elements** is constructed. Each grayscale value is used directly as an index into the histogram array, and the corresponding frequency value is incremented. After all pixels have been processed, the grayscale intensity distribution of the image is obtained.

The total number of pixels is equal to the product of the image width and height, and it is also equal to the sum of all histogram elements:

$$
N = \text{width} \times \text{height} = h(0) + h(1) + \dots + h(255)
$$

Here, $h(i)$ denotes the number of pixels with intensity value $i$.

This assignment is designed using a **modular structure**. Each function is defined to perform a single, well-defined task. This approach improves the **readability**, **maintainability**, and **testability** of the code.

---

## Mean and Variance Calculation

The **mean grayscale value** of the image is computed using the histogram representation. The mean is obtained by multiplying each intensity level by its corresponding histogram frequency, summing these values, and dividing by the total number of pixels:

$$
\mu = \frac{1}{N} \sum_{i=0}^{255} i \cdot h(i)
$$


---

The **variance** measures how much the pixel intensity values deviate from the mean. In histogram-based variance computation, the squared difference between each intensity level and the mean is multiplied by the corresponding histogram frequency. These values are summed over all intensity levels and divided by the total number of pixels:

$$
\sigma^2 = \frac{1}{N} \sum_{i=0}^{255} (i - \mu)^2 \cdot h(i)
$$

Using this approach, the statistical properties of the image are computed directly from the histogram.

---
## Example Results

| Input Image | Outputs |
|------------|---------|
| <img src="1.bmp" width="340"/> | 
Grayscale Image Analysis:<br>
Image Size   : 625 × 350<br>
Total Pixels : 218750<br>
Mean         : 68.25<br>
Variance     : 3717.62<br><br>

---

## References
1. Gonzalez, R. C., & Woods, R. E. *Digital Image Processing* (4th ed.). Pearson, 2018.
2.  Microsoft Learn. *Bitmap Storage (BMP format)*.
   https://learn.microsoft.com/en-us/windows/win32/gdi/bitmap-storage
3. Digital Video and HD: Algorithms and Interfaces Charles Poynton. Morgan Kaufmann, 2012.







