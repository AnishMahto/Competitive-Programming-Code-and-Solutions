#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[1001][1001] = {0}, n, scores[2][1001];
char rec[2][1001];

int solve (int p1, int p2) {
    if (dp[p1][p2] != -1) {
        return dp[p1][p2];
    } else if (p1 == 0 || p2 == 0) {
        return 0;
    } else {
        if (p1 >= 1) {
            dp[p1][p2] = max (dp[p1][p2], solve (p1-1, p2));
        }
        if (p2 >= 1) {
            dp[p1][p2] = max (dp[p1][p2], solve (p1, p2-1));
        }
        if ((rec[0][p1] == 'W' && rec[1][p2] == 'L' && scores[1][p2] < scores[0][p1]) || (rec[0][p1] == 'L' && rec[1][p2] == 'W' && scores[1][p2] > scores[0][p1])) {
            dp[p1][p2] = max (dp[p1][p2], solve (p1-1, p2-1) + scores[0][p1] + scores[1][p2]);
        }
    }
    return dp[p1][p2];
}

int main () {
    for (int x = 0; x < 1001; x++) { for (int i = 0; i < 1001; i++) { dp[x][i] = -1; } }
    cin >> n;
    for (int x = 1; x <= n; x++) {
        cin >> rec[0][x];
    }
    for (int x = 1; x <= n; x++) {
        cin >> scores[0][x];
    }
    for (int x = 1; x <= n; x++) {
        cin >> rec[1][x];
    }
    for (int x = 1; x <= n; x++) {
        cin >> scores[1][x];
    }
    cout << solve (n,n) << endl;
    return 0;
}
