#include <iostream>
#include <cstdio>
using namespace std;

int bit[8193][8193] = {0};
int h[8193];

void add (int height, int pos, int val) {
  int tempPos = pos;
  while (height < 8193) {
    tempPos = pos;
    while (tempPos < 8193) {
      bit[height][tempPos] += val;
      tempPos += tempPos & -tempPos;
    }
    height += height & -height;
  }
}

int query (int height, int pos) {
  int sum = 0, tempPos = pos;
  while (height > 0) {
    tempPos = pos;
    while (tempPos > 0) {
      sum += bit[height][tempPos];
      tempPos -= tempPos & -tempPos;
    }
    height -= height & -height;
  }
  return sum;
}

int main () {
  int n, q, t, i, j, a, b;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &h[x]);
    h[x]++;
    add (h[x], x, 1);
  }
  scanf ("%d", &q);
  long long sum = 0;
  while (q--) {
    scanf ("%d %d %d", &t, &i, &j);
    i++;
    j++;
    if (t==1) {
      scanf ("%d %d", &a, &b);
      a++;
      b++;
      printf ("%d\n", (query (b, j) - query(b, i-1) - query (a-1, j) + query(a-1,i-1)));
    } else {
      //j--;
      add (h[i], i, -1);
      h[i] = j;
      add (h[i], i, 1);
    }
  }
}
