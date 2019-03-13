#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))
#define PRINT(x,y) for(int i=y-1;i>=0;i--){cout << READ(x,i);}cout<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define LL long long
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

long long dp[2][10001] = {0}, psum[10001] = {0}, MOD = 1000000007;

int main() {
    int n, c;
    cin >> n >> c;
    if (c==0) {
        cout << 1 << endl;
        return 0;
    }
    dp[1][0] = psum[0] = 1;
    for (int x = 1; x <= c; x++) {
        if (x!=0) {
            dp[1][x] += dp[1][x-1];
        }
    }
    for (int x = 2; x <= n; x++) {
        int pos = x%2, prev = (x-1)%2;
        memset (dp[pos], 0, sizeof(dp[pos]));
        for (int i = 0; i <= c; i++) {
            if (i-(x-1)-1 >= 0) {
                dp[pos][i] = dp[prev][i] - dp[prev][i-(x-1)-1];
            } else {
                dp[pos][i] = dp[prev][i];
            }
            dp[pos][i] %= MOD;
            if (i!=0) {
                dp[pos][i] += dp[pos][i-1]; //dp table doubles as prefix sum array
            }
        }
    }
    cout << (dp[n%2][c]-dp[n%2][c-1]+MOD)%MOD << endl;
    return 0;
}
