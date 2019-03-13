#include <iostream>
#include <cstdio>
#include <bitset>
#include <string.h>
using namespace std;

int dp[12][1<<12+1], g[13][13] = {0}, r, c;

int solve (int row, long long prev);

void helper (int row, bitset <12> cur, bitset<12> nxt, int pos) {
    if (pos==c+1) {
        dp[row][(int)cur.to_ulong()] += solve (row+1, nxt.to_ulong());
        dp[row][(int)cur.to_ulong()] %= 100000000;
    } else {
        if (g[row+1][pos]==0) {
            helper (row, cur, nxt, pos+1);
            return;
        } else if (cur.test(pos) || (pos>0 && nxt.test(pos-1))) {
            helper (row, cur, nxt, pos+1);
        } else {
            helper (row, cur, nxt, pos+1);
            nxt.set(pos);
            helper (row, cur, nxt, pos+1);
        }
    }
    return;
}

int solve (int row, long long prev) {
    if (row==r) {
        return 1;
    } else if (dp[row][prev] != -1) {
        return dp[row][prev];
    } else {
        bitset <12> tmp = prev, nxt;
        dp[row][prev] = 0;
        helper (row, tmp, nxt, 0);
    }
    return dp[row][prev];
}

int main() {
    memset (dp, -1, sizeof(dp));
    scanf ("%d %d", &r, &c);
    for (int x = 1; x <= r; x++) {
        for (int i = 1; i <= c; i++) {
            scanf ("%d", &g[x][i]);
        }
    }
    bitset <12> tmp;
    cout << solve (0, tmp.to_ulong()) % 100000000 << "\n";
    return 0;
}
