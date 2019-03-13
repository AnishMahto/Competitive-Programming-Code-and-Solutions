#include <iostream>
#include <cstdio>
using namespace std;

long long field[200002] = {0}, dif[200002] = {0}, psum[200002] = {0};
int n, m;
long long k, a, b;

bool check (int w) {
  for (int x = w; x <= n; x++) {
    if (psum[x] - psum[x-w] >= k) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf ("%d %d %lld", &n, &m, &k);
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &a, &b);
    dif[a] += -1; 
    dif[b+1] += 1;
  }
  long long val = m;
  for (int x = 1; x <= n; x++) {
    val += dif[x];
    field[x] = val;
    psum[x] = field[x] + psum[x-1];
  }
  if (psum[n] < k) {
    cout << -1 << "\n";
    return 0;
  } else if (k==0) {
      cout << 0 << "\n";
      return 0;
  }
  int lo = 1, hi = n, mid;
  while (lo < hi) {
    mid = (lo+hi)/2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  cout << lo << "\n";
}

/*

P..P
....
.P.P


*/
