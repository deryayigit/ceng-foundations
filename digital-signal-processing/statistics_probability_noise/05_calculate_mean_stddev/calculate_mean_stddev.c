#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    double x;

    double mean = 0.0;   // running (incremental) mean
    double M2   = 0.0;   // accumulated sum of squared deviations
    double delta, delta2;

    printf("Eleman sayisini girin: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x);

        delta = x - mean;
        mean = mean + delta / i;
        delta2 = x - mean;
        M2 = M2 + delta * delta2;
    }

    double variance = M2 / N;
    double std = sqrt(variance);

    printf("\nMean               = %f\n", mean);
    printf("Standard Deviation = %f\n", std);

    return 0;
}
