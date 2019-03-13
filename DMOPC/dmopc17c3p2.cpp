#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>
using namespace std;

bool towers[4][100001] = {0};
int n;
vector <int> steps;
bool check (int t) {
  int ones = 0;
  for (int x = 1; x < n; x++) {
    if (towers[t][x]==1) {
      towers[t][x] = 0;
      steps.push_back(x+1);
      if (x+1 <= n) {
        towers[t][x+1] = !towers[t][x+1];
      }
      if (x+2 <= n) {
        towers[t][x+2] = !towers[t][x+2];
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    if (towers[t][x]) {
      return false;
    }
  }
  printf ("%d\n", (int)steps.size());
  for (int x = 0; x < steps.size(); x++) {
    printf ("%d\n", steps[x]);
  } printf ("\n");
  return true;
}

int main () {
  int cur;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &cur);
    if (cur==1) {
      towers[0][x] = true;
    } else {
      towers[0][x] = false;
    }
    towers[1][x] = towers[2][x] = towers[3][x] = towers[0][x];
  }
  //if towers == 1
  if (n==1) {
    if (towers[1][1]==0) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << 1 << endl << 1 << endl;
    }
  }
  //try neither
  if (check(0)) {
    return 0;
  }
  //try first
  steps.clear();
  steps.push_back(1);
  towers[1][1] = !towers[1][1];
  towers[1][2] = !towers[1][2];
  if (check(1)) {
    return 0;
  }
  //try second
  steps.clear();
  steps.push_back(n);
  towers[2][n] = !towers[2][n];
  towers[2][n-1] = !towers[2][n-1];
  if (check(2)) {
    return 0;
  }
  //try both
  steps.clear();
  steps.push_back(1);
  steps.push_back(n);
  towers[3][1] = !towers[3][1];
  towers[3][2] = !towers[3][2];
  towers[3][n] = !towers[3][n];
  towers[3][n-1] = !towers[3][n-1];
  if (check(3)) {
    return 0;
  }
}
