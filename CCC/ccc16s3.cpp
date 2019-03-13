#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector <int> pho;
vector < vector <int> > graph(100001);
bool useless[100001] = {0}, phoCheck[100001] = {0}, v[100001] = {0};
int dp[100001] = {0}, lp = 0, countUseless = 0;

bool trim (int pos, int parent) {
  bool useful = false;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x] != parent && trim(graph[pos][x], pos)) {
      useful = true;
    }
  }
  if (useful || phoCheck[pos]) {
    return true;
  } else {
    countUseless++;
    useless[pos] = true;
    return false;
  }
}

int longestPath (int pos, int parent) {
  int greatest = 0, secondGreatest = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x] != parent && !useless[graph[pos][x]]) {
      int temp = longestPath (graph[pos][x], pos);
      if (temp > greatest) {
        secondGreatest = greatest;
        greatest = temp;
      } else if (temp > secondGreatest) {
        secondGreatest = temp;
      }
    }
  }
  lp = max (lp, greatest + secondGreatest);
  return (greatest+1);
}

int main () {
  int n, m, a, b;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%d", &a);
    pho.push_back(a);
    phoCheck[a] = true;
  }
  for (int x = 0; x < n-1; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  trim (pho[0], -1);
  longestPath (pho[0], -1);
  cout << (2*(n-countUseless-1)-lp) << endl;
	return 0;
}
