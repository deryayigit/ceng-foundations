#include <stdio.h>   // input-output operations (printf, scanf)
#include <stdlib.h>  // dynamic memory management (malloc, free)
#include <math.h>    // mathematical functions (sin, cos)

#define PI 3.141592653589793

//Complex number representation: real + j*imag
typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

void IDFT(Complex *X, Complex *x, int N) {

    for(int n = 0; n < N; n++) {

        x[n].real = 0;
        x[n].imag = 0;

        for(int k = 0; k < N; k++) {

            double angle = 2 * PI * k * n / N;

            Complex W;
            W.real = cos(angle);
            W.imag = sin(angle);

            Complex temp = complex_multiply(X[k], W);

            x[n] = complex_add(x[n], temp);
        }

        x[n].real /= N;
        x[n].imag /= N;
    }
}

int main() {

    int N;

    printf("Enter number of samples (N): ");
    scanf("%d", &N);

    //Dynamic memory allocation
    Complex *X = (Complex *)malloc(N * sizeof(Complex));
    Complex *x = (Complex *)malloc(N * sizeof(Complex));

    if (X == NULL || x == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nEnter frequency-domain coefficients (real imag):\n");

    for(int k = 0; k < N; k++) {
        printf("X[%d] = ", k);
        scanf("%lf %lf", &X[k].real, &X[k].imag);
    }

    IDFT(X, x, N);

    printf("\nReconstructed time-domain signal:\n");

    for(int n = 0; n < N; n++) {
        printf("x[%d] = %.4f + %.4fj\n", n, x[n].real, x[n].imag);
    }

    free(X);
    free(x);

    return 0;
}
