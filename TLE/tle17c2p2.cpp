#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  int n, k, cur;
  scanf ("%d", &n);
  vector <int> bad(n);
  vector <int>::iterator it;
  for (int x = 0; x < n; x++) {
    scanf ("%d", &bad[x]);
  }
  sort (bad.begin(), bad.end());
  scanf ("%d", &k);
  while (k--) {
    scanf ("%d", &cur);
    if (bad[n-1] < cur) {
      printf ("%d\n", (cur-bad.size()));
      continue;
    }
    it = lower_bound(bad.begin(), bad.end(), cur);
    int pos = (it-bad.begin());
    if (bad[pos] > cur) {
      pos--;
    }
    printf ("%d\n", max(0, cur-(pos+1)));
  }
}
