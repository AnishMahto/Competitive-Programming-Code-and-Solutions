#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

double t2[10001], t3[10001], dp[10001], items[10001];

int main() {
	// your code goes here
	int n;
	cin >> n;
	for (int x = 1; x <= n; x++) {
	    cin >> items[x];
	    if (x >= 2) {
	        t2[x] = max (items[x], items[x - 1]) + min (items[x], items[x - 1])/2;
	    } else {
	        t2[x] = t3[x] = items[x];
	    }
	    if (x >= 3) {
	        t3[x] = items[x] + items[x - 1] + items[x - 2] - min (items[x], min (items[x - 1], items[x - 2]));
	    } else if (x == 2) {
	        t3[x] = t2[x];
	    }
	}
	for (int x = 1; x <= n; x++) {
	    if (x < 3) {
	        dp[x] = t2[x];
	    } else if (x == 3) {
	        dp[x] = min (t2[x] + items[x - 2], t3[x]);
	    } else {
	        dp[x] = min (dp[x - 2] + t2[x], dp[x - 3] + t3[x]);
	    }
	    if (x > 1) {
	        dp[x] = min (dp[x], dp[x - 1] + items[x]);
	    }
	}
	if (n == 1) {
	    printf("%.1f\n", items[1]);
	} else if (n == 2) {
	    printf("%.1f\n", t2[2]);
	} else {
	    printf("%.1f\n", dp[n]);
	}
	return 0;
}
