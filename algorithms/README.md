# Algorithms Overview

## Definition
An **algorithm** is a finite and well-defined sequence of operations designed to solve a specific problem.  
In computer science, algorithms define the fundamental processes for processing, storing, and managing data.  

The term *algorithm* originates from the 9th-century mathematician **Muhammad al-Khwarizmi**, whose works on algebra were translated into Latin and spread in Europe under the term *algorismus*.  
Over time, the word evolved to represent not only arithmetic procedures but also general problem-solving methods.  

---

## Properties of Algorithms
- **Finiteness:** The algorithm must terminate after a finite number of steps.  
- **Definiteness:** Each step must be clearly and unambiguously defined.  
- **Input / Output:** Algorithms take input(s) and produce at least one output.  
- **Effectiveness:** Each step must be executable within a reasonable time using basic operations.  

---

## Purpose of Algorithms
- To solve problems systematically  
- To search, sort, and process data  
- To form the foundation of computer programs  
- To decompose complex problems into smaller, manageable parts  

In short, algorithms are the **step-by-step recipes** for both real-world processes and software systems.  

---

## Key Algorithmic Paradigms

| Concept              | Description                              | Example                          |
|----------------------|------------------------------------------|----------------------------------|
| **Brute Force**      | Tries all possibilities/combinations      | Password cracking                |
| **Divide & Conquer** | Splits problem into subproblems and combines results | Merge Sort                       |
| **Greedy**           | Makes the best local choice at each step  | Huffman Coding, Activity Selection |
| **Dynamic Programming** | Optimizes by storing solutions to overlapping subproblems | Knapsack Problem                  |
| **Backtracking**     | Explores all possibilities but backtracks when a path is invalid | N-Queens, Sudoku                 |
| **Branch & Bound**   | Eliminates branches that cannot yield better solutions | Travelling Salesman Problem (TSP) |
| **Randomized**       | Uses random decisions to simplify or speed up computation | Randomized Quick Sort, Monte Carlo |


---

## Algorithmic Complexity
The performance of an algorithm is measured by the number of operations it requires, often expressed in **Big-O notation**.  

### Big-O Notation Explained

<img width="554" height="392" alt="image" src="https://github.com/user-attachments/assets/4b0727a4-3f95-4ed2-bcf2-194c9bbcb524" />

## Growth Order of Time Complexities

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


📌Algorithms can be compared based on how their **running time grows** with input size *n*.  
From the fastest (least time) to the slowest (most time):

O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2^n) < O(n!)


---

## Time and Space Complexity
- **Time Complexity:**  
  Represents the number of steps an algorithm takes to complete relative to input size.  

  ### Time Complexity Cases
  - **Best Case:** The fastest scenario for an algorithm.  
    *Example: Linear Search → element is the first one → O(1)*  
  - **Average Case:** The expected time for a random input.  
    *Example: Linear Search → element is somewhere in the middle → O(n)*  
  - **Worst Case:** The slowest scenario, maximum steps required. *Example: Linear Search → element not found or at the end → O(n)*  

  > ℹ️ By default, **Big-O notation usually refers to the worst case** unless otherwise stated.  

- **Space Complexity:**  
  Represents the amount of memory required by the algorithm during execution.  
  Choice of data structures and auxiliary variables can greatly affect this.  

---

## Example Complexity Table

| Algorithm           | Best Case | Average Case | Worst Case |
|---------------------|-----------|--------------|-------------|
| **Linear Search**   | O(1)      | O(n)         | O(n)        |
| **Binary Search**   | O(1)      | O(log n)     | O(log n)    |
| **Bubble Sort**     | O(n)      | O(n²)        | O(n²)       |
| **Merge Sort**      | O(n log n)| O(n log n)   | O(n log n)  |
| **Quick Sort**      | O(n log n)| O(n log n)   | O(n²)       |









