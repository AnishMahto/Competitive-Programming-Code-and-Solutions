#include <iostream>
#include <stdlib.h>
using namespace std;

int dp[1001][1001] = {0}, a, b, c;
string first, second;

int solve (int m, int n) {
    //cout << m << " " << n << endl;
    if (dp[m][n] != 0) {
        return dp[m][n];
    } else if (m == 0 && n == 0) {
        if (first[n] == second[m]) {
            return 0;
        } else {
            return min(c, a+b);
        }
    } else {
        dp[m][n] = 1000000000;
        if (first[n] == second[m] && m > 0 && n > 0) {
            dp[m][n] = min (dp[m][n], solve (m-1,n-1));
        } else if (first[n] == second[m] && m > 0) {
            dp[m][n] = min (dp[m][n], m*b);
        } else if (first[n] == second[m] && n > 0) {
            dp[m][n] = min (dp[m][n], n*a);
        }
            if (m > 0 && n > 0) {
                dp[m][n] = min (dp[m][n], solve (m-1,n-1)+min(c, a+b));
            }
            if (n > 0 && m != 0) {
                dp[m][n] = min (dp[m][n], solve(m,n-1)+a);
            } else if (m == 0) {
                dp[m][n] = min (dp[m][n], solve(m,n-1)+a);
            }
            if (m > 0 && n != 0) {
                dp[m][n] = min (dp[m][n], solve (m-1,n)+b);
            } else if (n == 0) {
                dp[m][n] = min (dp[m][n], solve (m-1,n)+b);
            }
        
    }
    return dp[m][n];
}

int main() {
	// your code goes here
	cin >> a >> b >> c >> first >> second;
	cout << solve (second.length() - 1, first.length() - 1) << endl;
	return 0;
}
