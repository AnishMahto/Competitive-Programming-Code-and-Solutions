#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

long long sp[1601][3601] = {0};
priority_queue < pair < pair <int, int>, int>, vector< pair < pair <int, int>, int> >, greater< pair < pair <int, int>, int> > > pq;
vector < vector < pair <int, int> > > graphA(1601), graphB(1601);

int main () {
  int n, e, s, a, b, c, t;
  scanf ("%d %d %d", &s, &n, &e);
  for (int x = 0; x < e; x++) {
    scanf ("%d %d %d %d", &a, &b, &c, &t);
    if (t == 0) {
      graphB[a].push_back(make_pair(b, c));
      graphB[b].push_back(make_pair(a, c));
    } else {
      graphA[a].push_back(make_pair(b, c));
      graphA[b].push_back(make_pair(a, c));
    }
  }
  for (int x = 0; x < graphA[0].size(); x++) {
    if (graphA[0][x].second <= s) {
      pq.push(make_pair(make_pair(graphA[0][x].second, graphA[0][x].second), graphA[0][x].first));
    }
  }
  for (int x = 0; x < graphB[0].size(); x++) {
    pq.push(make_pair(make_pair(graphB[0][x].second, 0), graphB[0][x].first));
  }
  int ans = 2000000000;
  while (!pq.empty()) {
    int pos = pq.top().second, cost = pq.top().first.first, above = pq.top().first.second;
    pq.pop();
    if (pos == n-1) {
      ans = min (ans, cost);
      continue;
    }
    if (sp[pos][above] == 0 || cost < sp[pos][above]) {
      sp[pos][above] = cost;
        for (int x = 0; x < graphB[pos].size(); x++) {
          if (graphB[pos][x].first != 0 && (sp[graphB[pos][x].first][above] == 0 || cost + graphB[pos][x].second < sp[graphB[pos][x].first][above])) {
            pq.push(make_pair(make_pair(cost + graphB[pos][x].second, above), graphB[pos][x].first));
          }
        }
        for (int x = 0; x < graphA[pos].size(); x++) {
          if (above + graphA[pos][x].second <= s && (sp[graphA[pos][x].first][above + graphA[pos][x].second] == 0 || cost + graphA[pos][x].second < sp[graphA[pos][x].first][above + graphA[pos][x].second])) {
            pq.push(make_pair(make_pair(cost + graphA[pos][x].second, above + graphA[pos][x].second), graphA[pos][x].first));
          }
        }
    }
  }
  if (ans == 2000000000) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
