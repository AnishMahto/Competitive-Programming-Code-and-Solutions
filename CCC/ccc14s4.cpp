#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> compressHor, compressVer, ver, hor;
//at most 2n unique vertical pts, at most 2n unique horizontal pts + 2n vertical and horizontal "divider" pts
long long grid[2*1001+2][2*1001+2] = {0};

int main () {
  vector <long long>::iterator it, it2, it3, it4;
  long long n, cmd[1001][5], k;
  scanf ("%lld %lld", &n, &k);
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < 5; i++) {
      scanf ("%lld", &cmd[x][i]);
    }
    compressHor.push_back(cmd[x][0]);
    compressHor.push_back(cmd[x][2]);
    compressVer.push_back(cmd[x][1]);
    compressVer.push_back(cmd[x][3]);
  }
  sort (compressVer.begin(), compressVer.end());
  sort (compressHor.begin(), compressHor.end());
  compressHor.push_back(compressHor.back()+1);
  compressVer.push_back(compressVer.back()+1);
  for (int x = 0; x < compressHor.size(); x++) {
    if (x == 0 || compressHor[x] != compressHor[x-1]) {
      hor.push_back(compressHor[x]);
    }
  }
  for (int x = 0; x < compressVer.size(); x++) {
    if (x == 0 || compressVer[x] != compressVer[x-1]) {
      ver.push_back(compressVer[x]);
    }
  }
  for (int x = 0; x < n; x++) {
    it = lower_bound(hor.begin(), hor.end(), cmd[x][0]);
    it2 = lower_bound(hor.begin(), hor.end(), cmd[x][2]);
    it3 = lower_bound(ver.begin(), ver.end(), cmd[x][1]);
    it4 = lower_bound(ver.begin(), ver.end(), cmd[x][3]);
    int tlx = it-hor.begin(), brx = it2-hor.begin(), tly = it3-ver.begin(), bly = it4-ver.begin();
    grid[tly][tlx] += cmd[x][4];
    grid[bly][tlx] -= cmd[x][4];
    grid[tly][brx] -= cmd[x][4];
    grid[bly][brx] += cmd[x][4];
  }
  for (int x = 0; x < ver.size(); x++) {
    for (int i = 1; i < hor.size(); i++) {
      grid[x][i] += grid[x][i-1];
    }
  }
  for (int x = 1; x < ver.size(); x++) {
    for (int i = 0; i < hor.size(); i++) {
      grid[x][i] += grid[x-1][i];
    }
  }
  long long area = 0;
  for (int x = 0; x < ver.size()-1; x++) {
    for (int i = 0; i < hor.size()-1; i++) {
      if (grid[x][i] >= k) {
        area += (hor[i+1]-hor[i])*(ver[x+1]-ver[x]);
      }
    }
  }
  cout << area << "\n";
  return 0;
}
