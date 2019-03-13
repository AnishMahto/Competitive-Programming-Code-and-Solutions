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

vector < vi > graph(100001);
int vis[100001][2];
bool s[100001] = {0};

int main () {
    CL (vis, -1);
    int n, m, k, A, B, a, b;
    si (n); si (m); si (k); si (A); si (B);
    REP (x, k) {
        si (a);
        s[a] = true;
    }
    REP (x, m) {
        si (a); si (b);
        graph[a].pb (b);
        graph[b].pb (a);
    }
    deque < pair <int, bool> > q;
    if (s[A]) {
        vis[A][1] = 0;
    } else {
        vis[A][0] = 0;
    }
    q.pb (mp (A, s[A]));
    while (!q.empty() && vis[B][1]==-1) {
        int pos = q.front().first;
        bool vS = q.front().second;
        q.pop_front();
        REP (x, (int)graph[pos].size()) {
            if (s[graph[pos][x]] || vS) {
                if (vis[graph[pos][x]][1] == -1) {
                    vis[graph[pos][x]][1] = vis[pos][vS] + 1;
                    q.pb (mp (graph[pos][x], true));
                }
            } else {
                if (vis[graph[pos][x]][0] == -1) {
                    vis[graph[pos][x]][0] = vis[pos][vS] + 1;
                    q.pb (mp (graph[pos][x], false));
                }
            }
        }
    }
    cout << vis[B][1] << "\n";
}
