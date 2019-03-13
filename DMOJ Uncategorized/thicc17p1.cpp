#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long power (int c, int x) {
  long long temp = 1;
  for (int i = 0; i < x; i++) {
    temp *= c;
    temp %= 1000000007;
  }
  return temp;
}

int main () {
  long long n, m, cur, pos = 0, total = 0;
  long long level = 0, used = 0;
  cin >> n >> m;
  vector <long long> flowers(n);
  for (int x = 0; x < n; x++) {
    cin >> flowers[x];
  }
  sort (flowers.begin(), flowers.end());
  for (int x = flowers.size() - 1; x >= 0; x--) {
    total += power (flowers[x], level);
    total %= 1000000007;
    used++;
    if (used == m) {
      used = 0;
      level++;
    }
  }
  cout << total << endl;
}
