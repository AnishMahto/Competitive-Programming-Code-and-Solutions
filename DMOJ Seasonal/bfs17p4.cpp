#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

vector < vector <int> > graph(100001);
int n, treeSize[100001] = {0}, maxWa[100001] = {0}, minWa[100001] = {0};
char type[100001];
bool root[100001] = {0};

int calcSize (int pos) {
  for (int x = 0; x < graph[pos].size(); x++) {
    treeSize[pos] += calcSize(graph[pos][x]);
  }
  treeSize[pos]++;
  return treeSize[pos];
}

int solve (int pos) {
  if (graph[pos].size() == 0) {
    if (type[pos] == 'A') {
      maxWa[pos] = minWa[pos] = 1;
    } else if (type[pos] == '?') {
      maxWa[pos] = 1;
    }
  }
  int sumMaxWa = 0, sumMinWa = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    solve (graph[pos][x]);
    sumMinWa += minWa[graph[pos][x]];
    sumMaxWa += maxWa[graph[pos][x]];
  }
  if (type[pos] == 'C') {
    maxWa[pos]++;
    minWa[pos]++;
    //if AC, all wa's collected by sum are same
    minWa[pos] = sumMinWa;
    maxWa[pos] = sumMaxWa;
  } else if (type[pos] == '?') {
    //                if wa                   if ac
    maxWa[pos] = max(treeSize[pos] - sumMinWa, sumMaxWa);
    minWa[pos] = min(treeSize[pos] - sumMaxWa, sumMinWa);
  } else {
    maxWa[pos] = treeSize[pos] - sumMinWa;
    minWa[pos] = treeSize[pos] - sumMaxWa;
  }  
}

int main () {
  int p;
  char cmd, tmp;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf (" %c", &cmd);
    if (cmd =='C') {
      root[x] = true;
      scanf (" %c", &type[x]);
      if (type[x] != '?') {
        scanf (" %c", &type[x]);
      }
    } else {
      scanf ("%d", &p);
      scanf (" %c", &type[x]);
      if (type[x] != '?') {
        scanf (" %c", &type[x]);
      }
      graph[p].push_back(x);
    }
  }
  
  for (int x = 1; x <= n; x++) {
    if (root[x]) {
      calcSize(x);
    }
  }
  for (int x = 1; x <= n; x++) {
    if (root[x]) {
      solve(x);
    }
  }
  int least = 0, greatest = 0;
  for (int x= 1; x <= n; x++) {
    if (root[x]) {
      least += minWa[x];
      greatest += maxWa[x];
    }
  }
  printf ("%d %d\n", least, greatest);
}
