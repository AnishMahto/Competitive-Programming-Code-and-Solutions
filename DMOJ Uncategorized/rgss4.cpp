#include <iostream>
using namespace std;

int n;
int heights[1001];
int dp[1001] = {0};

int solve (int pos, int sum) {
    if (dp[pos] != 0) {
        return dp[pos];
    }
    if (pos == n - 1) {
        dp[pos] = heights[pos];
        return dp[pos];
    }
    dp[pos] = heights[pos];
    for (int x = pos + 1; x < n; x++) {
        if (heights[pos] < heights[x]) {
            dp[pos] = max (dp[pos], heights[pos] + solve (x, sum));
        }
    }
    return dp[pos];
}

int main() {
	// your code goes here
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> heights[x];
	}
	for (int x = 0; x < n; x++) {
	    solve (x, 0);
	}
	int answer = -1;
	for (int x = 0; x < n; x++) {
	    if (dp[x] > answer) {
	        answer = dp[x];
	    }
	}
	cout << answer << endl;
	return 0;
}
