#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int ds[100001], greatest = 0;
vector < pair < pair <int, int>, pair <int, int> > > edges;

int find (int a) {
  if (ds[a] != a) {
    ds[a] = find (ds[a]);
  }
  return ds[a];
}

void merge (int a, int b) {
  int parA = find (a), parB = find (b);
  ds[parB] = parA;
}

int main () {
  int n, m, d, a, b, c, days = 0;
  scanf ("%d %d %d", &n, &m, &d);
  for (int x = 1; x <= n; x++) {
    ds[x] = x;
  }
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    edges.push_back(make_pair(make_pair(c, 0), make_pair (a, b)));
  }
  for (int x = 0; x < m-(n-1); x++) {
    scanf ("%d %d %d", &a, &b, &c);
    edges.push_back(make_pair(make_pair(c, 1), make_pair (a, b)));
  }
  sort (edges.begin(), edges.end());
  for (int x = 0; x < edges.size(); x++) {
    if (find (edges[x].second.first) != find (edges[x].second.second)) {
      if (edges[x].first.second!=0) {
        days++;
      }
      merge (edges[x].second.first, edges[x].second.second);
      greatest = edges[x].first.first;
    }
  }
  for (int x = 1; x <= n; x++) {
    ds[x] = x;
  }
  for (int x = 0; x < edges.size(); x++) {
    if (find (edges[x].second.first) != find (edges[x].second.second)) {
      if (edges[x].first.first < greatest || (edges[x].first.first==greatest && edges[x].first.second==0)) {
        merge (edges[x].second.first, edges[x].second.second);
      } else if (edges[x].first.first <= d && edges[x].first.second==0) {
        cout << days-1 << endl;
        return 0;
      }
    }
  }
  cout << days << endl;
}
