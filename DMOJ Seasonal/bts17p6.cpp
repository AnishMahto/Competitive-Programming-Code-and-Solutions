#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <int, int> nums;
map <int, int>::iterator it, it2;
int dp[100001] = {0}, trans[100001], alreadyInPlace = -1, bit[100002] = {0}, n;

void add (int pos, int val) {
  while (pos <= n+1) {
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
  int left = -1, right = -1;
  scanf ("%d", &n);
  int orig[n+1];
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &orig[x]);
    nums.insert(make_pair(orig[x], x));
  }
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &trans[x]);
    dp[x] = 1;
    if (x > 0) {
      it = nums.find(trans[x-1]);
      it2 = nums.find(trans[x]);
      //check if we can continue subarray
      if (it->second < it2->second) {
        dp[x] += dp[x-1];
      }
    }
    alreadyInPlace = max (alreadyInPlace, dp[x]);
  }
  printf ("%d\n", (n-alreadyInPlace));
  for (int x = n; x >= 1; x--) {
    if (dp[x] == alreadyInPlace) {
      right = x+1;
      left = x-dp[x];
      break;
    }
  }
  while (left > 0) {
    it = nums.find(trans[left]);
    printf ("F %d\n", it->second+query(it->second));
    add (1, 1);
    add (it->second+1, -1);
    left--;
  }
  while (right <= n) {
    it = nums.find(trans[right]);
    printf ("B %d\n", it->second+query(it->second));
    add (it->second, -1);
    right++;
  }
}
