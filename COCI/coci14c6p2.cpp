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
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int n, m, f[11][3] = {0}, all = 0, cur[3] = {0}, c[120];
bool possible[11] = {0};
vector < pii > p;

void solve (int pos, vi cnt) {
	if (pos >= p.size()) {
		REP (x, 3) {
			cnt[x] += cur[x];
		}
		REP (x, n) {
			if (!possible[x]) {
				int dif = 0;
				REP (i, 3) {
					dif += max (0, f[x][i]-cnt[i]);
				}
				if (dif <= all) {
					possible[x] = true;
				}
			}
		}
	} else {
		cnt[p[pos].pF]++;
		solve (pos+1, cnt);
		cnt[p[pos].pF]--;
		cnt[p[pos].pS]++;
		solve (pos+1, cnt);
	}
}

int main () {
	c['O'] = 0;
	c['V'] = 1;
	c['N'] = 2;
    fastCin;
    char w;
    string in;
    cin >> n;
    REP (x, n) {
    	cin >> f[x][0] >> w >> f[x][1] >> w >> f[x][2];
    }
    cin >> m;
    REP (x, m) {
    	cin >> in;
    	if (in.length()==3) {
    		all++;
    	} else if (in.length()==1) {
    		cur[c[in[0]]]++;
    	} else {
    		p.pb (mp (c[in[0]], c[in[1]]));
    	}
    }
    vi tmp(3);
    tmp[0] = tmp[1] = tmp[2] = 0;
    solve (0, tmp);
    REP (x, n) {
    	if (possible[x]) {
    		cout << "DA\n";
    	} else {
    		cout << "NE\n";
    	}
    }
}
