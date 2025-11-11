/*
Subject : Let us assume that Turkey's population is 85 million this year. If the population grows by 1.05 per cent each year, in which year will it exceed 100 million?
*/

#include <iostream>
using namespace std;

int main() {
    double pop = 85000000; 
    int year = 2025;
    
    while (pop <= 100000000) {
        pop *= 1.0105; 
        year++;
    }

    cout << "Population exceeds 100 million in the year " << yil <<  endl;
    return 0;
}
