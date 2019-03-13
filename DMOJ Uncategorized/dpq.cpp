#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <set>
#include <map>
#include <queue>
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

int n;
ll h[2*100005] = {0}, a[2*100005] = {0}, dp[2*100005*4] = {0};
vll H, temp;

void update (int pos, int l, int r, int tl, int tr, ll val) {
	if (l > r || l > tr || r < tl) {
		return;
	} else if (l >= tl && r <= tr) {
		dp[pos] = max (dp[pos], val);
	} else {
		int mid = (l+r)/2;
		update (2*pos, l, mid, tl, tr, val);
		update (2*pos+1, mid+1, r, tl, tr, val);
		dp[pos] = max (dp[2*pos], dp[2*pos+1]);
	}
}

ll query (int pos, int l, int r, int tl, int tr) {
	if (l > r || l > tr || r < tl) {
		return -1;
	} else if (l >= tl && r <= tr) {
		return dp[pos];
	} else {
		int mid = (l+r)/2;
		return max (query (2*pos, l, mid, tl, tr), query (2*pos+1, mid+1, r, tl, tr));
	}
}

int main () {
	fastCin;
	cin >> n;
	REP (x, n) {
		cin >> h[x];
		temp.pb (h[x]);
	}
	sort (allof (temp));
	REP (x, (int)temp.size()) {
		if (x==0 || temp[x] != temp[x-1]) {
			H.pb (temp[x]);
		}
	}
	REP (x, n) {
		cin >> a[x];
	}
	vll::iterator it;
	ll ans = 0;
	REP (x, n) {
		it = lower_bound (allof (H), h[x]);
		int pos = it-H.begin();
		ll best = query (1, 0, (int)H.size()-1, 0, pos);
		ans = max (ans, best+a[x]);
		update (1, 0, (int)H.size()-1, pos, pos, best+a[x]);
	}
	cout << ans << "\n";
}
