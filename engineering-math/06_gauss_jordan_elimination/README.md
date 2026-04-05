# Gauss–Jordan Elimination Solver

This project implements the Gauss–Jordan elimination method to solve a system of linear equations by transforming the augmented matrix into reduced row echelon form.

---

## Objective

The objective of this study is to solve systems of linear equations using the Gauss–Jordan elimination method and to analyze the structure of the solution set. The method transforms a system of equations into a simpler matrix form using elementary row operations. By reducing the matrix to reduced row echelon form (RREF), the solution can be obtained directly. This study focuses on implementing the Gauss–Jordan elimination algorithm at a low level, understanding the mathematical structure behind row operations, and examining different types of solutions such as unique solution, infinite solutions, and no solution cases.

The fundamental goal of the Gauss–Jordan method is to transform the augmented matrix into the form

$$
[A|b] \rightarrow [I|x]
$$

where $I$ is the identity matrix and $x$ is the solution vector.

---

## Input Format

The program expects the number of unknowns $n$ from the user. After this value is provided, the user enters the augmented matrix row by row. The matrix has dimensions

$$
n \times (n+1)
$$

where the first $n$ columns correspond to the coefficients of the variables and the last column represents the constant terms. The augmented matrix therefore fully describes the linear system, and all row operations are applied directly to this structure.

Example input for a three-variable system:

```text
Number of variables: 3

Row 1: 1 1 1 6
Row 2: 2 -1 1 3
Row 3: 1 2 -1 3

```
---

## Code Implementation

The Gauss–Jordan elimination algorithm is implemented by directly translating mathematical row operations into code. For each pivot element $a_{ii}$, the pivot row is first normalized

$$
R_i = \frac{R_i}{a_{ii}}
$$

and then the other entries in the pivot column are eliminated

$$
R_k = R_k - a_{ki}R_i \quad (k \neq i)
$$

These operations are repeated for all columns, transforming the augmented matrix into reduced row echelon form. The solution is then obtained directly from the last column.

The implementation is written in the C programming language. C is chosen to provide explicit control over memory management and to clearly demonstrate how matrix operations are performed at a low level. The program reads the number of variables from the user and dynamically allocates memory for an augmented matrix of size $n \times (n+1)$, allowing systems of arbitrary size to be solved at runtime.

To improve numerical stability, partial pivoting is applied. The row with the largest absolute value in the pivot column is selected and swapped with the current pivot row. The pivot row is then normalized, and the remaining rows are updated to eliminate the pivot column. After processing all pivot columns, the matrix reaches reduced row echelon form, and the solution values appear directly in the final column.

### Pseudo Code:

```text

Input: Augmented matrix A of size n × (n+1)

for i = 0 to n-1

    find row r with max |A[r][i]|
    swap row i and row r

    pivot = A[i][i]

    if pivot ≈ 0
        system has no unique solution

    for j = 0 to n
        A[i][j] = A[i][j] / pivot

    for k = 0 to n-1
        if k ≠ i
            factor = A[k][i]

            for j = 0 to n
                A[k][j] = A[k][j] - factor * A[i][j]

end for

for i = 0 to n-1
    x[i] = A[i][n]

```

## References

1. Gilbert Strang, *Introduction to Linear Algebra*, Wellesley-Cambridge Press.
2. David C. Lay, *Linear Algebra and Its Applications*, Pearson.
3. William H. Press et al., *Numerical Recipes in C: The Art of Scientific Computing*, Cambridge University Press.
4. GeeksforGeeks, "Program for Gauss Jordan Elimination Method",  
   https://www.geeksforgeeks.org/dsa/program-for-gauss-jordan-elimination-method/
