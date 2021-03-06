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

ll p[8] = {0};

int cnt (ll a[8], ll val, int n) {
    bool done = true;
    FORI (x, 0, n) {
        if (a[x] > 0) {
            done = false;
        }
    }
    if (done) {
        return 0;
    }
    ll nxt[8] = {0};
    FORI (x, 0, n-1) {
        int deg = n-x;
        a[x+1] += val*-a[x];
        nxt[x+1] += a[x];
        a[x] = 0;
    }
    FORI (x, 0, n) {
        if (a[x] != 0) {
            return 0;
        }
    }
    return cnt(nxt, val, n)+1;
}

int main () {
    ll pwr[301][8] = {0};
    FORI (x, -150, 150) {
        pwr[x+150][0] = 1;
        FORI (i, 1, 7) {
            pwr[x+150][i] = pwr[x+150][i-1]*x;
        }
    }
    int q, n;
    si (q);
    while (q--) {
        si (n);
        REP (x, n+1) {
            sl (p[x]);
        }
        FORI (i, -150, 150) {
            ll sum = 0;
            FORI (z, 0, n) {
                sum += p[z]*pwr[i+150][n-z];
            }
            if (sum==0) {
                ll cpy[8] = {0};
                REP (x, n+1) {
                    cpy[x] = p[x];
                }
                int up = cnt (cpy, -i, n);
                while (up--) {
                    printf ("%d ", i);
                }
            }
        } pnl;
    }
}
