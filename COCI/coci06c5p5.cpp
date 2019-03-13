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

int dp[301][301] = {0}, nums[301], n, tmp = 0;

int solve (int l, int r) {
    if (dp[l][r] != -200) {
        return dp[l][r];
    } else if (r-l+1>=n) {
        dp[l][r] = 0;
        return 0;
    } else {
        if ((r-l+1)%2==0) {
            dp[l][r] = -200;
            dp[l][r] = max (dp[l][r], solve (l-1, r)+nums[l-1]);
            dp[l][r] = max (dp[l][r], solve (l, r+1)+nums[r+1]);
        } else {
            dp[l][r] = 200;
            dp[l][r] = min (dp[l][r], solve (l-1, r)-nums[l-1]);
            dp[l][r] = min (dp[l][r], solve (l, r+1)-nums[r+1]);
        }
    }
    return dp[l][r];
}

int main () {
    for (int x = 0; x < 301; x++) {
        for (int i = 0; i < 301; i++) {
            dp[x][i] = -200;
        }
    }
    si (n);
    for (int x = 0; x < n; x++) {
        si (nums[100+x]);
        nums[100+x] %= 2;
    }
    int ctr = n-1, pos = 99;
    while (ctr != -1) {
        nums[pos] = nums[100+ctr];
        ctr--;
        pos--;
    }
    ctr = 0; pos = 100+n;
    while (ctr != n) {
        nums[pos] = nums[100+ctr];
        ctr++;
        pos++;
    }
    int tot = 0;
    for (int x = 0; x < n; x++) {
        int ans = solve (100+x, 100+x);
        if (nums[100+x]%2!=0) {
            ans++;
        }
        if (ans > 0) {
            tot++;
        }
    }
    cout << tot << "\n";
}
