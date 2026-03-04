#include <stdio.h>   // input-output operations (printf, scanf)
#include <stdlib.h>  // dynamic memory management (malloc, free)
#include <math.h>    // mathematical functions (sin, cos)

#define PI 3.141592653589793


//Complex number representation: real + j*imag
typedef struct {
    double real;
    double imag;
} Complex;


Complex add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}


Complex multiply(Complex a, Complex b)
{
    Complex result;
    result.real = a.real*b.real - a.imag*b.imag;
    result.imag = a.real*b.imag + a.imag*b.real;
    return result;
}

void DFT(double x[], Complex X[], int N)
{
    for(int k = 0; k < N; k++)
    {
        X[k].real = 0.0;
        X[k].imag = 0.0;

        for(int n = 0; n < N; n++)
        {
            double angle = -2.0 * PI * k * n / N;

            Complex W = {
                cos(angle),
                sin(angle)
            };

            Complex sample = {x[n], 0.0};

            Complex term = multiply(sample, W);
            X[k] = add(X[k], term);
        }
    }
}


int main()
{
    int N;

    printf("Enter number of samples (N): ");
    scanf("%d", &N);

    //Allocate memory at runtime since N is user-defined
    double *signal = (double*)malloc(N * sizeof(double));
    Complex *spectrum = (Complex*)malloc(N * sizeof(Complex));

    if(signal == NULL || spectrum == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter signal samples:\n");

    for(int i = 0; i < N; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &signal[i]);
    }

    DFT(signal, spectrum, N);

    printf("\nDFT Result:\n");

    for(int k = 0; k < N; k++)
    {
        printf("X[%d] = %.4f + j%.4f\n",
               k,
               spectrum[k].real,
               spectrum[k].imag);
    }

    free(signal);
    free(spectrum);

    return 0;
}
