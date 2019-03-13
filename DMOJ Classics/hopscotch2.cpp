#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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


int main () {
  long long n, k;
  deque <int> q;
  scanint(n); scanint(k);
  long long dp[n+1];
  int nxt[n+1];
  for (int x = 1; x <= n; x++) {
    scanint(dp[x]);
  }
  dp[0] = 0;
  for (int x = n; x > n-k; x--) {
    while (!q.empty() && dp[x] < dp[q.back()]) {
      q.pop_back();
    }
    nxt[x] = -1;
    q.push_back(x);
  }
  for (int x = n-k; x >= 0; x--) {
    while (!q.empty() && q.front() > x+k) {
      q.pop_front();
    }
    dp[x] += dp[q.front()];
    nxt[x] = q.front();
    while (!q.empty() && dp[x] < dp[q.back()]) {
      q.pop_back();
    }
    q.push_back(x);
  }
  printf ("%lld\n", dp[0]);
  int pos = 0;
  while (nxt[pos] != -1) {
    printf ("%d ", nxt[pos]);
    pos = nxt[pos];
  }
}
