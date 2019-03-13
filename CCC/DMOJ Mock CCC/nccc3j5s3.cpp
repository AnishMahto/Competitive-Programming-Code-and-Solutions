#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;

double sqr (double a) {
  return a*a;
}

int main() {
  int n;
  cin >> n;
  vector < pair <double, double> > pts(n);
  double rad = 0;
  for (int x = 0; x < n; x++) {
    cin >> pts[x].first >> pts[x].second;
  }
  if (pts.size()==1) {
    cout << 0 << endl;
    return 0;
  } else if (pts.size()==2) {
    rad = sqrt(sqr(pts[0].first-pts[1].first) + sqr(pts[0].second-pts[1].second))/(double)2;
    printf ("%.9f\n", rad);
    return 0;
  }
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < n; i++) {
      for (int z = 0; z < n; z++) {
        if (x!=i && x!=z && i != z) {
          double s1 = sqrt(sqr(pts[x].first-pts[i].first) + sqr(pts[x].second-pts[i].second)), s2 = sqrt(sqr(pts[i].first-pts[z].first) + sqr(pts[i].second-pts[z].second)), s3 = sqrt(sqr(pts[z].first-pts[x].first) + sqr(pts[z].second-pts[x].second));
          double s = (s1+s2+s3)/(double)2;
          double denom = sqrt(s*(s-s1)*(s-s2)*(s-s3));
          if (denom == 0 || (s1*s1 + s2*s2 - s3*s3 < 0) || (s2*s2 + s3*s3 - s1*s1 < 0) || (s3*s3 + s1*s1 -  s2*s2 < 0)) {
            rad = max ({rad, s1/2, s2/2, s3/2});
          } else {
            rad = max (rad, s1*s2*s3/(4*denom));
          }
        }
      }
    }
  }
  printf ("%.9f\n", rad);
}
