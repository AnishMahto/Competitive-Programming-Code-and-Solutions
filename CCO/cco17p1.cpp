#include <iostream>
#include <vector>
using namespace std;

int nodes = 1;
vector < pair <int, int> > edges;

int cycle (int pos, int left, bool first, int chain) {
  if (left == 0) {
    edges.push_back(make_pair(nodes, chain));
    return 0;
  }
  if (first) {
    edges.push_back(make_pair(chain, pos));
  } else {
    nodes++;
    edges.push_back(make_pair(nodes-1, nodes));
  }
  cycle (nodes, left - 1, false, chain);
}

int main () {
  int n;
  cin >> n;
  while (n != 0) {
    int temp = 1, count = 1, add = 2;
    while (temp + add <= n) {
      temp += add;
      add++;
      count++;
    }
    nodes++;
    edges.push_back(make_pair(1, nodes));
    nodes++;
    n -= temp;
    cycle (nodes, count, true, nodes-1);
  }
  cout << nodes << " " << edges.size() << endl;
  for (int x = 0; x < edges.size(); x++) {
    cout << edges[x].first << " " << edges[x].second << endl;
  }
}
