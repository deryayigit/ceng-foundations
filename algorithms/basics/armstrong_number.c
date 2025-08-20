#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];  //take number
    unsigned long long int num, originalNum, remainder, n = 0, result = 0;

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
    originalNum = num;

  
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;

        unsigned long long int power = 1;
        for (unsigned long long int i = 0; i < n; i++) {
            power *= remainder;
        }

        result += power;
        originalNum /= 10;
    }

    if (result == num)
        printf("You entered: %s → This is an Armstrong number.\n", cleaned);
    else
        printf("You entered: %s → This is NOT an Armstrong number.\n", cleaned);

    return 0;
}
