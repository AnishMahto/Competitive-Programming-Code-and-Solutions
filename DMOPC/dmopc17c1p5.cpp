#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > greatestBefore(1000001);
vector < pair <int, int> > q;
vector < pair <pair <int, int>, int> > lr;
//val, pos
int bit[1000001] = {0};

void add (int pos, int val) {
  while (pos <= 1000000) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}

int sum (int pos) {
  int count = 0;
  while (pos > 0) {
    count += bit[pos];
    pos -= pos & -pos;
  }
  return count;
}


int main () {
  int n, query, cur, l, r, curQ = 0, ans[1000001];
  scanf ("%d %d", &n, &query);
  q.push_back(make_pair(1000001, 0));
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &cur);
    while (cur > q.back().first) {
      q.pop_back();
    }
    //store all indexes which are peaks starting from this index
    greatestBefore[q.back().second].push_back(x);
    q.push_back(make_pair(cur, x));
  }
  for (int x = 0; x < query; x++) {
    scanf ("%d %d", &l, &r);
    lr.push_back(make_pair(make_pair(l, r), x));
  }
  sort (lr.begin(), lr.end());
  
  for (int x = 0; x <= n; x++) {
    for (int i = 0; i < greatestBefore[x].size(); i++) {
      add (greatestBefore[x][i], 1);
    }
    while (curQ < lr.size() && lr[curQ].first.first == x+1) {
      ans[lr[curQ].second] = sum (lr[curQ].first.second) - sum (lr[curQ].first.first-1);
      curQ++;
    }
  }
  for (int x = 0; x < query; x++) {
    printf ("%d\n", ans[x]);
  }
}
