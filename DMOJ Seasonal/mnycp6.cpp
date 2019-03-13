#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map <string, pair <int, int> > line;
//string, (pos, val)
int bit[10001] = {0}, rocks = 0, vals[10001] = {0};

int update (int pos, int val) {
  while (pos <= 10000) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}

int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & -pos;
  }
  return sum;
}


int main () {
  unordered_map <string, pair <int, int> >::iterator it, it2;
  cin.sync_with_stdio(0);
  cin.tie(0);
  char cmd;
  string temp, a, b;
  int c, sum = 0;
  cin >> c;
  while (c--) {
    sum = 0;
    cin >> cmd;
    if (cmd == 'A') {
      cin >> temp;
      it = line.find(temp);
      if (it != line.end()) {
        cout << "Can't add " << temp << "\n";
        continue;
      }
      rocks++;
      for (int x = 0; x < temp.length(); x++) {
        sum += (int)temp[x] - 96;
      }
      vals[rocks] = sum;
      line.insert(make_pair(temp, make_pair(rocks, sum)));
      update (rocks, sum);
    } else if (cmd == 'S') {
      cin >> a >> b;
      it = line.find(a);
      it2 = line.find(b);
      vals[it->second.first] = it2->second.second;
      vals[it2->second.first] = it->second.second;
      update (it2->second.first, it->second.second - it2->second.second);
      update (it->second.first, it2->second.second - it->second.second);
      int swap = it2->second.first;
      it2->second.first = it->second.first;
      it->second.first = swap;
    } else if (cmd == 'M') {
      cin >> a >> b;
      it = line.find(a);
      it2 = line.find(b);
      cout << query (max (it->second.first, it2->second.first)) - query (min (it->second.first, it2->second.first)-1) << "\n";
    } else if (cmd == 'R') {
      cin >> a >> temp;
      it = line.find(a);
      for (int x = 0; x < temp.length(); x++) {
        sum += (int)temp[x] - 96;
      }
      update (it->second.first, sum - vals[it->second.first]);
      vals[it->second.first] = sum;
      int pos = it->second.first;
      line.erase(it);
      line.insert(make_pair(temp, make_pair(pos, sum)));
    } else {
      cout << rocks << "\n";
    }
  }
}
