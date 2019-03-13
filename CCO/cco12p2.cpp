#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

long long sp[20001][2];
priority_queue < pair <int, int>, vector< pair <int, int> >, greater< pair <int, int> > > pq;
vector < vector < pair <int, int> > > graph(20001);

int main () {
  int n, m, a, b, l;
  memset(sp, -1, sizeof(sp));
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%d %d %d", &a, &b, &l);
    graph[a].push_back(make_pair(b, l));
  }
  sp[1][0] = 0;
  for (int x = 0; x < graph[1].size(); x++) {
    pq.push(make_pair(graph[1][x].second, graph[1][x].first));
  }
  while (!pq.empty()) {
    int pos = pq.top().second, cost = pq.top().first;
    pq.pop();
    if (sp[pos][0] == -1 || cost < sp[pos][0]) {
      sp[pos][1] = sp[pos][0];
      sp[pos][0] = cost;
      for (int x = 0; x < graph[pos].size(); x++) {
        pq.push(make_pair(graph[pos][x].second + cost, graph[pos][x].first));
      }
      if (sp[pos][1] != -1) {
        for (int x = 0; x < graph[pos].size(); x++) {
          pq.push(make_pair(graph[pos][x].second + sp[pos][1], graph[pos][x].first));
        }
      }
    } else if ((sp[pos][1] == -1 || cost <= sp[pos][1]) && cost > sp[pos][0]) {
      sp[pos][1] = cost;
      for (int x = 0; x < graph[pos].size(); x++) {
        pq.push(make_pair(graph[pos][x].second + cost, graph[pos][x].first));
      }
    }
  }
  printf ("%lld\n", sp[n][1]);
}
