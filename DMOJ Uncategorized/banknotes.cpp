#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main() {
    int n, b[201] = {0}, c[201] = {0}, k, used[201][20001] = {0}, dp[20001], least = 1e9;
    memset (dp, -1, sizeof(dp));
    dp[0] = 0;
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++) {
        scanf ("%d", &b[x]);
        least = min (least, b[x]);
    }
    for (int x = 1; x <= n; x++) {
        scanf ("%d", &c[x]);
    }
    scanf ("%d", &k);
    for (int x = least; x <= k; x++) {
        int best = -1;
        for (int i = 1; i <= n; i++) {
            if (x-b[i] >= 0 && (dp[x]==-1 || dp[x-b[i]]+1 < dp[x]) && dp[x-b[i]]!=-1 && used[i][x-b[i]]+1 <= c[i]) {
                dp[x] = dp[x-b[i]]+1;
                best = i;
            }
        }
        if (best!=-1) {
            for (int i = 1; i <= n; i++) {
                if (i==best) {
                    used[i][x] = used[i][x-b[best]]+1;
                } else {
                    used[i][x] = used[i][x-b[best]];
                }
            }
        }
    }
    cout << dp[k] << "\n";
}
