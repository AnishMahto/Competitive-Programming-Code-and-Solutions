#include <iostream>
#include <cstdio>
using namespace std;

int board[1002][1002], dp[1002][1002][4] = {0};
//0 is left, 1 is right, 2 is down, 3 is up
int main () {
  int r, c;
  scanf ("%d %d", &r, &c);
  for (int x = 1; x <= r; x++) {
    for (int i = 1; i <= c; i++) {
      scanf (" %c", &board[x][i]);
      if (board[x][i] == 'X') {
        for (int z = 0; z < 4; z++) {
          dp[x][i][z] = 1;
        }
      }
      if (dp[x][i-1][0] != 0) {
        dp[x][i][0] = 1;
      } 
      if (dp[x-1][i][3] != 0) {
        dp[x][i][3] = 1;
      }
    }
  }
  for (int x = r; x >= 1; x--) {
    for (int i = c; i >= 1; i--) {
      if (dp[x][i+1][1] != 0) {
        dp[x][i][1] = 1;
      } 
      if (dp[x+1][i][2] != 0) {
        dp[x][i][2] = 1;
      }
    }
  }
  
  int q, x, y;
  scanf ("%d", &q);
  
  while (q--) {
    scanf ("%d %d", &x, &y);
    for (int i = 0; i < 4; i++) {
      if (dp[y][x][i] != 0) {
        printf ("Y\n");
        break;
      } else if (i == 3) {
        printf ("N\n");
      }
    }
  }
}
