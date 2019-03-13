#include <iostream>
using namespace std;

int main ()
{
  int r, c;
  char tmp;
  cin >> r >> c;
  bool snake[r+1][c+1] = {0};
  for (int x = 1; x <= r; x++) {
      for (int i = 1; i <= c; i++) {
          cin >> tmp;
          if (tmp=='S') {
              snake[x][i] = true;
          } else {
              snake[x][i] = false;
          }
      }
  }
  int grid[r+1][c+1] = {0}, g[r+1][c+1] = {0};
  int tot = 0;
  for (int x = 1; x <= r; x++) {
      for (int i = 1; i <= c; i++) {
          if (!snake[x][i]) {
              int cnt = 0, safe = 0, adj = 0;
              for (int z = x-1; z <= x+1; z++) {
                  for (int w = i-1; w <= i+1; w++) {
                      if (z >= 1 && w >= 1 && z <= r && w <= c && !snake[z][w] && (z != x || w != i)) {
                          safe++;
                      }
                      if (z >= 1 && w >= 1 && z <= r && w <= c && (z != x || w != i)) {
                          adj++;
                      }
                  }
              }
              g[x][i] = adj;
              grid[x][i] = safe;
              if ((adj-safe)*2 < adj) {
                tot++;
            }
          }
      }
  }
    cout << tot << endl;
  return 0;
}
