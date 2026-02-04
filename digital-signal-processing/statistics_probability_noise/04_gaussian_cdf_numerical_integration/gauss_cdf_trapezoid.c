#include <stdio.h>   // Standard input/output functions
#include <stdlib.h>  // General utilities (strtod, strtoull)
#include <math.h>    // Mathematical functions (exp, sqrt)
#include <errno.h>   // Error reporting for strtod/strtoull

static const double PI = 3.141592653589793238462643383279502884;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

static void print_usage(const char *prog) {
    printf("Usage:\n");
    printf("  %s <mean> <std_dev> <X> [iterations]\n", prog);
    printf("Example:\n");
    printf("  %s 0 1 1.0 100000\n", prog);
}

// Normal Distribution PDF
static double pdf_gauss(double mean, double sigma, double x) {
    double z = (x - mean) / sigma; // Standardized variable
    return (1.0 / (sigma * sqrt(2.0 * PI))) * exp(-0.5 * z * z); // Gaussian PDF formula
}

//Trapezoidal integral
static double trapz_integral_pdf(double mean, double sigma,
                                 double x1, double x2,
                                 size_t iterations)
{
    double a = MIN(x1, x2);
    double b = MAX(x1, x2);

    if (iterations == 0) return 0.0;
    if (a == b) return 0.0;

    double step = (b - a) / (double)iterations; // Standardized variable
    double sum = 0.0;

    // x_i = a + i*step
    double x_left = a;
    for (size_t i = 0; i < iterations; i++) {
        double x_right = x_left + step;

        double f_left  = pdf_gauss(mean, sigma, x_left);
        double f_right = pdf_gauss(mean, sigma, x_right);

        sum += 0.5 * (f_left + f_right) * step;

        x_left = x_right;
    }

    return sum;
}

static double cdf_gauss_trapz(double mean, double sigma,
                              double x, size_t iterations)
{
    double left_limit  = mean - 6.0 * sigma;
    double right_limit = mean + 6.0 * sigma;

    if (x <= left_limit)  return 0.0;
    if (x >= right_limit) return 1.0;

    return trapz_integral_pdf(mean, sigma, left_limit, x, iterations);
}

// Argument parse: strtod + error checking
static int parse_double(const char *s, double *out) {
    errno = 0;
    char *end = NULL;
    double v = strtod(s, &end);
    if (errno != 0) return 0;
    if (end == s || *end != '\0') return 0; 
    *out = v;
    return 1;
}

static int parse_size_t(const char *s, size_t *out) {
    errno = 0;
    char *end = NULL;
    unsigned long long v = strtoull(s, &end, 10);
    if (errno != 0) return 0; // Conversion error check
    if (end == s || *end != '\0') return 0;
    if (v == 0) return 0; // Iteration count must be positive
    *out = (size_t)v;
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 4 && argc != 5) {
        print_usage(argv[0]);
        return 1;
    }

    double mean, sigma, x;
    size_t iterations = 100000; // default iteration count (1e5) 

  // Parse mean, standard deviation, and evaluation point
    if (!parse_double(argv[1], &mean) ||
        !parse_double(argv[2], &sigma) ||
        !parse_double(argv[3], &x))
    {
        fprintf(stderr, "Error: mean/std_dev/X parse edilemedi.\n");
        print_usage(argv[0]);
        return 1;
    }

    if (argc == 5) {
        if (!parse_size_t(argv[4], &iterations)) {
            fprintf(stderr, "Error: iterations pozitif integer olmalı.\n");
            return 1;
        }
    }

    if (!(sigma > 0.0)) { 
        fprintf(stderr, "Error: std_dev (sigma) > 0 olmalı.\n"); // Standard deviation must be strictly positive
        return 1;
    }

    double cdf = cdf_gauss_trapz(mean, sigma, x, iterations); // Compute Gaussian CDF using trapezoidal integration

    printf("mean=%.6f sigma=%.6f X=%.6f iterations=%zu\n", mean, sigma, x, iterations);
    printf("CDF(%.6f)=%.10f\n", x, cdf);

    return 0;
}
