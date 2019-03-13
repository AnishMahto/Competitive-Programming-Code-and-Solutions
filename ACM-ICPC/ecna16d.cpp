#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

map <string, int> conv;
vector < pair <int, pair <int, int> > > edges;
vector < vector < pair <int, int> > > graph(105);
int distFromOne[101] = {0}, total = 0;
bool visited[101] = {0};

int main() {
  int totalCost = 0;
  map <string, int>::iterator it, it2;
  int n, m, idx = 1, c;
  cin >> n >> m;
  conv.insert (make_pair("English", 1));
  string in, in2;
  for (int x = 0; x < n; x++) {
    cin >> in;
    idx++;
    conv.insert (make_pair(in, idx));
  }
  for (int x = 0; x < m; x++) {
    cin >> in >> in2 >> c;
    it = conv.find(in);
    it2 = conv.find(in2);
    graph[it->second].push_back(make_pair(c, it2->second));
    graph[it2->second].push_back(make_pair(c, it->second));
  }
  visited[1] = true;
  priority_queue <pair < pair <int, int>, int>, vector< pair < pair <int, int>, int> >, greater< pair < pair <int, int>, int> > > pq;
  //distance from 1, cost of edge, destination
  for (int x = 0; x < graph[1].size(); x++) {
    int dest = graph[1][x].second, cost = graph[1][x].first, dist = distFromOne[1]+1;
    pq.push(make_pair(make_pair(dist, cost), dest));
  }
  while (!pq.empty()) {
    int dest = pq.top().second, cost = pq.top().first.second, dist = pq.top().first.first;
    pq.pop();
    if (!visited[dest]) {
      total++;
      visited[dest] = true;
      distFromOne[dest] = dist;
      totalCost += cost;
      for (int x = 0; x < graph[dest].size(); x++) {
        cost = graph[dest][x].first;
        dist = distFromOne[dest] + 1;
        pq.push(make_pair(make_pair(dist, cost), graph[dest][x].second));
      }
    }
  }
  if (total == n) {
    cout << totalCost << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
