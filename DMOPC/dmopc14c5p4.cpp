#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <bitset>
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

int n, m, a, b, ans = 0;
deque <int> o, t;


int main () {
    si (n); si (m);
    REP (x, n) {
        si (a); si (b);
        if (b==2) {
            t.pb (a);
        } else {
            o.pb (a);
        }
    }
    sort (o.begin(), o.end());
    sort (t.begin(), t.end());
    ll psum[100001][2] = {0};
    FORI (x, 1, n) {
        psum[x][0] = psum[x-1][0];
        psum[x][1] = psum[x-1][1];
        if (x-1 < o.size()) {
            psum[x][0] += o[x-1];
        }
        if (x-1 < t.size()) {
            psum[x][1] += t[x-1];
        }
    }
    FORI (x, 0, (int)t.size()) {
        if (psum[x][1] > m || psum[x][1] == psum[x-1][1]) {
            break;
        } else {
            int lo = 0, hi = o.size();
            while (lo < hi) {
                int mid = (hi+lo)/2;
                if (psum[mid][0] <= m-psum[x][1]) {
                    lo = mid+1;
                } else {
                    hi = mid;
                }
            }
            if (psum[lo][0] > m-psum[x][1]) {
                lo--;
            }
            ans = max (ans, 2*x + lo);
        }
    }
    cout << ans << "\n";
}
