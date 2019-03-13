#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
#define gc getchar_unlocked
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int BLOCK_SIZE;

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

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

long long bit[100005] = {0};
int n, q;
vector <int> compress;
vector < pair <pair <int, int>, int> > queries;

inline void add (int pos, int val) {
  while (pos <= 100001) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}

inline long long query (int pos) {
  long long sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  vector <int>::iterator it;
  //scanint (n);
  scanf ("%d", &n);
  BLOCK_SIZE = sqrt (n);
  vector <int> nums(n+1), nums2(n+1), pos(n+1);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &nums[x]);
    nums2[x] = nums[x];
  }
  nums2[0] = -1;
  sort (nums2.begin(), nums2.end());
  compress.push_back(nums2[0]);
  for (int x = 1; x < nums2.size(); x++) {
    if (nums2[x] != nums2[x-1]) {
      compress.push_back(nums2[x]);
    }
  }
  for (int x = 1; x <= n; x++) {
    it = lower_bound(compress.begin(), compress.end(), nums[x]);
    pos[x] = it - compress.begin();
  }
  scanf ("%d", &q);
  for (int x = 0; x < q; x++) {
    scanf ("%d %d", &a, &b);
    queries.push_back(make_pair(make_pair(a, b), x));
  }
  sort (queries.begin(), queries.end(), mo_cmp);
  int l = 1, r = 1, total = 1;
  long long ans[100001], inv = 0;
  add (pos[1], 1);
  for (int x = 0; x < queries.size(); x++) {
    int L = queries[x].first.first, R = queries[x].first.second;
    if (r != R) {
      while (r < R) {
        r++;
        inv += total - query (pos[r]);
        add (pos[r], 1);
        total++;
      }
    }
    if (l != L) {
      while (l < L) {
        inv -= query (pos[l]-1);
        add (pos[l], -1);
        l++;
        total--;
      }
    }
    if (l != L) {
      while (l > L) {
        l--;
        inv += query (pos[l]-1);
        add (pos[l], 1);
        total++;
      }
    }
    if (r != R) {
      while (r > R) {
        inv -= total - query (pos[r]);
        add (pos[r], -1);
        r--;
        total--;
      }
    }
    ans[queries[x].second] = inv;
  }
  for (int x = 0; x < q; x++) {
    printf ("%lld\n", ans[x]);
  }
}
