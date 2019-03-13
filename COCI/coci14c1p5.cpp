#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int n, m, k;
long long dp[101][501] = {0}, cnt[101] = {0};

long long inline sum (long long N) {
    return N*(N+1)/2;
}

long long solve (int M, long long K) {
    if (dp[M][K] != -1) {
        return dp[M][K];
    } else if (M==1) {
        if (K==0) {
            dp[M][K] = sum (cnt[M]);
        } else {
            if (cnt[M] != 0) {
                long long sz = cnt[M]/(K+1), rem;
                dp[M][K] = sum (sz) * (K);
                rem = cnt[M] - sz * K;
                dp[M][K] += sum (sz) + (rem-sz)*(sz+1);
            } else {
                dp[M][K] = 0;
            }
        }
        return dp[M][K];
    } else if (cnt[M] == 0) {
        dp[M][K] = solve (M-1, K);
        return dp[M][K];
    } else if (K==0) {
        dp[M][K] = sum (cnt[M]) + solve (M-1, K);
    } else {
        dp[M][K] = sum (cnt[M]) + solve (M-1, K);
        long long cur, sz, rem;
        for (long long x = 1; x <= K; x++) {
            sz = cnt[M]/(x+1);
            cur = 0;
            cur = sum (sz) * (x);
                rem = cnt[M] - sz * x;
                cur += sum (sz) + (rem-sz)*(sz+1);
                cur += solve (M-1, K-x);
            dp[M][K] = min (dp[M][K], cur);
        }
    }
    return dp[M][K];
}

int main() {
    memset (dp, -1, sizeof(dp));
    int cur;
    scanf ("%d %d %d", &n, &m, &k);
    for (int x = 0; x < n; x++) {
        scanf ("%d", &cur);
        cnt[cur]++;
    }
    cout << solve (m, k) << "\n";
    return 0;
}
