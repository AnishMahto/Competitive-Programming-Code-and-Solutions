#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <set>
using namespace std;

set < pair <int, int> > edges;
vector < vector <int> > graph(500001), revGraph(500001);
vector < vector <int> > provGraph(500001);
vector <int> stack;
long long loot[500001] = {0}, components = 0, prov[500001] = {0}, n, m, lootPerProvince[500001] = {0};
bool visited[500001] = {0};
long long dp[500001][2], ways[500001][2] = {0};

void findComponents (int pos) {
  visited[pos] = true;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (!visited[graph[pos][x]]) {
      findComponents (graph[pos][x]);
    }
  }
  stack.push_back(pos);
}
void findComponents2 (int pos) {
  visited[pos] = true;
  prov[pos] = components;
  lootPerProvince[components] += loot[pos];
  for (int x = 0; x < revGraph[pos].size(); x++) {
    if (!visited[revGraph[pos][x]]) {
      findComponents2(revGraph[pos][x]);
    }
  }
}

long long solve (int pos, bool take) {
  if (dp[pos][take] != -1) {
    return dp[pos][take];
  } else if (pos==prov[n]) {
    ways[pos][take] = 1;
    if (take) {
      dp[pos][take] = lootPerProvince[prov[n]];
    } else {
      dp[pos][take] = 0;
    }
    return dp[pos][take];
  }
  else {
    long long current = 0, count = 0;
    if (take) {
      dp[pos][take] = lootPerProvince[pos];
    } else {
      dp[pos][take] = 0;
    }
    ways[pos][take] = 0;
    for (int x = 0; x < provGraph[pos].size(); x++) {
      if (take) {
        //try taking current province if allowed
        current = solve (provGraph[pos][x], 0) + lootPerProvince[pos];
        if (current > dp[pos][take]) {
          dp[pos][take] = current;
          ways[pos][take] = (ways[provGraph[pos][x]][0] % 1000000007);
        } else if (current == dp[pos][take]) {
          ways[pos][take] += (ways[provGraph[pos][x]][0] % 1000000007);
          ways[pos][take] %= 1000000007;
        }
      }
      if (!take) {
      //we can always try skipping this province, in some cases we have to skip it (if !take)
        current = solve (provGraph[pos][x], 1);
        if (current > dp[pos][take]) {
          dp[pos][take] = current;
          ways[pos][take] = (ways[provGraph[pos][x]][1] % 1000000007);
        } else if (current == dp[pos][take]) {
          ways[pos][take] += (ways[provGraph[pos][x]][1] % 1000000007);
          ways[pos][take] %= 1000000007;
        }
          current = solve (provGraph[pos][x], 0);
          if (current > dp[pos][take]) {
            dp[pos][take] = current;
            ways[pos][take] = (ways[provGraph[pos][x]][0] % 1000000007);
          } else if (current == dp[pos][take]) {
            ways[pos][take] += (ways[provGraph[pos][x]][0] % 1000000007);
            ways[pos][take] %= 1000000007;
          }
      }
    }
  }
    ways[pos][take] = max (ways[pos][take], (long long)1);
  return dp[pos][take];
}

int main () {
  set < pair<int, int> >::iterator it;
  memset (dp, -1, sizeof(dp));
  int a, b;
  scanf ("%d %d", &n, &m);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &loot[x]);
  }
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    if (b != a) {
      graph[a].push_back(b);
      revGraph[b].push_back(a);
    }
  }
  for (int x = 1; x <= n; x++) {
    if (!visited[x]) {
      findComponents(x);
    }
  }
  memset(visited, false, sizeof(visited));
  while (stack.size() != 0) {
    if (!visited[stack.back()]) {
      components++;
      findComponents2(stack.back());
    }
    stack.pop_back();
  }
  for (int x = 1; x <= n; x++) {
    for (int i = 0; i < graph[x].size(); i++) {
      if (prov[x] != prov[graph[x][i]]) {
        it = edges.find(make_pair(prov[x], prov[graph[x][i]]));
        if (it == edges.end()) {
          provGraph[prov[x]].push_back(prov[graph[x][i]]);
          edges.insert(make_pair(prov[x], prov[graph[x][i]]));
        }
      }
    }
  }
  long long ans = -1, numberOfWays = 0, ans2, numberOfWays2 = 0;
  
  ans = solve (prov[1], 1);
  numberOfWays = ways[prov[1]][1];
  
  if (solve (prov[1], 0) > ans) {
    ans = solve (prov[1], 0);
    numberOfWays = ways[prov[1]][0];
  } else if (solve (prov[1], 0) == ans) {
    numberOfWays += ways[prov[1]][0];
  }
  cout << ans << " " << numberOfWays << endl;
}
