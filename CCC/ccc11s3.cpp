#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
using namespace std;

bool possible (long long x, long long y, long long m) {
  if (m==1) {
    if (y==1 && x >= 2 && x <= 4) {
      return true;
    } else if (y==2 && x == 3) {
      return true;
    } else {
      return false;
    }
  } else {
    bool temp = false, temp2 = false;
    if ( (y%5==2 && x%5==3) || (y%5 == 1 && (x%5 > 1 && x%5 <= 4)) ) {
      //potentially part of 1 of the top 4 pattern
      temp = possible ((int)ceil ((double)x/(double)5), (y-y%5)/5, m-1);
    } else {
      //potentially part of a grid
      temp2 = possible ((int)ceil ((double)x/(double)5), (int)ceil ((double)y/(double)5), m-1);
    }
    return max (temp, temp2);
  }
}

int main() {
  long long t, x, y, m;
  scanf ("%lld", &t);
  while (t--) {
    scanf ("%lld %lld %lld", &m, &x, &y);
    if (possible (x+1, y+1, m)) {
      cout << "crystal" << endl;
    } else {
      cout << "empty" << endl;
    }
  }
}
