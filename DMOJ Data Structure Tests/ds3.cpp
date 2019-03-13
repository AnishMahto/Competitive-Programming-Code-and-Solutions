#include <iostream>
#include <cstdio>
using namespace std;

int n, m, minSeg[4000004] = {0}, gcdSeg[4000004] = {0}, opSeg[4000004] = {0}, array[1000001], rangeGCD, rangeMin, countMin[4000004] = {0};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build (int pos, int l, int r) {
  if (l == r) {
    gcdSeg[pos] = minSeg[pos] = array[l];
    opSeg[pos] = 1;
  } else if (l > r) {
    return;
  } else {
    int mid = l + (r-l)/2;
    build (2*pos, l, mid);
    build (2*pos+1, mid+1, r);
    minSeg[pos] = min (minSeg[2*pos], minSeg[2*pos+1]);
    gcdSeg[pos] = gcd (gcdSeg[2*pos], gcdSeg[2*pos+1]);
    opSeg[pos] = 0;
    if (gcdSeg[pos] == gcdSeg[2*pos]) {
      opSeg[pos] += opSeg[2*pos];
    }
    if (gcdSeg[pos] == gcdSeg[2*pos+1]) {
      opSeg[pos] += opSeg[2*pos+1];
    }
  }
}

void update (int pos, int l, int r, int tl, int tr, int val) {
  if (l == tl && r == tr) {
    gcdSeg[pos] = minSeg[pos] = array[l];
    opSeg[pos] = 1;
  } else if (l == r || l > r || r < tl || l > tr) {
    return;
  } else {
    int mid = l+(r-l)/2;
    update (2*pos, l, mid, tl, tr, val);
    update (2*pos+1, mid+1, r, tl, tr, val);
    minSeg[pos] = min (minSeg[2*pos], minSeg[2*pos+1]);
    gcdSeg[pos] = gcd (gcdSeg[2*pos], gcdSeg[2*pos+1]);
    opSeg[pos] = 0;
    if (gcdSeg[pos] == gcdSeg[2*pos]) {
      opSeg[pos] += opSeg[2*pos];
    }
    if (gcdSeg[pos] == gcdSeg[2*pos+1]) {
      opSeg[pos] += opSeg[2*pos+1];
    }
  }
}

int queryMin (int pos, int l, int r, int tl, int tr) {
  if (l > r || l > tr || r < tl) {
    return 2000000000;
  } else if (l >= tl && r <= tr) {
    return minSeg[pos];
  } else {
    int mid = l+(r-l)/2;
    return min (queryMin(2*pos, l, mid, tl, tr), queryMin(2*pos+1, mid+1, r, tl, tr));
  }
}

int queryGCD (int pos, int l, int r, int tl, int tr) {
  if (l > r || l > tr || r < tl) {
    return 1999000000;
  } else if (l >= tl && r <= tr) {
    return gcdSeg[pos];
  } else {
    int mid = l+(r-l)/2;
    int temp = queryGCD(2*pos, l, mid, tl, tr), temp2 = queryGCD(2*pos+1, mid+1, r, tl, tr);
    if (temp == 1999000000) {
      return temp2;
    } else if (temp2 == 1999000000) {
      return temp;
    } else {
      return gcd(temp, temp2);
    }
  }
}

int queryOp (int pos, int l, int r, int tl, int tr) {
  if (l >= tl && r <= tr) {
    if (gcdSeg[pos] == rangeGCD) {
      return opSeg[pos];
    } else {
      return 0;
    }
  } else if (l > r || l > tr || r < tl) {
    return 0;
  } else {
    int mid = l+(r-l)/2;
    return queryOp(2*pos, l, mid, tl, tr) + queryOp(2*pos+1, mid+1, r, tl, tr);
  }
}

int main () {
  int a, b;
  char cmd;
  scanf ("%d %d", &n, &m);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &array[x]);
  }
  build (1, 1, n);
  while (m--) {
    scanf (" %c %d %d", &cmd, &a, &b);
    if (cmd == 'C') {
      array[a] = b;
      update (1, 1, n, a, a, b);
    } else if (cmd == 'M') {
      printf ("%d\n", queryMin(1, 1, n, a, b));
    } else if (cmd == 'G') {
      printf ("%d\n", queryGCD(1, 1, n, a, b));
    } else {
      rangeMin = queryMin(1, 1, n, a, b);
      rangeGCD = queryGCD(1, 1, n, a, b);
      printf ("%d\n", queryOp(1, 1, n, a, b));
    }
  }
}
