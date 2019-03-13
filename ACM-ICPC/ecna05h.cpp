#include <iostream>
#include <string.h>
using namespace std;

int dp[1001][1001] = {0}, nums[1001] = {0};

int solve (int start, int end) {
    if (dp[start][end] != 0) {
        return dp[start][end];
    } else {
        if (end - 2 >= start) {
            dp[start][end] = nums[end] + ((nums[end - 1] > nums[start]) ? (solve (start, end - 2)):(solve (start + 1, end - 1)));
        }
        if (start + 2 <= end) {
            dp[start][end] = max (dp[start][end], nums[start] + ( (nums[end] > nums[start + 1]) ? (solve (start + 1, end - 1)):(solve (start + 2, end))));
        }
        if (end - 1 == start) {
            if (nums[start] > nums[end]) {
                dp[start][end] = nums[start];
            } else {
                dp[start][end] = nums[end];
            }
        }
    }
    return dp[start][end];
}

int main() {
	// your code goes here
	int n, sum, count = 0;
	cin >> n;
	while (n != 0) {
	    memset(dp, 0, sizeof(int)*1001*1001);
	    memset(nums, 0, sizeof(int)*1001);
	    sum = 0;
	    count++;
	    for (int x = 1; x <= n; x++) {
	        cin >> nums[x];
	        dp[x][x] = nums[x];
	        sum += nums[x];
	    }
	    cout << "In game " << count << ", the greedy strategy might lose by as many as " << solve (1, n) - (sum - dp[1][n]) << " points." << endl;
	    cin >> n;
	}
	return 0;
}
