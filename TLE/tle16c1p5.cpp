#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

long long dp[100001] = {0};
long long psum[100001] = {0}, segTree[4*100001] = {0}, inf = 100001, n, c[100001], segTreePos[4*100001] = {0};
vector < vector <int> > revGraph(100001);
int parent[100001] = {0};
int query (int pos, int l, int r, int tl, int tr, int currentPos) {
  
  if (l > r || r < tl || l > tr) {
    return -1;
  }
  if (l==r) {
    return segTreePos[pos];
  }
  else {
    int mid = l+(r-l)/2;
    int temp1 = query (2*pos+1, mid+1, r, tl, tr, currentPos);
    if (segTree[2*pos+1] < c[currentPos] && temp1 != -1) {
      return temp1;
    } else if (segTree[2*pos] < c[currentPos]) {
      return query (2*pos, l, mid, tl, tr, currentPos);
    } else {
      return -1;
    }
  }
}

int modify (int pos, int l, int r, int tl, int tr, int val, int currentPos) {
  if (l > r) {
    return 100001;
  }
  if (r < tl || l > tr) {
    return segTree[pos];
  }
  if (l == tl && r == tr) {
    segTreePos[pos] = currentPos; //tl = tr
    segTree[pos] = val;
    return val;
  } else {
    int mid = l+(r-l)/2;
    segTree[pos] = min (modify(2*pos, l, mid, tl, tr, val, currentPos), modify(2*pos+1, mid+1, r, tl, tr, val, currentPos));
  }
  return segTree[pos];
}

int solve (int pos, int par, int depth) {
  parent[pos] = par;
  int first;
  if (pos != n) {
    psum[pos] += psum[par];
    // query first value (higher depth index) with smaller cost than current
    first = query (1, 1, n, 1, depth-1, pos);
  }
  if (first <= 0 || first == 100001) {
    dp[pos] = c[pos]*psum[pos];
  } else {
    dp[pos] = (abs(psum[pos] - psum[first]))*c[pos] + dp[first];
  }
  if (revGraph[pos].size() > 0) {
    // add current node to seg tree
    if (pos != n) {
      modify (1, 1, n, depth, depth, c[pos], pos);
    }
  
    for (int x = 0; x < revGraph[pos].size(); x++) {
      solve (revGraph[pos][x], pos, depth+1);
    }
  
    // remove current node from seg tree;
    if (pos != n) {
      modify (1, 1, n, depth, depth, 100001, pos);
    }
  }
}

int main () {
  int p;
  scanf ("%d", &n);
  for (int x = 0; x < 4*(100001); x++) { segTree[x] = inf;}
  for (int x = 1; x < n; x++) {
    scanf ("%d %lld %lld", &p, &psum[x], &c[x]);
    revGraph[p].push_back(x);
  }
  solve (n, -1, 1);
  for (int x = 1; x < n; x++) {
    printf ("%lld\n", dp[x]);
  }
}
