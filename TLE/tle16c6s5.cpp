#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>
#define gc getchar_unlocked
using namespace std;

void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

long long dp[3001][3001] = {0};
long long delta = 0, inf = numeric_limits<long long>::max(), negInf = numeric_limits<long long>::min();
vector < vector < pair <int, int> > > revGraph(3001);
vector < vector < pair <long long, long long> > > lines(3001);
vector < vector < pair <double, double> > > range(3001); 
vector < vector <int> > id(3001);

double inline intersection (pair <long long, long long> l1, pair <long long, long long> l2) {
  return (double)(l2.second-l1.second)/(double)(l1.first-l2.first);
}

long long solve (int pos, int paths) {
  if (dp[pos][paths] != 0) {
    return dp[pos][paths];
  } else if (pos == 1 && paths == 0) {
    dp[pos][paths] = 0;
    return 0;
  } else if (paths == 0) {
    return negInf;
  } else {
    dp[pos][paths] = numeric_limits<long long>::max();
    for (int x = 0; x < revGraph[pos].size(); x++) {
      long long temp = solve (revGraph[pos][x].first, paths-1);
      if (temp != negInf) {
        dp[pos][paths] = min (dp[pos][paths], revGraph[pos][x].second + temp);
      }
    }
    if (dp[pos][paths] == numeric_limits<long long>::max()) {
      dp[pos][paths] = negInf;
    }
  }
  return dp[pos][paths];
}

int main () {
  long long n, m, d, a, b, c, dest;
  scanint(n); scanint(m); scanint(d);
  for (int x = 0; x < m; x++) {
    scanint(a); scanint(b); scanint(c);
    revGraph[b].push_back(make_pair(a, c));
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 2; x <= n; x++) {
      solve (x, i);
    }
  }
  for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= n; i++) {
      if (dp[x][i] != negInf) {
        lines[x].push_back(make_pair(i, dp[x][i]));
      }
    }
  }
  for (int pos = 2; pos <= n; pos++) {
    for (int x = lines[pos].size()-1; x >= 0; x--) {
      if (range[pos].size() == 0) {
        range[pos].push_back(make_pair(negInf, inf));
        id[pos].push_back(x);
      } else {
        
        double intersect = intersection (lines[pos][id[pos].back()], lines[pos][x]);
        while (range[pos].size() > 0 && intersect <= range[pos].back().first) {
          range[pos].pop_back();
          id[pos].pop_back();
          if (range[pos].size() > 0) {
            intersect = intersection (lines[pos][id[pos].back()], lines[pos][x]);
          }
        }
        if (range[pos].size() == 0) {
          range[pos].push_back(make_pair(negInf, inf));
          id[pos].push_back(x);
        } else {
          range[pos].back().second = intersect;
          range[pos].push_back(make_pair(intersect, inf));
          id[pos].push_back(x);
        }
      }
    }
  }
  vector < pair <double, double> >::iterator it;
  for (int x = 0; x < d; x++) {
    scanint(c); scanint(dest);
    delta += c;
    if (dest == 1) {
      printf ("0\n");
    } else {
      if (lines[dest].size()==0) {
        printf ("Cannot Deliver\n");
      } else {
        int lo = 0, up = range[dest].size()-1;
        while (lo < up) {
          int mid = lo + (up-lo)/2;
          if (range[dest][mid].second >= delta) {
            up = mid;
          } else {
            lo = mid + 1;
          }
        }
        int pos = id[dest][lo];
        printf ("%lld\n", (lines[dest][pos].second+lines[dest][pos].first*delta));
      }
    }
  }
  
}
