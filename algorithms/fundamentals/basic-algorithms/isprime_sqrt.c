/*
Time Complexity: O(√n) 
*/

#include <stdio.h>
#include <math.h>

int main() {
  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n < 2)
    flag = 1;
  else {
    for (i = 2; i <= sqrt(n); ++i) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
  }

  if (flag == 0)
    printf("%d is a prime number.\n", n);
  else
    printf("%d is not a prime number.\n", n);

  return 0;
}
