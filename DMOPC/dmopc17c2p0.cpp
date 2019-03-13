#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
using namespace std;

long long coord[3][2];

int main () {
  long long d;
  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < 2; i++) {
      cin >> coord[x][i];
    }
  }
  cin >> d;
  for (int x = 0; x < 2; x++) {
    long long dist = pow(coord[x][0]-coord[2][0], 2) + pow (coord[x][1]-coord[2][1], 2);
    if (abs(dist) <= d*d) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
