#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

vector < map <int, int> > importantDay(1000001);
vector < pair <char, pair <int, int> > > cmd;
vector < pair <int, int> > importantDays;

int main () {
  int n, q, cur, a, b, impPos = 0;
  int pos[1000001] = {0}, day = 0;
  char c;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &pos[x]);
  }
  scanf ("%d", &q);
  for (int x = 0; x < q; x++) {
    scanf (" %c %d %d", &c, &a, &b);
    cmd.push_back(make_pair(c, make_pair(a, b)));
    if (c == 'Q') {
      if (b == 0) {
        importantDay[a].insert(make_pair(b, pos[a]));
      } else {
        importantDay[a].insert(make_pair(b, -1));
        importantDays.push_back(make_pair(b, a));
      }
    }
  }
  sort (importantDays.begin(), importantDays.end());
  map <int, int>::iterator it;
  for (int x = 0; x < cmd.size(); x++) {
    int person = cmd[x].second.first, to = cmd[x].second.second;
    
    if (cmd[x].first == 'C') {
      day++;
      pos[person] = to;
      
      while (impPos < importantDays.size() && importantDays[impPos].first == day) {
        
        it = importantDay[importantDays[impPos].second].find(day);
        
        if (it != importantDay[importantDays[impPos].second].end()) {
          it->second = pos[importantDays[impPos].second];
        }
        
        impPos++;
      }
    } else {
      it = importantDay[person].find(to);
      //pos[person] = it->second;
      printf ("%d\n", it->second);
    }
  }
}
