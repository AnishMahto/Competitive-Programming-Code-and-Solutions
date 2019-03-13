#include <iostream>
#include <cstdio>
using namespace std;

int n, segTree[30001*4], lazy[4*30001] = {0}, nums[30001];

int build (int pos, int l, int r) {
  int mid = l + (r-l)/2;
  if (l == r) {
    segTree[pos] = nums[l];
  } else {
    segTree[pos] = min (build (2*pos, l, mid), build (2*pos+1, mid+1, r));
  }
  return segTree[pos];
}

int query (int pos, int l, int r, int tl, int tr) {
  int mid = l + (r-l)/2;
  if (lazy[pos] != 0) {
    segTree[pos] -= lazy[pos];
    segTree[pos] = max (segTree[pos], 0);
    if (l != r) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (l > r || r < tl || l > tr) {
    return 2000000000;
  } else if (l >= tl && r <= tr) {
    return segTree[pos];
  }
  return min (query(2*pos, l, mid, tl, tr), query(2*pos+1, mid+1, r, tl, tr));
} 

int subtract (int pos, int l, int r, int tl, int tr, int val) {
  int mid = l + (r-l)/2;
  if (lazy[pos] != 0) {
    segTree[pos] -= lazy[pos];
    segTree[pos] = max (segTree[pos], 0);
    if (l != r) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (l > r || r < tl || l > tr) {
    if (l > r) {
      return 2000000000;
    } else {
      return segTree[pos];
    }
  } else if (l >= tl && r <= tr) {
    segTree[pos] -= val;
    segTree[pos] = max (segTree[pos], 0);
    if (l != r) {
      lazy[2*pos] += val;
      lazy[2*pos+1] += val;
    }
    return segTree[pos];
  } else {
    segTree[pos] = min (subtract(2*pos, l, mid, tl, tr, val), subtract(2*pos+1, mid+1, r, tl, tr, val));
  }
  return segTree[pos];
}

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int q, a, b, c;
  scanf ("%d %d", &n, &q);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &nums[x]);
  }
  build (1, 1, n);
  for (int x = 0; x < q; x++) {
    scanf ("%d %d %d", &a, &b, &c);
    subtract (1, 1, n, a, b, c);
    printf ("%d %d\n", query (1, 1, n, a, b), segTree[1]);
  }
}
