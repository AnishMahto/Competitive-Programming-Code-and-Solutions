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
#define vll vector <long long>
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int main () {
    ll n, a, b, sumK[100002] = {0}, ans = 0;
    sl (n);
    vector < vector < pll > > V(100002);
    REP (x, n) {
        sl (a); sl (b);
        V[a+b].pb (mp (a, b));
        sumK[a+b] += a;
    }
    REP (x, 100001) {
        if (V[x].empty()) {
            continue;
        }
        sort (V[x].begin(), V[x].end());
        ll sumM = 0;
        REP (i, V[x].size()) {
            if (sumK[x] - V[x][i].first < sumM + V[x][i].second) {
                if (min (sumK[x], sumM) < min (sumK[x] - V[x][i].first, sumM + V[x][i].second)) {
                    sumK[x] -= V[x][i].first;
                    sumM += V[x][i].second;
                }
                break;
            }
            sumM += V[x][i].second;
            sumK[x] -= V[x][i].first;
        }
        ans = max (ans, min (sumK[x], sumM));
    }
    cout << ans << "\n";
}
