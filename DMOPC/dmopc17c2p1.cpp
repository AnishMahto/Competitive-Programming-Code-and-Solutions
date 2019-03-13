#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main () {
  int n, v, c;
  long long size = 0;
  scanf ("%d", &n);
  for (int x = 0; x < n; x++) {
    scanf ("%d %d", &c, &v);
    if (v > 0) {
      size += c;
    }
  }
  cout << size << endl;
}
