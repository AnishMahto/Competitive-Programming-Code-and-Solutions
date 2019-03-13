#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

int n, k[200001], blockId[200001], nextNode[200001] = {0}, jumpsToNextBlock[200001] = {0};
bitset<100001> visited;

void build (int pos, int orig) {
  if (pos > n || blockId[pos] != blockId[orig]) {
    nextNode[orig] = pos;
  } else {
    jumpsToNextBlock[orig]++;
    build (pos + k[pos], orig);
  }
  return;
}

int query (int pos) {
  int jumps = 0;
  while (pos <= n) {
    jumps += jumpsToNextBlock[pos];
    pos = nextNode[pos];
  }
  return jumps;
}

void modify (int pos, int val) {
  visited.reset();
  int delta = jumpsToNextBlock[pos], pos2 = pos-1;
  k[pos] = val;
  jumpsToNextBlock[pos] = 0;
  build (pos, pos);
  delta = jumpsToNextBlock[pos] - delta; //the sum of previous nodes affected by this node will change by this value
  visited.set(pos);
  while (pos2 > 0 && blockId[pos2] == blockId[pos]) {
    if (visited.test(pos2+k[pos2])) {
      nextNode[pos2] = nextNode[pos];
      jumpsToNextBlock[pos2] += delta;
      visited.set(pos2);
    }
    pos2--;
  }
}

int main () {
  int q, a, v, cmd, blocks;
  scanf ("%d", &n);
  blocks = sqrt((double)n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &k[x]);
    blockId[x] = ceil((double)x/(double)blocks);
  }
  for (int x = 1; x <= n; x++) {
    build (x, x);
  } 
  scanf ("%d", &q);
  while (q--) {
    scanf ("%d %d", &cmd, &a);
    if (cmd==2) {
      scanf ("%d", &v);
      modify(a+1, v);
    } else {
      printf ("%d\n", query(a+1));
    }
  }
}
