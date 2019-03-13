#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <int, int> mods;

int main () {
  map <int, int>::iterator it;
  int n, m, cur;
  long long sum = 0, total = 0;
  scanf ("%d %d", &n, &m);
  mods.insert(make_pair(0, 1));
  for (int x = 0; x < n; x++) {
    scanf ("%d", &cur);
    sum += cur;
    sum %= m;
    it = mods.find(sum);
    if (it==mods.end()) {
      mods.insert(make_pair(sum, 1));
      continue;
    }
    total += it->second;
    it->second++;
  }
  cout << total << endl;
}
