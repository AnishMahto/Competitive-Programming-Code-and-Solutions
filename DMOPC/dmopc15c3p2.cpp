#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	long long n, sum = 0, s[100001] = {0}, wasteOfTime = 0;
	scanf ("%lld", &n);
	for (int x = 0; x < n; x++) {
	    scanf ("%lld", &s[x]);
	    sum += s[x];
	}
	if (sum % n != 0) {
	    cout << "Impossible" << endl;
	    return 0;
	}
	sum /= n;
	for (int x = 0; x < n; x++) {
	    wasteOfTime += max(s[x], sum) - min (s[x], sum);
	}
	if (wasteOfTime % 2 != 0) {
	    cout << "Impossible" << endl;
	    return 0;
	} else {
	    cout << wasteOfTime/2 << endl;
	}
	return 0;
}
