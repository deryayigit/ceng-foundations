/*
Space Complexity: O(1)
Time Complexity: O(n^2)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];  //take number
    unsigned long long int num, original_num, remainder, n = 0; 
    unsigned long long int result = 0;

    printf("Enter an integer: ");
    fgets(input, sizeof(input), stdin);

    
    char cleaned[100]; //remove space
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            cleaned[j++] = input[i];
        }
    }
    cleaned[j] = '\0';

    num = strtoull(cleaned, NULL, 10);
    original_num = num;

  
    while (original_num != 0) {
        original_num /= 10;
        ++n;
    }

    original_num = num;

    while (original_num != 0) {
        remainder = original_num % 10;

        unsigned long long int power = 1;
        for (unsigned long long int i = 0; i < n; i++) {
            power *= remainder;
        }

        result += power;
        original_num /= 10;
    }

    if (result == num)
        printf("You entered: %s → This is an Armstrong number.\n", cleaned);
    else
        printf("You entered: %s → This is NOT an Armstrong number.\n", cleaned);

    return 0;
}



