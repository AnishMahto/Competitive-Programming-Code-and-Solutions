#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
  int n, t, ver = 0, pos;
  char current;
  bool line[100001] = {0};
  scanf ("%d %d", &n, &t);
  for (int x = 1; x <= n; x++) {
    scanf (" %c ", &current);
    if (current == '|') {
      line[x] = 1;
      ver++;
    }
  }
  for (int x = 0; x < t; x++) {
    scanf ("%d", &pos);
    if (line[pos]) {
      ver--;
    } else {
      ver++;
    }
    line[pos] = !line[pos];
    if (line[1]) {
      printf ("1\n");
    } else if (ver == 0) {
      printf ("%d\n", n);
    } else {
      printf ("%d\n", n+2*ver);
    }
  }
}
