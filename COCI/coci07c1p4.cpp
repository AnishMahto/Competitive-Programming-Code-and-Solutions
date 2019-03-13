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
#include <string>
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

ll dp[201][201] = {0}, n, w[201][201] = {0}, cnt[201];
bool modded[201][201] = {0};
string s;

ll getCnt (int l, int r) {
	if (l==0) {
		return cnt[r];
	} else {
		return cnt[r]-cnt[l-1];
	}
}

ll solve (int l, int r) {
	if (dp[l][r]!=-1) {
		return dp[l][r];
	} else if (l==r-1) {
		dp[l][r] = w[s[l]][s[r]];
	} else if (l>r) {
		return 1;
	} else if (getCnt(l,r)==0) {
		deque <char> q;
		FORI (x,l,r) {
			if (s[x]=='(' || s[x]=='{' || s[x]=='[') {
				q.pb (s[x]);
			} else {
				if (s[x]=='}' && !q.empty() && q.back()=='{') {
					q.pop_back();
				} else if (s[x]=='}') {
					dp[l][r] = 0;return 0;
				}
				if (s[x]==')' && !q.empty() && q.back()=='(') {
					q.pop_back();
				} else if (s[x]==')') {
					dp[l][r] = 0;return 0;
				}
				if (s[x]==']' && !q.empty() && q.back()=='[') {
					q.pop_back();
				} else if (s[x]==']') {
					dp[l][r] = 0;return 0;
				}
			}
		}
		if (!q.empty()) {
			dp[l][r]=0; return 0;
		}
		dp[l][r]=1;return 1;
	}
	else {
		dp[l][r] = 0;
		for (int x = l+1; x <= r; x += 2) {
			dp[l][r] += solve (l+1,x-1)*w[s[l]][s[x]]*solve (x+1,r);
			if (dp[l][r] >= 100000) {
				modded[l][r] = true;
				modded[l][r] = max (modded[l][r], max (modded[l+1][x-1], modded[x+1][r]));
			}
			dp[l][r] %= 100000;
		}
	}
	return dp[l][r];
}

int main () {
	CL (dp,-1);
	fastCin;
	cin >> n >> s;
	REP (x, n) {
		if (s[x]=='?') {
			cnt[x]++;
		}
		if (x>0) {
			cnt[x] += cnt[x-1];
		}
	}
	w['?']['?'] = 3;
	w['('][')'] = w['['][']'] = w['{']['}'] = 1;
	w['?'][')'] = w['(']['?'] = w['?'][']'] = w['[']['?'] = w['?']['}'] = w['{']['?'] = 1;
	ll ans = solve (0,n-1);
	if (modded[0][n-1]) {
		printf ("%05lld\n", ans);
	} else {
		printf ("%lld\n", ans);
	}
}
