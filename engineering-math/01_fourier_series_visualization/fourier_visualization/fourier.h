#pragma once

namespace Fourier
{
    constexpr double PI = 3.14159265358979323846;

    double Harmonic(double t,
        int n,
        double T,
        double an,
        double bn);

    double EvaluateSeries(double t,
        double T,
        double a0,
        const double* a,
        const double* b,
        int N);
}