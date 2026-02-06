# Mean and Standard Deviation Calculation Using the Welford Algorithm

## Project Objective

Implement an algorithm in the C programming language that calculates the mean and standard deviation. 

## Algorithm Choice: Welford’s Method

In this study, Welford’s online algorithm is selected for the computation of the mean and variance. Classical variance calculation methods, which rely on subtraction operations involving large values such as the sum of samples and the sum of squared samples, may lead to numerical instability in floating-point arithmetic. This issue is commonly referred to as catastrophic cancellation.

In contrast, the Welford algorithm updates the variance incrementally by using the deviation of each new sample from the current mean, rather than maintaining large cumulative sums. This approach operates in a single pass, requires constant memory complexity (O(1)), and provides numerically stable behavior for streaming data processing scenarios. For these reasons, the Welford algorithm constitutes a suitable and reliable method for processing sample-based signal data within the scope of this task.

## Algorithm Overview
At each step, the algorithm updates the running mean and an auxiliary variable (commonly denoted as *M2*), which represents the accumulated sum of squared deviations from the mean. After all data points have been processed, the variance is obtained by dividing *M2* by the total number of samples, and the standard deviation is computed as the square root of the variance.

Due to its numerical stability and efficiency, the Welford algorithm is widely used in statistical analysis, digital signal processing, and machine learning applications, especially when working with large datasets or streaming data.

## Computational Complexity

The algorithm operates in linear time, **O(N)**, where *N* is the number of data points. It requires constant memory, **O(1)**, since it does not store the entire dataset.

## Implementation Notes

The implementation is written in the C programming language and uses basic arithmetic operations. The standard math library is only utilized for computing the square root when deriving the standard deviation from the variance.

## Possible Extensions

Possible extensions of this project include computing the sample variance using *(N − 1)*, supporting streaming input from files or sensors, and extending the algorithm to compute additional statistical measures.

---

## References (Accessible & Concise)

1. **Wikipedia – Algorithms for Calculating Variance**  
   Includes the Welford online algorithm with formulas and explanation.  
   https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance

2. **Alchemmist – Welford Algorithm: Online Variance Estimation**  
   https://alchemmist.xyz/articles/welford-algorithm/

3. **John D. Cook – Computing Running Mean and Variance**  
   Clear and practical explanation of Welford’s algorithm with mathematical insight.  
   https://www.johndcook.com/blog/standard_deviation/

