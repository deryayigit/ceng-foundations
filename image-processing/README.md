# Image Processing

This repository contains lecture notes, assignments, and projects related to **Digital Image Processing**.  
The focus is on **low-level implementations in C/C++ without external libraries** (e.g., OpenCV), as required in coursework.  

---

## Topics Covered

- **Image Representation**
  - Pixels, Intensity 
  - RGB, Grayscale
  - Histograms and Histogram Equalization

**Pixel:**  
The pixel is the smallest unit of a digital image, and the resolution of the image is directly related to the number of pixels it contains.  
Each pixel represents a specific color.  

Every pixel has **x** and **y** coordinates, which is why a digital image can essentially be represented as a **two-dimensional matrix**.  

---

### Pixel Neighborhoods
- **N (4-Connectivity):** Neighborhood in horizontal and vertical directions.  
- **D (Diagonal Connectivity / 8-Connectivity):** Neighborhood in diagonal directions.  


- **Filtering**
  - Convolution & Correlation
  - Smoothing filters (Mean, Gaussian)
  - Sharpening filters (Laplacian, High-pass)
  - Edge detection (Sobel, Prewitt, Canny)

- **Segmentation**
  - Thresholding (Global, Adaptive, Otsu’s Method)
  - K-means clustering
  - Region-based segmentation

- **Feature Extraction**
  - Gradients
  - Edges, Lines, Circles (Hough Transform)
  - Object detection & classification

- **Geometric Transformations**
  - Scaling, Rotation, Translation
  - Affine transformation
  - Camera Calibration (A matrix computation)

---

## Assignments

1. **Basic Image Operations**
   - Read a BMP file manually
   - Convert RGB to Grayscale
   - Compute and display histogram in Windows Form

2. **Edge & Line Detection**
   - Implement Sobel filter in C
   - Apply Hough Transform for line/circle detection
   - Show detected features inside bounding boxes

3. **Segmentation Task**
   - Apply Otsu thresholding
   - Perform K-means clustering on sample images

4. **Calibration & Affine Transformation**
   - Camera calibration experiment
   - Derive transformation matrix between world and image coordinates





