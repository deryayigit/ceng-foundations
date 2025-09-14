# Algorithms Repository Structure

Algorithms is one of the cornerstone courses of Computer Engineering, forming the foundation of problem-solving and software development skills.  
This repository brings together my **theoretical knowledge** and **practical projects** from the course.  

The content is organized into **two main sections**:

📂 **algorithms**  
├── 📂 **fundamentals** – Topic-based algorithm implementations and practice problems  
│   ├── 📄 [Basics](fundamentals/basic-algorithms/)  
│   ├── 📄 [Recursion](fundamentals/recursion-problems/)  
│   ├── 📄 [Sorting](fundamentals/sorting-algorithms/)  
│   └── 📄 [Searching](fundamentals/searching-algorithms/)  
│  
└── 📂 **assignments** – Serious academic projects developed as coursework  
&nbsp;&nbsp;&nbsp; ├── 📄 [Soroban Project](assignments/soroban_project/) – Simulation of the Japanese abacus  
&nbsp;&nbsp;&nbsp; └── 📄 [Eight Queens Problem](assignments/eight-queens-problem/) – Backtracking solution  

---


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

Big O Notation is a **mathematical representation that describes the performance of an algorithm (time or space) as the input size grows**.  
- It shows how code execution scales with data.  
- Machine independent: based only on number of steps.  
- Ignores smaller operations:  
  - e.g. `O(n + 1)` → `O(n)`  

> **In short:** *"How code slows as data grows."*

---

## 🧮 Basic Definitions
- **Big O (O)** → **Worst case** performance of an algorithm.  
- **Big Ω (Ω)** → **Best case** performance of an algorithm.  
- **Big Θ (Θ)** → **Average case** performance of an algorithm.  

---

## 📘 Rules for Big O Complexity Analysis

These are general rules for analyzing algorithm complexity using **Big O notation**. They help estimate the upper bounds of operations, loops, and conditions during algorithm execution — both iteratively and structurally.

---

### General Rules

- **Single-line assignment statements**  
  Simple operations such as `a = a + 2` are considered to take **constant time** → **O(1)**.

- **Loops depending on array size**  
  If a loop runs in proportion to the size of an array or input `n`, its complexity is typically **O(n)**.

- **Nested loops**  
  When loops are nested, their ranges multiply:
  - Outer loop over `n` and inner loop over `m` → **O(n × m)**
  - Both loops over `n` → **O(n²)**

- **Loops where the range depends on another variable**  
  If a loop runs up to `m` instead of `n`, the complexity is based on `m`: → **O(m)**

- **Conditional branches (`if-else`)**  
  In complexity analysis, the **branch with higher cost dominates**:
  - Use **max(if branch, else branch)**

- **Halving the input size each iteration**  
  When the problem size is halved in each step (e.g., binary search), the complexity becomes **logarithmic**: → **O(log n)**

- **Highest-order term dominates**  
  When evaluating mathematical expressions, the highest-degree term determines growth:
  - Example: √(n³ + n²) ≈ **Θ(n^1.5)**

- **Ignore constant factors**  
  Constants are not considered in Big O analysis:
  - Example: `O((1/2) × n²)` → **O(n²)**


## 📌 Note

These rules apply primarily to **non-recursive (iterative)** algorithms.  
For **recursive algorithms**, special techniques.

---


### Big-O Notation Explained

<img width="554" height="392" alt="image" src="https://github.com/user-attachments/assets/4b0727a4-3f95-4ed2-bcf2-194c9bbcb524" />

## Growth Order of Time Complexities

- **O(1) — Constant Time:**  
  Independent of input size, runs in the same amount of time.  
  *Examples:*  
  - Random access of an element in an array  
  - Inserting at the beginning of a linked list  

- **O(log n) — Logarithmic Time:**  
  Operations grow slowly even as input size increases.  
  *Example:*  
  - Binary Search  

- **O(n) — Linear Time:**  
  Operations grow directly in proportion to input size.  
  *Examples:*  
  - Looping through elements in an array  
  - Searching through a linked list  

- **O(n log n) — Quasilinear Time (Linearithmic):**  
  Combination of linear and logarithmic growth.  
  *Examples:*  
  - Quicksort  
  - Mergesort  
  - Heapsort  

- **O(n²) — Quadratic Time:**  
  Operations grow proportional to the square of input size.  
  *Examples:*  
  - Insertion Sort  
  - Selection Sort  
  - Bubble Sort  

- **O(n!) — Factorial Time:**  
  The worst case; operations grow factorially with input size.  
  *Example:*  
  - Traveling Salesman Problem  



📌Algorithms can be compared based on how their **running time grows** with input size *n*.  
From the fastest (least time) to the slowest (most time):

O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n!)


---

## Time and Space Complexity
- **Time Complexity:**  
  Represents the number of steps an algorithm takes to complete relative to input size.  

  ### Time Complexity Cases
  The total number of steps an algorithm needs to complete.  

    Examples:  
    - `O(1)` → Constant  
    - `O(n)` → Linear  
    - `O(log n)` → Logarithmic  
    - `O(n²)` → Quadratic  

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



