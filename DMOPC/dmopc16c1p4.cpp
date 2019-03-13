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
#define allof(x) (x).begin(), (x).end()
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int n, sz[200001] = {0};
vector < vi > graph(200001);
ll V[200001] = {0}, ans = 0;
bool v[200001] = {0};
vector < pll > q;

int getSz (int pos, int par) {
	sz[pos] = 1;
	REP (x, (int)graph[pos].size()) {
		if (graph[pos][x] != par && !v[graph[pos][x]])
			sz[pos] += getSz (graph[pos][x], pos);
	}
	return sz[pos];
}

int findCent (int pos, int par, int tot) {
	REP (x, (int)graph[pos].size()) {
		if (!v[graph[pos][x]] && graph[pos][x] != par && 2*sz[graph[pos][x]] > tot) {
			return findCent (graph[pos][x], pos, tot);
		}
	} return pos;
}

void getPaths (int pos, int par, int len, ll val) {
	val += V[pos];
	len++;
	q.pb (mp (val, len));
	REP (x, (int)graph[pos].size()) {
		if (!v[graph[pos][x]] && graph[pos][x] != par) {
			getPaths (graph[pos][x], pos, len, val);
		}
	}
}

void solve (int pos) {
	int c = findCent (pos, -1, getSz (pos, -1));
	v[c] = true;
	ll cnt = 0, sumLen = 0; 
	REP (x, (int)graph[c].size()) {
		if (v[graph[c][x]]) {
			continue;
		}
		getPaths (graph[c][x], c, 0, V[c]);
		REP (i, (int)q.size()) {
			ll totLen = sumLen + cnt*q[i].pS;
			ans += totLen*q[i].pF;
		}
		while (!q.empty()) {
			ans += q.back().pS*q.back().pF;
			cnt++;
			sumLen += q.back().pS;
			q.pop_back();
		}
	}
	sumLen = cnt = 0;
	for (int x=(int)graph[c].size()-1; x >= 0; x--) {
		if (v[graph[c][x]]) {
			continue;
		}
		getPaths (graph[c][x], c, 0, 0);
		REP (i, (int)q.size()) {
			ll totLen = sumLen + cnt*q[i].pS;
			ans += totLen*q[i].pF;
		}
		while (!q.empty()) {
			cnt++;
			sumLen += q.back().pS;
			q.pop_back();
		}
	}
	REP (x, (int)graph[c].size()) {
		if (!v[graph[c][x]]) {
			solve (graph[c][x]);
		}
	}
}

int main () {
	fastCin;
	cin >> n;
	FORI (x,1,n) {
		cin >> V[x];
	}
	REP (x, n-1) {
		int a,b;
		cin >> a >> b;
		graph[a].pb (b);
		graph[b].pb (a);
	}
	solve (1);
	cout << ans << "\n";
}
