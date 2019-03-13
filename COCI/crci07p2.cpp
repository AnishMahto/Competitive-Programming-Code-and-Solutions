#include <iostream>
#include <cstdio>
using namespace std;

int dp[1001][1001] = {0}, s[1001] = {0}, n;

int solve (int pos, int prev) {
  if (pos == n) {
    return s[n];
  } else if (dp[pos][prev] != 0) {
    return dp[pos][prev];
  } else {
    dp[pos][prev] = 100000001;
    bool possible = false;
    if (pos + prev + 1 <= n) {
      dp[pos][prev] = min (dp[pos][prev], s[pos] + solve (pos + prev + 1, prev + 1));
      possible = true;
    }
    if (pos - prev >= 1 && (prev != 0 || pos != 1)) {
      dp[pos][prev] = min (dp[pos][prev], s[pos] + solve (pos - prev, prev));
      possible = true;
    }
    if (!possible) {
      cout << dp[pos][prev] << endl;
    }
  }
  return dp[pos][prev];
}

int main () {
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &s[x]);
  }
  cout << solve (2, 1) << endl;
}
