#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool important[203] = {0};
vector < vector <int> > graph(203), revGraph(203);
int e[203][203] = {0}, n, m, revE[203][203] = {0}, parent[203] = {0};
//n+m nodes, boys numbered 1..n, girls numbered n+1...n+m
//source = 0, sink = n+m+1;
bool augment () {
  queue <int> bfs;
  bfs.push(0);
  bool visited[203] = {0};
  visited[0] = true;
  while (!bfs.empty()) {
    int pos = bfs.front();
    bfs.pop();
    for (int x = 0; x < graph[pos].size(); x++) {
      int d = graph[pos][x];
      if (!visited[d] && e[pos][d] > 0) {
        visited[d] = true;
        bfs.push(d);
        parent[d] = pos;
      }
    }
  }
  if (visited[n+m+1]) {
    return true;
  } else {
    return false;
  }
}

int ford () {
  int maxFlow = 0;
  memset(parent, -1, sizeof(parent));
  while (augment()) {
    int flow = 20000001, pos = n+m+1;
    //trace back
    while (pos != 0) {
      flow = min (flow, e[parent[pos]][pos]);
      pos = parent[pos];
    }
    pos = m+n+1;
    while (pos != 0) {
      e[parent[pos]][pos] -= flow;
      e[pos][parent[pos]] += flow;
      pos = parent[pos];
    }
    maxFlow += flow;
  }
  return maxFlow;
}

int main () {
  int t, girl, importantGirlz = 0;
  scanf ("%d %d", &n, &m);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) {
      scanf ("%d", &girl);
      girl += n;
      if (x == 1) {
        important[girl] = 1;
      }
      if (important[girl]) {
        graph[x].push_back(girl);
        graph[girl].push_back(x);
        e[x][girl] = 1;
        revGraph[girl].push_back(x);
      }
    }
    if (x != 1 && graph[x].size() != 0) {
      graph[0].push_back(x);
      e[0][x] = 1;
    }
  }
  for (int x = n+1; x <= n+m; x++) {
    if (important[x]) {
      graph[x].push_back(n+m+1);
      e[x][n+m+1] = 1;
    }
  }
  importantGirlz = graph[1].size();
  printf ("%d\n", importantGirlz - ford());
}
