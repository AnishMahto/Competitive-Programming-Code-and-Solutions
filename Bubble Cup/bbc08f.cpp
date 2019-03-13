#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
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
#define pnl printf("\n")
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pF first
#define pS second
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define dbl(x) (double)(x)
#define vi vector <int>
#define vii vector < pair <int, int> >
#define vll vector <long long>
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

vll c, cc;
ll dp[2*5001], sPos, dp2[2*5001][2] = {0};
vector < pll > order;

int main () {
    ll n, m, a, b;
    sl (n); sl (m);
    REP (x, n) {
        sl (a); sl (b);
        c.pb (a);
        c.pb (b);
        order.pb (mp (a, b));
    }
    c.pb (m);
    sort (c.begin(), c.end());
    REP (x, 2*n+1) {
        if (x==0) {
            cc.pb (c[x]);
        } else if (c[x] != cc.back()) {
            cc.pb (c[x]);
        }
        if (cc.back() == m) {
            sPos = (int)cc.size()-1;
        }
    }
    int ccSz = (int)cc.size();
    REP (i, ccSz) {
        dp[i] = abs (cc[i] - m);
    }
    FORI (x, 0, n-1) {
        REP (i, ccSz) {
            dp2[i][0] = dp[i] - cc[i];
            if (i > 0) {
                dp2[i][0] = min (dp2[i][0], dp2[i-1][0]);
            }
        }
        for (int i = ccSz - 1; i >= 0; i--) {
            dp2[i][1] = dp[i] + cc[i];
            if (i < (int)cc.size() - 1) {
                dp2[i][1] = min (dp2[i][1], dp2[i+1][1]);
            }
        }
        REP (i, ccSz) {
            if (cc[i] < order[x].pF || cc[i] > order[x].pS) {
                dp[i] = min (dp2[i][0] + cc[i], dp2[i][1] - cc[i]) + min (abs(cc[i] - order[x].pF), abs(cc[i] - order[x].pS));
            } else {
                dp[i] = min (dp2[i][0] + cc[i], dp2[i][1] - cc[i]);
            }
        }
    }
    ll ans = longLIMIT::max();
    REP (x, ccSz) {
        ans = min (ans, dp[x]);
    }
    cout << ans << "\n";
}
