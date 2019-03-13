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

int n, m, k, fc[101][15], cnt[16] = {0}, least = intLIMIT::max();

void solve (int pos, int mask, int tot) {
    if (pos==m+1) {
        int tmp[16] = {0}, greatest = 0, pos;
        REP (x, n) {
            int ptr = 0;
            while (READ (mask, fc[x][ptr])) {
                ptr++;
            }
            tmp[fc[x][ptr]]++;
        }
        FORI (x, 1, m) {
            if (tmp[x] > greatest) {
                greatest = tmp[x];
                pos = x;
            }
        }
        if (pos == k) {
            least = min (least, tot);
        }
    } else {
        if (pos == k) {
            solve (pos+1, mask, tot);
        } else {
            solve (pos+1, mask, tot);
            if (tot+1 < least) {
                TOGGLE (mask, pos);
                solve (pos+1, mask, tot+1);
            }
        }
    }
}

int main () {
    si (n); si (m); si (k);
    REP (x, n) {
        REP (i, m) {
            si (fc[x][i]);
        }
        cnt[fc[x][0]]++;
    }
    int greatest = 0, pos;
    FORI (x, 1, m) {
        if (cnt[x] > greatest) {
            greatest = cnt[x];
            pos = x;
        }
    }
    solve (1, 0, 0);
    cout << pos << "\n" << least << "\n";
}
