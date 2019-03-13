#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
  int n, leastArea = 2000000000;
  cin >> n;
  vector < pair <int, int> > p(n);
  for (int x = 0; x < n; x++) {
    cin >> p[x].first >> p[x].second;
    for (int i = x-1; i >= 0; i--) {
      int len = abs(p[x].first - p[i].first), wid = abs(p[x].second - p[i].second);
      leastArea = min (leastArea, max(len,wid)*max(len,wid));
    }
  }
  cout << leastArea << endl;
}
