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
#define larger(x,v) x=max((x),(v))
#define smaller(x,v) x=min((x),(v))
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int main () {
	fastCin;
	int n, tot;
	vi p;
	bool s[10000001] = {0};
	FORI (x,2,10000000) {
		if (!s[x]) {
			if (x!=2) {
				p.pb (x);
			}
			for (int i = 2*x; i <= 10000000; i += x) {
				s[i] = true;
			}
		}
	}
	tot = (int)p.size();
	REP (z, 5) {
		cin >> n;
		if (!s[n]) {
			cout << n << " = " << n << "\n";
			continue;
		}
		int l = 0, r = tot-1;
		string ans = "-", ans2 = "-";
		pii a2 = mp (-1,-1);
		for (; l <= tot-1; l++) {
			while (r-1 >= l && p[l] + p[r] > n) {
				r--;
			}
			if (p[l] + p[r] == n) {
				ans = to_string (p[l]) + " + " + to_string (p[r]);
			}
		}
		if (ans != "-") {
			cout << n << " = " << ans << "\n";
		} else {
			REP (x, tot) {
				if (p[x] >= n) {
					break;
				}
				if (!s[n-p[x]]) {
					continue;
				}
				FORI (i,x,tot-1) {
					if (p[i]+p[x] >= n) {
						break;
					} else if (!s[n-p[x]-p[i]]) {
						pii tmp = mp (min (p[x], min (p[i], n-p[x]-p[i])), max (p[x], min (p[i], n-p[x]-p[i])));
						if (tmp > a2) {
							a2 = tmp;
							vi tmp2;
							tmp2.pb (p[x]);
							tmp2.pb (p[i]);
							tmp2.pb (n-p[x]-p[i]);
							sort (allof (tmp2));
							ans = to_string (tmp2[0]) + " + " + to_string (tmp2[1]) + " + " + to_string (tmp2[2]);
						}
						break;
					}
				}
			}
			cout << n << " = " << ans << "\n";
		}
	}
}
