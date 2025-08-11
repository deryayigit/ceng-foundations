#include <stdio.h>

int is_perfect(int val)
{
    int div_sum = 0;

    for (int i = 1; i <= val / 2; ++i) {
        if (val % i == 0)
            div_sum += i;
    }

    return val == div_sum;
}

int main()
{
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Perfect numbers between %d and %d:\n", start, end);

    for (int i = start; i <= end; ++i) {
        if (is_perfect(i))
            printf("%d\n", i);
    }

    return 0;
}
