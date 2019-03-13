#include <bits/stdc++.h>
using namespace std;

int bit[100001] = {0};
vector <int> nums;
vector <int> sorted;
vector <int>::iterator it;

void update (int pos, int val) {
  while (pos <= sorted.size()-1) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}

int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main () {
  int t, cur;
  double sum = 0;
  scanf ("%d", &t);
  for (int x = 0; x < t; x++) {
    scanf ("%d", &cur);
    nums.push_back(cur);
    sorted.push_back(cur);
  }
  sorted.push_back(-1);
  sort (sorted.begin(), sorted.end());
  for (int x = 0; x < nums.size(); x++) {
    it = lower_bound(sorted.begin(), sorted.end(), nums[x]);
    sum += (x+1) - query((it - sorted.begin()));
    update ((it - sorted.begin()), 1);
  }
  sum /= t;
  cout<<fixed<<setprecision(2)<<sum<<"\n";
}
