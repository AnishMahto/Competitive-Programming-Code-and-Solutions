#include <iostream>
#include <cstdio>
#include <math.h>
#define gc getchar_unlocked
using namespace std;

void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
long long segTree[2000001] = {0}, lazy[2000001] = {0}, nums[200001] = {0};
long long n, m;

long long modular_pow(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

long long build (int pos, int l, int r) {
  int mid = l+(r-l)/2;
  if (l == r) {
    segTree[pos] = nums[l]; 
    return segTree[pos];
  } else {
    segTree[pos] = (build (2*pos, l, mid) % m + build (2*pos+1, mid+1, r) % m) % m;
  }
  return segTree[pos];
}

long long query (int pos, int l, int r, int tl, int tr) {
  int times = r-l+1; //add the val this many times, as there are this many elements that need to be increased by val
  if (lazy[pos] != 0) {
    segTree[pos] += times*lazy[pos];
    segTree[pos] %= m;
    if (l != r) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (r < l || r < tl || l > tr) {
    return 0;
  }
  int mid = l + (r-l)/2;
  if (l >= tl && r <= tr) {
    return segTree[pos];
  } else {
    return ((query (2*pos, l, mid, tl, tr) % m + query(2*pos+1, mid+1, r, tl, tr) % m) % m);
  }
}

long long add (int pos, int l, int r, int tl, int tr, int val) {
  int times = r-l+1; //add the val this many times, as there are this many elements that need to be increased by val
  if (lazy[pos] != 0) {
    segTree[pos] += lazy[pos]*times;
    segTree[pos] %= m;
    if (l != r) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (r < l || r < tl || l > tr) {
    if (r < l) {
      return 0;
    } else {
      return segTree[pos];
    }
  }
  int mid = l + (r-l)/2;
  if (l >= tl && r <= tr) {
    segTree[pos] += val*times; segTree[pos] %= m;
    if (l != r) {
      lazy[pos*2] += val;
      lazy[pos*2+1] += val;
    }
  } else {
    segTree[pos] = ((add (2*pos, l, mid, tl, tr, val) % m + add(2*pos+1, mid+1, r, tl, tr, val) % m) % m);
  }
  return segTree[pos];
}

int main () {
  long long q, cmd, a, b, c;
  scanint(m); scanint(n); scanint(q);
  for (int x = 1; x <= n; x++) {
    scanint(nums[x]);
    nums[x] %= m;
  }
  build (1, 1, n);
  while (q--) {
    scanint(cmd);
    if (cmd == 1) {
      scanint(a); scanint(b); scanint (c);
      add (1, 1, n, a, b, modular_pow(c, m, m));
    } else {
      scanint (a); scanint (b);
      printf ("%lld\n", query (1, 1, n, a, b));
    }
  }
  return 0;
}
