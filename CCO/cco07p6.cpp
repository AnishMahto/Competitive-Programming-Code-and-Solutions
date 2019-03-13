#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <math.h>
using namespace std;

vector < vector <int> > graph (1001), tree(1001);
int inEcc[1001] = {0}, eccs = 0, esc[1001] = {0}, depth[1001] = {0};
bool v[1001] = {0};
vector < pair <int, int> > bridges;
deque <int> q;

int dfs (int pos, int par) {
  v[pos] = true;
  if (pos!=1) {
    depth[pos] = depth[par] + 1;
  } else {
    depth[pos] = 1;
  }
  q.push_back(pos);
  esc[pos] = depth[pos];
  for (int x = 0; x < graph[pos].size(); x++) {
    if (!v[graph[pos][x]]) {
      esc[pos] = min (esc[pos], dfs (graph[pos][x], pos));
    } else if (graph[pos][x] != par) {
      esc[pos] = min (esc[pos], depth[graph[pos][x]]);
    }
  }
  if (depth[pos]==esc[pos]) {
    eccs++;
    while (q.back() != pos) {
      inEcc[q.back()] = eccs;
      q.pop_back();
    }
    q.pop_back();
    inEcc[pos] = eccs;
    if (pos != 1) {
      bridges.push_back(make_pair(par, pos));
    }
  }
  return esc[pos];
}

int main() {
  int n, m, a, b;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs (1, -1);
  for (int x = 0; x < bridges.size(); x++) {
    tree[inEcc[bridges[x].first]].push_back(inEcc[bridges[x].second]);
    tree[inEcc[bridges[x].second]].push_back(inEcc[bridges[x].first]);
  }
  int leaves = 0;
  for (int x = 0; x < tree.size(); x++) {
    if (tree[x].size()==1) {
      leaves++;
    }
  }
  cout << (int)ceil((double)leaves/(double)2) << endl;
}
