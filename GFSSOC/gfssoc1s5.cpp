#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

pair <int, int> grid[52][52];
int dp[52][52][52][52] = {0}, m, rows, cols, highestRow = 0;

int solve (int r, int c, int b, int k) {
  if (dp[r][c][b][k] != -1) {
    return dp[r][c][b][k];
  }
  if (r == highestRow || k == 0) {
    return 0;
  } else {
    dp[r][c][b][k] = 0;
    for (int x = max(1, c-m); x <= min (cols, c+m); x++) {
      bool canTake = (grid[r+1][x].second != 0 && b-grid[r+1][x].first > 0 && k-1>=0) ? true:false;
      if (canTake) {
        dp[r][c][b][k] = max (dp[r][c][b][k], solve (r+1, x, b-grid[r+1][x].first, k-1) + grid[r+1][x].second);
      }
      dp[r][c][b][k] = max (dp[r][c][b][k], solve (r+1, x, b, k));
    }
  }
  return dp[r][c][b][k];
}

int main () {
  memset (dp, -1, sizeof(dp));
  int s, b, k, t, v, Ci, Ri, ans = 0;
  scanf ("%d %d %d %d %d %d", &rows, &cols, &s, &b, &k, &m);
  for (int x = 0; x < s; x++) {
    scanf ("%d %d %d %d", &t, &v, &Ci, &Ri);
    grid[Ri][Ci].first = t;
    grid[Ri][Ci].second = v;
    highestRow = max (highestRow, Ri);
  }
  cout << solve (0, 1, b, k) << endl;
}
