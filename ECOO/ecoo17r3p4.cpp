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

pll p[4001];
int n, m;
ll dp2[4001][4001] = {0}, dp[4001][21], rPsum[4001] = {0}, MOD = 1000000007;

void inline genCosts () {
    FORI (x, 1, n) {
        FORI (i, 1, n) {
            dp2[x][i] = (ll)abs(p[i].pF - p[x].pF) * p[i].pS + dp2[x][i-1];
        }
    }
}

void inline genReluctancePsum () {
    FORI (x, 1, n) {
        rPsum[x] = p[x].pS + rPsum[x-1];
    }
}

ll inline gRSum (int l, int r) {
    return rPsum[r] - rPsum[l-1];
}

ll inline gdp2Sum (int pos, int l, int r) {
    return dp2[pos][r] - dp2[pos][l-1];
}

ll solve (int pos, int rem) {
    if (dp[pos][rem] != -1) {
        return dp[pos][rem];
    } else if (pos == 0) {
        dp[pos][rem] = 0;
        return 0;
    } else if (rem == 0) {
        dp[pos][rem] = -2;
        return -2;
    } else {
        dp[pos][rem] = -2;
        deque <int> q;
        for (int x = pos; x >= 1; x--) {
            ll med = gRSum (x, pos)/2;
            q.pb (x);
            while (!q.empty() && gRSum(q.front(), pos) < med) {
                q.pop_front();
            }
            if (solve (x-1, rem-1) < 0) {
                continue;
            }
            if (dp[pos][rem] == -2) {
                dp[pos][rem] = solve (x-1, rem-1) + gdp2Sum (q.front(), x, pos);
            } else {
                dp[pos][rem] = min (dp[pos][rem], solve (x-1, rem-1) + gdp2Sum (q.front(), x, pos));
            }
        }
    }
    return dp[pos][rem];
}

int main () {
    REP (t, 10) {
        CL (dp, -1);
        si (n); si (m);
        FORI (x, 1, n) {
            sl (p[x].pF); sl (p[x].pS);
        }
        genCosts();
        genReluctancePsum();
        printf ("%lld\n", solve (n, m)%MOD);
    }
}
