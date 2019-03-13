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
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int LCA[100001][20][3] = {0}, n, d[100001] = {0}, g[2] = {0}, p[100001];
vector < vector < pii > > graph(100001); 

void cmp (int val) {
    if (val >= g[0]) {
        g[1] = g[0];
        g[0] = val;
    } else if (val > g[1]) {
        g[1] = val;
    }
}

void buildLCA (int pos, int par, int cst) {
    LCA[pos][0][0] = par;
    LCA[pos][0][1] = cst;
    p[pos] = par;
    d[pos] = d[par] + 1;
    FORI (x, 1, 19) {
        if (LCA[pos][x-1][0] == 0 || LCA[LCA[pos][x-1][0]][x-1][0] == 0) {
            break;
        } else {
            LCA[pos][x][0] = LCA[LCA[pos][x-1][0]][x-1][0];
            vi tmp;
            FORI (i, 1, 2) {
                tmp.pb (LCA[pos][x-1][i]);
                tmp.pb (LCA[LCA[pos][x-1][0]][x-1][i]);
            }
            sort (tmp.begin(), tmp.end());
            LCA[pos][x][1] = tmp[3];
            LCA[pos][x][2] = tmp[2];
        }
    }
    REP (x, (int)graph[pos].size()) {
        if (graph[pos][x].pF != par) {
            buildLCA (graph[pos][x].pF, pos, graph[pos][x].pS);
        }
    }
}

void queryLCA (int a, int b) {
    g[0] = g[1] = 0;
    if (d[a] < d[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int dif = d[a]-d[b], tmp;
    while (dif > 0) {
        tmp = (int)log2(dif & -dif);
        cmp (LCA[a][tmp][1]);
        cmp (LCA[a][tmp][2]);
        a = LCA[a][tmp][0];
        dif -= dif & -dif;
    }
    for (int x = 19; x >= 0; x--) {
        if (LCA[a][x][0] != 0) {
            if (LCA[a][x][0] != LCA[b][x][0]) {
                FORI (i, 1, 2) {
                    cmp (LCA[a][x][i]);
                    cmp (LCA[b][x][i]);
                }
                a = LCA[a][x][0];
                b = LCA[b][x][0];
            }
        }
    }
    if (a != b) {
        FORI (i, 1, 2) {
            cmp (LCA[a][0][i]);
            cmp (LCA[b][0][i]);
        }
    }
}

int main () {
    int a, b, w, q;
    si (n);
    REP (x, n-1) {
        si (a); si (b); si (w);
        graph[a].pb (mp (b, w));
        graph[b].pb (mp (a, w));
    }
    buildLCA (1, 0, 0);
    si (q);
    REP (x, q) {
        si (a); si (b);
        if (p[a] == b || p[b] == a) {
            printf ("-1\n");
            continue;
        }
        queryLCA (a, b);
        printf ("%d\n", g[1]);
    }
}
