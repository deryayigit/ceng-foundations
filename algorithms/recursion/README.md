# Recursion

Recursion is a technique used in computer science to solve big problems by breaking them into smaller, similar problems.  
The process in which a function calls itself directly or indirectly is called **recursion**, and the corresponding function is called a **recursive function**.  

For recursion to work correctly, there must always be a **base condition (termination condition)** — otherwise the recursion will continue infinitely and cause a stack overflow.

Recursion helps in **logic building** and provides a natural way to solve complex problems by decomposing them into smaller subproblems.  
It is a powerful technique, but must be used carefully to avoid performance issues and infinite loops.  


---

## Base Case and Recursive Case
Every recursive function must contain two parts:

- **Base Case:** The simplest instance of the problem that can be solved directly.  
- **Recursive Case:** The part where the function calls itself with a smaller/simpler input.  

**Example (Factorial):**
```
int factorial(int n) {
    if (n == 0) return 1;      // Base case
    return n * factorial(n-1); // Recursive case
}


## Types of Recursion

There are several common types of recursion:

- **Direct Recursion**  
  A function calls itself directly.  
  *Example: factorial implementation.*

- **Indirect Recursion**  
  One function (say `A`) calls another (`B`), which then calls `A` again.  
  This involves two or more methods forming a circular call sequence.  

- **Head Recursion**  
  The recursive call is made **at the beginning** of the method, before any other processing.  

- **Tail Recursion**  
  The recursive call is the **last statement** in the method.  
  Tail recursion can sometimes be optimized by compilers into iteration.  



