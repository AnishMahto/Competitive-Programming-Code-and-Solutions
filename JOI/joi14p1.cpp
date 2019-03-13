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
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

vector < vector < pll > > graph(500001);
const int LG = (int)log2(500001)+2;
long long sz[500001] = {0}, depth[500001], cTreeDist[500001][LG], dp[500001], path[500001][LG], levelZeroCentroid;
bool v[500001] = {0};

ll getSz (int pos, int par, int prevCentroid, int lvl, ll c) {
    if (lvl >= 0) {
        //cout << pos << " " << c << "!" << endl;
        cTreeDist[pos][lvl] = c;
        path[pos][lvl] = prevCentroid;
        depth[pos] = lvl;
    }
    sz[pos] = 1;
    REP (x, graph[pos].size()) {
        if (v[graph[pos][x].first] || graph[pos][x].first == par) {
            continue;
        }
        sz[pos] += getSz(graph[pos][x].first, pos, prevCentroid, lvl, c + graph[pos][x].second);
    }
    return sz[pos];
}

ll findCentroid (int pos, int par, int tot) {
    REP (x, graph[pos].size()) {
        if (v[graph[pos][x].first] || graph[pos][x].first == par) {
            continue;
        }
        if (sz[graph[pos][x].first] > tot/2) {
            return findCentroid (graph[pos][x].first, pos, tot);
        }
    }
    return pos;
}

void buildDist (int pos, int par, ll c, ll lvl, int centroid) {
    cTreeDist[pos][lvl] = c;
    path[pos][lvl] = centroid;
    depth[pos] = lvl;
    REP (x, graph[pos].size()) {
        if (v[graph[pos][x].first] || graph[pos][x].first == par) {
            continue;
        }
        buildDist (graph[pos][x].first, pos, c + graph[pos][x].second, lvl, centroid);
    }
}

void build (int pos, int par, int lvl, int prevCentroid, ll c) {
    int tot = getSz (pos, -1, prevCentroid, lvl-1, c);
    int centroid = findCentroid (pos, -1, tot);
    v[centroid] = true;
    if (lvl==0) {
        levelZeroCentroid = centroid;
    }
    REP (x, graph[centroid].size()) {
        if (v[graph[centroid][x].first]) {
            continue;
        }
        build(graph[centroid][x].first, centroid, lvl+1, centroid, graph[centroid][x].second);
        
    }
}

void Init(int N, int A[], int B[], int D[]) {
    CL (dp, -1);
    REP (x, N-1) {
        graph[A[x]].pb(mp(B[x], D[x]));
        graph[B[x]].pb(mp(A[x], D[x]));
    }
    build (0, -1, 0, -1, 0);
}

long long Query(int S, int X[], int T, int Y[]) {
    ll ans = longLIMIT::max();
    vi idx;
    REP (x, S) {
        dp[X[x]] = 0;
        idx.pb (X[x]);
        int pos = depth[X[x]];
        while (pos >= 0 && X[x] != levelZeroCentroid) {
            //cout << path[X[x]][pos] << endl;
            if (dp[path[X[x]][pos]] == -1) {
                dp[path[X[x]][pos]] = cTreeDist[X[x]][pos];
                idx.pb (path[X[x]][pos]);
            } else {
                dp[path[X[x]][pos]] = min (dp[path[X[x]][pos]], cTreeDist[X[x]][pos]);
            }
            pos--;
        }
    }
    REP (x, T) {
        if (dp[Y[x]] != -1) {
            ans = min (ans, dp[Y[x]]);
        }
        int pos = depth[Y[x]];
        while (pos >= 0 && Y[x] != levelZeroCentroid) {
            if (dp[path[Y[x]][pos]] != -1) {
                ans = min (ans, cTreeDist[Y[x]][pos] + dp[path[Y[x]][pos]]);
            }
            pos--;
        }
    }
    while (!idx.empty()) {
        dp[idx.back()] = -1;
        idx.pop_back();
    }
    return ans;
}
