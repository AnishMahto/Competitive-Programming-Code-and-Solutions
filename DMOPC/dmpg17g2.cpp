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

ll sqt = 320, idx[100001] = {0}, pre[400] = {0}, suf[400] = {0}, arr[100001], s[400] = {0}, e[400] = {0}, dp[400] = {0}, tot[400] = {0};
int n, q;

ll solveRange (int l, int r) {
    ll ans = longLIMIT::min(), prev = 0, cur = 0;
    FORI (x, l, r) {
        cur = max (prev+arr[x], arr[x]);
        ans = max (ans, cur);
        prev = cur;
    }
    return ans;
}

void genPreSuf (int pos) {
    ll sum = 0;
    pre[idx[pos]] = suf[idx[pos]] = longLIMIT::min();
    FORI (x, s[idx[pos]], e[idx[pos]]) {
        sum += arr[x];
        pre[idx[pos]] = max (pre[idx[pos]], sum);
    }
    sum = 0;
    for (int x = e[idx[pos]]; x >= s[idx[pos]]; x--) {
        sum += arr[x];
        suf[idx[pos]] = max (suf[idx[pos]], sum);
    }
}

void build (int l, int r) {
    dp[idx[l]] = solveRange (l, r);
    FORI (x, l, r) {
        tot[idx[l]] += arr[x];
    }
    genPreSuf (l);
}

void update (int pos, ll val) {
    tot[idx[pos]] -= arr[pos];
    tot[idx[pos]] += val;
    arr[pos] = val;
    genPreSuf (pos);
    dp[idx[pos]] = solveRange (s[idx[pos]], e[idx[pos]]);
}

ll query (int l, int r) {
    if (idx[l] == idx[r]) {
        return solveRange (l, r);
    } else {
        ll ans = max (solveRange (l, e[idx[l]]), solveRange (s[idx[r]], r));
        
        ll sufL = arr[e[idx[l]]], preR = arr[s[idx[r]]], sum = arr[e[idx[l]]], S = idx[l]+1, E = idx[r]-1, prev;
        
        for (int x = e[idx[l]]-1; x >= l; x--) {
            sum += arr[x];
            sufL = max (sufL, sum);
        }
        sum = arr[s[idx[r]]];
        FORI (x, s[idx[r]]+1, r) {
            sum += arr[x];
            preR = max (preR, sum);
        }
        prev = sufL;
        ans = max (ans, max (sufL, preR));
        FORI (x, S, E) {
            ans = max (ans, dp[x]);
            ans = max (ans, prev + pre[x]);
            ans = max (ans, prev + tot[x]);
            ans = max (ans, pre[x]);
            ans = max (ans, max (tot[x], suf[x]));
            prev = max (prev + tot[x], max (tot[x], suf[x]));
        }
        ans = max (ans, preR+prev);
        return ans;
    }
}

int main () {
   char cmd;
   ll a, b;
   si (n); si (q);
   FORI (x, 1, n) {
       sl (arr[x]);
       idx[x] = x/sqt + 1;
       if (s[idx[x]] == 0) {
           s[idx[x]] = x;
       }
       e[idx[x]] = x;
   }
   FORI (x, idx[1], idx[n]) {
       build (s[x], e[x]);
   }
   while (q--) {
       scanf (" %c", &cmd);
       sl (a); sl (b);
       if (cmd == 'S') {
           update (a, b);
       } else {
           printf ("%lld\n", query (a, b));
       }
   }
}
