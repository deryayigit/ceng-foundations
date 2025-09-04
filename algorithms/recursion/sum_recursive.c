/*
Time complexity: O(n)
Space complexity: O(n)
*/

#include <stdio.h>

int addNumbers(int n) {
  if (n > 0)
    return n + addNumbers(n - 1);
  else
    return 0;
}

int main() {

  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  printf("Sum = %d", addNumbers(num));
  return 0;
}


