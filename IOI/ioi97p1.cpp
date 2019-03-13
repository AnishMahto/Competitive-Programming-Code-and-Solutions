#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int vehicles, w, h, terrain[255][255] = {0}, dp[255][255];

int solve (int ex, int why) {
  if (terrain[why][ex] == 1) {
    return -1;
  }
  if (dp[why][ex] != -1) {
    return dp[why][ex];
  } else if (ex == w-1 && why == h-1) {
    if (terrain[why][ex] == 1) {
      dp[why][ex] = -1;
    } else if (terrain[why][ex] == 0) {
      dp[why][ex] = 0;
    } else {
      dp[why][ex] = 1;
    }
    return dp[why][ex];
  }
  if (why < h-1 && solve (ex, why+1) != -1) {
    if (terrain[why][ex] == 0) {
      dp[why][ex] = max (dp[why][ex], solve (ex, why+1));
    } else {
      dp[why][ex] = max (dp[why][ex], solve (ex, why+1)+1);
    }
  }
  if (ex < w-1 && solve (ex+1, why) != -1) {
    if (terrain[why][ex] == 0) {
      dp[why][ex] = max (dp[why][ex], solve (ex+1, why));
    } else {
      dp[why][ex] = max (dp[why][ex], solve (ex+1, why)+1);
    }
  }
  return dp[why][ex];
}

void printAns (int ex, int why, int v) {
  terrain[why][ex] = 0;
  if (ex == w-1 && why == h-1) {
    return;
  }
  if (why < h-1 && ex < w-1 && terrain[why+1][ex] != 1 && terrain[why][ex+1] != 1) {
    if (dp[why][ex+1] > dp[why+1][ex]) {
      printf ("%d 1\n", v);
      printAns (ex+1, why, v);
    } else {
      printf ("%d 0\n", v);
      printAns (ex, why+1, v);
    }
  } else if (why < h-1 && terrain[why+1][ex] != 1) {
    printf ("%d 0\n", v);
    printAns (ex, why+1, v);
  } else if (ex < w-1 && terrain[why][ex+1] != 1) {
    printf ("%d 1\n", v);
    printAns (ex+1, why, v);
  }
}

int main () {
  scanf ("%d %d %d", &vehicles, &w, &h);
  for (int x = 0; x < h; x++) {
    for (int i = 0; i < w; i++) {
      scanf ("%d", &terrain[x][i]);
    }
  }
  for (int x = 1; x <= vehicles; x++) {
    memset (dp, -1, sizeof(dp));
    solve (0, 0);
    printAns (0, 0, x);
  }
}
