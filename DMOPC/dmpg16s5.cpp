#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

int main () {
  int n, k;
  scanf ("%d %d", &n, &k);
  vector <int> slice(2*n+1);
  vector <long long> psum(2*n+1);
  long long sparse[200001][(int)log2((double)k)+2] = {0};
  for (int x = 0; x < n; x++) {
    scanf ("%d", &slice[x]);
    if (x == 0) {
      psum[x] = slice[x];
    } else {
      psum[x] = psum[x-1] + slice[x];
    }
    sparse[x][0] = psum[x];
  }
  for (int x = n; x < 2*n; x++) {
    slice[x] = slice[x-n];
    psum[x] = psum[x-1] + slice[x];
    sparse[x][0] = psum[x];
  }
  for (int i = 1; i < (int)log2((double)k)+1; i++) {
    for (int x = 0; x < 2*n; x++) {
      if (x+pow(2,i-1) >= 2*n) {
        sparse[x][i] = sparse[x][i-1];
      } else {
        sparse[x][i] = max (sparse[x][i-1], sparse[x+(int)pow(2, i-1)][i-1]);
      }
    }
  }
  int logk = (int)log2((double)k);
  long long query, ans = numeric_limits<long long>::min();
  for (int x = 0; x < 2*n-1; x++) {
    query = max (sparse[x][logk], sparse[max(0, min(x+k-(int)pow(2, logk), 2*n-1))][logk]);
    if (x > 0) {
      ans = max (ans, query - psum[x-1]);
    } else {
      ans = max (ans, query);
    }
  }
  cout << ans << endl;
}
