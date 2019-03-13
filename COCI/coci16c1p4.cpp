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

ll suf[1000001][2] = {0}, pre[1000001] = {0}, v[1000001];
pll ans;
vector < vi > graph(1000001);

void cmpAns (pll t) {
    if (ans.pF == 0) {
        ans = t;
        return;
    }
    // a1/a2 > t1/t2 then t2*a1 > t1*a2
    if (ans.pF*t.pS > t.pF*ans.pS) {
        ans = t;
    }
    ll gcd = GCD (ans.pF, ans.pS);
    ans = mp (ans.pF/gcd, ans.pS/gcd);
}

void cmpLen (int pos, int val) {
    if (val >= suf[pos][0]) {
        suf[pos][1] = suf[pos][0];
        suf[pos][0] = val;
    } else if (val >= suf[pos][1]) {
        suf[pos][1] = val;
    }
}

int dfs1 (int pos, int par) {
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x] != par) {
            if (v[graph[pos][x]] == 1) {
                cmpLen (pos, dfs1 (graph[pos][x], pos));
            } else {
                dfs1 (graph[pos][x], pos);
            }
        }
    }
    if (v[pos]==1) {
        suf[pos][0]++;
        suf[pos][1]++;
    }
    return suf[pos][0];
}

int dfs2 (int pos, int par) {
    if (v[pos]==1) {
        pre[pos]++;
    }
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x] != par) {
            if (v[pos]==1) {
                if (suf[pos][0] == suf[pos][1] || suf[pos][0]-1 != suf[graph[pos][x]][0]) {
                    pre[graph[pos][x]] = max (pre[pos], suf[pos][0]);
                } else {
                    pre[graph[pos][x]] = max (pre[pos], suf[pos][1]);
                }
            }
            dfs2 (graph[pos][x], pos);
        }
    }
}

int main () {
    int n, a, b;
    si (n);
    REP (x, n-1) {
        si (a); si (b);
        graph[a].pb (b);
        graph[b].pb (a);
    }
    FORI (x, 1, n) {
        sl (v[x]);
    }
    dfs1 (1, -1);
    dfs2 (1, -1);
    FORI (x, 1, n) {
        if (v[x]==1) {
            cmpAns (mp (v[x], suf[x][0] + max (pre[x], suf[x][1]) - 1));
        } else {
            cmpAns (mp (v[x], suf[x][0] + max (pre[x], suf[x][1]) + 1));
        }
    }
    cout << ans.pF << "/" << ans.pS << "\n";
}
