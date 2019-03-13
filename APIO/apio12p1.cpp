#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;
typedef vector <int> vi;
typedef vector < pair <int, int> > vpii;
#define mset(a, b) memset (a,(b), sizeof(a))
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(x,a,b) for (int x = a; x < b; x++)
#define sd(x) scanf ("%d", &x);
#define sl(x) scanf ("%lld", &x);
#define sc(x) scanf (" %c", &x);
#define rnd(a, x) (double)round(a*(pow(10,x)))*(pow((double)10,-x))
#define dbg(x) x << "!"
#define dbg2(x) x << " ~"

long long n, m, par[100001], cost[100001], l[100001], ans = 0, dp[100001] = {0};
priority_queue <int> pq[100001];
vector < vector <int> > graph(100001);

int solve (int pos) {
  dp[pos] = cost[pos];
  loop (x, 0, graph[pos].size()) {
    solve (graph[pos][x]);
    if (pq[graph[pos][x]].size() > pq[pos].size()) {
      pq[pos].swap(pq[graph[pos][x]]);
      swap (dp[pos], dp[graph[pos][x]]);
    }
    while (!pq[graph[pos][x]].empty()) {
      pq[pos].push(pq[graph[pos][x]].top());
      dp[pos] += pq[graph[pos][x]].top();
      pq[graph[pos][x]].pop();
    }
  }
  while (dp[pos] > m) {
    dp[pos] -= pq[pos].top();
    pq[pos].pop();
  }
  ans = max (ans, l[pos]*(int)pq[pos].size());
}

int main () {
  long long boss;
  sl (n); sl (m);
  loop (x, 1, n+1) {
    sl (par[x]); sl (cost[x]); sl (l[x]);
    graph[par[x]].pb(x);
    if (par[x]==0) {
      boss = x;
    }
    pq[x].push(cost[x]);
  }
  solve (boss);
  cout << ans << endl;
}
