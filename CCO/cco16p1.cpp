#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector < vector <int> > graph(1000001);
int size = 0, edges = 0;
bool visited[1000001] = {0};
int ds[1000001], sz[1000001];

int find (int a) {
  if (ds[a] != a) {
    ds[a] = find (ds[a]);
  }
  return ds[a];
}

void merge (int a, int b) {
  find (a);
  find (b);
  if (sz[find(a)] >= sz[find(b)]) {
    sz[find(a)] += sz[find(b)];
    ds[find(b)] = find (a);
  } else {
    sz[find(b)] += sz[find(a)];
    ds[find(a)] = find (b);
  }
}

int main () {
  // if two people are in the same set already upon merge, this means cycle
  // otherwise there shouldnt be any merge errors
  
  int n, m, k, a, b;
  int cuts = 0, kids = 0;
  scanf ("%d %d %d", &n, &m, &k);
  for (int x = 1; x <= n; x++) {
    ds[x] = x;
    sz[x] = 1;
  }
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    //graph[a].push_back(b);
    //graph[b].push_back(a);
    if (find (a) != find (b)) {
      //acyclic group thus far
      merge (a, b);
    } else {
      //cycle is formed
      if (sz[find(a)] >= k) {
        if (sz[find(a)] == k) {
          kids += sz[find(a)];
        } else {
          cuts++; //cut to become acyclic
          if (sz[find(a)]%k==0) {
            cuts += sz[find(a)]/k-1;
          } else {
            cuts += sz[find(a)]/k;
          }
          kids += sz[find(a)]/k * k;
        }
      }
      visited[find(a)] = true;
    }
  }
  for (int x = 1; x <= n; x++) {
    if (!visited[find(x)] && sz[find(x)] >= k) {
      visited[find(x)] = true;
      if (sz[find(x)]%k==0) {
          cuts += sz[find(x)]/k-1;
        } else {
          cuts += sz[find(x)]/k;
        }
        kids += sz[find(x)]/k * k;
    }
  }
  cout << kids << " " << cuts << endl;
}
