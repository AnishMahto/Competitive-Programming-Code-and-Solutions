#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <deque>
#include <bitset>
//#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;
typedef vector <int> vi;
typedef vector < pair <int, int> > vpii;
#define mset(a, b) memset (a,(b), sizeof(a))
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(x,a,b) for (int x = a; x < b; x++)
#define sd(x) scanf ("%d", &x);
#define sl(x) scanf ("%lld", &x);
#define sc(x) scanf (" %c", &x);
#define rnd(a, x) (double)round(a*(pow(10,x)))*(pow((double)10,-x))
#define dbg(x) x << "!"
#define dbg2(x) x << " ~"

const int sqr = sqrt (100000) + 1;
bitset <1001> uni[sqr+1];
deque <int> ids;
map <int, int> id, rev;
map<int,int>::iterator it, it2;
int sz, rem[1001] = {0}, nums[100001], group[100001], nxt[100001];
int n, cur, q;

void add (int pos, int val) {
  int ID;
  it = id.find(val);
  if (it!=id.end()) {
    ID = it->second;
  } else {
    ID = ids[0];
    id.insert(mp(val, ID));
    rev.insert(mp(ID, val));
    ids.pop_front();
  }
  rem[ID]++;
  uni[group[pos]].set(ID);
  nums[pos] = ID;
}

void del (int pos) {
  it = rev.find(nums[pos]);
  int ID = nums[pos];
  rem[ID]--;
  if (rem[ID]==0) {
    id.erase(it->second);
    rev.erase(it);
  }
  ids.push_back(ID);
  int fix = pos+1;
  bool duplicate = false;
  while (fix <= n && group[fix] == group[pos]) {
    if (nums[pos]==nums[fix]) {
      duplicate = true;
      break;
    }
    fix++;
  }
  fix = pos-1;
  if (!duplicate) {
    while (fix >= 1 && group[fix] == group[pos]) {
      if (nums[pos]==nums[fix]) {
        duplicate = true;
        break;
      }
      fix--;
    }
  }
  if (!duplicate) {
    uni[group[pos]].flip(ID);
  }
}

int query (int l, int r) {
  bitset <1001> temp;
  int pos = l;
  while (pos <= r && group[pos]==group[l]) {
    temp.set (nums[pos]);
    pos++;
  }
  if (group[l]==group[r]) {
    return temp.count();
  }
  pos = nxt[l];
  while (group[pos] != group[r]) {
    temp |= uni[group[pos]];
    pos = nxt[pos];
    if (pos==-1) {
      break;
    }
  }
  pos = r;
  while (pos >= 1 && group[pos]==group[r]) {
    temp.set (nums[pos]);
    pos--;
  }
  return temp.count();
}

int main () {
  int t,a,b;
  loop (x, 0, 1000) {
    ids.pb(x);
  }
  sd (n); sd (q);
  sz = sqrt ((double)n);
  loop (x, 1, n+1) {
    group[x] = x/sz + 1;
    sd (cur);
    it = id.find(cur);
    if (it!=id.end()) {
      rem[it->second]++;
      nums[x] = it->second;
      uni[group[x]].set (it->second);
    } else {
      rev.insert (mp(ids[0], cur));
      id.insert(mp(cur, ids[0]));
      rem[ids[0]]++;
      nums[x] = ids[0];
      uni[group[x]].set (ids[0]);
      ids.pop_front();
    }
  }
  nxt[n] = -1;
  for (int x = n-1; x >= 1; x--) {
    if (group[x]==group[x+1]) {
      nxt[x] = nxt[x+1];
    } else {
      nxt[x] = x+1;
    }
  }
  loop (x, 0, q) {
    sd(t); sd(a); sd(b);
    if (t==1) {
      del(a);
      add(a,b);
    } else {
      printf ("%d\n", query(a,b));
    }
  }
}
