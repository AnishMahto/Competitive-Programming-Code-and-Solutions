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

vector < pll > P;
vll rX, rY;

ll check (ll X, ll Y) {
    ll sum = 0;
    REP (x, (int)P.size()) {
        sum += max (abs (P[x].pF-X), abs (P[x].pS-Y));
    }
    return sum;
}

int main () {
    int n, med;
    ll A, B, pX, pY, ans = longLIMIT::max();
    si (n);
    med = n/2;
    REP (x, n) {
        sl (A); sl (B);
        P.pb (mp (A, B));
        rX.pb (A+B); rY.pb (A-B);
    }
    sort (rX.begin(), rX.end());
    sort (rY.begin(), rY.end());
    pY = (rY[med] - rX[med])/-2;
    pX = (rY[med] + rX[med])/2;
    FORI (y, -1, 1) {
        FORI (x, -1, 1) {
            ans = min (ans, check (pX+x, pY+y));
        }
    }
    cout << ans << "\n";
}

/*
x + y = x', x - y = y'
x' - y - y = y'
(y'-x')/-2 = y'

x + x - y' = x'
2x = (y' + x')
x = (y'+x')/2
*/
