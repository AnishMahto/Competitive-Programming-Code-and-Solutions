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

ll a,b,c, v[200001], dp[2][101][2] = {0}, MAX = 101L*sqr(101)*200001L;

int main () {
	int n;
	cin >> n >> a >> b >> c;
	FORI (x,1,n) {
		cin >> v[x];
	}
	FORI (x,0,100) {
		dp[0][x][0] = dp[0][x][1] = 0;
	}
	FORI (x,1,n) {
		int pos = x%2, pre = 1-pos;
		for (int w=100; w >= 0; w--) {
			dp[pos][w][1] = MAX;
			if (w+1<=100) {
				dp[pos][w][1] = min (dp[pos][w][1], dp[pos][w+1][1]+b);
			}
			dp[pos][w][1] = min (dp[pos][w][1], min (dp[pre][w][0], dp[pre][w][1]) + a*(ll)w + c*sqr ((v[x] - w)));

		}
		FORI (w,0,100) {
			dp[pos][w][0] = MAX;
			if (w>0) {
				dp[pos][w][0] = min (dp[pos][w][0], dp[pos][w-1][0]);
			}
			dp[pos][w][0] = min (dp[pos][w][0], min (dp[pre][w][0], dp[pre][w][1]) + a*(ll)w + c*sqr ((v[x] - w)));
		}
	}
	cout << min (dp[n%2][0][0], dp[n%2][0][1]) << "\n";
}
