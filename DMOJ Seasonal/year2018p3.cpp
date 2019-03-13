#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

long long snow[100002], n, m, k, least = 2000000000;

long long check (long long L) {
  long long dif[100002] = {0};
  long long used = 0, add = 0;
  for (int x = 0; x < n; x++) {
    add += dif[x];
    if (snow[x] + add < L) {
      int use = L - (snow[x] + add);
      used += use;
      add += use;
      dif[min(x+m, (long long)100001)] -= use;
    }
  }
  return used;
}

int main() {
  scanf ("%lld %lld %lld", &n, &m, &k);
  for (int x = 0; x < n; x++) {
    scanf ("%lld", &snow[x]);
    least = min (least, snow[x]);
  }
  long long lo = least, hi = least + k + 1;
  while (lo < hi) {
    long long mid = (lo + hi)/2;
    if (check (mid) > k) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  cout << lo-1 << endl;
}
