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

int n;
ll w;
vll crkrs;

ll check (bool L, ll prev) {
    ll tot = 0;
    int l = 0, r = n-1;
    while (r >= l) {
        if (L) {
            if (abs (w - crkrs[l]) > abs (prev - crkrs[l])) {
                tot += abs (w - crkrs[l]);
            } else {
                tot += abs (prev - crkrs[l]);
            }
            prev = crkrs[l];
            l++;
            L = !L;
        } else {
            if (abs (w - crkrs[r]) > abs (prev - crkrs[r])) {
                tot += abs (w - crkrs[r]);
            } else {
                tot += abs (prev - crkrs[r]);
            }
            prev = crkrs[r];
            r--;
            L = !L;
        }
    }
    return tot;
}

int main () {
    ll cur;
    si (n); sl (w);
    REP (x, n) {
        sl (cur);
        crkrs.pb (cur);
    }
    sort (crkrs.begin(), crkrs.end());
    ll least = crkrs[n-1] - crkrs[0], greatest = 0;
    if (w < crkrs[0]) {
        least += crkrs[0] - w;
    } else if (w > crkrs[n-1]) {
        least += w-crkrs[n-1];
    }
    cout << least << " " << max (check (true, w), check (false, w)) << "\n";
}
