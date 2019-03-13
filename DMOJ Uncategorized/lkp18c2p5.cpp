#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <set>
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
#define larger(x,v) x=max((x),(v))
#define smaller(x,v) x=min((x),(v))
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

long long a[300001] = {0}, bit[600005][2] = {0}, tot = 0;
vector <long long> tmp, c;
int n;

void add (int pos, long long val) {
	while (pos < 600005) {
		bit[pos][0] += val;
		bit[pos][1]++;
		pos += pos & -pos;
	}
}

void sub (int pos, long long val) {
	while (pos < 600005) {
		bit[pos][0] -= val;
		bit[pos][1]--;
		pos += pos & -pos;
	}
}

long long query (int pos, bool b) {
	long long sum = 0;
	while (pos > 0) {
		sum += bit[pos][b];
		pos -= pos & -pos;
	}
	return sum;
}

void ans () {
	long long req = tot/2+1;
	int sz = (int)c.size();
	int lo = 1, hi = sz-1, mid;
	while (lo < hi) {
		mid = (lo+hi)/2;
		if (tot-query (mid, false) < req) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	if (tot-query (lo, false) < req) {
		lo--;
	}
	long long cur = tot-query (lo, false);
	int bad = (cur-req)/c[lo+1];
	cout << n-query (lo, true)-bad << "\n";
}

int main () {
	vector <long long>::iterator it;
	int q[300001][2], d;
	scanf ("%d %d", &n, &d);
	for (int x = 1; x <= n; x++) {
		scanf ("%lld", &a[x]);
		tmp.push_back (a[x]);
		tot += a[x];
	}
	for (int x = 0; x < d; x++) {
		cin >> q[x][0] >> q[x][1];
		tmp.push_back (q[x][1]);
	}
	tmp.push_back (-2000000000);
	sort (tmp.begin(), tmp.end());
	for (int x = 0; x < tmp.size(); x++) {
		if (c.empty() || c.back() != tmp[x]) {
			c.push_back (tmp[x]);
		}
	}
	for (int x = 1; x <= n; x++) {
		it = lower_bound (c.begin(), c.end(), a[x]);
		int pos = it-c.begin();
		add (pos, a[x]);
	}
	ans ();
	for (int x = 0; x < d; x++) {
		tot += q[x][1] - a[q[x][0]];
		
		it = lower_bound (c.begin(), c.end(), a[q[x][0]]);
		int pos = it-c.begin();
		sub (pos, a[q[x][0]]);
		
		a[q[x][0]] = q[x][1];
		it = lower_bound (c.begin(), c.end(), a[q[x][0]]);
		pos = it-c.begin();
		add (pos, a[q[x][0]]);
		
		ans ();
	}
}
