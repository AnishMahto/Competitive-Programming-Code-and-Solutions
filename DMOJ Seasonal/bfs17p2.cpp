#include <iostream>
#include <cstdio>
using namespace std;

//red, orange, yellow, green, blue, black.
int c[6] = {0};

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string temp;
  cin >> n;
  for (int x = 0; x < n; x++) {
    cin >> temp;
    if (temp == "red") {
      c[0]++;
    } else if (temp == "orange") {
      c[1]++;
    } else if (temp == "yellow") {
      c[2]++;
    } else if (temp == "green") {
      c[3]++;
    } else if (temp == "blue") {
      c[4]++;
    } else {
      c[5]++;
    }
  }
  int prev = -1;
  int len = 0;
  while (n > 0) {
    int greatest = 0;
    int pos;
    for (int x = 0; x < 6; x++) {
      if (c[x] > greatest && x != prev) {
        greatest = c[x];
        pos = x;
      }
    }
    if (greatest == 0) {
      cout << len << endl;
      return 0;
    } else {
      prev = pos;
      c[pos]--;
      len++;
    }
  }
  cout << len << endl;
}
