#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
vector < vector < pair <int, int> > > graph(6001);
long long dp[6001] = {0};
int lca[6001][13], level[6001] = {0};

int solve (int pos, int par) {
  if (pos == 0) {
    lca[pos][0] = 0;
    level[pos] = 1;
  } else {
    lca[pos][0] = par;
    level[pos] = level[par] + 1;
    for (int x = 1; x <= 12; x++) {
      if (lca[lca[pos][x-1]][x-1] == -1) {
        break;
      } else {
        lca[pos][x] = lca[lca[pos][x-1]][x-1];
      }
    }
  }
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      dp[graph[pos][x].first] = dp[pos] + graph[pos][x].second;
      solve (graph[pos][x].first, pos);
    }
  }
}

int LCA (int a, int b) {
  if (level[a] > level[b]) {
    int dif = level[a] - level[b];
    while (dif > 0) {
      a = lca[a][(int)log2(dif & -dif)];
      dif -= dif & -dif;
    }
  } else {
    int dif = level[b] - level[a];
    while (dif > 0) {
      b = lca[b][(int)log2(dif & -dif)];
      dif -= dif & -dif;
    }
  }
  if (a == b) {
    return a;
  }
  for (int x = 12; x >= 0; x--) {
    if (lca[a][x] != lca[b][x]) {
      a = lca[a][x];
      b = lca[b][x];
    }
  }
  return lca[a][0];
}

int main () {
  memset(lca, -1, sizeof(lca));
  int n, a, b, c, q;
  scan(n);
  for (int x = 0; x < n-1; x++) {
    scan(a); scan(b); scan(c);
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  solve (0, -1);
  scan(q);
  while (q--) {
    scan(a); scan(b);
    int qLca = LCA (a, b);
    printf ("%lld\n", (dp[a]-dp[qLca])+(dp[b]-dp[qLca]));
  }
}
