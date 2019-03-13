#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n, m, dp[105][105];
int sx, sy;
char in[105][105];
bool cam[105][105] = {0};
bool camRow[101] = {0}, camCol[101] = {0};
vector < pair <int, pair<int, int> > > graph[105][105];

bool check (int x, int y) {
  if (in[y][x] != '.' && in[y][x] != 'W' && in[y][x] != 'C' && in[y][x] != 'S') {
    return true;
  } else {
    return false;
  }
}

bool letter (int x, int y) {
  //cout << y << " " << x << ": ";
  if (in[y][x] == 'L' || in[y][x] == 'R' || in[y][x] == 'U' || in[y][x] == 'D') {
    //cout << in[y][x] << " .." << endl;
    return true;
  } else {
    return false;
  }
}

void solve (int x, int y) {
    
    if (x > 0 && (!cam[y][x-1] || check(x-1, y)) && in[y][x-1] != 'W' && (in[y][x] == '.' || in[y][x] == 'L' || in[y][x] == 'S')) {
      //move left
      if (in[y][x] == 'L') {
        graph[y][x].push_back(make_pair(0, make_pair(y, x-1)));
      } else {
        graph[y][x].push_back(make_pair(1, make_pair(y, x-1)));
      }
    }
    if (x < m-1 && (!cam[y][x+1] || check(x+1, y)) && in[y][x+1] != 'W' && (in[y][x] == '.' || in[y][x] == 'R' || in[y][x] == 'S')) {
      //move right
      if (in[y][x] == 'R') {
        graph[y][x].push_back(make_pair(0, make_pair(y, x+1)));
      } else {
        graph[y][x].push_back(make_pair(1, make_pair(y, x+1)));
      }
    }
    if (y > 0 && (!cam[y-1][x] || check(x, y-1)) && in[y-1][x] != 'W' && (in[y][x] == '.' || in[y][x] == 'U' || in[y][x] == 'S')) {
      //move up
      if (in[y][x] == 'U') {
        graph[y][x].push_back(make_pair(0, make_pair(y-1, x)));
      } else {
        graph[y][x].push_back(make_pair(1, make_pair(y-1, x)));
      }
    }
    if (y < n-1 && (!cam[y+1][x] || check(x, y+1)) && in[y+1][x] != 'W' && (in[y][x] == '.' || in[y][x] == 'D' || in[y][x] == 'S')) {
      //move down
      if (in[y][x] == 'D') {
        graph[y][x].push_back(make_pair(0, make_pair(y+1, x)));
      } else {
        graph[y][x].push_back(make_pair(1, make_pair(y+1, x)));
      }
    }
  
}

int main() {
  memset (dp, -1, sizeof(dp));
  cin >> n >> m;
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < m; i++) {
      dp[x][i] = -1;
      cin >> in[x][i];
      graph[x][i].clear();
      
      if (in[x][i] == 'S') {
        sx = i;
        sy = x;
      }
    }
  }
  /*for (int x = 0; x < n; x++) {
    for (int i = 0; i < m; i++) {
      cout << in[x][i] << " ";
    } cout << endl;
  }*/
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < m; i++) {
      if (in[x][i] == 'C') {
        //cout << x << " " << i << "!" << endl;
        cam[x][i] = true;
        for (int z = x-1; z >= 0; z--) {
          if (in[z][i] == 'W') {
            z = -1;
            break;
          } else if (!letter(i,z)) {
            cam[z][i] = true;
          }
        }
        for (int z = x+1; z <= n-1; z++) {
          //cout << z << " " << i << endl;
          if (in[z][i] == 'W'/* || cam[z][i]*/) {
            z = n;
            break;
          } else if (!letter(i,z)) {
            cam[z][i] = true;
          }
        }
        for (int z = i+1; z <= m-1; z++) {
          if (in[x][z] == 'W'/* || cam[x][z]*/) {
            z = m;
            break;
          } else if (!letter(z,x)) {
            cam[x][z] = true;
          }
        }
        for (int z = i-1; z >= 0; z--) {
          if (in[x][z] == 'W' /*|| cam[x][z]*/) {
            z = -1;
            break;
          } else if (!letter(z,x)) {
            cam[x][z] = true;
          }
        }
      }
    }
  }
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < m; i++) {
      //cout << cam[x][i] << " ";
      //if (in[x][i] != 'W' && in[x][i] != 'C') {
        solve (i, x);
      //}
    } //cout << endl;
  } //cout << endl;
  
  dp[sy][sx] = 0;
  priority_queue<pair <int, pair<int, int> >, std::vector< pair <int, pair<int, int> > >, greater< pair <int, pair<int, int> > > > minH;
  for (int x = 0; x < graph[sy][sx].size() && !cam[sy][sx]; x++) {
    //cout << graph[sy][sx][x].first << " " << graph[sy][sx][x].second.first << " " << graph[sy][sx][x].second.second << endl;
    minH.push(graph[sy][sx][x]);
  }
  while (!minH.empty()) {
    int x = minH.top().second.second, y = minH.top().second.first, cost = minH.top().first;
    minH.pop();
    if (cost < dp[y][x] || dp[y][x]==-1) {
      
      dp[y][x] = cost;
      for (int i = 0; i < graph[y][x].size(); i++) {
        //cout << graph[y][x][i].first << " " << graph[y][x][i].second.first << " " << graph[y][x][i].second.second << endl;
        minH.push(make_pair(cost + graph[y][x][i].first, graph[y][x][i].second));
      }
    }
  }
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < m; i++) {
      if (in[x][i] == '.') {
        cout << dp[x][i] << endl;
      }
    }
  }
}
