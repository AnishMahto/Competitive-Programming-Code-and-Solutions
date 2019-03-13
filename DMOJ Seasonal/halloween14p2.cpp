#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
  vector < pair <long long, long long> > girls;
  vector <long long> wsum, csum, dp;
  vector <long long>::iterator it;
  char cmd;
  long long n, w, p, c;
  scanf ("%lld %lld", &n, &w);
  while (n--) {
    scanf (" %c", &cmd);
    if (cmd == 'A') {
      scanf ("%lld %lld", &p, &c);
      girls.push_back(make_pair(p,c));
      if (dp.size() == 0) {
        if (p <= w) {
          dp.push_back(c);
        } else {
          dp.push_back(0);
        }
        wsum.push_back(p);
        csum.push_back(c);
      } else if (p > w) {
        dp.push_back(dp.back());
        wsum.push_back(p + wsum.back());
        csum.push_back(c + csum.back());
      } else {
        it = lower_bound(wsum.begin(), wsum.end(), (wsum.back() - (w-p)));
        int pos = it - wsum.begin();
        if ((pos > 0 && wsum.back() - wsum[pos-1] + p > w) || (pos == 0 && wsum.back() + p > w)) {
          pos++;
        }
        if (pos > 0 && wsum.back() - wsum[pos-1] + p <= w) {
          dp.push_back(max(dp.back(), csum.back() - csum[pos-1] + c));
        } else if (pos == 0 && wsum.back() + p <= w) {
          dp.push_back(max(dp.back(), csum.back() + c));
        } else if (p <= w) {
          dp.push_back(max(dp.back(), c));
        } else {
          dp.push_back(dp.back());
        }
        wsum.push_back(p + wsum.back());
        csum.push_back(c + csum.back());
      }
      printf ("%lld\n", dp.back());
    } else {
      dp.pop_back();
      wsum.pop_back();
      csum.pop_back();
      girls.pop_back();
    }
  }
}
