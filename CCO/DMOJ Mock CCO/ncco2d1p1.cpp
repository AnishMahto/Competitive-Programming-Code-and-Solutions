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
#define GCD(a,b) __gcd((a),(b))
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

int dp[302][302][2] = {0}, tot, N, sub = 0, T;
vi p;

int solve (int l, int r, bool L) {
    if (dp[l][r][L] != -1) {
        return dp[l][r][L];
    } else if (r-l+1 - sub == N) {
        dp[l][r][L] = 0;
    } else {
        dp[l][r][L] = 100000000;
        int rem = N - (r-l+1-sub);
        if (L) {
            if (l > 0) {
                dp[l][r][L] = min (dp[l][r][L], solve (l-1, r, true)+(p[l]-p[l-1])*rem);
            }
            if (r < tot-1) {
                dp[l][r][L] = min (dp[l][r][L], solve (l, r+1, false)+(p[r+1]-p[l])*rem);
            }
        } else {
            if (l > 0) {
                dp[l][r][L] = min (dp[l][r][L], solve (l-1, r, true)+(p[r]-p[l-1])*rem);
            }
            if (r < tot-1) {
                dp[l][r][L] = min (dp[l][r][L], solve (l, r+1, false)+(p[r+1]-p[r])*rem);
            }
        }
    }
    return dp[l][r][L];
}

int main () {
    int n, t, cur, idxZ = -1, ans = 0;
    bool z = false;
    si (n); si (t);
    REP (x, n) {
        si (cur);
        p.pb (cur);
        if (cur==0) {
            z = true;
        }
    }
    if (!z) {
        sub++;
        p.pb (0);
    }
    sort (p.begin(), p.end());
    tot = (int)p.size();
    REP (x, tot) {
        if (p[x]==0) {
            idxZ = x;
            break;
        }
    }
    T=t;
    FORI (x, 1, n) {
        CL (dp, -1);
        N = x;
        ans = max (ans, t*x-solve (idxZ,idxZ,false));
    }
    cout << ans << "\n";
}
