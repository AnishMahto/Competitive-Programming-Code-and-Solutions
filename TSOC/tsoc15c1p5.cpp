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

int n, m, antSp[101], sp[101], ans;
vector < vi > graph (101);
bool v[101] = {0};

void antBfs (int s) {
    CL (v, 0);
    deque < pii > q;
    antSp[s] = 0;
    v[s] = true;
    REP (x, (int)graph[s].size()) {
        if (!v[graph[s][x]]) {
            v[graph[s][x]] = true;
            antSp[graph[s][x]] = min (antSp[graph[s][x]], 4);
            q.pb (mp (graph[s][x], 4));
        }
    }
    while (!q.empty()) {
        int pos = q.front().pF, t = q.front().pS;
        q.pop_front();
        REP (x, (int)graph[pos].size()) {
            if (!v[graph[pos][x]]) {
                v[graph[pos][x]] = true;
                antSp[graph[pos][x]] = min (antSp[graph[pos][x]], t+4);
                q.pb (mp (graph[pos][x], t+4));
            }
        }
    }
}

void bfs (int s) {
    if (antSp[s] == 0) {
        ans = -1;
        return;
    }
    sp[s] = 0;
    CL (v, 0);
    deque < pii > q;
    v[s] = true;
    REP (x, (int)graph[s].size()) {
        if (!v[graph[s][x]] && antSp[graph[s][x]] > 1) {
            v[graph[s][x]] = true;
            sp[graph[s][x]] = 1;
            q.pb (mp (graph[s][x], 1));
        }
    }
    while (!q.empty()) {
        int pos = q.front().pF, t = q.front().pS;
        q.pop_front();
        REP (x, (int)graph[pos].size()) {
            if (!v[graph[pos][x]] && antSp[graph[pos][x]] > t+1) {
                v[graph[pos][x]] = true;
                sp[graph[pos][x]] = t+1;
                q.pb (mp (graph[pos][x], t+1));
            }
        }
    }
    //printArr (sp, n+1);
    if (sp[n] != intLIMIT::max()) {
        ans = sp[n];
        return;
    }
    ans = -1;
}

int main () {
    REP (x, 101) {
        sp[x] = antSp[x] = intLIMIT::max();
    }
    int a, b, w;
    si (n); si (m);
    REP (x, m) {
        si (a); si (b);
        graph[a].pb (b);
        graph[b].pb (a);
    }
    si (w);
    REP (x, w) {
        si (a);
        antBfs (a);
    }
    bfs (1);
    if (ans != -1) {
        cout << ans << "\n";
    } else {
        cout << "sacrifice bobhob314\n";
    }
}
