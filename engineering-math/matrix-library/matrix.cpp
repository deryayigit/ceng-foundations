#include "matrix.h"

#include <iostream> // Standard I/O streams (cin, cout).
#include <iomanip> // Controls output format (width, precision, etc.).
#include <stdexcept> // Exception types like invalid_argument, out_of_range.
#include <cmath> // Math utilities such as abs.
#include <algorithm> // Generic operations like swap and max.

void Matrix::allocateMemory() {
    data = new double[rows * cols] {}; // Value-initialization sets all matrix elements to 0.0.
}

void Matrix::releaseMemory() {
    delete[] data;
    data = nullptr;
}

void Matrix::validateIndex(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Matrix index is out of range.");
    }
}

int Matrix::calculateIndex(int row, int col) const {
    return row * cols + col;
}

double& Matrix::getElementReference(int row, int col) {
    return data[calculateIndex(row, col)];
}

const double& Matrix::getConstElementReference(int row, int col) const {
    return data[calculateIndex(row, col)];
}

Matrix::Matrix(int rowCount, int colCount)
    : rows(rowCount), cols(colCount), data(nullptr) {

    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive.");
    }

    allocateMemory();
}

Matrix::~Matrix() {
    releaseMemory();
}

// Copy constructor performs a deep copy.
Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols), data(nullptr) {

    allocateMemory();

    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

// Copy assignment uses a temporary copied buffer before replacing the current data.
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    double* copiedData = new double[other.rows * other.cols];

    for (int i = 0; i < other.rows * other.cols; i++) {
        copiedData[i] = other.data[i];
    }

    releaseMemory();

    rows = other.rows;
    cols = other.cols;
    data = copiedData;

    return *this;
}

// Move constructor transfers ownership of the memory from another matrix.
Matrix::Matrix(Matrix&& other) noexcept
    : rows(other.rows), cols(other.cols), data(other.data) {

    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

// Move assignment releases current memory and takes ownership of another matrix's data.
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    releaseMemory();

    rows = other.rows;
    cols = other.cols;
    data = other.data;

    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;

    return *this;
}

int Matrix::getRowCount() const {
    return rows;
}

int Matrix::getColCount() const {
    return cols;
}

void Matrix::setValue(int row, int col, double value) {
    validateIndex(row, col);
    getElementReference(row, col) = value;
}

double Matrix::getValue(int row, int col) const {
    validateIndex(row, col);
    return getConstElementReference(row, col);
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Addition requires matrices with the same dimensions.");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] + other.data[i];
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Subtraction requires matrices with the same dimensions.");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] - other.data[i];
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Multiplication requires the number of columns of A to equal the number of rows of B.");
    }

    Matrix result(rows, other.cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < other.cols; col++) {
            double sum = 0.0;

            for (int k = 0; k < cols; k++) {
                sum += getConstElementReference(row, k) *
                    other.getConstElementReference(k, col);
            }

            result.getElementReference(row, col) = sum;
        }
    }

    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] * scalar;
    }

    return result;
}

Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
}

Matrix Matrix::operator/(double scalar) const {
    if (std::abs(scalar) < EPSILON) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] / scalar;
    }

    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.getElementReference(col, row) =
                getConstElementReference(row, col);
        }
    }

    return result;
}

double Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Determinant requires a square matrix.");
    }

    int size = rows;
    Matrix temp(*this);

    double determinantValue = 1.0;
    int rowSwapCount = 0;

    for (int pivotIndex = 0; pivotIndex < size; pivotIndex++) {
        int bestPivotRow = pivotIndex;
        double bestRatio = 0.0;

        for (int row = pivotIndex; row < size; row++) {
            double largestValueInRow = 0.0;

            for (int col = pivotIndex; col < size; col++) {
                largestValueInRow = std::max(
                    largestValueInRow,
                    std::abs(temp.getConstElementReference(row, col))
                );
            }

            if (largestValueInRow < EPSILON) {
                continue;
            }

            double pivotRatio =
                std::abs(temp.getConstElementReference(row, pivotIndex)) /
                largestValueInRow;

            if (pivotRatio > bestRatio) {
                bestRatio = pivotRatio;
                bestPivotRow = row;
            }
        }

        if (std::abs(temp.getConstElementReference(bestPivotRow, pivotIndex)) < EPSILON) {
            return 0.0;
        }

        if (bestPivotRow != pivotIndex) {
            for (int col = 0; col < size; col++) {
                std::swap(
                    temp.getElementReference(pivotIndex, col),
                    temp.getElementReference(bestPivotRow, col)
                );
            }

            rowSwapCount++;
        }

        double pivotValue = temp.getConstElementReference(pivotIndex, pivotIndex);

        for (int row = pivotIndex + 1; row < size; row++) {
            double eliminationFactor =
                temp.getConstElementReference(row, pivotIndex) / pivotValue;

            temp.getElementReference(row, pivotIndex) = 0.0;

            for (int col = pivotIndex + 1; col < size; col++) {
                temp.getElementReference(row, col) -=
                    eliminationFactor *
                    temp.getConstElementReference(pivotIndex, col);
            }
        }
    }

    // For an upper triangular matrix, determinant is the product of diagonal elements.
    for (int i = 0; i < size; i++) {
        determinantValue *= temp.getConstElementReference(i, i);
    }

    if (rowSwapCount % 2 != 0) {
        determinantValue = -determinantValue;
    }

    return determinantValue;
}

Matrix Matrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Inverse requires a square matrix.");
    }

    int size = rows;

    Matrix left(*this);
    Matrix right = Matrix::identity(size);

    for (int pivotIndex = 0; pivotIndex < size; pivotIndex++) {
        int bestPivotRow = pivotIndex;
        double bestRatio = 0.0;

        for (int row = pivotIndex; row < size; row++) {
            double largestValueInRow = 0.0;

            for (int col = 0; col < size; col++) {
                largestValueInRow = std::max(
                    largestValueInRow,
                    std::abs(left.getConstElementReference(row, col))
                );
            }

            if (largestValueInRow < EPSILON) {
                continue;
            }

            double pivotRatio =
                std::abs(left.getConstElementReference(row, pivotIndex)) /
                largestValueInRow;

            if (pivotRatio > bestRatio) {
                bestRatio = pivotRatio;
                bestPivotRow = row;
            }
        }

        if (std::abs(left.getConstElementReference(bestPivotRow, pivotIndex)) < EPSILON) {
            throw std::invalid_argument("Singular matrix. Inverse does not exist.");
        }

        if (bestPivotRow != pivotIndex) {
            for (int col = 0; col < size; col++) {
                std::swap(
                    left.getElementReference(pivotIndex, col),
                    left.getElementReference(bestPivotRow, col)
                );

                std::swap(
                    right.getElementReference(pivotIndex, col),
                    right.getElementReference(bestPivotRow, col)
                );
            }
        }

        double pivotValue = left.getConstElementReference(pivotIndex, pivotIndex);

        for (int col = 0; col < size; col++) {
            left.getElementReference(pivotIndex, col) /= pivotValue;
            right.getElementReference(pivotIndex, col) /= pivotValue;
        }

        for (int row = 0; row < size; row++) {
            if (row == pivotIndex) {
                continue;
            }

            double eliminationFactor =
                left.getConstElementReference(row, pivotIndex);

            left.getElementReference(row, pivotIndex) = 0.0;

            for (int col = 0; col < size; col++) {
                left.getElementReference(row, col) -=
                    eliminationFactor *
                    left.getConstElementReference(pivotIndex, col);

                right.getElementReference(row, col) -=
                    eliminationFactor *
                    right.getConstElementReference(pivotIndex, col);
            }
        }
    }

    return right;
}

Matrix Matrix::identity(int size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be positive.");
    }

    Matrix result(size, size);

    for (int i = 0; i < size; i++) {
        result.getElementReference(i, i) = 1.0;
    }

    return result;
}

Matrix Matrix::zero(int rowCount, int colCount) {
    return Matrix(rowCount, colCount);
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (int row = 0; row < matrix.rows; row++) {
        for (int col = 0; col < matrix.cols; col++) {
            out << std::setw(10)
                << std::fixed
                << std::setprecision(3)
                << matrix.getConstElementReference(row, col);
        }

        out << '\n';
    }

    return out;
}
