#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	double n, x;
	cin >> n;
	x = -0.5 + sqrt(0.25 + (double)2*n);
	if ((long long)x - ceil(x) == 0) {
	    cout << x << endl;
	} else {
	    long long bottom = floor (x), top = ceil (x);
	    long long temp1 = 0.5*pow(bottom, 2) + 0.5*bottom + 1;
	    long long temp2 = 0.5*pow(top, 2) + 0.5*top;
	    cout << ((temp1 + temp2)*(temp2 - temp1 + 1))/2 << endl;
	}
	return 0;
}
