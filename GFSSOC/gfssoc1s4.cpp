#include <iostream>
#include <cstdio>
using namespace std;

long long bit[251][251][251] = {0};
long long current[251][251][251] = {0};
int n;

void update (int y, int x, int z, long long val) {
  int rx = x, rz = z;
  while (y <= n) {
    while (x <= n) {
      while (z <= n) {
        bit[y][x][z] += val;
        z += z & -z;
      }
      z = rz;
      x += x & -x;
    }
    x = rx;
    y += y & -y;
  }
}

long long getSum (int y, int x, int z) {
  long long sum = 0;
  int rx = x, rz = z;
  while (y > 0) {
    while (x > 0) {
      while (z > 0) {
        sum += bit[y][x][z];
        z -= z & -z;
      }
      z = rz;
      x -= x & -x;
    }
    x = rx;
    y -= y & -y;
  }
  return sum;
}

int main () {
  int q, x, y, z, l, x2, y2, z2;
  char cmd;
  long long sum = 0;
  scanf ("%d %d", &n, &q);
  while (q--) {
    scanf (" %c", &cmd);
    if (cmd == 'C') {
      scanf ("%d %d %d %d", &x, &y, &z, &l);
      update (y, x, z, l-current[y][x][z]);
      current[y][x][z]=l;
    } else {
      scanf ("%d %d %d %d %d %d", &x, &y, &z, &x2, &y2, &z2);
      sum += ( getSum(y2,x2,z2) - getSum(y2,x2,z-1) - getSum(y2,x-1,z2) - getSum(y-1,x2,z2) + getSum(y-1,x-1,z2) - getSum(y-1,x-1,z-1) + getSum(y-1,x2,z-1) + getSum(y2,x-1,z-1));
    }
  }
  printf ("%lld", sum);
}
