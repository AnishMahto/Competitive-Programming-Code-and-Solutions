#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n, counter = 1, greatest = 1;
	float d, a, b, prevA, prevB;
	scanf ("%d %f", &n, &d);
	for (int x = 0; x < n; x++) {
	    scanf ("%f %f", &a, &b);
	    if (x == 0) {
	        prevA = a;
	        prevB = b;
	    } else {
	        float distance = sqrt(pow(abs(a - prevA), 2) + pow(abs(b - prevB), 2));
	        if (distance <= d) {
	            counter++;
	            greatest = max (greatest, counter);
	        } else {
	            counter = 0;
	        }
	        prevA = a;
	        prevB = b;
	    }
	}
	cout << greatest << endl;
	return 0;
}
