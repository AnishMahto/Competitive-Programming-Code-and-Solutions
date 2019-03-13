#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, k, parentEdge[500001] = {0}, parent[500001] = {0}, closestImportant[500001] = {0};
long long treeSum = 0, longestPaths[500001][2] = {0}, dp[500001] = {0}, someSums[500001] = {0};
vector < vector < pair <int, int> > > graph(500001);
vector <int> kamps;
bool important[500001] = {0};

bool findImportant (int pos, int par) {
  int imp = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      if (findImportant(graph[pos][x].first, pos)) {
        imp = 1;
        //find 2 longest paths going down
        for (int i = 0; i < 2; i++) {
          int nextPos = graph[pos][x].first, cost = graph[pos][x].second;
          if (longestPaths[nextPos][0] + cost > longestPaths[pos][i]) {
            
            if (i == 0) {
              longestPaths[pos][1] = longestPaths[pos][0]; //propagate value
            }
            
            longestPaths[pos][i] = longestPaths[nextPos][0] + cost;
            break;
          }
        }
        treeSum += graph[pos][x].second;
      }
      
        parentEdge[graph[pos][x].first] = graph[pos][x].second;
        parent[graph[pos][x].first] = pos;
        
    }
  }
  if (imp) {
    important[pos] = 1;
  }
  return important[pos];
}

void solve (int pos, int par) {
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first == par || !important[graph[pos][x].first]) {
      continue;
    }
    if ((longestPaths[pos][0] == longestPaths[pos][1]) || (longestPaths[pos][0] != graph[pos][x].second + longestPaths[graph[pos][x].first][0])) {
      dp[graph[pos][x].first] = max (dp[pos], longestPaths[pos][0]) + graph[pos][x].second;
    } else {
      dp[graph[pos][x].first] = max (dp[pos], longestPaths[pos][1]) + graph[pos][x].second;
    }
    solve (graph[pos][x].first, pos);
  }
}

long long add (int pos, long long sum, int closest, int par) {
  someSums[pos] = sum;
  closestImportant[pos] = closest;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      add (graph[pos][x].first, sum + graph[pos][x].second, closest, pos);
    }
  }
}

int main () {
  int a, b, c;
  scanf ("%d %d", &n, &k);
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  for (int x = 0; x < k; x++) {
    scanf ("%d", &a);
    kamps.push_back(a);
    important[a] = 1;
  }
  findImportant(kamps[0], -1);
  solve (kamps[0], -1);
  for (int x = 1; x <= n; x++) {
    if (important[x]) {
      for (int i = 0; i < graph[x].size(); i++) {
        if (!important[graph[x][i].first]) {
          add (graph[x][i].first, graph[x][i].second, x, x);
        }
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    if (important[x]) {
      printf ("%lld\n", (2*treeSum - max (dp[x], longestPaths[x][0])));
    } else {
      printf ("%lld\n", (2*treeSum - max (dp[closestImportant[x]], longestPaths[closestImportant[x]][0]) + someSums[x]));
    }
  }
}
