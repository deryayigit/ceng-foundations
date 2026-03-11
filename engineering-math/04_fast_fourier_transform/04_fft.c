#include <stdio.h>   // input-output operations 
#include <stdlib.h>  // dynamic memory management (malloc, free)
#include <math.h>    // mathematical functions (sin, cos, sqrt)

#define PI 3.141592653589793


//Complex number representation: real + j*imag
typedef struct
{
    double real;
    double imag;
} Complex;


Complex add(Complex a, Complex b)
{
    Complex r;

    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;

    return r;
}


Complex subtract(Complex a, Complex b)
{
    Complex r;

    r.real = a.real - b.real;
    r.imag = a.imag - b.imag;

    return r;
}


Complex multiply(Complex a, Complex b)
{
    Complex r;

    r.real = a.real*b.real - a.imag*b.imag;
    r.imag = a.real*b.imag + a.imag*b.real;

    return r;
}


//Twiddle factor: e^(-j2πk/N) 
Complex twiddle(int k, int N)
{
    Complex W;

    double angle = -2.0 * PI * k / N;

    W.real = cos(angle);
    W.imag = sin(angle);

    return W;
}


void FFT(Complex x[], int N)
{
    if(N <= 1)
        return;

    int k;

    int half = N / 2;

    Complex *even = (Complex*)malloc(half * sizeof(Complex));
    Complex *odd  = (Complex*)malloc(half * sizeof(Complex));


    for(k = 0; k < half; k++)
    {
        even[k] = x[2*k];
        odd[k]  = x[2*k + 1];
    }


    FFT(even, half);
    FFT(odd, half);


    for(k = 0; k < half; k++)
    {
        Complex W = twiddle(k, N);

        Complex t = multiply(W, odd[k]);

        x[k] = add(even[k], t);

        x[k + half] = subtract(even[k], t);
    }


    free(even);
    free(odd);
}


//Magnitude of complex number 
double magnitude(Complex x)
{
    return sqrt(x.real*x.real + x.imag*x.imag);
}


int main()
{
    int N;

    printf("Enter number of samples (power of 2): ");
    scanf("%d",&N);


    Complex *signal = (Complex*)malloc(N * sizeof(Complex));

    if(signal == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }


    printf("\nEnter signal samples:\n");

    for(int i=0;i<N;i++)
    {
        printf("x[%d] = ",i);

        scanf("%lf",&signal[i].real);

        signal[i].imag = 0.0;
    }


    FFT(signal,N);


    printf("\nFFT Result:\n");

    for(int k=0;k<N;k++)
    {
        printf("X[%d] = %.4f + j%.4f |X| = %.4f\n",
               k,
               signal[k].real,
               signal[k].imag,
               magnitude(signal[k]));
    }


    free(signal);

    return 0;
}
