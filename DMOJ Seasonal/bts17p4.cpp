#include <iostream>
#include <cstdio>
using namespace std;

int mud[100001] = {0}, n, m, j;

bool possible (int tim) {
  int prev = 0;
  for (int x = 1; x <= n; x++) {
    if (mud[x] <= tim && x-prev <= j) {
      prev = x;
    }
  }
  if (prev+j > n) {
    return true;
  } else {
    return false;
  }
}

int main () {
  scanf ("%d %d %d", &n, &m, &j);
  int pos, tim;
  for (int x = 0; x < m; x++) {
    scanf ("%d %d", &pos, &tim);
    mud[pos] = tim;
  }
  for (int x = 1; x <= n; x++) {
    if (mud[x] == 0) {
      mud[x] = 100000000;
    }
  }
  int lo = 0, hi = 1000001;
  int mid;
  while (lo < hi) {
    mid = (lo+hi)/2;
    if (possible(mid)) {
      //mid is large enough
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  if (lo == 1000001) {
    lo = -1;
  }
  cout << lo << endl;
}
