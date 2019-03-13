#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <bitset>
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

int n, m, s, e, v, ans = intLIMIT::max(), len;
bool V[1048576+1][19] = {0};

vector < vi > graph(20);

void solve (int pos, int m) {
	if (V[m][pos]) {
		return;
	}
	V[m][pos] = true;
	bitset <20> tmp = m;
	if (pos == e) {
		//cout << tmp << "\n";
		if (abs(v-((int)tmp.count()-1)) < ans) {
			len = (int)tmp.count()-1;
			ans = abs(v-((int)tmp.count()-1));
		} else if (abs(v-((int)tmp.count()-1)) == ans) {
			len = min (len, (int)tmp.count()-1);
		}
		return;
	}
	REP (x, (int)graph[pos].size()) {
		if (!tmp.test(graph[pos][x])) {
			tmp.set (graph[pos][x]);
			solve (graph[pos][x], tmp.to_ulong());
			tmp.flip (graph[pos][x]);
		}
	}

}

int main () {
	 fastCin;
     cin >> n >> m >> s >> e >> v;
     int a, b;
     REP (x, m) {
     	cin >> a >> b;
     	graph[a].pb (b);
     	graph[b].pb (a);
     }
     bitset <20> tmp;
     tmp.set (s);
     solve (s, tmp.to_ulong());
     cout << len << "\n";
}
