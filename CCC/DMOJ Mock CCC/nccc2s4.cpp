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

vector < vector < pii > > graph(50001);
vector < vi > C(50001);
vi curC;
int n, cnt=0;
bool bad[50001]={0}, curBad=false, bbad[50001]={0};

void dfs (int pos, int par, int prev) {
	if (bad[pos]) {
		return;
	}
	bad[pos]=true;
	REP (x,(int)graph[pos].size()) {
		if (graph[pos][x].pF!=par) {
			if (graph[pos][x].pS==prev) {
				curBad=true;
			}
			dfs (graph[pos][x].pF, pos, graph[pos][x].pS);
		}
	}
}

int main () {
	fastCin;
	int a,b,c;
	cin>>n;
	REP(x,n-1) {
		cin>>a>>b>>c;
		graph[a].pb(mp(b,c));
		graph[b].pb(mp(a,c));
	}
	FORI(x,1,n) {
		curBad=false;
		if (!bad[x]) {
			REP (i,(int)graph[x].size()) {
				if (C[graph[x][i].pS].empty()) {
					curC.pb (graph[x][i].pS);
				}
				C[graph[x][i].pS].pb(graph[x][i].pF);
			}
			while (!curC.empty()) {
				int cur=curC.back();
				curC.pop_back();
				if (C[cur].size()>1) {
					REP (i,(int)C[cur].size()) {
						dfs (C[cur][i], x,-1);
					}
				}
				C[cur].clear();
			}
			if (curBad) {
				bbad[x]=true;
				REP(i,(int)graph[x].size()) {
					dfs (graph[x][i].pF, x, -1);
				}
			}
		}
	}
	vi ans;
	FORI(x,1,n) {
		if (!bad[x]&&!bbad[x]) {
			cnt++;
			ans.pb(x);
		}
	}
	cout<<cnt<<"\n";
	REP(x,cnt) {
		cout<<ans[x]<<"\n";
	}
}
