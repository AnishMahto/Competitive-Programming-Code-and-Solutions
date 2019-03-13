#include <iostream>
#include <cstdio>
using namespace std;

long long greatest[4*1000001], pre[4*1000001], suf[4*1000001], sum[4*1000001], n, m, nums[1000001], z = 0;

void build (int pos, int l, int r) {
  if (l > r) {
    return;
  }
  if (l==r) {
    greatest[pos] = max (z, nums[l]);
    pre[pos] = suf[pos] = sum[pos] = nums[l];
  } else {
    int mid = l+(r-l)/2;
    build (2*pos, l, mid);
    build (2*pos+1, mid+1, r);
    sum[pos] = sum[2*pos] + sum[2*pos+1]; 
    
    pre[pos] = max (pre[2*pos], sum[2*pos] + pre[2*pos+1]);
    pre[pos] = max (pre[pos], sum[2*pos]+sum[2*pos+1]);
    
    suf[pos] = max (suf[2*pos+1], sum[2*pos+1] + suf[2*pos]);
    suf[pos] = max (suf[pos], sum[2*pos] + sum[2*pos+1]);
    
    greatest[pos] = max (greatest[2*pos], greatest[2*pos+1]);
    greatest[pos] = max (greatest[pos], max (pre[pos], suf[pos]));
    greatest[pos] = max (greatest[pos], sum[pos]);
    greatest[pos] = max (greatest[pos], pre[2*pos+1] + suf[2*pos]);
  }
}

void update (int pos, int l, int r, int tl, int tr, long long val) {
  if (l > r || l > tr || r < tl) {
    return;
  }
  if (l >= tl && r <= tr) {
    greatest[pos] = max (z, val);
    pre[pos] = suf[pos] = sum[pos] = val;
  } else {
    int mid = l+(r-l)/2;
    update (2*pos, l, mid, tl, tr, val);
    update (2*pos+1, mid+1, r, tl, tr, val);
    
    //calculate sum of range
    sum[pos] = sum[2*pos] + sum[2*pos+1]; 
    
    //prefix is max of left range prefix, entire left range + right range prefix, or sum of entire range
    pre[pos] = max (pre[2*pos], sum[2*pos] + pre[2*pos+1]);
    pre[pos] = max (pre[pos], sum[pos]);
    
    //suffix is max of right range prefix, entire right range + left range suffix, or sum of entire range
    suf[pos] = max (suf[2*pos+1], sum[2*pos+1] + suf[2*pos]);
    suf[pos] = max (suf[pos], sum[pos]);
    
    //greatest is max of all values calculated
    greatest[pos] = max (greatest[2*pos], greatest[2*pos+1]);
    greatest[pos] = max (greatest[pos], max (pre[pos], suf[pos]));
    greatest[pos] = max (greatest[pos], sum[pos]);
    greatest[pos] = max (greatest[pos], pre[2*pos+1] + suf[2*pos]);
  }
} 

int main () {
  int a, b;
  scanf ("%lld", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &nums[x]);
  }
  build (1, 1, n);
  scanf ("%lld", &m);
  printf ("%lld\n", greatest[1]);
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    update (1, 1, n, a+1, a+1, (long long)b);
    printf ("%lld\n", greatest[1]);
  }
}
