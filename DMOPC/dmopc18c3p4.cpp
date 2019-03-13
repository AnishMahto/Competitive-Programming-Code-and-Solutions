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

vector < vector < pll > > graph(200001);
int c[200001] = {0}, sz[200001] = {0};
bool bad[200001] = {0};
int n;
ll ans = 0;

void dfs1 (int pos, int par) {
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x].pF != par) {
            dfs1 (graph[pos][x].pF, pos);
            if (!bad[graph[pos][x].pF]) {
                bad[pos] = false;
            }
        }
    }
    if (c[pos] > 0) {
        bad[pos] = false;
    }
}

int getSize (int pos, int par) {
    sz[pos] = c[pos];
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x].pF != par && !bad[graph[pos][x].pF]) {
            sz[pos] += getSize (graph[pos][x].pF, pos);
        }
    }
    return sz[pos];
}

int getCent (int pos, int par, int totSz) {
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x].pF != par && !bad[graph[pos][x].pF]) {
            if (sz[graph[pos][x].pF]*2 > totSz) {
                return getCent (graph[pos][x].pF, pos, totSz);
            }
        }
    }
    return pos;
}

void dfs2 (int pos, int par, ll dist) {
    ans += (ll)c[pos]*dist;
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x].pF != par && !bad[graph[pos][x].pF]) {
            dfs2 (graph[pos][x].pF, pos, dist+graph[pos][x].pS);
        }
    }
}

int main () {
    int a, b, d, s, k;
    si (k); si (n);
    FORI (x, 1, n) {
        bad[x] = true;
    }
    FORI (x, 1, k) {
        si (a);
        c[a]++;
        s = a;
    }
    REP (x, n-1) {
        si (a); si (b); si (d);
        graph[a].pb (mp (b, d));
        graph[b].pb (mp (a, d));
    }
    dfs1 (s, -1);
    getSize (s, -1);
    dfs2 (getCent (s, -1, sz[s]), -1, 0);
    cout << ans << "\n";
}
