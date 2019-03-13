#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

vector < vector <int> > graph(3001);
vector < vector <int> > graph2(3001);
int aBall, bBall, aStart, bStart;
int dp[3001];

int solveA () {
  priority_queue < pair <int, int>, vector< pair <int, int> >, greater< pair <int, int> > > pq;
  for (int x = 0; x < 3001; x++) {
    dp[x] = 100000000;
  }
  dp[aStart] = 0;
  for (int x = 0; x < graph[aStart].size(); x++) {
    pq.push(make_pair(dp[aStart]+1, graph[aStart][x]));
  }
  while (!pq.empty()) {
    int pos = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    if (dp[pos] > cost) {
      dp[pos] = cost;
      if (dp[pos]+1 < dp[aBall]) {
      
      for (int x = 0; x < graph[pos].size(); x++) {
        if (dp[pos]+1 < dp[graph[pos][x]]) {
          dp[graph[pos][x]] = dp[pos]+1;
          pq.push(make_pair(dp[pos]+1, graph[pos][x]));
        }
      }
      
      }
    }
  }
  if (dp[aBall] == -1) {
    dp[aBall] = 100000000;
  }
  return dp[aBall];
}

int solveB () {
  priority_queue < pair <int, int>, vector< pair <int, int> >, greater< pair <int, int> > > pq;
  for (int x = 0; x < 3001; x++) {
    dp[x] = 100000000;
  }
  dp[bStart] = 0;
  for (int x = 0; x < graph2[bStart].size(); x++) {
    pq.push(make_pair(dp[bStart]+1, graph2[bStart][x]));
  }
  while (!pq.empty()) {
    int pos = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    if (dp[pos] > cost) {
      dp[pos] = cost;
      if (dp[pos]+1 < dp[bBall]) {
      
      for (int x = 0; x < graph2[pos].size(); x++) {
        if (dp[pos]+1 < dp[graph2[pos][x]]) {
          dp[graph2[pos][x]] = dp[pos]+1;
          pq.push(make_pair(dp[pos]+1, graph2[pos][x]));
        }
      }
      
      }
    }
  }
  if (dp[bBall] == -1) {
    dp[bBall] = 100000000;
  }
  return dp[bBall];
}

int main () {
  int p[3001][3];
  int n, m, temp1, temp2;
  int closest = 0, pos;
  scan(n); scan(m);
  for (int x= 0; x < n; x++) {
    for (int i = 0; i < 3; i++) {
      scan(p[x][i]);
    }
    for (int i = 0; i < x; i++) {
      double t =sqrt((double)(p[x][0]-p[i][0])*(p[x][0]-p[i][0]) + (double)(p[x][1]-p[i][1])*(p[x][1]-p[i][1]));
      if (t <= (double)p[x][2]) {
        //within range of x;
        graph[x].push_back(i);
      }
      if (t <= (double)p[i][2]) {
        //within range of i;
        graph[i].push_back(x);
      }
    }
    if (p[x][2] == 9001) {
      aBall = x;
    }
    if (p[x][1] > closest) {
      closest = p[x][1];
      pos = x;
    }
  }
  aStart = pos;
  temp1 = solveA ();
  closest = 0;
  for (int x= 0; x < m; x++) {
    for (int i = 0; i < 3; i++) {
      scan(p[x][i]);
    }
    for (int i = 0; i < x; i++) {
      double t = sqrt((double)(p[x][0]-p[i][0])*(p[x][0]-p[i][0]) + (double)(p[x][1]-p[i][1])*(p[x][1]-p[i][1]));
      if (t <= (double)p[x][2]) {
        //within range of x;
        graph2[x].push_back(i);
      }
      if (t <= (double)p[i][2]) {
        //within range of i;
        graph2[i].push_back(x);
      }
    }
    if (p[x][2] == 9001) {
      bBall = x;
    }
    if (p[x][1] > closest) {
      closest = p[x][1];
      pos = x;
    }
  }
  bStart = pos;
  temp2 = solveB ();
  if (temp1 < temp2) {
    cout << "We are the champions!" << endl;
  } else if (temp2 < temp1) {
    cout << ":'(" << endl;
  } else {
    cout << "SUDDEN DEATH" << endl;
  }
}
