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
    ll C, D, E, A, B;
    cin >> C >> D >> E;
    A = B = D;
    bool any[40] = {0}, dif[40] = {0}, zero[40] = {0}, one[40] = {0};
    
    REP (x, 30) {
        if (READ(D, x) && READ(E, x)) {
            cout << 0 << "\n";
            return 0;
        } else if (!READ (D, x) && !READ (E, x)) {
            zero[x] = true;
        } else if (READ(D, x) && !READ (E, x)) {
            one[x] = true;
        } else {
            dif[x] = true;
        }
    }
    REP (x, 30) {
        if (READ (D, x) && !READ (C, x)) {
            cout << 0 << "\n";
            return 0;
        } else if (!READ (D, x) && READ (C, x)) {
            dif[x] = true;
        } else if (!READ (D, x) && !READ (C, x)) {
            zero[x] = true;
        } else if (READ (D, x) && READ (C, x)) {
            one[x] = true;
        }
    }
    REP (x, 30) {
        if (READ (C,x) && READ (E, x)) {
            dif[x] = true;
        } else if (READ (C, x) && !READ (E, x)) {
            one[x] = true;
        } else if (!READ (C, x) && READ (E, x)) {
            cout << 0 << "\n";
            return 0;
        } else if (!READ (C, x) && !READ (E, x)) {
            zero[x] = true;
        }
    }
    ll cnt = 0;
    REP (x, 30) {
        if (one[x] && zero[x]) {
            cout << 0 << "\n";
            return 0;
        } else if (dif[x] && (one[x] || zero[x])) {
            continue;
        } else if (dif[x]) {
            cnt++;
        }
    }
    ll ans = 1;
    REP (x, cnt) {
        ans *= 2;
    }
    cout << ans << "\n";
}
