#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

long long criminal[100001], dp[100001] = {0};

//p1 is point we are considering, p2 is already in queue
inline double solve (pair <double, double> p1, pair <double, double> p2) {
  return (p1.first-p2.first)/(double)(criminal[(int)p1.second+1]-criminal[(int)p2.second+1]);
}

inline int s (int temp) {
  return temp*temp;
}

int main () {
  int n, h;
  scanf ("%d %d", &n, &h);
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &criminal[x]);
  }
  deque < pair <double, double> > monoq;
  for (int x = 1; x <= n; x++) {
    pair <double, int> cur = make_pair((double)(dp[x-1]+criminal[x]*criminal[x]), x-1);
    while (monoq.size() >= 2 && solve (cur, monoq[monoq.size()-1]) < solve (monoq[monoq.size()-1], monoq[monoq.size()-2])) {
      monoq.pop_back();
    }
    monoq.push_back(cur);
    while (monoq.size() >= 2 && solve (monoq[0], monoq[1]) < 2*criminal[x]) {
      monoq.pop_front();
    }
    dp[x] = dp[(int)monoq.front().second]+h+s(criminal[(int)monoq.front().second+1]-criminal[x]);
  }
  printf ("%lld\n", dp[n]);
}
