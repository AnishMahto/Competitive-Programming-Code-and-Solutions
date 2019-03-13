#include <iostream>
#include <cstdio>
using namespace std;

long long diag[2001][2001] = {0};

void add (int d, int pos, int val) {
  while (pos <= 2000) {
    diag[d][pos] += val;
    pos += pos & -pos;
  }
}

long long sum (int d, int pos) {
  long long sum = 0;
  while (pos >= 1) {
    sum += diag[d][pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main () {
  int n, a, b, c, d;
  long long total = 0;
  scanf ("%d", &n);
  while (n--) {
    scanf ("%d %d %d %d", &a, &b, &c, &d);
    if (a == 1) {
      add (c-1+b-1+1, c, d);
    } else {
      total += (sum(c-1+b-1+1, c+d) - sum(c-1+b-1+1, c-1));
      total %= 1000000007;
    }
  }
  cout << total << endl;
  return 0;
}
