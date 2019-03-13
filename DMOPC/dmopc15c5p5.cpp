#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long n, order[200001] = {0}, ans[200001] = {0};
long long bit[200001] = {0};
vector < vector <int> > graph(200001);

void add (int pos, long long val) {
  val %= 1000000007;
  while (pos <= n) {
    bit[pos] += val;
    bit[pos] %= 1000000007;
    pos += pos & -pos;
  }
}

long long query (int pos) {
  long long sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    sum %= 1000000007;
    pos -= pos & -pos;
  }
  return sum;
}

void dfs (int pos) {
  long long before = 0, after = 0;
  before = query (order[pos]);
  for (int x = 0; x < graph[pos].size(); x++) {
    dfs (graph[pos][x]);
  }
  after = query (order[pos]);
  if (after > before) {
    ans[pos] = (after - before + 1) % 1000000007;
  } else {
    ans[pos] = (after - before + 1 + 1000000007) % 1000000007;
  }
  add (order[pos], ans[pos]);
}

int main () {
  long long par, temp, root = -1;
  scanf ("%lld", &n);
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &par);
    graph[par].push_back(x);
    if (par == 0) {
      root = x;
    }
  }
  for (int x = 1; x <= n; x++) {
    scanf ("%lld", &temp);
    order[temp] = x;
  }
  dfs (root);
  for (int x = 1; x <= n; x++) {
    printf ("%lld ", ans[x] % 1000000007);
  } printf ("\n");
}
