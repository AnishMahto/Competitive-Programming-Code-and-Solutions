#include <iostream>
#include <cstdio>
using namespace std;

int bit[500001] = {0}, n;

void add (int pos) {
  while (pos <= n) {
    bit[pos]++;
    pos += pos & -pos;
  }
}
int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main () {
  long long total = 0;
  int cur, q;
  scanf ("%d", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%d", &cur);
    q = query (cur);
    total += min (q, x-1-q);
    add (cur);
  }
  cout << total << endl;
}
