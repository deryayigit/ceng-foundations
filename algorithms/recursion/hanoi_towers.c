/*
- Time complexity: O(2^n)
- Space complexity: O(n)
*/

#include <stdio.h>

static long long step_no = 0;

void hanoi(int n, char src, char dst, char aux) {
    if (n <= 0) return;             

    if (n == 1) {
        printf("%lld. Move disk 1 from %c to %c\n", ++step_no, src, dst);
        return;
    }

    hanoi(n - 1, src, aux, dst);
    printf("%lld. Move disk %d from %c to %c\n", ++step_no, n, src, dst);
    hanoi(n - 1, aux, dst, src);
}

int main(void) {
    int n;
    printf("Enter number of disks: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid entry.\n");
        return 1;
    }

    if (n >= 63) {
        printf("Warning: total move count overflows 64-bit for n >= 63.\n");
    } else {
        long long total = (1LL << n) - 1;
        printf("Tower of Hanoi for %d disks\nTotal moves: %lld\n\n", n, total);
    }

    hanoi(n, 'A', 'C', 'B');
    return 0;
}

