#include <iostream>
using namespace std;

int dp[401][401] = {0}, balls[401] = {0}, greatest = 0;

int solve (int start, int end) {
    //start and end are inclusive
    if (start == end) {
        dp[start][end] = balls[start];
        greatest = max (greatest, dp[start][end]);
        return balls[start];
    } else if (dp[start][end] != 0) {
        return dp[start][end];
    } else {
        int left, right, middle, firstBreak = start, lastBreak = end;
        for (int x = start; x < end; x++) {
            if (solve (start, x) == solve (x + 1, end) && solve (start, x) != -1) {
                dp[start][end] = max (dp[start][end], solve (start, x)*2);
            } else if (solve (start, x) > solve (x + 1, end) && solve (x + 1, end) != -1) {
                break;
            }
            greatest = max (greatest, max (solve(start, x), solve (x + 1, end)));
        }
        while (lastBreak - firstBreak > 0) {
                left = solve (start, firstBreak);
                right = solve (lastBreak, end);
                if (left == right && left != -1) {
                    middle = solve (firstBreak + 1, lastBreak - 1);
                    if (middle != -1) {
                        dp[start][end] = max (dp[start][end], left*2+middle);
                    }
                    break;
                } else if (right > left) {
                    firstBreak++;
                } else {
                    lastBreak--;
                }
                greatest = max (greatest, max (left, right));
                greatest = max (greatest, middle);
        }
    }
    if (dp[start][end] == 0) {
        dp[start][end] = -1;
    }
    greatest = max (greatest, dp[start][end]);
    return dp[start][end];
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> balls[x];
	}
	solve (0, n - 1);
	cout << greatest << endl;
	return 0;
}
