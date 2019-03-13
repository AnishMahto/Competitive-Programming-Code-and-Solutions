#include <iostream>
#include <cstdio>
#include <deque>
#include <string.h>
using namespace std;

long long n, L, dp[3*1000002];
deque <long long> pts;
long long sum[3*1000002];
//(dp[x] + X^2, X) 
double slope (long long f, long long s) {
  return (double)((dp[f] + sum[f]*sum[f])-(dp[s] + sum[s]*sum[s]))/(double)(2*(sum[f]-sum[s]));
}

int main () {
  memset(dp, sizeof(dp), 0);
  memset(sum, sizeof(sum), 0);
  long long temp, X;
  scanf ("%lld %lld", &n, &L);
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &temp);
    sum[x] = temp + sum[x-1] + 1;
  }
  sum[0] = dp[0] = 0;
  L++;
  pts.push_back(0);
  for (int x = 1; x <= n; x++) {
    
    while (pts.size() >= 2 && (slope(pts.front(), pts[1]) < (sum[x]-L))) {
      pts.pop_front();
    }
    
    X = (sum[x]-sum[pts.front()]);
    dp[x] = dp[pts.front()] + (X-L)*(X-L);
    while (pts.size() >= 2) {
      if (slope(x, pts.back()) < slope(pts.back(), pts[pts.size()-2])) {
        pts.pop_back();
      } else {
        break;
      }
    }
    pts.push_back(x);
  }
  cout << dp[n] << endl;
}
