#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int h, k, gap, greatestGap = 0;
//the house at beginning of gap is stored in gap
vector <int> house;
vector <int> looped;

int bs (int low, int up) {
  if (low == up) {
    return low;
  }
  int mid = low + (up-low)/2, d = mid*2, hoses = 0, used = 0, pos = gap, end, counter = 0;
  (gap == h-1) ? end=0:end=h+1;
  bool first = true;
  while ((pos - gap) != h+1) {
    if (used == d) {
      hoses++;
      used = 0;
      pos++;
    } else if (used == 0) {
      used=1;
      pos++;
    } else if (looped[pos] > looped[pos-1]) {
      if (used == 1) {
        used = 0;
      }
      if (used + looped[pos] - looped[pos-1] <= d) {
        used += looped[pos] - looped[pos-1];
        pos++;
      } else {
        used = 0;
        hoses++;
      }
    } else {
      if (used == 1) {
        used = 0;
      }
      if (used + 1000000 - looped[pos-1] + looped[pos] <= d) {
        used += 1000000 - looped[pos-1] + looped[pos];
        pos++;
      } else {
        used = 0;
        hoses++;
      }
    }
  }
  if (hoses <= k) {
    return bs (low, mid);
  } else {
    return bs (mid+1, up);
  }
}

int main () {
  int cur;
  scanf ("%d", &h);
  for (int x = 0; x < h; x++) {
    scanf ("%d", &cur);
    house.push_back(cur);
  }
  scanf ("%d", &k);
  sort (house.begin(), house.end());
  for (int x = 0; x < 4; x++) {
    for (int i = 0; i < house.size(); i++) {
      looped.push_back(house[i]);
    }
  }
  for (int x = 0; x < house.size(); x++) {
    if (x < house.size() - 1) {
      (greatestGap < house[x+1]-house[x]) ? gap = x:true;
      greatestGap = max (greatestGap, house[x+1]-house[x]);
    } else {
      (greatestGap < 1000000 - house[x] + house[0]) ? gap = x:true;
      greatestGap = max (greatestGap, 1000000 - house[x] + house[0]);
    }
  }
  gap += h + 1; // add 1 to start at the end of break
  cout << bs (0, 1000000) << "\n";
}
