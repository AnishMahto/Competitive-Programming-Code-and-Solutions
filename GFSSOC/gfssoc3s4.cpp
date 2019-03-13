#define SET(x,y) (x) |= (1 << (y))
#define CLEAR(x,y) (x) &= ~(1<< (y))
#define READ(x,y) ((0u == ((x) & (1<<(y))))?0u:1u)
#define TOGGLE(x,y) ((x) ^= (1<<(y)))
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
#include <vector>
#include <string.h>
using namespace std;

void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }
 
int r, c, MOD = 1000000007;
vector < vector <int> > children(3001);
int dp[2][3001] = {0};

int main () {
    vector <int> valid;
    scanf ("%d %d", &r, &c);
    children[0].push_back(0);
    for (int x = 0; x < (1<<c); x++) {
        if ((x&(x<<1))==0 && (x&(x<<2))==0) {
            if (READ(x, 0)==0 && READ(x, c-1)==0) {
                for (int i = 0; i < valid.size(); i++) {
                    if ((x&valid[i]) == 0 && ((x<<1)&valid[i]) == 0 && ((x>>1)&valid[i]) == 0) {
                        children[valid.size()].pb(i);
                        children[i].pb(valid.size());
                    }
                }
                valid.pb(x);
            }
        }
    }
    for (int x = 2; x <= r; x++) {
        int pos = x%2, prev = (x-1)%2;
        if (x==2) {
            for (int i = 0; i < valid.size(); i++) {
                dp[pos][i] = 1;
            }
            continue;
        }
        for (int i = 0; i < valid.size(); i++) {
            dp[pos][i] = 0;
            for (int j = 0; j < children[i].size(); j++) {
                dp[pos][i] += dp[prev][children[i][j]];
                dp[pos][i] %= MOD;
            }
        }
    }
    long long ans = 0;
    for (int x = 0; x < valid.size(); x++) {
        ans += dp[r%2][x];
        ans %= MOD;
    }
    cout << ans-1 << "\n";
}
