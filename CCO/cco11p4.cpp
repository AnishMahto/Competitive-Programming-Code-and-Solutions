#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int count[100001] = {0};
map <int, int> supervisors;

int main () {
  int current, n;
  scanf ("%d", &n);
  map <int, int>::iterator it;
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &current);
    if (x == 1) {
      supervisors.insert (make_pair(current, x));
      it = supervisors.find(current);
    } else {
      it = supervisors.lower_bound(current);
      if (it == supervisors.begin()) {
        cout << "NO" << endl;
        return 0;
      } else {
        it--;
      }
      if (it->first < current) {
        count[it->second]++;
        if (count[it->second] == 2) {
          supervisors.erase(it);
        }
        supervisors.insert(make_pair(current, x));
      }
    }
  }
  cout << "YES" << endl;
}
