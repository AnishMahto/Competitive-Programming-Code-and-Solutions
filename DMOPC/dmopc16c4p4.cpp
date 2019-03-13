#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int n, BLOCK_SIZE, arr[100001] = {0};

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

int main () {
  int q, a, b, ans[100001], freq[100001] = {0}, evenFreq = 0;
  scanf ("%d", &n);
  for (int x = 0; x < n; x++) {
    scanf ("%d", &arr[x]);
  }
  scanf ("%d", &q);
  BLOCK_SIZE = sqrt ((float)n);
  vector < pair < pair <int, int>, int> > query(q);
  for (int x = 0; x < q; x++) {
    scanf ("%d %d", &query[x].first.first, &query[x].first.second);
    query[x].second = x;
  }
  sort (query.begin(), query.end(), mo_cmp);
  int l = 0, r = 0;
  for (int x = 0; x < q; x++) {
    int tl = query[x].first.first-1, tr = query[x].first.second-1;
    while (l < tl) {
      freq[arr[l]]--;
      if (freq[arr[l]] >= 1) {
        if (freq[arr[l]]%2==0) {
          evenFreq++;
        } else {
          evenFreq--;
        }
      }
      l++;
    }
    while (r <= tr) {
      freq[arr[r]]++;
      if (freq[arr[r]] > 1) {
        if (freq[arr[r]]%2==0) {
          evenFreq++;
        } else {
          evenFreq--;
        }
      }
      r++;
    }
    while (l > tl) {
      freq[arr[l-1]]++;
      if (freq[arr[l-1]] > 1) {
        if (freq[arr[l-1]]%2==0) {
          evenFreq++;
        } else {
          evenFreq--;
        }
      }
      l--;
    }
    while (r > tr + 1) {
      freq[arr[r-1]]--;
      if (freq[arr[r-1]] >= 1) {
        if (freq[arr[r-1]]%2==0) {
          evenFreq++;
        } else {
          evenFreq--;
        }
      }
      r--;
    }
    ans[query[x].second] = evenFreq;
  }
  for (int x = 0; x < q; x++) {
    printf ("%d\n", ans[x]);
  }
}
