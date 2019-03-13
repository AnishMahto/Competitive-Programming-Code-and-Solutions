#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main () {
  int n, A, C, a, b;
  scanint(n); scanint(A); scanint(C);
  vector < pair <int, int> > events;
  for (int x = 0; x < A; x++) {
    scanint(a); scanint(b);
    events.push_back(make_pair(a, 1));
    events.push_back(make_pair(b + 1, -1));
  }
  for (int x = 0; x < C; x++) {
    scanint(a); scanint(b);
    events.push_back(make_pair(a, -100001));
    events.push_back(make_pair(b, +100001));
  }
  sort (events.begin(), events.end());
  int counter = 1, tim = 0;
  long long sum = events[0].second;
  while (counter != events.size()) {
    if (sum > 0) {
      if (events[counter-1].second < -1 || events[counter-1].second >= 100001) {
        tim += events[counter].first - events[counter-1].first - 1;
      } else {
        tim += events[counter].first - events[counter-1].first;
      }
    }
    sum += events[counter].second;
    counter++;
  }
  cout << tim << endl;
}
