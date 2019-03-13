#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int dp[2001][2001] = {0}, dp2[2001][2001] = {0};

int main() {
	// your code goes here
	int a, b, t;
	char w;
	scanf ("%d", &t);
	for (int r = 1; r <= t; r++) {
	    scanf ("%d %c %d", &a, &w, &b);
	    dp[1][0] = dp[2][0] = 1;
	    dp2[0][0] = dp2[0][1] = 1;
	    for (int x = 0; x <= a; x++) {
	        for (int i = 0; i <= b; i++) {
	                if (x - 1 > i && i - 1 >= 0) {
	                    dp[x][i] = (dp[x - 1][i] + dp[x][i - 1]) % 1000000007;
	                } else if (i - 1 >= 0) {
	                    dp[x][i] = dp[x][i - 1] % 1000000007;
	                } else if (x - 1 > i) {
	                    dp[x][i] = dp[x - 1][i] % 1000000007;
	                }
	            if (dp2[x][i] == 0) {
	            if (i - 1 >= x) {
	                dp2[x][i] += dp2[x][i - 1] % 1000000007;
	            }
	            if (x - 1 >= 0) {
	                dp2[x][i] += dp2[x - 1][i] % 1000000007;
	            }
	            }
	        }
	    }
	    cout << "Case #" << r << ": " << dp[a][b] << " " << dp2[a][b] << endl;
	}
	return 0;
}
