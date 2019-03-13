#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, t, pp, vp, pa, va, pg, vg;
	long long greatest = 0;
	cin >> n >> t;
	long long dp[t + 1];
	for (int i = 0; i < n; i++) {
	    cin >> pp >> vp >> pa >> va >> pg >> vg;
	    if (i == 0) {
	        for (int x = 0; x <= t; x++) {
	            if (x < pp) {
	                dp[x] = 0; 
	            } else if (x >= pg) {
	                dp[x] = vg;
	            } else if (x >= pa) {
	                dp[x] = va;
	            } else if (x >= pp) {
	                dp[x] = vp;
	            }
	            if (dp[x] > greatest) {
	                greatest = dp[x];
	            }
	        }
	    } else {
	        for (int x = t; x >= 0; x--) {
	            if (x >= pg) {
	                dp[x] = max (max (dp[x - pp] + vp, dp[x]), max (dp[x - pg] + vg, dp[x - pa] + va) );
	            } else if (x >= pa) {
	                dp[x] = max (max (dp[x - pp] + vp, dp[x]), dp[x - pa] + va);
	            } else if (x >= pp) {
	                dp[x] = max (dp[x - pp] + vp, dp[x]);
	            } else {
	                x = 0;
	            }
	            if (dp[x] > greatest) {
	                greatest = dp[x];
	            }
	        }
	    }
	}
	cout << greatest << endl;
	return 0;
}
