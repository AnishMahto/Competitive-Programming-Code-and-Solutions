#include <iostream>
#include <cstdio>
using namespace std;

int bit[1026][1026] = {0}, s;

int update (int x, int y, int a) {
  int mask = x;
  while (mask <= s) {
    bit[y][mask] += a;
    mask += mask & -mask;
  }
}

int query (int x, int y) {
  int mask = x, sum = 0;
  while (mask > 0) {
    sum += bit[y][mask];
    mask -= mask & -mask;
  }
  return sum;
}

int main () {
  scanf ("%d", &s); scanf ("%d", &s);
  int cmd, px, py, a, l, b, r, t;
  scanf ("%d", &cmd);
  while (cmd != 3) {
    if (cmd == 1) {
      scanf ("%d %d %d", &px, &py, &a);
      px++;py++;
      update (px, py, a);
    } else if (cmd == 2) {
      scanf ("%d %d %d %d", &l, &b, &r, &t);
      l++;b++;r++;t++;
      int sum = 0;
      for (int x = b; x <= t; x++) {
        sum += query (r, x) - query (l - 1, x);
      }
      printf ("%d\n", sum);
    }
    scanf ("%d", &cmd);
  }
}
