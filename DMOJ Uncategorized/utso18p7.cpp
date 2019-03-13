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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define TOGGLE(x,y) (x ^= (1<<y))
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

int n, sz[100001] = {0}, e=0, depth[100001] = {0};
ll CT[100001][20][2] = {0};
ll p[100001] = {0}, sum[100001] = {0}, sub[200001] = {0}, MOD = 1e9+7;
bool v[100001] = {0};
vector < vi > g(100001);
vector < deque < pll > > ctPar(100001), ct(100001);

//MOD DIVISION CODE BELONGS TO GEEKSFORGEEKS

// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    int inv = modInverse(b, m); 
    if (inv == -1) 
       return -1; 
    else
       return (inv * a) % m; 
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

int getSz (int pos, int par, ll d) {
    sz[pos] = 1;
    REP (x, (int)g[pos].size()) {
        if (!v[g[pos][x]] && g[pos][x] != par) {
            sz[pos] += getSz (g[pos][x], pos, d*p[pos]%MOD);
        }
    }
    return sz[pos];
}

int getCent (int pos, int par, int tot) {
    REP (x, (int)g[pos].size()) {
        if (!v[g[pos][x]] && g[pos][x] != par && sz[g[pos][x]]*2 > tot) {
            return getCent (g[pos][x], pos, tot);
        }
    }
    return pos;
}

void buildCt (int pos, int cent, int par, ll d) {
	d *= p[pos];
	ctPar[pos].push_front(mp (cent, d));
	REP (x, (int)g[pos].size()) {
		if (!v[g[pos][x]] && g[pos][x] != par) {
			buildCt (g[pos][x], cent, pos, d%MOD);
		}
	}
}

void solve (int pos, int par, ll d) {
    getSz (pos, par, d);
    int cent = getCent (pos, par, sz[pos]);
    v[cent] = true;
    if (par != 0) {
    	e++;
    	ct[cent].pb (mp (par, e));
	}
    REP (x, (int)g[cent].size()) {
        if (!v[g[cent][x]]) {
        	buildCt (g[cent][x], cent, cent, p[cent]);
            solve (g[cent][x], cent, p[cent]%MOD);
        }
    }
}

void update (int pos, ll val) {
	sum[pos] += val;
	//sum[pos] %= val;
	val %= MOD;
	int curPos = pos;
	for (int x = 0; x < (int)ctPar[pos].size(); x++) {
		int node = ctPar[pos][x].pF;
		int edge = ct[curPos][0].pS;
		ll d = modDivide (ctPar[pos][x].pS, p[node], MOD);
		d %= MOD;
		val %= MOD;
		sub[edge] += val*d%MOD;
		sum[node] += val*d%MOD;
		
		curPos = node;
		sub[edge] %= MOD;
		sum[node] %= MOD;
	}
}

ll query (int pos) {
	ll ans = sum[pos];
	int curPos = pos;
	for (int x = 0; x < (int)ctPar[pos].size(); x++) {
		int node = ctPar[pos][x].pF;
		int edge = ct[curPos][0].pS;
		ll d = modDivide (ctPar[pos][x].pS, p[pos], MOD);
		ans += (sum[node]%MOD-sub[edge]%MOD + MOD)%MOD*d%MOD;
		curPos = node;
	}
	return ans%MOD;
}

int main () {
    int q, a, b, t;
    si (n); si (q);
    FORI (x, 1, n) {
        sl (p[x]);
    }
    REP (x, n-1) {
        si (a); si (b);
        g[a].pb (b);
        g[b].pb (a);
    }
    solve (1, 0, 0);
    while (q--) {
        si (t); si (a);
        if (t==1) {
            si (b);
            update (a, (ll)b);
        } else {
            printf ("%lld\n", query (a));
        }
    }
}
