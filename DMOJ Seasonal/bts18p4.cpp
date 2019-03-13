#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <queue>
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

bool good[100001] = {0}, v[100001] = {0}, v2[100001] = {0};
int n, furthest = -1, n1, diam = -1;
vector < vector <int> > graph (100001);

void dfs2 (int pos, int dist) {
    v2[pos] = true;
    if (dist > diam) {
        diam = dist;
    }
    REP (x, graph[pos].size()) {
        if (v2[graph[pos][x]] || !good[graph[pos][x]]) {
            continue;
        }
        dfs2 (graph[pos][x], dist+1);
    }
}

void dfs1 (int pos, int dist) {
    v[pos] = true;
    if (dist > furthest) {
        furthest = dist;
        n1 = pos;
    }
    REP (x, graph[pos].size()) {
        if (v[graph[pos][x]] || !good[graph[pos][x]]) {
            continue;
        }
        dfs1 (graph[pos][x], dist+1);
    }
}

int main () {
    si (n);
    int a, b;
    FORI (x, 1, n) {
        ll tmp;
        sl (tmp);
        ll X = (-1 + sqrt ((ll)1*1 - (ll)4*1*-tmp))/((ll)2*1);
        ll X2 = (-1 - sqrt ((ll)1*1 - (ll)4*1*-tmp))/((ll)2*1);
        if (X*X+X == tmp || X2*X2+X2 == tmp) {
            good[x] = true;
        }
    }
    REP (x, n-1) {
        si (a); si (b);
        if (good[a] && good[b]) {
                graph[a].pb (b);
                graph[b].pb (a);
        }
    }
    int ans = 0;
    FORI (x, 1, n) {
        if (!v[x] && good[x]) {
            furthest = diam = -1;
            dfs1 (x,1);
            dfs2 (n1,1);
            ans = max (ans, diam);
        }
    }
    cout << ans << endl;
}
