#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n, s, startD, endD, furthest = 0, node;
vector < vector <int> > graph(5001);
vector <int> bfsOrder;
int p[5001] = {0};
bool v[5001] = {0}, v2[5001] = {0};

void mark (int pos, int step) {
  v[pos] = v2[pos] = true;
  if (step==0) {
    return;
  }
  for (int x = 0; x < graph[pos].size(); x++) {
    if (!v2[graph[pos][x]]) {
      mark (graph[pos][x], step-1);
    }
  }
}

void climb (int pos, int up, int d) {
  if (up == 0 || p[pos] == -1) {
    mark (pos, d);
  } else {
    climb (p[pos], up-1, d);
  }
}

void findFurthest (int pos, int par, int step) {
  if (step > furthest) {
    furthest = step;
    node = pos;
  }
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x] != par) {
      findFurthest (graph[pos][x], pos, step+1);
    }
  }
  return;
}

void bfs () {
  bool visited[5001] = {0};
  visited[endD] = true;
  p[endD] = -1;
  queue <int> q;
  q.push(endD);
  while (!q.empty()) {
    int pos = q.front();
    bfsOrder.push_back(pos);
    q.pop();
    for (int x = 0; x < graph[pos].size(); x++) {
      if (!visited[graph[pos][x]]) {
        visited[graph[pos][x]] = true;
        q.push(graph[pos][x]);
        p[graph[pos][x]] = pos;
      }
    }
  }
}

int possible (int d) {
  memset (v, 0, sizeof(v));
  int total = 0;
  for (int x = n-1; x >= 0; x--) {
    if (!v[bfsOrder[x]]) {
      memset (v2, 0, sizeof(v2));
      climb (bfsOrder[x], d, d);
      total++;
    }
  }
  return total;
}

int main() {
  int a, b;
  scanf ("%d %d", &n, &s);
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  findFurthest (1, -1, 0);
  startD = node;
  furthest = 0;
  findFurthest (startD, -1, 0);
  endD = node;
  bfs();
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo+hi)/2;
    if (possible (mid) <= s) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  cout << lo << endl;
}
