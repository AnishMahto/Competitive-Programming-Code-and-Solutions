#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int find_subset(int l, int u, int w[], int n, int result[]) {
  vector <long long> sum(n);
  vector < pair <int, int> > tempW(n);
  //val, pos found at
  for (int x = 0; x < n; x++) {
    tempW[x].first = w[x];
    tempW[x].second = x;
  }
  sort(tempW.begin(), tempW.end());
  for (int x = 0; x < n; x++) {
    sum[x] = tempW[x].first;
    if (x != 0) {
      sum[x] += sum[x-1];
    }
    if (tempW[x].first >= l && tempW[x].first <= u) {
      result[0] = tempW[x].second;
      return 1;
    }
  }
  vector <long long>::iterator it;
  for (int x = 0; x < n; x++) {
    if (x != 0) {
      it = lower_bound(sum.begin()+x, sum.end(), l+sum[x-1]);
    } else {
      it = lower_bound(sum.begin(), sum.end(), l);
    }
    int pos = (it-sum.begin());
    long long subtract = 0;
    if (x != 0) {
      subtract = sum[x-1];
    }
    if (pos < n && sum[pos] - subtract <= u && sum[pos] - subtract >= l) {
      //answer found
      for (int i = x; i <= pos; i++) {
        result[i-x] = tempW[i].second;
      }
      return (pos-x+1);
    } else if (x == n-1) {
      return 0;
    }
  }
}

int main () {
  int n, l, u;
  cin >> n >> l >> u;
  int temp[n], result[n];
  for (int x = 0; x < n; x++) {
    cin >> temp[x];
  }
  find_subset (l, u, temp, n, result);
  //return 0;
}
