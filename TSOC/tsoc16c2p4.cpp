#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

bool prime[100001];
int dp[101][10001] = {0}, n, m;
//1 = possible, 2 = not possible, 0 = not calculated
vector <int> primes, obj;

void sieve () {
  for (int x = 2; x <= sqrt(10000); x++) {
    if (prime[x]) {
      for (int i = 2*x; i <= 10000; i += x) {
        prime[i] = false;
      }
      primes.push_back(x);
    }
  }
  for (int x = sqrt(10000)+1; x <= 10000; x++) {
    if (prime[x]) {
      primes.push_back(x);
    }
  }
}

int solve (int pos, int money) {
  if (pos == m) {
    if (prime[n-money]) {
      return 1;
    } else {
      return 0;
    }
  } else if (dp[pos][money] != 0) {
    return dp[pos][money];
  }
  dp[pos][money] = 2;
  for (int x = 0; x < primes.size(); x++) {
    if (primes[x]*obj[pos] <= money && solve (pos+1, money-primes[x]*obj[pos]) == 1) {
      dp[pos][money] = 1;
      return 1;
    } else if (primes[x]*obj[pos] > money) {
      
      return 2;
    }
  }
  return dp[pos][money];
}

int main () {
  memset(prime, true, sizeof(prime));
  sieve();
  int cur;
  scanf ("%d %d", &n, &m);
  for (int x = 0; x < m; x++) {
    scanf ("%d", &cur);
    obj.push_back(cur);
  }
  if (solve (0, n) == 1) {
    printf ("its primetime\n");
  } else {
    printf ("not primetime\n");
  }
}
