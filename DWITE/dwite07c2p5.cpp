#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector < pair <int, int> > edges;
vector < vector < pair <int, int> > > graph(101);
int sz = 0, cnt = 0;
bool visited[101] = {0};

int count (int pos, int del) {
  visited[pos] = true;
  cnt++;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].second != del && !visited[graph[pos][x].first]) {
      count (graph[pos][x].first, del);
    }
  }
}

int main () {
  int n, m, a, b;
  for (int x = 1; x <= 5; x++) {
    edges.clear();
    for (int i = 1; i <= 100; i++) {
      graph[i].clear();
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      graph[a].push_back(make_pair(b, i));
      graph[b].push_back(make_pair(a, i));
      edges.push_back(make_pair(a, b));
    }
    int br = 0;
    for (int i = 0; i < m; i++) {
      memset (visited, 0, sizeof(visited));
      cnt = 0;
      count (1, i);
      if (cnt != n) {
        br++;
      }
    }
    cout << br << endl;
  }
}
