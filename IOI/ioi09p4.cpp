#include <iostream>
#include <cstdio>
using namespace std;

int dp[52][52][52][52] = {0}, choc[52][52] = {0}, n, m, rangeSum[52][52] = {0};
//cancerous O(n^5) dp :))))))))))))

int solve (int tlx, int tly, int brx, int bry) {
  if (dp[tlx][tly][brx][bry] != 0) {
    return dp[tlx][tly][brx][bry];
  } else if (tlx == brx && tly == bry) {
    return 0;
  }
  dp[tlx][tly][brx][bry] = 1000000001;
  int sum = rangeSum[bry][brx] - rangeSum[bry][tlx-1] - rangeSum[tly-1][brx] + rangeSum[tly-1][tlx-1];
  for (int x = tly; x <= bry-1; x++) {
    dp[tlx][tly][brx][bry] = min (dp[tlx][tly][brx][bry], solve (tlx, tly, brx, x) + solve (tlx, x+1, brx, bry) + sum);
  }
  for (int x = tlx; x <= brx-1; x++) {
    dp[tlx][tly][brx][bry] = min (dp[tlx][tly][brx][bry], solve (tlx, tly, x, bry) + solve (x+1, tly, brx, bry) + sum);
  }
  return dp[tlx][tly][brx][bry];
}

int main () {
  scanf ("%d %d", &n, &m);
  for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= m; i++) {
      scanf ("%d", &choc[x][i]);
      rangeSum[x][i] = choc[x][i] + rangeSum[x-1][i] + rangeSum[x][i-1] - rangeSum[x-1][i-1];
    }
  }
  cout << solve (1, 1, m, n) << endl;
}
