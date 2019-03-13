#include <iostream>
#include <cstdio>
using namespace std;

int dp[3][3][3][3][150001] = {0}, values[3][150001], n;

int solve (int p, int pos, int o[3], int prev) {
  if (pos == n) {
    if (p == o[2] && prev == o[2]) {
      return 0;
    } else {
      return 1000000000;
    }
  } else if (dp[o[0]][o[1]][o[2]][p][pos] != 0) {
    return dp[o[0]][o[1]][o[2]][p][pos];
  } else {
    int curr;
    for (int x = 0; x < 3; x++) {
      if (p == o[x]) {
        curr = x;
        break;
      }
    }
    dp[o[0]][o[1]][o[2]][p][pos] = 1000000000;
    dp[o[0]][o[1]][o[2]][p][pos] = solve (p, pos+1, o, p) + values[p][pos];
    if (p != o[2]) {
      dp[o[0]][o[1]][o[2]][p][pos] = min (dp[o[0]][o[1]][o[2]][p][pos], solve (o[curr+1], pos+1, o, p) + values[p][pos]);
    }
  }
  return dp[o[0]][o[1]][o[2]][p][pos];
}

int main () {
  scanf ("%d", &n);
  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < n; i++) {
      scanf ("%d", &values[x][i]);
    }
  }
  int ans = 2000000000;
  int o[3];
  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < 3; i++) {
      if (x != i) {
        for (int z = 0; z < 3; z++) {
          if (z != x && z != i) {
            o[0] = x; o[1] = i; o[2] = z;
            ans = min (ans, solve(o[0], 0, o, o[0]));
          }
        }
      }
    }
  }
  cout << ans << endl;
}
