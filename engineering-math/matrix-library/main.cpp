#include <iostream>  // Standard I/O streams (cin, cout).
#include <stdexcept> // Exception types like invalid_argument, out_of_range.
#include <limits> // Used to clear input buffer safely.
#include <string> // std::string for text handling.
#include "matrix.h"

int readPositiveInteger(const std::string& message) {
    int value;

    while (true) {
        std::cout << message;
        std::cin >> value;

        if (!std::cin.fail() && value > 0) {
            return value;
        }

        std::cout << "Invalid input. Please enter a positive integer.\n";

        // Clears the error state and removes invalid characters from the input buffer.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double readDouble(const std::string& message) {
    double value;

    while (true) {
        std::cout << message;
        std::cin >> value;

        if (!std::cin.fail()) {
            return value;
        }

        std::cout << "Invalid input. Please enter a numeric value.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Matrix readMatrixFromUser(int rows, int cols) {
    Matrix matrix(rows, cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            double value = readDouble(
                "Element [" + std::to_string(row) + "][" + std::to_string(col) + "]: "
            );

            matrix.setValue(row, col, value);
        }
    }

    return matrix;
}

void runTwoMatrixOperation(int choice) {
    int rowsA = readPositiveInteger("Enter rows for Matrix A: ");
    int colsA = readPositiveInteger("Enter columns for Matrix A: ");

    int rowsB = readPositiveInteger("Enter rows for Matrix B: ");
    int colsB = readPositiveInteger("Enter columns for Matrix B: ");

    std::cout << "Enter Matrix A:\n";
    Matrix A = readMatrixFromUser(rowsA, colsA);

    std::cout << "Enter Matrix B:\n";
    Matrix B = readMatrixFromUser(rowsB, colsB);

    if (choice == 1) {
        std::cout << "\nA + B:\n" << A + B;
    }
    else if (choice == 2) {
        std::cout << "\nA - B:\n" << A - B;
    }
    else {
        std::cout << "\nA * B:\n" << A * B;
    }
}

void runScalarOperation(int choice) {
    int rows = readPositiveInteger("Enter rows: ");
    int cols = readPositiveInteger("Enter columns: ");

    std::cout << "Enter Matrix:\n";
    Matrix matrix = readMatrixFromUser(rows, cols);

    double scalar = readDouble("Enter scalar: ");

    if (choice == 4) {
        std::cout << "\nMatrix * Scalar:\n" << matrix * scalar;
    }
    else {
        std::cout << "\nMatrix / Scalar:\n" << matrix / scalar;
    }
}

void runTransposeOperation() {
    int rows = readPositiveInteger("Enter rows: ");
    int cols = readPositiveInteger("Enter columns: ");

    std::cout << "Enter Matrix:\n";
    Matrix matrix = readMatrixFromUser(rows, cols);

    std::cout << "\nTranspose Matrix:\n" << matrix.transpose();
}

void runDeterminantOperation() {
    int size = readPositiveInteger("Enter matrix size: ");

    std::cout << "Enter Matrix:\n";
    Matrix matrix = readMatrixFromUser(size, size);

    std::cout << "\nDeterminant: " << matrix.determinant() << '\n';
}

void runInverseOperation() {
    int size = readPositiveInteger("Enter matrix size: ");

    std::cout << "Enter Matrix:\n";
    Matrix matrix = readMatrixFromUser(size, size);

    std::cout << "\nInverse Matrix:\n" << matrix.inverse();
}

int main() {
    int choice;

    do {
        std::cout << "\n MATRIX OPERATIONS: \n";
        std::cout << "1. Add Matrix\n";
        std::cout << "2. Subtract Matrix\n";
        std::cout << "3. Multiply Matrix\n";
        std::cout << "4. Scalar Multiply\n";
        std::cout << "5. Scalar Divide\n";
        std::cout << "6. Transpose Matrix\n";
        std::cout << "7. Calculate Determinant\n";
        std::cout << "8. Calculate Inverse\n";
        std::cout << "9. Exit\n";

        choice = readPositiveInteger("Enter your choice: ");

        try {
            if (choice >= 1 && choice <= 3) {
                runTwoMatrixOperation(choice);
            }
            else if (choice == 4 || choice == 5) {
                runScalarOperation(choice);
            }
            else if (choice == 6) {
                runTransposeOperation();
            }
            else if (choice == 7) {
                runDeterminantOperation();
            }
            else if (choice == 8) {
                runInverseOperation();
            }
            else if (choice == 9) {
                std::cout << "Exiting...\n";
            }
            else {
                std::cout << "Invalid choice.\n";
            }
        }
        catch (const std::exception& error) {
            // Catches runtime errors such as invalid dimensions, singular matrices, or division by zero.
            std::cout << "Error: " << error.what() << '\n';
        }

    } while (choice != 9);

    return 0;
}
