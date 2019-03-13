#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip> 
using namespace std;

string a, b;

inline int solve (int lenA, int lenB) {
  int dp[101][101] = {0};
  for (int x = 0; x <= lenA; x++) {
    for (int i = 0; i <= lenB; i++) {
      if (x == 0 && i == 0) {
        dp[x][i] = 0;
      } if (x == 0) {
        dp[x][i] = i;
      } else if (i == 0) {
        dp[x][i] = x;
      } else if (a[x-1] == b[i-1]) {
        dp[x][i] = dp[x-1][i-1];
      } else {
        dp[x][i] = min (dp[x][i-1], min (dp[x-1][i], dp[x-1][i-1])) + 1;
      }
    }
  }
  return dp[lenA][lenB];
}

int main () {
  cin.sync_with_stdio(0);
    cin.tie(0);
  double best = 101;
  string correct, cur;
  cin >> correct;
  a = correct;
  int n, t;
  cin >> n;
  while (n--) {
    cin >> t;
    double total = 0;
    for (int x = 0; x < t; x++) {
      cin >> cur;
      b = cur;
      total += solve (correct.length(), cur.length());
    }
    total /= t;
    best = min (best, total);
  }
  cout << setprecision(7) << best << "\n";
}
