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

int main () {
	fastCin;
	int n, m, d[100005], dp[100005][2] = {0}, a[100005], last[100005] = {0};
	cin >> n >> m;
	FORI (x,1,n) {
		cin >> a[x];
	}
	FORI (x,1,m) {
		cin >> d[x];
	}
	//dp[x][0] = dont use any counter, dp[x][1] = use counter
	for (int x = n; x >= 1; x--) {
		if (x==n) {
			dp[x][0] = 0;
			dp[x][1] = 1;
		} else {
			if (x+d[a[x]]+1 <= n) {
				//switch now
				dp[x][1] = max (dp[x][1], 1 + max (dp[x+d[a[x]]+1][0], dp[x+d[a[x]]+1][1]) );
			}
			//dont switch now (hence next possible switch is next attack that equals a[x])
			if (last[a[x]] != 0) {
				dp[x][1] = max (dp[x][1], 1+dp[last[a[x]]][1]);
			} else {
				dp[x][1] = max (dp[x][1], 1);
			}
			dp[x][0] = max (dp[x+1][0], dp[x+1][1]);
		}
		last[a[x]] = x;
	}
	cout << max (dp[1][0], dp[1][1]) << "\n";
	//printArr (dp, n+1);
}
