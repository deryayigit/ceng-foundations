#include <iostream>
#include <iomanip>
#include <stdexcept>

inline int idx(int i, int j, int cols) { return i * cols + j; }


float* matmul(const float* A, const float* B, int N, int K, int M) {
    if (N <= 0 || K <= 0 || M <= 0) {
        throw std::invalid_argument("Boyutlar pozitif olmalı");
    }

    float* C = new float[N * M];
  
    for (int i = 0; i < N * M; ++i) C[i] = 0.0f;

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < K; ++k) {
            const float a_ik = A[idx(i, k, K)];
            for (int j = 0; j < M; ++j) {
                C[idx(i, j, M)] += a_ik * B[idx(k, j, M)];
            }
        }
    }
    return C;
}

int main() {
    int N = 2, K = 3, M = 2;

    float* A = new float[N * K] {
        1, 2, 3,
            4, 5, 6
        };
    float* B = new float[K * M] {
        7, 8,
            9, 10,
            11, 12
        };

    float* C = matmul(A, B, N, K, M);

    std::cout << "C = A x B (" << N << "x" << M << ")\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(6) << C[idx(i, j, M)] << ' ';
        }
        std::cout << '\n';
    }

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
