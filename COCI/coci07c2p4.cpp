#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int shift[100002] = {0};

void add (int pos, int val) {
  while (pos < 100001) {
    shift[pos] += val;
    pos += pos & -pos;
  }
}

int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += shift[pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main () {
  int n;
  scanf ("%d", &n);
  vector <int> nums(n+1);
  vector < pair <int, int> > sorted;
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &nums[n]);
    sorted.push_back(make_pair(nums[n], x));
  }
  sort (sorted.begin(), sorted.end());
  int l = 0, r = n-1, move = 1;
  while (l <= r) {
    if (move%2==1) {
      
      int pos = sorted[l].second + query (sorted[l].second);
      printf ("%d\n", max(pos, sorted[l].first)-min(pos, sorted[l].first));
      //number moved to the left, thus everything before it gets shifted right once
      add (1, 1);
      add (sorted[l].second, -1);
      l++;
    } else {
      
      int pos = sorted[r].second + query (sorted[r].second);
      printf ("%d\n", max(pos, sorted[r].first)-min(pos, sorted[r].first));
      //number moved to the right, thus everything after it gets shifted left once
      add (sorted[r].second+1, -1);
      add (n+1, 1);
      r--;
    }
    move++;
  }
}
