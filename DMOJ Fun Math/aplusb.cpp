#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int tests;
    scanf ("%d", &tests);
    
    int a;
    int b;
    for (int x = 0; x < tests; x++) {
        scanf ("%d", &a);
        scanf("%d", &b);
        printf ("%d\n", a + b);
    }
}
