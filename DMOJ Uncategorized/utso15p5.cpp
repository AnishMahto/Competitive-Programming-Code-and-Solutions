#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector < vector < pair <int, int> > > mst(50001);
vector < vector <int> > decomposition(50001);

long long n, m, parent[50001], mstCost = 0, chains = 0, chainIdx[50001], chainLen[50001] = {0}, inChain[50001], startOfChain[50001] = {0}, maxEdgeOfChainUp[50001], LCA[50001][17], level[50001], connectEdge[50001] = {0}, nodeEdge[50001], segId[50001], nCount = 1, segTree[50001 * 4] = {0}, edgesUsed = 0, rev[50001];
vector < pair <int, pair <int, int> > > edges;
bool used[100001] = {0};

void build (int pos, int l, int r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    segTree[pos] = rev[l];
    return;
  }
  int mid = l+(r-l)/2;
  build (2*pos, l, mid);
  build (2*pos+1, mid+1, r);
  segTree[pos] = max (segTree[2*pos], segTree[2*pos+1]);
}

long long query (int pos, int l, int r, int tl, int tr) {
  if (l > r || r < tl || l > tr) {
    return 0;
  } else if (l >= tl && r <= tr) {
    return segTree[pos];
  }
  int mid = l+(r-l)/2;
  return max (query (2*pos, l, mid, tl, tr), query(2*pos+1, mid+1, r, tl, tr));
}

long long queryGreatestPathUp (int pos, int end, bool start) {
  if (inChain[pos] == inChain[end]) {
    if (pos == end) {
      return 0;
    }
    return query (1, 1, nCount-1, min(segId[end], segId[LCA[pos][0]]), max(segId[end], segId[LCA[pos][0]]));
  } else {
    long long temp = 0;
    if (pos != startOfChain[pos]) {
      temp = query (1, 1, nCount-1, min(segId[startOfChain[pos]], segId[LCA[pos][0]]), max(segId[startOfChain[pos]], segId[LCA[pos][0]]));
    } else if (start) {
      temp = maxEdgeOfChainUp[pos];
    }
      return max (connectEdge[inChain[pos]], max (temp, queryGreatestPathUp(LCA[startOfChain[pos]][0], end, false)));
  }
}

int lca (int a, int b) {
  if (level[a] < level[b]) {
    int dif = level[b] - level[a];
    while (dif > 0) {
      b = LCA[b][(int)log2(dif & -dif)];
      dif -= dif & -dif;
    }
  } else if (level[b] < level[a]) {
    int dif = level[a] - level[b];
    while (dif > 0) {
      a = LCA[a][(int)log2(dif & -dif)];
      dif -= dif & -dif;
    }
  }
  if (a != b) {
    for (int x = 16; x >= 0; x--) {
      if (LCA[a][x] != -1) {
        if (LCA[a][x] != LCA[b][x]) {
          a = LCA[a][x];
          b = LCA[b][x];
        }
      }
    }
  } else {
    return a;
  }
  return LCA[a][0];
}

void buildLca (int pos, int par, int lvl) {
  LCA[pos][0] = par;
  level[pos] = lvl;
  if (pos != 1) {
    for (int x = 1; x <= 16; x++) {
      if (LCA[LCA[pos][x-1]][x-1] != -1) {
        LCA[pos][x] = LCA[LCA[pos][x-1]][x-1];
      } else {
        break;
      }
    }
  }
  for (int x = 0; x < mst[pos].size(); x++) {
    if (mst[pos][x].first != par) {
      buildLca (mst[pos][x].first, pos, lvl+1);
    }
  }
}

void decompose (int pos, int par) {
  int greatestSize = -1, greatestChild;
  for (int x = 0; x < mst[pos].size(); x++) {
    if (mst[pos][x].first != par) {
      decompose (mst[pos][x].first, pos);
      if (chainLen[mst[pos][x].first] > greatestSize) {
        greatestSize = chainLen[inChain[mst[pos][x].first]];
        greatestChild = mst[pos][x].first;
      }
    }
  }
  if (greatestSize != -1) {
    inChain[pos] = inChain[greatestChild];
    chainLen[inChain[pos]]++;
  } else {
    chains++;
    inChain[pos] = chains;
    chainLen[inChain[pos]] = 1;
  }
  decomposition[inChain[pos]].push_back(pos);
}

void getIndex (int pos, int par) {
  if ((par != -1 && inChain[par] != inChain[pos]) || par == -1) {
    chainIdx[pos] = 1;
    startOfChain[pos] = pos;
  } else {
    chainIdx[pos] = chainIdx[par]+1;
    startOfChain[pos] = startOfChain[par];
  }
  maxEdgeOfChainUp[pos] = 0;
  bool lastNodeInChain = true;
  for (int x = 0; x < mst[pos].size(); x++) {
    if (mst[pos][x].first != par) {
      getIndex(mst[pos][x].first, pos);
      if (inChain[mst[pos][x].first] == inChain[pos]) {
        lastNodeInChain = false;
        maxEdgeOfChainUp[pos] = mst[pos][x].second;
      }
    }
  }
  for (int x = 0; x < mst[pos].size(); x++) {
      if (mst[pos][x].first != par && inChain[mst[pos][x].first] != inChain[pos]) {
        connectEdge[inChain[mst[pos][x].first]] = mst[pos][x].second;
      }
    }
}

int find (int pos) {
  if (parent[pos] != pos) {
    parent[pos] = find (parent[pos]);
  }
  return parent[pos];
}

void merge (int a, int b) {
  if (find(a) < find(b)) {
    parent[find(a)] = parent[find(b)];
  } else {
    parent[find(b)] = parent[find(a)];
  }
}

bool connected (int a, int b) {
  if (find (a) == find (b)) {
    return true;
  }
  return false;
}

void calcMst () {
  for (int x = 0; x < m; x++) {
    if (!connected(edges[x].second.first, edges[x].second.second)) {
      merge (edges[x].second.first, edges[x].second.second);
      used[x] = true;
      edgesUsed++;
      mstCost += edges[x].first;
      mst[edges[x].second.first].push_back(make_pair(edges[x].second.second, edges[x].first));
      mst[edges[x].second.second].push_back(make_pair(edges[x].second.first, edges[x].first));
    }
  }
}

int main () {
  memset(LCA, -1, sizeof(LCA));
  pair <int, pair <int, int> > edge;
  scanf ("%d %d", &n, &m);
  for (int x = 1; x <= n; x++) {
    parent[x] = x;
  }
  for (int x = 0; x < m; x++) {
    scanf ("%d %d %d", &edge.second.first, &edge.second.second, &edge.first);
    edges.push_back(edge);
  } 
  sort (edges.begin(), edges.end());
  calcMst();
  if (edgesUsed != n-1) {
    cout << -1 << endl;
    return 0;
  }
  for (int x = 2; x <= n; x++) {
    if (!connected(1, x)) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  decompose (1, -1);
  getIndex (1, -1);
  buildLca (1, -1, 0);
  LCA[1][0] = 1;
  
  for (int x = 0; x < decomposition.size(); x++) {
    if (decomposition[x].size() > 0) {
    }
    for (int i = 0; i < decomposition[x].size(); i++) {
      segId[decomposition[x][i]] = nCount;
      rev[nCount] = maxEdgeOfChainUp[decomposition[x][i]];
      nCount++;
    } 
  }
  
  build (1, 1, nCount-1);
  
  long long ans = 1000000000000;
  for (int x = 0; x < edges.size(); x++) {
    if (!used[x]) {
      long long s1 = edges[x].second.first, s2 = edges[x].second.second;
      long long end = lca (s1, s2), greatestPath = 0;
      if (inChain[end] == inChain[s1]) {
        if (s1 != end) {
          greatestPath = max (greatestPath, query (1, 1, nCount-1, min(segId[end], segId[LCA[s1][0]]), max (segId[end], segId[LCA[s1][0]])));
        }
      } else {
        if (chainIdx[s1] == 1) {
          greatestPath = max (greatestPath, queryGreatestPathUp(LCA[s1][0], end, false));
          greatestPath = max (greatestPath, connectEdge[inChain[s1]]);
        } else {
          greatestPath = max (greatestPath, queryGreatestPathUp(LCA[s1][0], end, true));
        }
      }
      if (inChain[end] == inChain[s2]) {
        if (s2 != end) {
          greatestPath = max (greatestPath, query (1, 1, nCount-1, min(segId[end], segId[LCA[s2][0]]), max (segId[end], segId[LCA[s2][0]])));
        }
      } else {
        if (chainIdx[s2] == 1) {
          greatestPath = max (greatestPath, queryGreatestPathUp(LCA[s2][0], end, false));
          greatestPath = max (greatestPath, connectEdge[inChain[s2]]);
        } else {
          greatestPath = max (greatestPath, queryGreatestPathUp(LCA[s2][0], end, true));
        }
      }
      if (mstCost - greatestPath + edges[x].first != mstCost) {
        ans = min (ans, mstCost - greatestPath + edges[x].first);
      }
    }
  }
  if (ans == 1000000000000) {
    ans = -1;
  }
  cout << ans << endl;
}
