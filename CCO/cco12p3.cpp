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

int V, T;
vector <char> v, t;
bool r1[120][120] = {0};
vector < vector < pair <char, char> > > r2(120);
string s;
int dp[35][35][35];

int solve (int l, int r, int sLtr) {
	if (dp[l][r][sLtr]!=-1) {
		return dp[l][r][sLtr];
	} else if (l==r) {
		if (r1[sLtr+'A'][s[l]]) {
			dp[l][r][sLtr]=1;
		} else {
			dp[l][r][sLtr]=0;
		}
	} else {
		dp[l][r][sLtr] = 0;
		FORI (i,l,r-1) {
			REP (x, (int)r2[sLtr+'A'].size()) {
				char A = r2[sLtr+'A'][x].pF, B = r2[sLtr+'A'][x].pS;
				dp[l][r][sLtr] = max (dp[l][r][sLtr], min (solve(l,i,A-'A'), solve(i+1,r,B-'A')));
			}
		}
	}
	return dp[l][r][sLtr];
}

int main () {
	fastCin;
	char cur, a, b;
	cin >> V >> T;
	REP (x, V) {
		cin >> cur;
		v.pb (cur);
	}
	REP (x, T) {
		cin >> cur;
		t.pb (cur);
	}
	int r, w;
	cin >> r;
	REP (x, r) {
		cin >> a >> b;
		r1[a][b] = true;
	}
	cin >> r;
	REP (x, r) {
		cin >> cur >> a >> b;
		r2[cur].pb (mp (a,b));
	}
	cin >> w;
	while (w--) {
		cin >> s;
		CL (dp, -1);
		cout << solve (0, (int)s.length()-1, v[0]-'A') << "\n";
	}
}
