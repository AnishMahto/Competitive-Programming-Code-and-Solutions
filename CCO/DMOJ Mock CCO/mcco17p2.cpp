#include <iostream>
#include <cstdio>
#include <string.h>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
long long seg[2000001], lazy[2000001];

long long update (int pos, int l, int r, int tl, int tr, int val) {
  int mid = l + (r-l)/2;
  if (lazy[pos] != 0) {
    if (l!=r) {
      lazy[pos*2] += lazy[pos];
      lazy[pos*2+1] += lazy[pos];
    }
    seg[pos] += lazy[pos];
    lazy[pos] = 0;
  }
  if (l > r) {
    return 0;
  } else if (l > tr || r < tl) {
    return seg[pos];
  }
  if (l >= tl && r <= tr) {
    if (l!=r) {
      lazy[pos*2] += val;
      lazy[pos*2+1] += val;
    }
    seg[pos] += val;
    return seg[pos];
  }
  seg[pos] = max (update(pos*2, l, mid, tl, tr, val), update(pos*2+1, mid+1, r, tl, tr, val));
  return seg[pos];
}

long long query (int pos, int l, int r, int tl, int tr) {
  if (l > tr || r < tl || l > r) {
    return 0;
  }
  if (lazy[pos] != 0) {
    if (l!=r) {
      lazy[pos*2] += lazy[pos];
      lazy[pos*2+1] += lazy[pos];
    }
    seg[pos] += lazy[pos];
    lazy[pos] = 0;
  }
  if (l >= tl && r <= tr) {
    return seg[pos];
  }
  int mid = l + (r-l)/2;
  return max (query(2*pos, l, mid, tl, tr), query(2*pos+1, mid+1, r, tl, tr));
}

int main () {
  memset(seg, 0, sizeof(seg));
  memset(lazy, 0, sizeof(lazy));
  int n, k, q, c, a, b;
  scanint(n); scanint(k); scanint(q);
  for (int x = 0; x < q; x++) {
    scanint(c); scanint(a); scanint(b);
    if (c == 0) {
      update (1, 0, n-1, max(0, a-k+1), min(a, n-1), b);
    } else {
      printf ("%lld\n", query (1, 0, n-1, min(a, b), max(a,b)));
    }
  }
}
