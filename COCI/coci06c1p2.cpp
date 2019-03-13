#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	double r, euclid, noneuclid, pi = 3.14159265358979323;
	cin >> r;
	euclid = pi * (r * r);
	noneuclid = 2 * (r * r);
	printf ("%.6f\n%.6f", euclid, noneuclid);
	return 0;
}
