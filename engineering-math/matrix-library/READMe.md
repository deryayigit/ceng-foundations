# Matrix Library

This project implements a custom matrix library in C++ using object-oriented programming principles and manual dynamic memory management. The library supports fundamental matrix operations such as addition, subtraction, multiplication, transpose, determinant calculation, and matrix inversion.

---

## Input Format

The program runs through a console-based menu system where the user selects a matrix operation and enters the required matrix dimensions and elements interactively. Depending on the selected operation, the program may request one matrix, two matrices, or an additional scalar value.

---

## Code Implementation

Matrix operations naturally involve repetitive numerical calculations and intensive loop-based processing. As the library includes operations such as matrix multiplication, determinant calculation, and inverse matrix calculation, computational efficiency is crucial for the project.

For this reason, C++ has been chosen as the project’s implementation language. This language provides efficient execution alongside direct memory management and a modular program structure. Object-oriented programming support also makes it suitable for representing matrix structures in a clean and organised manner throughout the application.

The project has been organised into `matrix.h`, `matrix.cpp`, and `main.cpp` files to separate the mathematical implementation from the console interface and to provide a modular structure.

The `matrix.h` file defines the Matrix class interface, which includes the supported operations and the internal class structure. The `matrix.cpp` file implements the matrix operations and memory management logic, whilst the `main.cpp` file manages the console menu system, user interaction, input validation, and runtime control flow.

In the `matrix.cpp` file, the determinant operation is implemented using the Gaussian elimination method, whilst the matrix inversion operation is implemented using the Gauss-Jordan elimination method.

### Pseudo Codes

#### Matrix Addition

```text
Function add(Matrix A, Matrix B):

    If A.rows != B.rows OR A.cols != B.cols:
        Throw dimension error

    Create result matrix with same size as A

    For each index from 0 to rows * cols - 1:
        result[index] = A[index] + B[index]

    Return result
```

#### Matrix Multiplication

```text
Function multiply(Matrix A, Matrix B):

    If A.cols != B.rows:
        Throw dimension error

    Create result matrix with size A.rows x B.cols

    For each row in A:
        For each column in B:
            sum = 0

            For k from 0 to A.cols - 1:
                sum = sum + A[row][k] * B[k][column]

            result[row][column] = sum

    Return result
```

#### Transpose

```text
Function transpose(Matrix A):

    Create result matrix with size A.cols x A.rows

    For each row in A:
        For each column in A:
            result[column][row] = A[row][column]

    Return result
```

#### Determinant

```text
Function determinant(Matrix A):

    If A is not square:
        Throw error

    Create a temporary copy of A

    determinantValue = 1
    rowSwapCount = 0

    For each pivot column:
        Find the best pivot row

        If pivot is zero:
            Return 0

        If pivot row is not current row:
            Swap rows
            Increase rowSwapCount

        Eliminate values below the pivot

    Multiply all diagonal elements

    If rowSwapCount is odd:
        determinantValue = -determinantValue

    Return determinantValue
```

#### Inverse

```text
Function inverse(Matrix A):

    If A is not square:
        Throw error

    left = copy of A
    right = identity matrix

    For each pivot column:
        Find the best pivot row

        If pivot is zero:
            Throw singular matrix error

        Swap rows if needed

        Normalize pivot row

        Eliminate all other values in the pivot column

    Return right
```

---

## References

1. Steven C. Chapra, *Numerical Methods for Engineers*
2. Golub, G. H., & Van Loan, C. F. *Matrix Computations* (4th Edition), Johns Hopkins University Press.
3. Interactive Matrix Calculator  
   https://github.com/Abhrankan-Chakrabarti/Interactive-Matrix-Calculator/tree/main
