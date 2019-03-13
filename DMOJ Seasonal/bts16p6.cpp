#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int c, r, m;
long long da[502][502] = {0}, dada[502][502] = {0}, subtractV[502][502] = {0}, subtractH[502][502] = {0};
long long dp[501][501], sum[501][501] = {0};

long long solve (int py, int px) {
  if (dp[py][px] != -1) {
    return dp[py][px];
  }
  sum[py][px] = dada[py][px] /*% 1000000007*/;
  //try left
  long long temp = 1;
  if (px-1 >= 1 && dada[py][px-1] > dada[py][px]) {
    if (temp < solve (py, px-1)+1) {
      temp = solve (py, px-1)+1;
      sum[py][px] = (sum[py][px-1] + dada[py][px]) /*% 1000000007*/;
    } else if (temp == solve (py, px-1)+1) {
      sum[py][px] = max (sum[py][px], ((sum[py][px-1] + dada[py][px]) /*% 1000000007*/)); 
    }
  }
  //try right
  if (px+1 <= c && dada[py][px+1] > dada[py][px]) {
    if (temp < solve (py, px+1)+1) {
      temp = solve (py, px+1)+1;
      sum[py][px] = (sum[py][px+1] + dada[py][px]) /*% 1000000007*/;
    } else if (temp == solve (py, px+1)+1) {
      sum[py][px] = max (sum[py][px], ((sum[py][px+1] + dada[py][px]) /*% 1000000007*/)); 
    }
  }
  //try up
  if (py-1 >= 1 && dada[py-1][px] > dada[py][px]) {
    if (temp < solve (py-1, px)+1) {
      temp = solve (py-1, px)+1;
      sum[py][px] = (sum[py-1][px] + dada[py][px]) /*% 1000000007*/;
    } else if (temp == solve (py-1, px)+1) {
      sum[py][px] = max (sum[py][px], ((sum[py-1][px] + dada[py][px]) /*% 1000000007*/)); 
    }
  }
  //try down
  if (py+1 <= r && dada[py+1][px] > dada[py][px]) {
    if (temp < solve (py+1, px)+1) {
      temp = solve (py+1, px)+1;
      sum[py][px] = (sum[py+1][px] + dada[py][px]) /*% 1000000007*/;
    } else if (temp == solve (py+1, px)+1) {
      sum[py][px] = max (sum[py][px], ((sum[py+1][px] + dada[py][px]) /*% 1000000007*/)); 
    }
  }
  dp[py][px] = temp;
  return dp[py][px];
}

int main () {
  memset(dp, -1, sizeof(dp));
  int tlx, tly, w, h, n;
  scanf ("%d %d %d", &c, &r, &m);
  for (int a = 0; a < m; a++) {
    scanf ("%d %d %d %d %d", &tlx, &tly, &w, &h, &n);
    da[tly][tlx] += n;
    da[tly][tlx+w] -= n;
    da[tly+h][tlx] -= n;
    da[tly+h][tlx+w] += n;
    for (int x = tly; x <= tly+h-1; x++) {
      subtractH[x][tlx+w] -= (w*n) ;
    }
    for (int x = tlx; x <= tlx+w-1; x++) {
      subtractV[tly+h][x] -= (h*n)*(x-tlx+1);
    }
  }
  for (int x = 1; x <= r; x++) {
    for (int i = 1; i <= c; i++) {
      da[x][i] += da[x][i-1];
    }
  }
  for (int x = 1; x <= r; x++) {
    for (int i = 1; i <= c; i++) {
      da[x][i] += da[x-1][i];
    }
  }
  for (int x = 1; x <= r; x++) {
    for (int i = 1; i <= c; i++) {
      dada[x][i] += dada[x][i-1] + da[x][i] + subtractH[x][i];
    }
  }
  for (int x = 1; x <= r; x++) {
    for (int i = 1; i <= c; i++) {
      dada[x][i] += dada[x-1][i] + subtractV[x][i];
    }
  }
  int sx, sy;
  scanf ("%d %d", &sx, &sy);
  solve (sy, sx);
  cout << (sum[sy][sx] % 1000000007) << endl;
}
