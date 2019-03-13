#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int tree[200001], n, m, dp[200001][19] = {0};
vector < vector <int> > graph(200001);

int solve (int pos, int c) {
  if (dp[pos][c] != 0) {
    return dp[pos][c];
  } else if (graph[pos].size()==0) {
    return 0;
  } else {
    dp[pos][c] = 0;
    int arr[(int)graph[pos].size()+1] = {0};
    for (int x = 1; x <= 18; x++) {
      if (x != c) {
        for (int i = 0; i < graph[pos].size(); i++) {
          if (arr[i]==0) {
            arr[i] = solve (graph[pos][i], x)+x;
            dp[pos][c] += solve (graph[pos][i], x)+x;
          } else if (solve (graph[pos][i], x)+x < arr[i]) {
            dp[pos][c] -= arr[i]; 
            arr[i] = solve (graph[pos][i], x)+x;
            dp[pos][c] += arr[i];
          }
        }
      }
    }
    return dp[pos][c];
  }
}

int main() {
  int t;
  scan(t);
  for (int u = 1; u <= t; u++) {
    memset (dp, 0, sizeof(dp));
    scan(n);
    for (int x = 1; x <= n; x++) { graph[x].clear(); }
    for (int x = 1; x <= n; x++) {
      scan(tree[x]);
      graph[tree[x]].push_back(x);
    }
    int ans = 200000000;
    for (int x = 1; x <= 18; x++) {
      ans = min (ans, solve(1, x)+x);
    }
    printf ("Case #%d: %d\n", u, ans);
  }
}
