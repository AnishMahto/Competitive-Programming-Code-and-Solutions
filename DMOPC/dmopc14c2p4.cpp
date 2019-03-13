#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int mass[n];
	
	for (int x = 0; x < n; x++) {
	    scanf ("%d", &mass[x]);
	    if (x > 0) {
	        mass[x] += mass[x - 1];
	    }
	}
	
	int q;
	cin >> q;
	
	int a, b;
	
	for (int x = 0; x < q; x++) {
	    scanf("%d", &a);
	    scanf("%d", &b);
	    if (a > 0) {
	        printf ("%d\n", mass[b] - mass[a - 1]);
	    } else {
	        printf("%d\n", mass[b]);
	    }
	}
	
	return 0;
}
