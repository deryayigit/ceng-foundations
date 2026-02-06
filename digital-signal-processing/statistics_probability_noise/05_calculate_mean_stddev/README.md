
In this project, the calculation of the mean and standard deviation is performed using the Welford algorithm instead of the classical two-pass formula.

The Welford algorithm is a numerically stable, single-pass (online) algorithm that allows the mean and variance to be updated incrementally as new data points are processed. Unlike the traditional approach, which requires iterating over the dataset multiple times, Welford’s method computes these statistics in one pass without storing the entire dataset in memory.

At each step, the algorithm updates the running mean and an auxiliary variable (commonly denoted as M2), which represents the accumulated sum of squared deviations from the mean. After all data points have been processed, the variance is obtained by dividing M2 by the total number of samples, and the standard deviation is computed as the square root of the variance.

Due to its numerical stability and efficiency, the Welford algorithm is widely used in statistical analysis, digital signal processing, and machine learning applications, especially when working with large datasets or streaming data.

---
## References (Accessible & Concise)

1. Wikipedia – Algorithms for Calculating Variance
Includes the Welford’s online algorithm with formulas and explanation.
https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance

2. Alchemmist, “Welford Algorithm – Online Variance Estimation,”
https://alchemmist.xyz/articles/welford-algorithm/

3. John D. Cook – Computing Running Mean and Variance
Clear and practical explanation of Welford’s algorithm with mathematical insight.
https://www.johndcook.com/blog/standard_deviation/
