#include <cstdio>
#include <iostream>
using namespace std;

int main () {
  int n, k;
  scanf ("%d %d", &n, &k);
  k = min (k, n);
  int arr[n+1], pos[n+1], perm[n+1] = {0}, ptr = n;
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &arr[x]);
    pos[arr[x]] = x;
  }
  while (ptr > 0 && k > 0) {
    if (n - (ptr-1) != pos[ptr]) {
      pos[arr[n - (ptr-1)]] = pos[ptr];
      arr[pos[ptr]] = arr[n - (ptr-1)];
      arr[n - (ptr-1)] = ptr;
      pos[ptr] = ptr - (ptr-1);
      k--;
    }
    ptr--;
  }
  for (int x = 1; x <= n; x++) {
    printf ("%d ", arr[x]);
  }
}
