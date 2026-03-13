#include "fourier.h"
#include <cmath>

using namespace std;

namespace Fourier
{
    // Computes the nth harmonic term = an*cos(2πnt/T) + bn*sin(2πnt/T)
    double Harmonic(double t, int n, double T, double an, double bn)
    {
        double angle = 2.0 * PI * n * t / T;
        return an * cos(angle) + bn * sin(angle);
    }

    // Evaluates the truncated Fourier series: f(t) = a0/2 + Σ[ an*cos(2πnt/T) + bn*sin(2πnt/T) ]
    double EvaluateSeries(double t,
        double T,
        double a0,
        const double* a,
        const double* b,
        int N)
    {
        double sum = a0 / 2.0;

        for (int n = 1; n <= N; n++)
        {
            sum += Harmonic(t, n, T, a[n - 1], b[n - 1]);
        }

        return sum;
    }

}