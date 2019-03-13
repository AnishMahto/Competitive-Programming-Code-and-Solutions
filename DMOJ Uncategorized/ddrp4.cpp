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
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define dbl(x) (double)(x)
#define vi vector <int>
#define vll vector <long long>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

int dp[501][501] = {0}, n;
vector <string> w;
vector < vi > graph(501);

bool cmp (int s1, int s2) {
    string f = w[s1], s = w[s2];
    if (f.length() > s.length()) {
        swap (f, s);
    }
    if (abs((int)f.length() - (int)s.length()) > 1) {
        return false;
    } else {
        int cnt = 0, len, pos = 0;
        if (f.length()==s.length()) {
            REP (x, f.length()) {
                if (f[x] != s[x]) {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
            }
        } else if (s.length() > f.length()) {
            len = f.length();
            REP (x, s.length()) {
                if (x > len) {
                    cnt++;
                    len++;
                } else if (f[pos] != s[x]) {
                    cnt++;
                    len++;
                } else {
                    pos++;
                }
                if (cnt > 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool bfs (int s, int e) {
    bool v[501] = {0};
    deque < pii > q;
    v[s] = true;
    dp[s][s] = 0;
    for (int x = 0; x < graph[s].size(); x++) {
        if (!v[graph[s][x]]) {
            v[graph[s][x]] = true;
            q.pb (mp(graph[s][x], 1));
        }
    }
    while (!q.empty()) {
        int pos = q.front().first, c = q.front().second;
        q.pop_front();
        dp[s][pos] = dp[pos][s] = c;
        for (int x = 0; x < graph[pos].size(); x++) {
            if (!v[graph[pos][x]]) {
                v[graph[pos][x]] = true;
                q.pb (mp(graph[pos][x], c+1));
            }
        }
    }
    REP (x, n) {
        if (dp[s][x] == -1) {
            dp[s][x] = -2;
        }
    }
}

int main () {
    CL (dp, -1);
    string cur;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    REP (x, n) {
        cin >> cur;
        w.pb(cur);
        REP (i, w.size()-1) {
            if (cmp(i, x)) {
                graph[x].pb(i);
                graph[i].pb(x);
            }
        }
        
    }
    int q, a, b;
    cin >> q;
    REP (x, q) {
        cin >> a >> b;
        a--; b--;
        if (dp[a][b] == -1) {
            bfs (a, b);
        }
        if (dp[a][b] != -2) {
            cout << dp[a][b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
