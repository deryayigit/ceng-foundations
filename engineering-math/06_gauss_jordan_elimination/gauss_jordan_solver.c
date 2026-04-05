#include <stdio.h>   // I/O functions
#include <stdlib.h>  // Dynamic memory management (malloc, free)
#include <math.h>    // fabs

/* Parameters:
   a -> augmented matrix of size n x (n+1)
   n -> number of variables
*/
void gauss_jordan(double **a, int n)
{
    // Process each pivot column
    for(int i = 0; i < n; i++)
    {
        // Partial pivoting
        int max_row = i;

        for(int k = i+1; k < n; k++)
            if(fabs(a[k][i]) > fabs(a[max_row][i]))
                max_row = k;

        if(a[max_row][i] == 0.0)
        {
            printf("No unique solution\n");
            return;
        }

        // Swap rows if needed
        if(max_row != i)
        {
            for(int j = 0; j <= n; j++)
            {
                double temp = a[i][j];
                a[i][j] = a[max_row][j];
                a[max_row][j] = temp;
            }
        }

        // Pivot element
        double pivot = a[i][i];

        // Normalize pivot row (make pivot = 1)
        for(int j = 0; j <= n; j++)
            a[i][j] /= pivot;

        // Eliminate pivot column
        for(int k = 0; k < n; k++)
        {
            if(k != i)
            {
                double factor = a[k][i];

                // Rk = Rk - factor * Ri
                for(int j = 0; j <= n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }
}

int main()
{
    int n;

    printf("Number of variables: ");
    scanf("%d",&n);

    // Allocate augmented matrix dynamically
    double **a = malloc(n * sizeof(double*));

    for(int i=0;i<n;i++)
        a[i] = malloc((n+1) * sizeof(double));

    printf("\nEnter augmented matrix row by row\n");
    printf("Values must be separated by spaces\n\n");

    // Read matrix input
    for(int i=0;i<n;i++)
    {
        printf("Row %d: ", i+1);

        for(int j=0;j<=n;j++)
            scanf("%lf",&a[i][j]);
    }

    // Apply Gauss-Jordan elimination
    gauss_jordan(a,n);

    // Print solution
    printf("\nSolution:\n");
    for(int i=0;i<n;i++)
        printf("x%d = %.6f\n",i+1,a[i][n]);

    return 0;
}
