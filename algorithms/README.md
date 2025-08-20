# Algorithms Overview

## What is an Algorithm?
An algorithm is a finite sequence of well-defined steps designed to solve a specific problem.  
In computer science, algorithms define the fundamental processes for handling, storing, and processing data.  

---

## Historical Background
The concept of the algorithm is named after the 9th-century mathematician **Muhammad al-Khwarizmi**.  
His works on algebra were translated into Latin and spread in Europe under the term *algorismus*.  
Over time, the word evolved to represent not only arithmetic procedures but also general problem-solving methods.  

---

## Purpose of Algorithms
- To solve problems systematically  
- To search, sort, and process data  
- To form the foundation of computer programs  
- To decompose complex problems into smaller, manageable parts  

In short, algorithms are the **step-by-step recipes** for both real-world processes and software systems.  

---

## Types of Algorithms
- **Searching Algorithms:** Linear Search, Binary Search  
- **Sorting Algorithms:** Bubble Sort, Merge Sort, Quick Sort  
- **Recursive Algorithms:** Fibonacci, Factorial (recursive)  
- **Graph Algorithms:** BFS, DFS, Dijkstra, Kruskal  
- **Dynamic Programming Algorithms:** Knapsack, Longest Common Subsequence  
- **Greedy Algorithms:** Activity Selection, Huffman Coding  

---

## Algorithmic Complexity
The performance of an algorithm is measured by the number of operations it requires, often expressed in **Big-O notation**.  

### Big-O Notation Explained

<img width="554" height="392" alt="image" src="https://github.com/user-attachments/assets/4b0727a4-3f95-4ed2-bcf2-194c9bbcb524" />


- **O(1) — Constant Time:**  
  Independent of input size, runs in the same amount of time.  
  *Example: Accessing the first element of an array.*  

- **O(log n) — Logarithmic Time:**  
  Operations grow slowly even as input size increases.  
  *Example: Binary Search.*  

- **O(n) — Linear Time:**  
  Operations grow directly in proportion to input size.  
  *Example: Linear Search.*  

- **O(n log n) — Linearithmic Time:**  
  Combination of linear and logarithmic growth.  
  *Example: Merge Sort, Quick Sort (average case).*  

- **O(n²) — Quadratic Time:**  
  Operations grow proportional to the square of input size.  
  *Example: Bubble Sort, Selection Sort.*  

- **O(2^n) — Exponential Time:**  
  Each increase in input size doubles the required operations.  
  *Example: Brute force solutions for combinatorial problems.*  

- **O(n!) — Factorial Time:**  
  The worst case; operations grow factorially with input size.  
  *Example: Naive backtracking approaches for the N-Queens problem.*  

---

## Time and Space Complexity
- **Time Complexity:**  
  Represents the number of steps an algorithm takes to complete relative to input size.  

- **Space Complexity:**  
  Represents the amount of memory required by the algorithm during execution.  
  Choice of data structures and auxiliary variables can greatly affect this.  

---

📌 This directory contains C language implementations of the above concepts, with examples that demonstrate both theory and practice.  



