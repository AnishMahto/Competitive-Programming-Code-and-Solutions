#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int n, nums[201] = {0}, dp[201][201] = {0}, greatest = 0;

int solve (int start, int end) {
    if (end - start <= 1) {
        return 0;
    } else if (dp[start][end] != -1) {
        return dp[start][end];
    } else {
        for (int x = start + 1; x < end; x++) {
            dp[start][end] = max (dp[start][end], nums[start] + nums[end] + nums[x] + solve (start, x) + solve (x, end));
        }
    }
    return dp[start][end];
}

int main() {
	// your code goes here
	scanf ("%d", &n);
	while (n != 0) {
	    greatest = 0;
	    memset(dp, -1, sizeof(int)*201*201);
	    for (int x = 0; x < n; x++) {
	        scanf ("%d", &nums[x]);
	    }
	    cout << solve (0, n - 1) << endl;
	    scanf ("%d", &n);
	}
	return 0;
}
