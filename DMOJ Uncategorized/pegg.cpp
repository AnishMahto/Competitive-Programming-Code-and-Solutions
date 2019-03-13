#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

long long dp[33][33] = {0};
//dp[eggs][drops] = max floors can cover

long long solve (int eggs, int drops) {
    if (dp[eggs][drops] != -1) {
        return dp[eggs][drops];
    } else if (eggs == 0 || drops == 0) {
        dp[eggs][drops] = 0;
        return 0;
    } else if (drops==1) {
        dp[eggs][drops]=1;
        return 1;
    } else if (eggs==1) {
        dp[eggs][drops] = drops;
        return drops;
    } else {
        dp[eggs][drops] = 1 + solve(eggs-1,drops-1) + solve(eggs,drops-1);
    }
    return dp[eggs][drops];
}

int main() {
    memset (dp, -1, sizeof(dp));
    long long t, n, k;
    scanf ("%lld", &t);
    for (int x = 32; x >= 0; x--) {
        for (int i = 32; i >= 0; i--) {
            solve (x, i);
        }
    }
    for (int x = 0; x < t; x++) {
        scanf ("%lld %lld", &n, &k);
        for (int i = 0; i <= 32; i++) {
            if (dp[k][i] >= n) {
                printf ("%d\n", i);
                break;
            } else if (i==32) {
                printf ("Impossible\n");
            }
        }
    }

    return 0;
}
