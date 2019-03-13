#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector < vector < pair <int, int> > > graph(200001);
int connections[200001] = {0};
int dp[200001] = {0}, sum = 0;
pair <int, int> longestPaths[200001];

void dfs2 (int pos, int par) {
  for (int x = 0; x < graph[pos].size(); x++) {
    
    if (graph[pos][x].first == par) {
      continue;
    }
    
    if ((longestPaths[pos].first == longestPaths[pos].second) || (graph[pos][x].second + longestPaths[graph[pos][x].first].first != longestPaths[pos].first)) {
      dp[graph[pos][x].first] = max (dp[pos], longestPaths[pos].first) + graph[pos][x].second;
    } else {
      dp[graph[pos][x].first] = max (dp[pos], longestPaths[pos].second) + graph[pos][x].second;
    }
    dfs2 (graph[pos][x].first, pos);
  }
}

int dfs1 (int pos, int par) {
  longestPaths[pos].first = longestPaths[pos].second = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      sum += graph[pos][x].second;
      int ans = dfs1 (graph[pos][x].first, pos) + graph[pos][x].second;
      if (ans > longestPaths[pos].first) {
        longestPaths[pos].second = longestPaths[pos].first;
        longestPaths[pos].first = ans;
      } else if (ans > longestPaths[pos].second) {
        longestPaths[pos].second = ans;
      }
    }
  }
  return longestPaths[pos].first;
}

int main () {
  int n, t, a, b, c;
  scanf ("%d %d", &n, &t);
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
    connections[a]++;
    connections[b]++;
  }
  dfs1 (1, -1);
  dfs2 (1, -1);
  for (int x = 1; x <= n; x++) {
    if (connections[x] == t) {
      printf ("%d %d\n", x, 2*sum - max (dp[x], longestPaths[x].first));
    }
  }
}
