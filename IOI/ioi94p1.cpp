#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, greatest = 0;
	cin >> n;
	int dp[n + 1][n + 1] = {0};
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i <= x; i++) {
	        cin >> dp[x][i];
	        if (x > 0) {
	            if (i == 0) {
	                dp[x][i] += dp[x - 1][i];
	            } else if (i == x) {
	                dp[x][i] += dp[x - 1][i - 1];
	            } else {
	                dp[x][i] += max (dp[x - 1][i], dp[x - 1][i - 1]);
	            }
	        }
	        greatest = max (greatest, dp[x][i]);
	    }
	}
	cout << greatest << endl;
	return 0;
}
