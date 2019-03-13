#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

unsigned long long n, t, one = 1, two = 2;

bool check (unsigned long long k) {
  if (two*(k*(n+one) - ((k+1)*(k+one+1)/two - one)) >= t) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin >> n;
  unsigned long long lo = 1, hi = n;
  t = n*(n-1)/2;
  while (lo < hi) {
    unsigned long long mid = lo+(hi-lo)/2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  cout << max(one, lo) << endl;
}
