#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int mtx[102][102];
//node 101 is outside all pens
pair <int, int> edgeL[1001][1001];
//part of pen x, weight of edge

int main () {
  priority_queue<pair<int, int> , std::vector< pair<int, int> >, std::greater< pair<int, int> > > minH;
  for (int x = 0; x < 102; x++) {
    for (int i = 0; i < 102; i++) {
      mtx[x][i] = 1000000000;
    }
  }
  int n, k, temp;
  scanf ("%d", &n);
  for (int z = 1; z <= n; z++) {
    scanf ("%d", &k);
    vector <int> e(k);
    for (int x = 0; x < k; x++) {
      scanf ("%d", &e[x]);
    }
    for (int x = 0; x < k-1; x++) {
      scanf ("%d", &temp);
      if (edgeL[e[x]][e[x+1]].first == 0) {
        edgeL[e[x]][e[x+1]].first = edgeL[e[x+1]][e[x]].first = z;
        edgeL[e[x]][e[x+1]].second = edgeL[e[x+1]][e[x]].second = temp;
      } else {
        mtx[z][edgeL[e[x]][e[x+1]].first] = mtx[edgeL[e[x]][e[x+1]].first][z] = min(temp,mtx[edgeL[e[x]][e[x+1]].first][z]);
        edgeL[e[x]][e[x+1]].second = edgeL[e[x+1]][e[x]].second = -1;
      }
    }
    scanf ("%d", &temp);
    if (edgeL[e[0]][e[k-1]].first == 0) {
      edgeL[e[0]][e[k-1]].first = edgeL[e[k-1]][e[0]].first = z;
      edgeL[e[0]][e[k-1]].second = edgeL[e[k-1]][e[0]].second  = temp;
    } else {
      mtx[z][edgeL[e[0]][e[k-1]].first] = mtx[edgeL[e[0]][e[k-1]].first][z] = min(temp,mtx[edgeL[e[0]][e[k-1]].first][z]);
      edgeL[e[0]][e[k-1]].second = edgeL[e[k-1]][e[0]].second = -1;
    }
  }
  for (int x = 1; x <= 1000; x++) {
    for (int i = 1; i <= 1000; i++) {
      if (edgeL[x][i].second > 0) {
        mtx[edgeL[x][i].first][101] = mtx[101][edgeL[x][i].first] = min (mtx[101][edgeL[x][i].first], edgeL[x][i].second);
      }
    }
  }
  bool visited[105] = {0};
  int mst = 0, mst2 = 0;
  //meet inside the same pen
  visited[1] = 1;
  for (int x = 1; x <= n; x++) {
    if (mtx[1][x] != 1000000000) {
      minH.push(make_pair(mtx[1][x], x));
    }
  }
  while (!minH.empty()) {
    int cost = minH.top().first, node = minH.top().second;
    minH.pop();
    if (!visited[node]) {
      mst += cost;
      visited[node] = 1;
      for (int x = 1; x <= n; x++) {
        if (mtx[node][x] != 1000000000 && !visited[x]) {
          minH.push(make_pair(mtx[node][x], x));
        }
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    if (!visited[x]) {
      mst = 10000000000;
      break;
    }
  }
  //meet outside all pens
  memset(visited, 0, sizeof(visited));
  visited[101] = 1;
  for (int x = 1; x <= n; x++) {
    if (mtx[101][x] != 1000000000) {
      minH.push(make_pair(mtx[101][x], x));
    }
  }
  while (!minH.empty()) {
    int cost = minH.top().first, node = minH.top().second;
    minH.pop();
    if (!visited[node]) {
      mst2 += cost;
      visited[node] = 1;
      for (int x = 1; x <= n; x++) {
        if (mtx[node][x] != 1000000000 && !visited[x]) {
          minH.push(make_pair(mtx[node][x], x));
        }
      }
    }
  }
  cout << min (mst, mst2) << endl;
}
