#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector < vector <int> > graph(200001);
int dp[200001] = {0};
bool bunny[200001] = {0};
bool visited[200001] = {0};

vector <int> path;
vector < vector <int > > dist(200001);

bool dfs (int pos, int par, int end) {
  if (pos==end) {
    path.push_back(pos);
    return true;
  } else {
    for (int x = 0; x < graph[pos].size(); x++) {
      if (graph[pos][x] != par && dfs (graph[pos][x], pos, end)) {
        path.push_back(pos);
        return true;
      }
    }
  }
  return false;
}

int main () {
  int n, a, b, r;
  scanf ("%d %d", &n, &r);
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int x = 0; x < r; x++) {
    scanf ("%d", &a);
    bunny[a] = true;
    dist[0].push_back(a);
    visited[a] = true;
  }
  scanf ("%d %d", &a, &b);
  for (int x = 0; x < 200001; x++) {
    for (int i = 0; i < dist[x].size(); i++) {
      
      for (int z = 0; z < graph[dist[x][i]].size(); z++) {
        if (!visited[ graph[dist[x][i]][z] ]) {
          visited[ graph[dist[x][i]][z] ] = true;
          dp[ graph[dist[x][i]][z] ] = dp[ dist[x][i] ] + 1;
          dist[x+1].push_back(graph[dist[x][i]][z]);
        }
      }
    }
  }
  dfs (a, -1, b);
  int least = 10000000;
  for (int x = 0; x < path.size(); x++) {
    least = min (least, dp[path[x]]);
  }
  cout << least << endl;
}
