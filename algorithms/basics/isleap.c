#include <stdio.h>

int isleap(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main()
{
    int year;
    printf("Eneter a year please: ");
    scanf("%d", &year);

    return printf("%d %s\n", year, isleap(year) ? "leap year" : "not a leap year");
}
