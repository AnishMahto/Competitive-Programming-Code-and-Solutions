#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

set < pair<int, int> > edge;
vector < vector <int> > graph(200001);
vector <int> top;
int level[200001] = {0}, n, m, indeg[200001] = {0}, indeg2[200001] = {0}, levels = 0;
bool kill[200001] = {0}, rem[200001] = {0}, type[200001][2], fire = false, bullet = false;
priority_queue < pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > q;

int kahnZero (int deg[200001]) {
  queue <int> zero, one;
  for (int x = 0; x < n; x++) {
    if (indeg[x] == 0) {
      if (kill[x]) {
        one.push(x);
      } else {
        zero.push(x);
      }
    }
  }
  bool current = false;
  int count = 0;
  while (!zero.empty() || !one.empty()) {
    int pos;
    if (current) {
      while (!one.empty()) {
        pos = one.front();
        one.pop();
        for (int x = 0; x < graph[pos].size(); x++) {
          deg[graph[pos][x]]--;
          if (deg[graph[pos][x]] == 0) {
            if (kill[graph[pos][x]]) {
              one.push(graph[pos][x]);
            } else {
              zero.push(graph[pos][x]);
            }
          }
        }
      }
    } else if (!current) {
      while (!zero.empty()) {
        pos = zero.front();
        zero.pop();
        for (int x = 0; x < graph[pos].size(); x++) {
          deg[graph[pos][x]]--;
          if (deg[graph[pos][x]] == 0) {
            if (kill[graph[pos][x]]) {
              one.push(graph[pos][x]);
            } else {
              zero.push(graph[pos][x]);
            }
          }
        }
      }
    }
    count++;
    current = !current;
  }
  count--;
  return count;
}

int kahnOne (int deg[200001]) {
  queue <int> zero, one;
  for (int x = 0; x < n; x++) {
    if (indeg[x] == 0) {
      if (kill[x]) {
        one.push(x);
      } else {
        zero.push(x);
      }
    }
  }
  bool current = true;
  int count = 0;
  while (!zero.empty() || !one.empty()) {
    int pos;
    if (current) {
      while (!one.empty()) {
        pos = one.front();
        one.pop();
        for (int x = 0; x < graph[pos].size(); x++) {
          deg[graph[pos][x]]--;
          if (deg[graph[pos][x]] == 0) {
            if (kill[graph[pos][x]]) {
              one.push(graph[pos][x]);
            } else {
              zero.push(graph[pos][x]);
            }
          }
        }
      }
    } else if (!current) {
      while (!zero.empty()) {
        pos = zero.front();
        zero.pop();
        for (int x = 0; x < graph[pos].size(); x++) {
          deg[graph[pos][x]]--;
          if (deg[graph[pos][x]] == 0) {
            if (kill[graph[pos][x]]) {
              one.push(graph[pos][x]);
            } else {
              zero.push(graph[pos][x]);
            }
          }
        }
      }
    }
    count++;
    current = !current;
  }
  count--;
  return count;
}

int main () {
  set< pair<int,int> >::iterator it;
  int a, b;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < n; x++) {
    scanf ("%d", &kill[x]);
  }
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    it = edge.find(make_pair(a,b));
    if (it == edge.end()) {
      graph[a].push_back(b);
      indeg[b]++;
      indeg2[b]++;
      edge.insert(make_pair(a,b));
    }
  }
  cout << min (kahnZero(indeg), kahnOne(indeg2)) << endl;
}
