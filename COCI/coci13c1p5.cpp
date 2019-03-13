#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	long long n, teams[2000001] = {0}, finalists[2000001] = {0}, current;
	scanf ("%lld", &n);
	for (int x = 0; x < n; x++) {
	    scanf ("%lld", &current);
	    teams[current]++;
	}
	for (long long x = 2000000; x >= 1; x--) {
	    for (int i = x; i <= 2000000; i += x) {
	        finalists[x] += x*teams[i];
	    }
	}
	long long greatest = n;
	for (int x = 1; x <= 2000000; x++) {
	    if (finalists[x] != x) {
	        greatest = max (greatest, finalists[x]);
	    }
	}
	cout << greatest << endl;
	return 0;
}
