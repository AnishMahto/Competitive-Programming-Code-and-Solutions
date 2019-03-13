#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int dp[n + 1];
	dp[0] = 0;
	for (int x = 1; x <= n; x++) {
	    dp[x] = 0;
	    if (x >= a && (dp[x - a] >= 1 || x - a == 0)) {
	        dp[x] = max (dp[x], dp[x - a] + 1);
	    }
	    if (x >= b && (dp[x - b] >= 1 || x - b == 0)) {
	        dp[x] = max (dp[x], dp[x - b] + 1);
	    }
	    if (x >= c && (dp[x - c] >= 1 || x - c == 0)) {
	        dp[x] = max (dp[x], dp[x - c] + 1);
	    }
	}
	cout << dp[n] << endl;
	return 0;
}
