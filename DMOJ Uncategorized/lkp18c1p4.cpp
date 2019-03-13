#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <queue>
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

int n, m;
vector < vector < pair < pii, ll> > > graph(100005);
priority_queue < pair <ll, int> , vector< pair <ll, int> >, greater< pair <ll, int> > > pq;

ll dijk (int m, int s, int e) {
    ll sp[100005];
    REP (x, 100005) {
        sp[x] = longLIMIT::max();
    }
    sp[s] = 0;
    pq.push(mp (0, s));
    while (!pq.empty()) {
        ll d = pq.top().first, pos = pq.top().second;
        pq.pop();
        if (d <= sp[pos]) {
            REP (x, (int)graph[pos].size()) {
                if (d+graph[pos][x].pS < sp[graph[pos][x].pF.pF] && graph[pos][x].pF.pS <= m) {
                    pq.push (mp (d+graph[pos][x].pS, graph[pos][x].pF.pF));
                    sp[graph[pos][x].pF.pF] = d+graph[pos][x].pS;
                }
            }
        }
    }
    return sp[e];
}

int main () {
    ll a, b, c;
    si (n); si (m);
    FORI (x, 1, m+1) {
        sl (a); sl (b); sl (c);
        if (x <= m) {
            graph[a].pb (mp (mp (b, x), c));
            graph[b].pb (mp (mp (a, x), c));
        }
    }
    if (a==b) {
        printf ("0\n");
    } else if (dijk (m, a, b) >= c) {
        printf ("-1\n");
    } else {
        int lo = 1, hi = m, mid;
        while (lo < hi) {
            mid = (lo+hi)/2;
            if (dijk (mid, a, b) >= c) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if (dijk (lo-1, a, b) < c) {
            printf ("%d\n", lo-1);
        } else {
            printf ("%d\n", lo);
        }
    }
}
