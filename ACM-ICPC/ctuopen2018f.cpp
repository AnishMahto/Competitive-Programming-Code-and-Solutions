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

ll dp[1005][1005][2],n,k,MOD=1e9+7;
bool b[1005]={0};

ll solve (int pos, int cnt, bool c) {
	if (dp[pos][cnt][c]!=-1) {
		return dp[pos][cnt][c];
	} else if (pos==0) {
		if ((cnt==k&&!c)||(cnt==k-1&&c)) {
			dp[pos][cnt][c]=1;
		} else {
			dp[pos][cnt][c]=0;
		}
	} else {
		dp[pos][cnt][c]=0;
		int tot=0;
		(c)?tot++:false; (b[pos])?tot++:false;
		if (tot==0) {
			dp[pos][cnt][c] += solve (pos-1, cnt, false);
			dp[pos][cnt][c] += solve (pos-1, cnt+1, false);
		} else if (tot==1) {
			dp[pos][cnt][c] += solve (pos-1, cnt+1, false);
			dp[pos][cnt][c] += solve (pos-1, cnt, true);
		} else if (tot==2) {
			dp[pos][cnt][c] += solve (pos-1, cnt, true);
			dp[pos][cnt][c] += solve (pos-1, cnt+1, true);
		}
	}
	dp[pos][cnt][c]%=MOD;
	return dp[pos][cnt][c];
}

int main () {
	CL(dp,-1);
	fastCin;
	char c;
	cin>>n>>k;
	FORI(x,1,n) {
		cin>>c;
		b[x]=c-'0';
	}
	cout << solve (n,0,false) << "\n";
}
