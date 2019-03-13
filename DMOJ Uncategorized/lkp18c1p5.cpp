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
#define gc getchar_unlocked
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int arr[100001] = {0}, n, m, k, cnt[401][22] = {0}, sqt, idx[100001], s[100001] = {0}, e[100001] = {0}, d[50001][22];
int a[401] = {0};

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void bf (int id) {
    if (a[id] == 0) {
        return;
    }
    int pos = s[id];
    FORI (x, 0, k) {
        REP (i, cnt[id][d[a[id]][x]]) {
            arr[pos] = d[a[id]][x];
            pos++;
        }
    }
    a[id] = 0;
}

void update (int l, int r, int p) {
    bf (idx[l]);
    bf (idx[r]);
    int tcnt[22] = {0}, S = idx[l]+1, E = idx[r]-1, curPos = 0;
    if (idx[l] == idx[r]) {
        FORI (x, l, r) {
            tcnt[arr[x]]++;
        }
        FORI (x, l, r) {
            while (tcnt[d[p][curPos]] == 0) {
                curPos++;
            }
            cnt[idx[l]][arr[x]]--;
            cnt[idx[l]][d[p][curPos]]++;
            arr[x] = d[p][curPos];
            tcnt[d[p][curPos]]--;
        }
        return;
    }
    FORI (x, l, e[idx[l]]) {
        tcnt[arr[x]]++;
    }
    FORI (x, s[idx[r]], r) {
        tcnt[arr[x]]++;
    }
    FORI (x, S, E) {
        FORI (i, 0, k) {
            tcnt[i] += cnt[x][i];
            cnt[x][i] = 0;
        }
    }
    FORI (x, l, e[idx[l]]) {
        while (tcnt[d[p][curPos]] == 0) {
            curPos++;
        }
        cnt[idx[l]][arr[x]]--;
        cnt[idx[l]][d[p][curPos]]++;
        arr[x] = d[p][curPos];
        tcnt[d[p][curPos]]--;
    }
    FORI (x, S, E) {
        a[x] = p;
        int tot = e[x] - s[x] + 1;
        while (tot > 0) {
            while (tcnt[d[p][curPos]] == 0) {
                curPos++;
            }
            if (tcnt[d[p][curPos]] >= tot) {
                cnt[x][d[p][curPos]] += tot;
                tcnt[d[p][curPos]] -= tot;
                tot = 0;
            } else {
                cnt[x][d[p][curPos]] += tcnt[d[p][curPos]];
                tot -= tcnt[d[p][curPos]];
                tcnt[d[p][curPos]] = 0;
            }
        }
    }
    FORI (x, s[idx[r]], r) {
        while (tcnt[d[p][curPos]] == 0) {
            curPos++;
        }
        cnt[idx[r]][arr[x]]--;
        cnt[idx[r]][d[p][curPos]]++;
        arr[x] = d[p][curPos];
        tcnt[d[p][curPos]]--;
    }
}

int main () {
    scanint (n); scanint (m); scanint (k);
    sqt = 280;
    FORI (x, 1, n) {
        scanint (arr[x]);
        idx[x] = x/sqt + 1;
        if (s[idx[x]] == 0) {
            s[idx[x]] = x;
        }
        e[idx[x]] = x;
        cnt[idx[x]][arr[x]]++;
    }
    int l, r;
    FORI (x, 1, m) {
        scanint (l); scanint (r);
        REP (i, k) {
            scanint (d[x][i]);
        }
        update (l, r, x);
    }
    FORI (x, 1, n) {
        bf(idx[x]);
        printf ("%d ", arr[x]);
    } pnl;
}
