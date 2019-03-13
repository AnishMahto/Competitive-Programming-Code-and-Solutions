#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int jumps = (int)ceil(log(300001)/log(2)); //(int)ceil(log(300001)/log(2)) = smallest power of 2 that is greater than or equal to the number of nodes in the tree
int parent[300001] = {0}, top[300001] = {0}, level[300001] = {0}, skip[300001][22+1] = {0};
int dup[300001];
void addNode (int pos, int par) {
  skip[pos][0] = par;
  int powerOf = 1;
  //while loop runs at most log n times, so adding is log n
  while (skip[skip[pos][powerOf-1]][powerOf-1] != -1 && powerOf <= jumps) {
    skip[pos][powerOf] = skip[skip[pos][powerOf-1]][powerOf-1];
    powerOf++;
  }
}
void copyNode (int copycat, int org) {
  int powerOf = 0;
  //while loop runs at most log n times, so adding is log n
  while (skip[org][powerOf] != -1 && powerOf <= jumps) {
    skip[copycat][powerOf] = skip[org][powerOf];
    powerOf++;
  }
}

int getLca (int pos, int jump) {
  while (jump > 0) {
    pos = skip[pos][(int)(log(jump & (-jump))/log(2))];
    jump -= jump & (-jump);
  }
  return parent[pos];
}

int findLca (int a, int b, int jump) {
  int aPos = a, bPos = b;
  int temp = 0;
  while (jump != -1) {
    if (skip[aPos][jump] != skip[bPos][jump]) {
      aPos = skip[aPos][jump]; bPos = skip[bPos][jump];
      temp += pow(2,jump);
    }
    jump--;
  }
  return getLca(a, temp);
}

int lca (int a, int b) {
  int catchUp = max(level[a], level[b]) - min(level[a], level[b]);
  int pos = (level[a] < level[b]) ? b:a, higherPos;
  if (pos == a) {
    higherPos = b;
  } else {
    higherPos = a;
  }
  while (catchUp > 0) {
    pos = skip[pos][(int)(log(catchUp & (-catchUp))/log(2))];
    catchUp -= catchUp & (-catchUp);
  }
  int start;
  for (int x = jumps; x >= 0; x--) {
    if (skip[pos][x] != -1) {
      start = x;
      break;
    }
  }
  if (higherPos == pos) {
    return higherPos;
  }
  return findLca(higherPos, pos, start);
}

int main () {
  memset(skip, -1, sizeof(skip));
  memset(dup, -1, sizeof(dup));
  char cmd;
  int n, v, w;
  parent[0] = -1;
  top[0] = -1;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf (" %c ", &cmd);
    if (cmd == 'a') {
      scanf ("%d", &v);
      if (dup[v] != -1) {
        v = dup[v];
      }
      level[x] = level[v]+1; //level below, as it is child
      top[x] = x;
      parent[x] = v;
      addNode(x, parent[x]);
    } else if (cmd == 'b') {
      scanf ("%d", &v);
      if (dup[v] != -1) {
        v = dup[v];
      }
      dup[x] = parent[v];
      printf ("%d\n", top[v]);
    } else {
      scanf ("%d %d", &v, &w);
      if (dup[v] != -1) {
        v = dup[v];
      }
      if (dup[w] != -1) {
        w = dup[w];
      }
      dup[x] = v;
      if (v == w) {
        printf ("%d\n", level[v]);
        continue;
      }
      printf ("%d\n", level[lca(v, w)]);
    }
  }
}
