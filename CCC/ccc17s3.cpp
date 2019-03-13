#include <iostream>
#include <cstdio>
using namespace std;

int boards[2001] = {0}, len[4001] = {0};

int main() {
  int n, cur;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &cur);
    boards[cur]++;
  }
  for (int x = 2; x <= 4000; x++) {
    //for each possible height, what is the longest board we can make
    for (int i = 1; i <= x/2; i++) {
      if (x-i > 2000) {
        continue;
      }
      if (x%i==0 && x/i == 2) {
        len[x] += boards[i]/2;
      } else {
        len[x] += min (boards[i], boards[x-i]);
      }
    }
  }
  int greatest = 0, ways = 0;
  for (int x = 1; x <= 4000; x++) {
    if (len[x] > greatest) {
      greatest = len[x];
      ways = 1;
    } else if (len[x] == greatest) {
      ways++;
    }
  }
  cout << greatest << " " << ways << endl;
}
