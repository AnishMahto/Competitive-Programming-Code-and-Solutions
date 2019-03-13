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
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n);i>=0;i--)
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define dbl(x) (double)(x)
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

ll dp[2001][2001] = {0}, useQ[2001], useP[2001], W;
int n;
vector <int> s;
vector<int>::iterator it;

void genQ () {
    REPR (x, s.size()-1) {
        if (x==1) {
            useQ[x] = 0;
            break;
        }
        if (s[x]-2*W+1 <= 0) {
            useQ[x] = 0;
            continue;
        }
        it = upper_bound(s.begin(), s.begin()+x+1, s[x]-2*W+1);
        int pos = it-s.begin();
        pos--;
        if (s[pos] >= s[x]-2*W+1) {
            pos--;
            useQ[x] = pos;
        } else {
            useQ[x] = pos;
        }
    }
}

void genP () {
    REPR (x, s.size()-1) {
        if (x==1) {
            useP[x] = 0;
            break;
        }
        if (s[x]-W+1 <= 0) {
            useP[x] = 0;
            continue;
        }
        it = upper_bound(s.begin(), s.begin()+x+1, s[x]-W+1);
        int pos = it-s.begin();
        pos--;
        if (s[pos] >= s[x]-W+1) {
            pos--;
            useP[x] = pos;
        } else {
            useP[x] = pos;
        }
    }
}

ll solve (int pos, int Q) {
    if (dp[pos][Q] != -1) {
        return dp[pos][Q];
    } else if (pos==0) {
        dp[pos][Q] = 0;
        return 0;
    } else {
        dp[pos][Q] = intLIMIT::max();
        if (Q > 0) {
            dp[pos][Q] = min (dp[pos][Q], solve (useQ[pos], Q-1));
        }
        dp[pos][Q] = min (dp[pos][Q], solve (useP[pos], Q)+1);
        dp[pos][Q] = max (dp[pos][Q], (ll)0);
    }
    return dp[pos][Q];
}

int main () {
    int p, q, cur;
    ll lo = 1, hi = intLIMIT::max(), mid;
    si (n); si (p); si (q);
    s.pb(-1);
    REP (x, n) {
        si (cur);
        s.pb(cur);
    }
    sort (s.begin(), s.end());
    int cnt = 0;
    while (lo < hi) {
        memset (dp, -1, sizeof(dp));
        cnt++;
        if (cnt==100) {
            break;
        }
        mid = (lo+hi)/2;
        W = mid;
        genQ();
        genP();
        int tmp = solve (n, min (n, q));
        if (tmp <= p) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << lo << "\n";
}
