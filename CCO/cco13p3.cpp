#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector < vector <int> > graph(400001);
vector <int> centers;
int lp[400001][2] = {0}, nxt[400001][2] = {0}, diam = 0, start, greatestPath = 400002, deepest = 0, len[400001] = {0};
long long total = 0, runSum = 0, cnt[400001] = {0};

void dfs (int pos, int par) {
  int child;
  for (int x = 0; x < graph[pos].size(); x++) {
    child = graph[pos][x];
    if (child != par) {
      dfs (child, pos);
      if (lp[child][0] > lp[pos][0]) {
        lp[pos][1] = lp[pos][0];
        nxt[pos][1] = nxt[pos][0];
        lp[pos][0] = lp[child][0];
        nxt[pos][0] = child;
      } else if (lp[child][0] > lp[pos][1]) {
        lp[pos][1] = lp[child][0];
        nxt[pos][1] = child;
      }
    }
  }
  lp[pos][0]++;
  if (lp[pos][0] + lp[pos][1] > diam) {
    diam = lp[pos][0] + lp[pos][1];
    start = pos;
  }
}

void findCenters (int pos) {
  while (nxt[pos][0] != 0) {
    if (max(lp[pos][0]-1, diam-lp[pos][0]) < greatestPath) {
      centers.clear();
      centers.push_back(pos);
      greatestPath = max(lp[pos][0]-1, diam-lp[pos][0]);
    } else if (max(lp[pos][0]-1, diam-lp[pos][0]) == greatestPath) {
      centers.push_back(pos);
    }
    pos = nxt[pos][0];
  }
}

void countDeepest (int pos, int par) {
  int child;
  for (int x = 0; x < graph[pos].size(); x++) {
    child = graph[pos][x];
    if (child != par) {
      countDeepest (child, pos);
      if (len[child] > len[pos]) {
        len[pos] = len[child];
        cnt[pos] = cnt[child];
      } else if (len[pos]==len[child]) {
        cnt[pos] += cnt[child];
      }
    }
  }
  len[pos]++;
  cnt[pos] = max (cnt[pos], (long long)1);
}

int main () {
  int n, a, b;
  scanf ("%d", &n);
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs (1, -1);
  findCenters(start);
  if (nxt[start][1] != 0) {
    findCenters(nxt[start][1]);
  }
  if (centers.size() == 2) {
    countDeepest (centers[0], centers[1]);
    countDeepest (centers[1], centers[0]);
    cout << diam << " " << cnt[centers[0]] * cnt[centers[1]] << endl;
  } else {
    for (int x = 0; x < graph[centers[0]].size(); x++) {
      countDeepest (graph[centers[0]][x], centers[0]);
      if (len[graph[centers[0]][x]] == (diam-1)/2) {
        total += runSum*cnt[graph[centers[0]][x]];
        runSum += cnt[graph[centers[0]][x]];
      }
    }
    cout << diam << " " << total << endl;
  }
}
