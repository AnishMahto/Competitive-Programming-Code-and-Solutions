#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long bit[1000001] = {0};
vector <long long> com;

void update (int pos) {
  while (pos <= 1000000) {
    bit[pos]++;
    pos += pos & (-pos);
  }
}

long long query (int pos) {
  long long sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= pos & (-pos);
  }
  return sum;
}

int main () {
  long long n, p;
  long long sum[1000001] = {0};
  long long total = 0;
  scanf ("%lld", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &sum[x]);
  }
  scanf ("%lld", &p);
  for (int x = 1; x <= n; x++) {
    sum[x] -= p;
    sum[x] += sum[x-1];
    com.push_back(sum[x]);
  }
  sort (com.begin(), com.end());
  vector <long long> compress;
  for (int x = 0; x < com.size(); x++) {
    if (x == 0 || com[x] != com[x-1]) {
      compress.push_back(com[x]);
    }
  }
  vector <long long>::iterator it;
  for (int x = 1; x <= n; x++) {
    it = lower_bound(compress.begin(), compress.end(), sum[x]);
    int pos = (it - compress.begin()) + 1;
    total += query (pos);
    update (pos);
    if (sum[x] >= 0) {
      total++;
    }
  }
  cout << total << endl;
}
