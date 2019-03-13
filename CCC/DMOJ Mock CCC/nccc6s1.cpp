#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n, s = 0, c;
	cin >> n;
	for (int x = 0; x < n; x++) {
		cin >> c;
		s += c;
	}
	printf ("%.1f\n", (double)s/(double)n);
}
