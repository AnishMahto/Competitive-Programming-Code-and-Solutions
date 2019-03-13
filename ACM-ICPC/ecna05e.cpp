#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

vector < vector <int> > edges;
bool cutEdges = false;
vector < vector <int> > graph(16);
int n, m, leastCost = 1000000000, count = 0, childOfOne = 0;
int depth[16] = {0}, furthestBack[16];
bool visited[16] = {0};
vector <int> order;

int lowlink (int pos, int par) {
  depth[pos] = depth[par] + 1;
  visited[pos] = true;
  count++;
  furthestBack[pos] = 1000000;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (!visited[graph[pos][x]]) {
      if (pos == 1) {
        childOfOne++;
      }
      furthestBack[pos] = min (furthestBack[pos], lowlink (graph[pos][x], pos));
    } else if (graph[pos][x] != par) {
      furthestBack[pos] = min (furthestBack[pos], depth[graph[pos][x]]);
    }
  }
  if ((pos==1 && furthestBack[pos] > depth[pos]) || (pos != 1 && furthestBack[pos] >= depth[pos])) {
    cutEdges = true;
  }
  return furthestBack[pos];
}

void generate (int pos, vector <int> e) {
  if (pos==edges.size()) {
    count = 0;
    childOfOne = 0;
    cutEdges = false;
    int cost = 0;
    for (int x = 0; x < 16; x++) {
      visited[x] = false;
      furthestBack[x] = 1000000;
      graph[x].clear();
    }
    for (int x = 0; x < e.size(); x++) {
      graph[edges[e[x]][0]].push_back(edges[e[x]][1]);
      graph[edges[e[x]][1]].push_back(edges[e[x]][0]);
      cost += edges[e[x]][2];
    }
    //check cut edges;
    lowlink(1, 0);
    if (!cutEdges && count==n) {
      leastCost = min (leastCost, cost);
    }
  } else if (pos < edges.size()) {
    generate (pos+1, e);
    e.push_back(pos);
    generate (pos+1, e);
  }
}

int main () {
  vector <int> temp;
  int a, b, c, t = 1;
  scanf ("%d %d", &n, &m);
  while (n != 0 || m != 0) {
    edges.clear();
    leastCost = 1000000000;
    for (int x = 0; x < m; x++) {
      temp.clear();
      scanf ("%d %d %d", &a, &b, &c);
      temp.push_back(a);
      temp.push_back(b);
      temp.push_back(c);
      edges.push_back(temp);
    }
    temp.clear();
    generate (0, temp);
    if (leastCost != 1000000000) {
      printf ("The minimal cost for test case %d is %d.\n", t, leastCost);
    } else {
      printf ("There is no reliable net possible for test case %d.\n", t);
    }
    scanf ("%d %d", &n, &m);
    t++;
  }
}
