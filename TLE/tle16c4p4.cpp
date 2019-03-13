#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

long long longestPaths[100001][2] = {0}, diameter = 0, sumOfDiams = 0, nextNode[100001][2] = {0}, diamNode = 0, minimizedDist = -1, center, greatestCenter, greatestCenterVal = 0;
bool calculated[100001] = {0};
vector < vector < pair <int, int> > > graph(100001);
vector <int> centers;
int n, m, q;

long long diam (int pos, int par) {
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      long long len = diam (graph[pos][x].first, pos) + graph[pos][x].second;
      for (int i = 0; i < 2; i++) {
        if (len > longestPaths[pos][i]) {
          
          if (i == 0) {
            nextNode[pos][1] = nextNode[pos][0];
            longestPaths[pos][1] = longestPaths[pos][0];
          }
          
          nextNode[pos][i] = graph[pos][x].first;
          longestPaths[pos][i] = len;
          break;
        }
      }
    }
  }
  calculated[pos] = 1;
  diameter = max (diameter, longestPaths[pos][0] + longestPaths[pos][1]);
  if (diameter == (longestPaths[pos][0] + longestPaths[pos][1])) {
    diamNode = pos;
  }
  return longestPaths[pos][0];
}

void findCenter (int pos, int par) {
  if (pos == 0) {
    return;
  }
  if (pos == diamNode) {
    if (minimizedDist==-1 || max (longestPaths[pos][0], diameter-longestPaths[pos][0]) < minimizedDist) {
      minimizedDist = max (longestPaths[pos][0], diameter-longestPaths[pos][0]);
      center = pos;
    }
    findCenter (nextNode[pos][0], pos);
    findCenter (nextNode[pos][1], pos);
  } else {
    if (minimizedDist==-1 || max (longestPaths[pos][0], diameter-longestPaths[pos][0]) < minimizedDist) {
      minimizedDist = max (longestPaths[pos][0], diameter-longestPaths[pos][0]);
      center = pos;
    } 
    findCenter (nextNode[pos][0], pos);
  }
}

int main () {
  long long sumOfMaxMinLen = 0;
  scanf ("%d %d %d", &n, &m, &q);
  int a, b, c;
  for (int x = 0; x < m; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  int components = 0;
  if (q==1) {
    for (int x = 1; x <= n; x++) {
      if (!calculated[x]) {
        diameter = 0;
        diam (x, -1);
        sumOfDiams += diameter;
        components++;
      }
    }
    printf ("%lld\n", (sumOfDiams + components-1));
  } else {
    for (int x = 1; x <= n; x++) {
      if (!calculated[x]) {
        diameter = 0;
        minimizedDist = -1;
        diam (x, -1);
        components++;
        findCenter (diamNode, -1);
        centers.push_back(center);
        if (minimizedDist >= greatestCenterVal) {
          greatestCenterVal = minimizedDist;
          greatestCenter = center;
        }
      }
    }
    for (int x = 0; x < centers.size(); x++) {
      if (centers[x] != greatestCenter) {
        graph[greatestCenter].push_back(make_pair(centers[x], 1));
        graph[centers[x]].push_back(make_pair(greatestCenter, 1));
      }
    }
    memset(longestPaths, 0, sizeof(longestPaths));
    memset(nextNode, 0, sizeof(nextNode));
    minimizedDist = -1;
    diamNode = diameter = 0;
    diam (1, -1);
    findCenter(diamNode, -1);
    printf ("%lld\n", minimizedDist);
  }
}
