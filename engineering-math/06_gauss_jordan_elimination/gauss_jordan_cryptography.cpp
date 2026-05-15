#include <iostream>   // Provides console input and output
#include <iomanip>    // For formatted matrix output
#include <cmath>      // Used for mathematical functions such as fabs()

using namespace std;

const double EPS = 1e-9; // Small threshold for detecting near-zero pivot values

bool inverseMatrix(double** A, double** inverse, int n)
{
    // Create augmented matrix [A | I]
    double** augmented = new double* [n];

    for (int i = 0; i < n; i++)
    {
        augmented[i] = new double[2 * n];

        for (int j = 0; j < n; j++)
            augmented[i][j] = A[i][j];

        for (int j = 0; j < n; j++)
            augmented[i][j + n] = (i == j) ? 1.0 : 0.0;
    }

    // Apply Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
    {
        int pivotRow = i;

        // Partial pivoting for numerical stability
        for (int r = i + 1; r < n; r++)
        {
            if (fabs(augmented[r][i]) > fabs(augmented[pivotRow][i]))
                pivotRow = r;
        }

        if (fabs(augmented[pivotRow][i]) < EPS)
        {
            for (int r = 0; r < n; r++)
                delete[] augmented[r];

            delete[] augmented;
            return false;
        }

        if (pivotRow != i)
        {
            double* temp = augmented[i];
            augmented[i] = augmented[pivotRow];
            augmented[pivotRow] = temp;
        }

        // Normalize pivot row
        double pivot = augmented[i][i];

        for (int j = 0; j < 2 * n; j++)
            augmented[i][j] /= pivot;

        // Eliminate all other entries in the pivot column
        for (int r = 0; r < n; r++)
        {
            if (r != i)
            {
                double factor = augmented[r][i];

                for (int j = 0; j < 2 * n; j++)
                    augmented[r][j] -= factor * augmented[i][j];
            }
        }
    }

    // Extract inverse matrix from the right side of [I | A^-1]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            inverse[i][j] = augmented[i][j + n];
    }

    for (int i = 0; i < n; i++)
        delete[] augmented[i];

    delete[] augmented;

    return true;
}

void multiplyMatrices(double** A, double** B, double** result, int rowsA, int colsA, int colsB)
{
    // Standard matrix multiplication: result = A * B
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

void printMatrix(double** matrix, int rows, int cols)
{
    // Print matrix with fixed-width formatted values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(10) << fixed << setprecision(2) << matrix[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter the size of the encoding matrix: ";
    cin >> n;

    double** A = new double* [n];
    double** inverse = new double* [n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
        inverse[i] = new double[n];
    }

    cout << "\nEnter the encoding matrix A:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    }

    int dataSize;

    cout << "\nEnter the size of encoded data sequence: ";
    cin >> dataSize;

    if (dataSize % n != 0)
    {
        cout << "Error: Encoded data size must be divisible by matrix size." << endl;
        return 1;
    }

    int columns = dataSize / n;

    double* sequence = new double[dataSize];

    cout << "\nEnter the encoded data sequence:\n";

    for (int i = 0; i < dataSize; i++)
        cin >> sequence[i];

    double** B = new double* [n];

    for (int i = 0; i < n; i++)
        B[i] = new double[columns];

    // Convert encoded sequence into matrix B column by column
    int index = 0;

    for (int col = 0; col < columns; col++)
    {
        for (int row = 0; row < n; row++)
            B[row][col] = sequence[index++];
    }

    // Compute decoding matrix A^-1 using Gauss-Jordan elimination
    if (!inverseMatrix(A, inverse, n))
    {
        cout << "Error: The encoding matrix is singular. Inverse matrix cannot be found." << endl;
        return 1;
    }

    double** X = new double* [n];

    for (int i = 0; i < n; i++)
        X[i] = new double[columns];

    // Decode the message using X = A^-1 * B
    multiplyMatrices(inverse, B, X, n, n, columns);

    cout << "\nDecoding Matrix A^-1:\n";
    printMatrix(inverse, n, n);

    cout << "\nEncoded Message Matrix B:\n";
    printMatrix(B, n, columns);

    cout << "\nRecovered Original Message Matrix X:\n";
    printMatrix(X, n, columns);

    // Release dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] inverse[i];
        delete[] B[i];
        delete[] X[i];
    }

    delete[] A;
    delete[] inverse;
    delete[] B;
    delete[] X;
    delete[] sequence;

    return 0;
}
