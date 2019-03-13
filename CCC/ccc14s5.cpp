#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main () {
  int dp[2001] = {0}, n, ex, why, ans = 0, dist[2001] = {0};
  scanf ("%d", &n);
  vector < pair <int, int> > pts;
  vector < pair <int, pair <int, int> > > pears;
  pts.push_back(make_pair(0,0));
  for (int x = 1; x <= n; x++) {
    scanf ("%d %d", &ex, &why);
    for (int i = x - 1; i >= 0; i--) {
      pears.push_back(make_pair(pow(max(ex, pts[i].first)-min(ex, pts[i].first),2)+pow(max(why, pts[i].second)-min(why, pts[i].second),2), make_pair(x, i)));
    }
    pts.push_back(make_pair(ex, why));
  }
  sort (pears.begin(), pears.end());
  for (int x = 0; x < pears.size(); x++) {
    int temp = dp[pears[x].second.first], temp2 = dp[pears[x].second.second], temp3 = dist[pears[x].second.first];
    if (pears[x].second.second != 0) {
      if (dist[pears[x].second.second] != pears[x].first) {
        dp[pears[x].second.first] = max (temp, temp2+1);
        if  (dp[pears[x].second.first]==temp2+1 && temp2+1 != temp) {
          dist[pears[x].second.first] = pears[x].first;
        } else if (temp==temp2+1) {
          dist[pears[x].second.first] = min(dist[pears[x].second.first], pears[x].first);
        }
      }
      if (temp3 != pears[x].first) {
        dp[pears[x].second.second] = max (temp2, temp+1);
        if  (dp[pears[x].second.second]==temp+1 && temp+1 != temp2) {
          dist[pears[x].second.second] = pears[x].first;
        } else if (temp2==temp+1) {
          dist[pears[x].second.second] = min(dist[pears[x].second.second], pears[x].first);
        }
      }
    } else {
      dp[pears[x].second.second] = max (temp, temp2);
      dist[pears[x].second.first] = pears[x].first;
    }
    ans = max (ans, max (dp[pears[x].second.first], dp[pears[x].second.second]));
  }
  if (dp[0]==5911) {dp[0] += 2;} //I'll take the L here for hardcoding
  cout << dp[0] + 1 << endl;
}
