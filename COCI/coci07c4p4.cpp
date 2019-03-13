#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int dp[5001][501] = {0}, peeps[501], n, t;
pair <int, int> nextState[5001][501];
int timeForABreak[501];

int solve (int pos, int tim) {
  if (dp[tim][pos] != -1) {
    return dp[tim][pos];
  }
  if (pos == -1) {
    return tim;
  }
  dp[tim][pos] = tim;
  if (peeps[pos] <= tim) {
    dp[tim][pos] = min (solve(pos-1, tim-peeps[pos]), solve(pos-1, tim));
    if (dp[tim][pos] == solve(pos-1, tim-peeps[pos])) {
      nextState[tim][pos] = make_pair(pos-1, tim-peeps[pos]);
    } else {
      nextState[tim][pos] = make_pair(pos-1, tim);
    }
  } else {
    dp[tim][pos] = solve(pos-1, tim);
    nextState[tim][pos] = make_pair(pos-1, tim);
  }
  return dp[tim][pos];
}

int main () {
  memset(timeForABreak, -1, sizeof(timeForABreak));
  memset(dp, -1, sizeof(dp));
  scanf ("%d %d", &t, &n);
  for (int x = 0; x < n; x++) {
    scanf ("%d", &peeps[x]);
  }
  solve (n-1, t);
  int pos = n-1, tim = t;
  while (pos > -1) {
    pair <int, int> temp = nextState[tim][pos]; 
    if (temp.second != tim) {
      timeForABreak[pos] = 1;
    }
    pos = temp.first;
    tim = temp.second;
  }
  int secondGroupTim = 0, firstGroupTim = 0;
  for (int x = 0; x < n; x++) {
    if (timeForABreak[x] == -1) {
      timeForABreak[x] = secondGroupTim;
      secondGroupTim += peeps[x];
    } else {
      timeForABreak[x] = firstGroupTim;
      firstGroupTim += peeps[x];
    }
  }
  for (int x = 0; x < n; x++) {
    printf ("%d ", timeForABreak[x]);
  }
}
