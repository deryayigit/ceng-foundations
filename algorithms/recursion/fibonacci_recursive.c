/*
- Time complexity: O(2^n)
- Space complexity: O(n)
*/
#include <stdio.h>

int fibonacci(int n) {
    return (n < 2) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Which Fibonacci number do you want? ");
    scanf("%d", &n);

    printf("%d. Fibonacci number: %d\n", n, fibonacci(n));
    return 0;
}

