#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][30001];
int pSum[30001];

int main() {
	// your code goes here
	int n, k, w, current, t;
	cin >> t;
	vector <int> pins;
	while (t--) {
	pins.clear();
	cin >> n >> k >> w;
	memset(dp, 0, sizeof(int)*501*30001);
	memset(pSum, 0, sizeof(int)*30001);
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    pins.push_back(current);
	}
	for (int x = 0; x < k; x++) {
	    for (int i = 0; i < n; i++) {
	        if (x == 0) {
	            if (i == 0) {
	                pSum[i] = pins[i];
	                dp[x][i] = pSum[i];
	            } else if (i <= w - 1) {
	                pSum[i] = pins[i] + pSum[i - 1];
	                dp[x][i] = pSum[i];
	            } else {
	                pSum[i] = pSum[i - 1] - pins[i - w] + pins[i];
	                dp[x][i] = max (dp[x][i - 1], pSum[i]);
	            }
	        } else {
	            if (i <= w - 1) {
	                dp[x][i] = pSum[i];
	            } else {
	                dp[x][i] = max (dp[x - 1][i - w] + pSum[i], dp[x][i - 1]);
	            }
	        }
	    }
	}
	cout << dp[k - 1][n - 1] << endl;
	}
	return 0;
}
