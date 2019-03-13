#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <limits>
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

ll dp[5001][5001], c[5001][2] = {0};
int n;

ll solve (int pos, int topCard) {
    if (topCard<=0) {
        return 0;
    } else if (dp[pos][topCard] != -1) {
        return dp[pos][topCard];
    } else if (pos==topCard+1) {
        if (c[pos][1]==0) {
            dp[pos][topCard] = -2;
            return -2;
        }
        dp[pos][topCard] = solve (pos-1, topCard-c[pos][1]) + c[pos][0];
        return dp[pos][topCard];
    } else {
        dp[pos][topCard] = numeric_limits<ll>::max();
        if (solve (pos-1, topCard-c[pos][1]) >= 0) {
            dp[pos][topCard] = min(dp[pos][topCard], solve (pos-1, topCard-c[pos][1]) + c[pos][0]);
        }
        if (solve (pos-1, topCard) >= 0) {
            dp[pos][topCard] = min(dp[pos][topCard], solve (pos-1, topCard));
        }
    }
    return dp[pos][topCard];
}

int main () {
    memset (dp, -1, sizeof(dp));
    si (n);
    for (int x = n; x >= 1; x--) {
        si (c[x][0]); si (c[x][1]);
    }
    cout << solve (n, n-1) << "\n";
}
