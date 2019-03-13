#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
using namespace std;

map < pair <int, int>, int > id;
//slope, intercept, id

int main () {
  map < pair <int, int>, int >::iterator it2, it3;
  int n, q;
  scanf ("%d %d", &n, &q);
  vector < pair <int, int> > mem;
  //slope, y-intercept, will be used from descending slope to ascending slope.
  for (int x = 0; x < n; x++) {
    int t1, t2;
    scanf ("%d %d", &t2, &t1);
    mem.push_back(make_pair(t1, t2));
    id.insert(make_pair(make_pair(t1, t2), x));
  }
  sort (mem.begin(), mem.end());
  vector < pair < pair <double, double>, pair <int, int> > > env;
  //range x->i, slope and y-intercept
  for (int x = 0; x < mem.size(); x++) {
    if (env.size() == 0) {
      env.push_back(make_pair(make_pair(0, 2000000001), make_pair(mem[x].first, mem[x].second)));
    } else {
      double m1, m2, b1, b2, intersection;
      m1 = mem[x].first; b1 = mem[x].second;
      m2 = env.back().second.first; b2 = env.back().second.second;
      if (m1 == m2 && b1 == b2) {
        continue;  
      }
      intersection = (b2 - b1)/(m1 - m2);
      while (env.size() != 0 && intersection <= env.back().first.first) {
        env.pop_back();
        m1 = mem[x].first; b1 = mem[x].second;
        m2 = env.back().second.first; b2 = env.back().second.second;
        if (m1 == m2 && b1 == b2) {
          break;  
        }
        intersection = (b2 - b1)/(m1 - m2);
      }
      if (env.size() == 0) {
        env.push_back(make_pair(make_pair(0, 2000000001), make_pair(mem[x].first, mem[x].second)));
      } else {
        env.back().first.second = intersection;
        env.push_back(make_pair(make_pair(intersection, 2000000001), make_pair(mem[x].first, mem[x].second)));
      }
    }
  }
  double x;
  vector < pair < pair <double, double>, pair <int, int> > >::iterator it;
  for (int i = 0; i < q; i++) {
    scanf ("%lf", &x);
    int lo = 0, up = env.size()-1;
    while (lo < up) {
      int mid = lo + (up-lo)/2;
      if (env[mid].first.first >= x) {
        up = mid;
      } else {
        lo = mid + 1;
      }
    }
    int pos = lo;
    while (pos > 0 && env[pos-1].first.first < x && env[pos-1].first.second > x) {
      pos--;
    }
    //in case x val is an intersection point;
    it2 = id.find(make_pair(env[pos].second.first, env[pos].second.second));
    if (abs(x - env[pos].first.first) < 0.001 && pos > 0) {
      it3 = id.find(make_pair(env[pos-1].second.first, env[pos-1].second.second));
      printf ("%d\n", min(it2->second, it3->second));
    } else if (abs(x - env[pos].first.second) < 0.001 && pos < env.size()-1) {
      it3 = id.find(make_pair(env[pos+1].second.first, env[pos+1].second.second));
      printf ("%d\n", min(it2->second, it3->second));
    } else {
      printf ("%d\n", it2->second);
    }
  }
  return 0;
}
/*
y_1 = m_1x + b_1
y_2 = m_2x + b_2

point of intersection
m_1x + b_1 = m_2x + b_2
x(m_1 - m_2) = b_2 - b_1
x = (b_2 - b_1)/(m_1 - m_2)
*/
