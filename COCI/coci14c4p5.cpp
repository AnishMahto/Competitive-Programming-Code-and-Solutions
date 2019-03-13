#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool party[200001] = {0};
vector < vector <int> > graph(200001);

int collisions (int pos) {
  int cols = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (party[graph[pos][x]] == party[pos]) {
      if (x==0 && party[pos]==party[graph[pos][x]]) {
        cols++;
      }
      for (int i = x-1; i >= 0; i--) {
        if (graph[pos][x]==graph[pos][i]) {
          //already counted
          break;
        } else if (i==0) {
          cols++;
        }
      }
    }
  }
  return cols;
}

int main() {
  int n, args, a, b;
  scanf ("%d", &n);
  for (int o = 0; o < 5; o++) {
    scanf ("%d", &args);
    for (int x = 0; x < args; x++) {
      scanf ("%d %d", &a, &b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
  }
  bool done = false;
  while (!done) {
    done = true;
    for (int x = 1; x <= n; x++) {
      if (collisions(x) > 2) {
        done = false;
        party[x] = !party[x];
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    if (party[x]) {
      printf ("A");
    } else {
      printf ("B");
    }
  }
}
