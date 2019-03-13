#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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

int bit[100001] = {0}, n, Q;

void add (int pos, int val) {
  while (pos <= n) {
    bit[pos] += val;
    pos += pos & (-pos);
  }
}

long long query (int pos) {
  long long sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & (-pos);
  }
  return sum;
}

int main () {
  scanint(n);
  int counter = n - 1;
  vector < pair <int, int> > trees(n);
  for (int x = 0; x < n; x++) {
    scanint(trees[x].first);
    trees[x].second = x+1;
  }
  sort (trees.begin(), trees.end());
  scanint (Q);
  vector < pair < pair <int, int> , pair <int, int> > > q (Q);
  long long order[Q+1] = {0};
  for (int x = 0; x < Q; x++) {
    scanint (q[x].second.first);
    scanint (q[x].second.second);
    scanint (q[x].first.first);
    q[x].second.first++;
    q[x].second.second++;
    q[x].first.second = x;
  }
  sort (q.begin(), q.end());
  for (int x = Q-1; x >= 0; x--) {
    while (counter >= 0 && trees[counter].first >= q[x].first.first) {
      add (trees[counter].second, trees[counter].first);
      counter--;
    }
    order[q[x].first.second] = query (q[x].second.second) - query (q[x].second.first - 1);
  }
  for (int x = 0; x < Q; x++) {
    printf ("%lld\n", order[x]);
  }
}
