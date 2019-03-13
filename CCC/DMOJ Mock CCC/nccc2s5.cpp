#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector < pair <int, int> > > mst(1001);
vector < pair < pair <int, int>, pair <int, int> > > edges;
int ds[1001], minW = 1000000001;
int n, m;

void init () {
  for (int x = 1; x <= n; x++) {
    ds[x] = x;
    mst[x].clear();
  }
}

int find (int a) {
  if (ds[a] != a) {
    return ds[a] = find(ds[a]);
  }
  return ds[a];
}

void merge (int a, int b) {
  find (a);
  find (b);
  if (a < b) {
    ds[find(a)] = find(b);
  } else {
    ds[find(b)] = find(a);
  }
}

void buildMST () {
  sort (edges.begin(), edges.end());
  init();
  for (int x = m-1; x >= 0; x--) {
    int a = edges[x].second.first, b = edges[x].second.second, cost = edges[x].first.first;
    if (find(a) != find (b)) {
      merge (a, b);
      mst[a].push_back(make_pair(b, cost));
      mst[b].push_back(make_pair(a, cost));
    }
  }
}

bool query (int pos, int par, int end) {
  if (pos==end) {
    return true;
  } else {
    bool onPath = false;
    for (int x = 0; x < mst[pos].size(); x++) {
      if (mst[pos][x].first != par) {
        if (query (mst[pos][x].first, pos, end)) {
          onPath = true;
          minW = min (minW, mst[pos][x].second);
          break;
        }
      }
    }
    return onPath;
  }
}

int main() {
  int a, b, c, q, t;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    edges.push_back(make_pair(make_pair(c, x+1), make_pair(a, b)));
  }
  buildMST ();
  scanf ("%d", &q);
  while (q--) {
    scanf ("%d", &t);
    if (t==1) {
      scanf ("%d %d", &a, &b);
      for (int x = 0; x < edges.size(); x++) {
        
        if (edges[x].first.second==a) {
          edges[x].first.first = b;
          break;
        }
      }
      buildMST ();
    } else {
      minW = 1000000001;
      scanf ("%d %d %d", &a, &b, &c);
      query (a, -1, b);
      if (minW < c || minW==1000000001) {
        printf ("0\n");
      } else {
        printf ("1\n");
      }
    }
  }
}
