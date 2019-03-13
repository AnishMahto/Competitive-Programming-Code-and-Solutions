#include <iostream>
#include <cstdio>
using namespace std;

short dp[10002][10002] = {0};

int main() {
	// your code goes here
	int n, m, a, b, c, d;
	scanf ("%d %d", &n, &m);
	for (int x = 0; x < m; x++) {
	    scanf ("%d %d %d %d", &a, &b, &c, &d);
	    a++;b++;
	    dp[a][b]++;
	    if (n > 1001) {
	        dp[a][b] %= 30;
	    }
	    dp[a][b + d]--;
	    if (n > 1001) {
    	    dp[a][b + d] %= 30;
	    }
	    dp[a + c][b]--;
	    if (n > 1001) {
	        dp[a + c][b] %= 30;
	    }
	    dp[a + c][b + d]++;
	    if (n > 1001) {
    	    dp[a + c][b + d] %= 30;
	    }
	}
	long long count = 0;
	for (int x = 1; x <= n; x++) {
	    for (int i = 1; i <= n; i++) {
	        if (x != 1 || i != 1) {
	            if (x == 1) {
	                dp[x][i] += dp[x][i - 1];
	            } else if (i == 1) {
	                dp[x][i] += dp[x - 1][i];
	            } else {
	                dp[x][i] += dp[x - 1][i] + dp[x][i - 1] - dp[x - 1][i - 1];
	            }
	        }
	        if (dp[x][i] % 2 == 1) {
	            count++;
	        }
	        if (n > 1001) {
	            dp[x][i] %= 30;
	        }
	    }
	}
	cout << count << endl;
	return 0;
}
