#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int w[1000001], v[1000001];
long long seg[4*1000001] = {0};
vector <int> compress;

long long update (int pos, int l, int r, int tl, int tr, long long val) {
  if (l > r || l > tr || r < tl) {
    return seg[pos];
  } else if (l >= tl && r <= tr) {
    seg[pos] = max (seg[pos], val);
  } else {
    int mid = (l+r)/2;
    seg[pos] = max (update (2*pos, l, mid, tl, tr, val), update (2*pos+1, mid+1, r, tl, tr, val));
  }
  return seg[pos];
}

long long query (int pos, int l, int r, int tl, int tr) {
  if (l > r || l > tr || r < tl) {
    return -1;
  } else if (l >= tl && r <= tr) {
    return seg[pos];
  } else {
    int mid = (l+r)/2;
    return max (query (2*pos, l, mid, tl, tr), query (2*pos+1, mid+1, r, tl, tr));
  }
}

int main() {
  int n;
  vector <int> clean;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &w[x]);
    clean.push_back(w[x]);
  }
  sort (clean.begin(), clean.end());
  compress.push_back(-1);
  for (int x = 0; x < clean.size(); x++) {
    if (x==0 || clean[x] != clean[x-1]) {
      compress.push_back(clean[x]);
    }
  }
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &v[x]);
  }
  vector <int>::iterator it;
  int pos, sz = compress.size()-1;
  long long dp;
  for (int x = 1; x <= n; x++) {
    it = lower_bound (compress.begin(), compress.end(), w[x]);
    pos = it - compress.begin();
    if (pos < sz) {
      dp = v[x] + query (1, 1, sz, pos+1, sz);
      update (1, 1, sz, pos, pos, dp);
    } else {
      update (1, 1, sz, pos, pos, v[x]);
    }
  }
  printf ("%lld\n", seg[1]);
}
