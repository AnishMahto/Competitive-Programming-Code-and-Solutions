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

int h, w, dp[1005][1005] = {0};
char a[1005][1005];
deque < pii > q;

int main () {
	int t;
	si (t);
	while (t--) {
		int ans = 0;
		si (h); si (w);
		FORI (x,1,h) {
			int pre = 0;
			FORI (i,1,w) {
				dp[x][i] = 0;
				scanf (" %c", &a[x][i]);
				if (a[x][i] == 'F') {
					dp[x][i] = 1+dp[x-1][i];
					while (!q.empty() && q.back().pF >= dp[x][i]) {
						if (q.size() > 1) {
							larger (ans, (i-(q[q.size()-2].pS) - 1)*q.back().pF);
						} else {
							larger (ans, (i-pre-1)*q.back().pF);
						}
						q.pop_back();
					}
					q.push_back (mp (dp[x][i], i));
				} else {
					pre = i;
				}
				if (a[x][i] == 'R' || i==w) {
					REP (j, (int)q.size()) {
						if (j==0) {
							larger (ans, q.front().pF*(q.back().pS-pre));
						} else {
							larger (ans, q[j].pF*(q.back().pS-q[j-1].pS));
						}
					}
					q.clear();
				}
			}
		}
		cout << ans*3 << "\n";
	}
}
