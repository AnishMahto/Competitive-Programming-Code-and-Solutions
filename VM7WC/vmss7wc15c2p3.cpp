#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main () {
  int n;
  scanf ("%d", &n);
  long long total = 0, cur;
  vector <long long> heights, dup;
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &cur);
    if (heights.size() == 0) {
      heights.push_back(cur);
      dup.push_back(0);
    } else {
      long long duplicates = 0;
      while (heights.size() > 0 && heights.back() <= cur) {
        if (heights.back() == cur) {
          duplicates += dup.back()+1;
        }
        heights.pop_back();
        total++;
        total += dup.back();
        dup.pop_back();
      }
      if (heights.size() > 0) {
        total++;
      }
      heights.push_back(cur);
      dup.push_back(duplicates);
    }
  }
  cout << total << endl;
}
