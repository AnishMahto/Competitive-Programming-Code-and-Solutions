#include <iostream>
#include <cstdio>
#include <deque>
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;

int main() {
  int n, m, c, val;
  bool found = false;
  deque < pair <int, int> > minq, maxq;
  scan (n); scan(m); scan(c);
  if (n < m) {
      printf ("NONE\n");
      return 0;
  }
  for (int x = 1; x <= m; x++) {
      scan(val);
      while (minq.size() > 0 && val <= minq.back().first) {
          minq.pop_back();
      }
      minq.push_back(make_pair(val, x));
      while (maxq.size() > 0 && val >= maxq.back().first) {
          maxq.pop_back();
      }
      maxq.push_back(make_pair(val, x));
  }
  if (maxq.front().first - minq.front().first <= c) {
      printf ("1\n");
      found=true;
  }
  for (int x = m+1; x <= n; x++) {
      scan(val);
      while (minq.size() > 0 && val <= minq.back().first) {
          minq.pop_back();
      }
      while (minq.size() > 0 && minq.front().second <= x-m) {
          minq.pop_front();
      }
      minq.push_back(make_pair(val, x));
      while (maxq.size() > 0 && val >= maxq.back().first) {
          maxq.pop_back();
      }
      while (maxq.size() > 0 && maxq.front().second <= x-m) {
          maxq.pop_front();
      }
      maxq.push_back(make_pair(val, x));
      if (maxq.front().first - minq.front().first <= c) {
        printf ("%d\n", (x-m+1));
        found=true;
      }
  }
  if (!found) {
      printf ("NONE\n");
  }
}
