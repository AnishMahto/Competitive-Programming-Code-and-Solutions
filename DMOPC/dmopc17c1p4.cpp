#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    long long ans = 0, n, h, dp[2][5001] = {0};
    scanf ("%lld %lld", &n, &h);
    long long q[n+1][4] = {0};
    //0 = init gold, 1 = init time, 2 = quest gold, 3 = quest time
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < 4; i++) {
            scanf ("%lld", &q[x][i]);
        }
    }
    for (int x = 0; x < n; x++) {
        long long iH = q[x][1], iG = q[x][0], qH = q[x][3], qG = q[x][2];
        memset (dp[1], 0, sizeof(dp[1]));
        dp[1][iH] = iG;
        for (int i = iH; i <= h; i++) {
            dp[1][i] = dp[0][i-iH] + iG;
            if (i-qH>=0 && dp[1][i-qH]!=0) {
                dp[1][i] = max (dp[1][i], dp[1][i-qH]+qG);
                ans = max (ans, dp[1][i]);
            }
        }    
        for (int i = 0; i <= h; i++) {
            dp[0][i] = max (dp[1][i], dp[0][i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
