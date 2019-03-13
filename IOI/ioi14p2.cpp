#include <iostream>
#include <string.h>
using namespace std;

int down[4*2000001], up[4*2000001] = {0}, inf = 2147483647, ans[2000001] = {0};

int comb (int pos, int u, int d) {
  down[pos] = min (down[pos], d);
  down[pos] = max (down[pos], u);
  up[pos] = max (up[pos], u);
  up[pos] = min (up[pos], d);
}

int solve (int pos, bool cmd, int val) {
  if (cmd) {
    down[pos] = min (down[pos], val);
    up[pos] = min (up[pos], val);
  } else {
    down[pos] = max (down[pos], val);
    up[pos] = max (up[pos], val);
  }
}

void update (int pos, int l, int r, int tl, int tr, int val, bool cmd) {
  if (l > r || r < tl || l > tr) {
    return;
  } else if (l >= tl && r <= tr) {
    solve(pos, cmd, val);
  } else {
    comb (2*pos, up[pos], down[pos]);
    comb (2*pos+1, up[pos], down[pos]);
    up[pos] = 0;
    down[pos] = inf;
    int mid = l+(r-l)/2;
    update (2*pos, l, mid, tl, tr, val, cmd);
    update (2*pos+1, mid+1, r, tl, tr, val, cmd);
  }
}

void update2 (int pos, int l, int r) {
  if (l > r) {
    return;
  } else if (l == r) {
    ans[l] = min (down[pos], up[pos]);
  } else {
    comb (2*pos, up[pos], down[pos]);
    comb (2*pos+1, up[pos], down[pos]);
    up[pos] = 0;
    down[pos] = inf;
    int mid = l+(r-l)/2;
    update2 (2*pos, l, mid);
    update2 (2*pos+1, mid+1, r);
  }
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
  for (int x = 0; x < 4*2000001; x++) {down[x] = inf;}
  for (int x = 0; x < k; x++) {
    if (op[x] == 1) {
      update (1, 0, n-1, left[x], right[x], height[x], 0);
    } else {
      update (1, 0, n-1, left[x], right[x], height[x], 1);
    }
  }
  update2(1, 0, n-1);
  for (int x = 0; x < n; x++) {
    finalHeight[x] = ans[x];
  }
}

int main () {
  
}
