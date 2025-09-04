/*
Space Complexity: O(n)
Time Complexity: O(n)
*/

#include <stdio.h>

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int num;

    printf("Bir sayi girin: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of negative numbers is undefined\n");
    } else {
        printf("%d! = %d\n", num, factorial(num));
    }

    return 0;
}
