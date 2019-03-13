#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
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

unordered_map < int, int > m[200001];
unordered_map < int, int >::iterator it;
vector < vector < pii > > graph(200001);
vector < pii > updates;
bool v[200001] = {0};
int sz[200001] = {0}, k;
int minLen = intLIMIT::max(), minHalf[200001][2];

int getSize (int pos, int par) {
    sz[pos] = 1;
    REP (x, graph[pos].size()) {
        if (graph[pos][x].pF == par || v[graph[pos][x].pF]) {
            continue;
        }
        sz[pos] += getSize (graph[pos][x].pF, pos);
    }
    return sz[pos];
}

int findCentroid (int pos, int par, int N) {
    REP (x, graph[pos].size()) {
        if (graph[pos][x].pF == par || v[graph[pos][x].pF]) {
            continue;
        }
        if (sz[graph[pos][x].pF]*2 > N) {
            return findCentroid (graph[pos][x].pF, pos, N);
        }
    }
    return pos;
}

void getDist (int pos, int par, int dist, int len, int cent) {
    if (dist > k || len >= minLen) {
        return;
    }
    if (dist==k) {
        minLen = min (minLen, len);
        return;
    }
    it = m[cent].find (k-dist);
    if (it!=m[cent].end()) {
        minLen = min (minLen, it->second + len);
    }
    REP (x, graph[pos].size()) {
        if (graph[pos][x].pF == par || v[graph[pos][x].pF]) {
            continue;
        }
        getDist (graph[pos][x].pF, pos, dist+graph[pos][x].pS, len+1, cent);
    }
    updates.pb (mp(dist, len));
}

void solve (int pos) {
    getSize (pos, -1);
    int cent = findCentroid (pos, -1, sz[pos]);
    v[cent] = true;
    //watch (cent);
    REP (x, graph[cent].size()) {
        if (v[graph[cent][x].pF]) {
            continue;
        }
        
        getDist (graph[cent][x].pF, cent, graph[cent][x].pS, 1, cent);
        
        while (updates.size() > 0) {
            it = m[cent].find (updates.back().pF);
            if (it==m[cent].end()) {
                m[cent].insert (mp(updates.back().pF, updates.back().pS));
            } else {
                it->second = min (it->second, updates.back().pS);
            }
            updates.pop_back();
        }
        
    }
    REP (x, graph[cent].size()) {
        if (!v[graph[cent][x].pF]) {
            solve (graph[cent][x].pF);
        }
    }
}


int best_path(int N, int K, int H[][2], int L[]) {
    k = K;
    REP (x, N-1) {
        graph[H[x][0]].pb (mp (H[x][1], L[x]));
        graph[H[x][1]].pb (mp (H[x][0], L[x]));
    }
    solve (1);
    if (minLen == intLIMIT::max()) {
        return -1;
    }
    return minLen;
}

int main () {
    //int H[10][2] = {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10}}, L[10] = {1,1,1,1,1,1,1,1,1,1};
    //cout << best_path (11, 2, H, L) << endl;
    //int H[10][2] = {{0,1},{0,2},{2,3},{3,4},{4,5},{0,6},{6,7},{6,8},{8,9},{8,10}}, L[10] = {3,4,5,4,6,3,2,5,6,7};
    //cout << best_path (11, 12, H, L) << endl;
    //int H[3][2] = {{0, 1}, {1, 2}, {1, 3}}, L[3] = {1, 2, 4};
    //cout << best_path (4, 3, H, L) << endl;
    //int H[2][2] = {{0, 1}, {1, 2}}, L[3] = {1, 1};
    //cout << best_path (3, 3, H, L) << endl;
}
