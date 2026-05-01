#ifndef MATRIX_H
#define MATRIX_H

#include <iosfwd> // Forward declarations for stream classes.

class Matrix {
private:
    int rows;
    int cols;
    double* data;

    static constexpr double EPSILON = 1e-9; // Threshold for floating - point comparisons

    void allocateMemory();
    void releaseMemory();

    void validateIndex(int row, int col) const;
    int calculateIndex(int row, int col) const;

    double& getElementReference(int row, int col);
    const double& getConstElementReference(int row, int col) const;

public:
    Matrix(int rowCount, int colCount);
    ~Matrix();

    Matrix(const Matrix& other); // Deep copy
    Matrix& operator=(const Matrix& other); //Copy assignment

    Matrix(Matrix&& other) noexcept; // Move constructor
    Matrix& operator=(Matrix&& other) noexcept; // Move assignment

    int getRowCount() const;
    int getColCount() const;

    void setValue(int row, int col, double value);
    double getValue(int row, int col) const;

    Matrix transpose() const;
    double determinant() const; // Uses Gaussian elimination
    Matrix inverse() const; // Uses Gauss-Jordan elimination

    static Matrix identity(int size);
    static Matrix zero(int rowCount, int colCount);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const; // Matrix multiplication
    Matrix operator*(double scalar) const; 
    Matrix operator/(double scalar) const;

    friend Matrix operator*(double scalar, const Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif
