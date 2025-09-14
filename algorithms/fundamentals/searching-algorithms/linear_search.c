/*
Complexity:
-Time Complexity: Best O(1), Worst O(n), Average O(n)
-Space Complexity: O(1), with array: O(n)
*/

#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, key;

    printf("Enter size of array please: ");
    scanf("%d", &n);

    int arr[n];
    printf("%d values (separate with spaces or commas):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d,", &arr[i]); // accepts comma separeted input
    }

    printf("Please enter the number to search: ");
    scanf("%d", &key);

    int result = linear_search(arr, n, key);

    if (result != -1)
        printf("Number found! Index: %d\n", result);
    else
        printf("Number not found.\n");

    return 0;
}


