#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector < vector < pair <long long, long long> > > graph(100001);
long long dp[100001] = {0};
int safe[100001] = {0}, unsafe[100001] = {0};

int main () {
  int n, m;
  long long a, b, t;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%lld %lld %lld", &a, &b, &t);
    if (a != b) {
    if (t==0) {
      graph[a].push_back(make_pair(b, 1));
      graph[b].push_back(make_pair(a, 1));
    } else {
      graph[a].push_back(make_pair(b, 100001));
      graph[b].push_back(make_pair(a, 100001));
    }
    }
  }
  priority_queue < pair <long long, pair <long long, long long> >, vector< pair <long long, pair <long long, long long> > >, greater< pair <long long, pair <long long, long long> > > > pq;
  for (int x = 0; x < graph[1].size(); x++) {
    pq.push(make_pair(graph[1][x].second, make_pair(graph[1][x].first, 1)));
  }
  while (!pq.empty()) {
    long long pos = pq.top().second.first, cost = pq.top().first, from = pq.top().second.second;
    pq.pop();
    if ((dp[pos]==0 || dp[pos] > (cost + dp[from]))) {
      dp[pos] = cost + dp[from];
      safe[pos] = safe[from];
      unsafe[pos] = unsafe[from];
      if (cost == 100001) {
        unsafe[pos]++;
      } else {
        safe[pos]++;
      }
      for (int x = 0; x < graph[pos].size(); x++) {
        if (graph[pos][x].first != 1) {
          pq.push(make_pair(graph[pos][x].second, make_pair(graph[pos][x].first, pos)));
        }
      }
    }
  }
  if (dp[n]==0) {
    cout << -1 << endl;
  } else {
    cout << unsafe[n] << " " << (safe[n]+unsafe[n]) << endl;
  }
}
