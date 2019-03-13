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

class Sparse {
	public:
		long long *a, n, **minS, **maxS, lg, negInf = -9223372036854775807, inf = 9223372036854775807, pwr[60] = {0};
		void reset (int N) {
			pwr[0] = 1;
			for (int x = 1; x < 60; x++) {
				pwr[x] = pwr[x-1]*2;
			}
			n=N;
			lg = log2(n);
			a = new long long [n+5];
			minS = new long long *[n+5];
			maxS = new long long *[n+5];
			for (int x = 0; x < n+5; x++) {
				minS[x] = new long long [lg+5];
				maxS[x] = new long long [lg+5];
			}
		}
		void build () {
			for (int x = 0; x <= lg; x++) {
				maxS[0][x] = negInf;
				minS[0][x] = inf;
				long long curPow = pwr[x];
				for (int i = 1; i <= n; i++) {
					if (x==0) {
						minS[i][x] = maxS[i][x] = a[i];
					} else {
						minS[i][x] = min (minS[i][x-1], minS[max(i-curPow/2, (long long)0)][x-1]);
						maxS[i][x] = max (maxS[i][x-1], maxS[max(i-curPow/2, (long long)0)][x-1]);
					}
				}
			}
		}
		long long query (int l, int r, bool MAX) {
			long long LG = (int)log2((double)(r-l+1)), curPow = pwr[LG];
			if (l==r) {
				return a[l];
			} else {
				if (!MAX) {
					return min (minS[r][LG], minS[l+curPow-1][LG]);
				} else {
					return max (maxS[r][LG], maxS[l+curPow-1][LG]);
				}
			}
		}
};

int main () {
	fastCin;
	Sparse st;
	int n, q, a, b;
	cin >> n >> q;
	st.reset (n);
	FORI (x,1,n) {
		cin >> st.a[x];
	}
	st.build ();
	while (q--) {
		cin >> a >> b;
		cout << st.query (a,b,true) - st.query(a,b,false) << "\n";
	}
}
