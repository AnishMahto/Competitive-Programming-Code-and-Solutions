#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

int n, m, leastCost = 100000000, need[11] = {0};
int deal[11][11] = {0}, cost[11] = {0}, reg[11] = {0};


void test (bitset<10>deals) {
  int cur = 0, flower[10] = {0};
  for (int x = 0; x < m; x++) {
    if (deals.test(x)) {
      cur += cost[x];
      for (int i = 0; i < n; i++) {
        flower[i] += deal[x][i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (flower[i] <= need[i]) {
      cur += (need[i] - flower[i])*reg[i];
    } else {
      return;
    }
  }
  leastCost = min (leastCost, cur);
}

void gen (bitset<10> cur, int pos) {
  if (pos==m) {
    test (cur);
  } else {
    gen (cur, pos+1);
    cur.set(pos);
    gen (cur, pos+1);
  }
}

int main() {
  cin >> n >> m;
  int temp;
  for (int x = 0; x < n; x++) {
    cin >> reg[x];
  }
  for (int x = 0; x < m; x++) {
    cin >> cost[x];
    for (int i = 0; i < n; i++) {
      cin >> deal[x][i];
    }
  }
  leastCost = 0;
  for (int x = 0; x < n; x++) {
    cin >> need[x];
    leastCost += need[x]*reg[x];
  }
  bitset<10> cur;
  gen (cur, 0);
  cout << leastCost << endl;
}
