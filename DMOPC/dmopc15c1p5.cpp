#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int w, h, n, b[301][301] = {0}, greatest = 0;
	scanf ("%d %d %d", &w, &h, &n);
	for (int x = 1; x <= h; x++) {
	    for (int i = 1; i <= w; i++) {
	        scanf ("%d", &b[x][i]);
	        b[x][i] += b[x][i - 1];
	        b[x][i] += b[x - 1][i];
	        b[x][i] -= b[x - 1][i - 1];
	        if (x*i <= n) {
	            greatest = max (greatest, b[x][i]);
	        } else {
	            for (int z = 1; z <= (int)(sqrt(n)) + 1; z++) {
	                    if (z <= x & (n - (n%z))/z <= i) {
	                        greatest = max (greatest, b[x][i] - b[x - z][i] - b[x][i - (n - (n%z))/z] + b[x - z][i - (n - (n%z))/z]);
	                    }
	                    if (z <= i & (n - (n%z))/z <= x) {
	                        greatest = max (greatest, b[x][i] - b[x - (n - (n%z))/z][i] - b[x][i - z] + b[x - (n - (n%z))/z][i - z]);
	                    }
	            }
	        }
	    }
	}
	cout << greatest << endl;
	return 0;
}
