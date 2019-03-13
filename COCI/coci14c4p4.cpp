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

vector < vector < pair <double,  pair <int, bool> > > > graph (1001);
int n;
double dp[1001] = {0}, req[1001];

double solve (int pos, int par) {
    if (req[pos] > 0) {
        return req[pos];
    } else {
        dp[pos] = 0;
        REP (x, (int)graph[pos].size()) {
            if (graph[pos][x].pS.pF == par) {
                continue;
            }
            if (graph[pos][x].pS.pS) {
                dp[pos] = max(dp[pos], sqrt (solve (graph[pos][x].pS.pF, pos))/graph[pos][x].pF);
            } else {
                dp[pos] = max (dp[pos], solve (graph[pos][x].pS.pF, pos)/graph[pos][x].pF);
            }
        }
    }
    return dp[pos];
}

int main () {
    int a, b, c, d;
    si (n);
    REP (x, n-1) {
        si (a); si (b); si (c); si (d);
        graph[a].pb (mp ( (double)c/(double)100, mp(b, d) ));
    }
    FORI (x, 1, n) {
        si (a);
        req[x] = a;
    }
    printf ("%.3lf\n", solve (1, 0));
}

//(i*X)^2 = req 
//sqrt(req)/x = i
