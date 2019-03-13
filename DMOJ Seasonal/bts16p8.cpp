#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <int, int> points;
vector <int> order;
vector < pair <int, pair <int, int> > > books(5*100001);
int seg[4*1000001] = {0}, lazy[4*1000001] = {0}, mod = 1000000007;

void update (int pos, int l, int r, int tl, int tr, int val) {
  if (lazy[pos] != 0) {
    seg[pos] = lazy[pos];
    if (l != r) {
      lazy[2*pos] = max (lazy[2*pos], lazy[pos]);
      lazy[2*pos+1] = max (lazy[2*pos+1], lazy[pos]);
    }
    lazy[pos] = 0;
  }
  if (r < l || l > tr || r < tl) {
    return;
  } else if (l >= tl && r <= tr) {
    seg[pos] = val;
    if (l != r) {
      lazy[2*pos] = val;
      lazy[2*pos+1] = val;
    }
  } else {
    int mid = l+(r-l)/2;
    update (2*pos, l, mid, tl, tr, val);
    update (2*pos+1, mid+1, r, tl, tr, val);
    seg[pos] = max (seg[2*pos], seg[2*pos+1]);
  }
}

int query (int pos, int l, int r, int tl, int tr) {
  if (lazy[pos] != 0) {
    seg[pos] = lazy[pos];
    if (l != r) {
      lazy[2*pos] = lazy[pos];
      lazy[2*pos+1] = lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (r < l || l > tr || r < tl) {
    return 0;
  } else if (l >= tl && r <= tr) {
    return seg[pos];
  } else {
    int mid = l+(r-l)/2;
    return max (query (2*pos, l, mid, tl, tr), query (2*pos+1, mid+1, r, tl, tr));
  }
}

int main () {
  int n;
  long long total = 0;
  scanf ("%d", &n);
  for (int x = 0; x < n; x++) {
    scanf ("%d %d %d", &books[x].first, &books[x].second.first, &books[x].second.second);
    points.insert (make_pair(books[x].first, 0));
    points.insert (make_pair(books[x].first+books[x].second.first, 0));
    total -= (long long)((long long)(books[x].second.first%mod)*(long long)(books[x].second.second%mod)%mod);
    total += mod;
    total %= mod;
  }
  map <int, int>::iterator it;
  for (it = points.begin(); it != points.end(); it++) {
    order.push_back(it->first);
    it->second = order.size()-1;
  }
  for (int x = 0; x < n; x++) {
    int tl = points[books[x].first], tr = points[books[x].second.first+books[x].first]-1, currentH = query (1, 0, order.size()-1, tl, tr);
    update (1, 0, order.size()-1, tl, tr, currentH+books[x].second.second);
  }
  for (int x = 1; x < order.size(); x++) {
    total += (long long)((long long)((long long)(order[x]-order[x-1])%mod)*(long long)(query (1, 0, order.size()-1, x-1, x-1)%mod)%mod);
    total += mod;
    total %= mod;
  }
  cout << total << "\n";
}
