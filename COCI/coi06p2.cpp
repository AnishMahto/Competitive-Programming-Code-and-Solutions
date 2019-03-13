#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
using namespace std;

int n, e;
//connected vertex, edge index
vector < vector < pair <int, int> > > graph(100001);
int LCA[100001][18] = {0}, depth[100001], esc[100001] = {0}, waysToEsc[100001] = {0}, escWithoutPar[100001];
bool visited[100001] = {0};

int build (int pos, int par, int edgeIdx) {
  visited[pos] = true;
  if (pos != 1) {
    depth[pos] = depth[par]+1;
    LCA[pos][0] = par;
    for (int x = 1; x <= 18; x++) {
      if (LCA[LCA[pos][x-1]][x-1] != 0) {
        LCA[pos][x] = LCA[LCA[pos][x-1]][x-1];
      } else {
        break;
      }
    }
  }
  esc[pos] = escWithoutPar[pos] = depth[pos];
  for (int x = 0; x < graph[pos].size(); x++) {
    if (!visited[graph[pos][x].first]) {
      int temp = build (graph[pos][x].first, pos, graph[pos][x].second);
      escWithoutPar[pos] = min (escWithoutPar[pos], temp);
      esc[pos] = min (esc[pos], temp);
    } else if (graph[pos][x].first != par || edgeIdx != graph[pos][x].second) {
      if (graph[pos][x].first != par) {
        escWithoutPar[pos] = min (escWithoutPar[pos], depth[graph[pos][x].first]);
      }
      esc[pos] = min (esc[pos], depth[graph[pos][x].first]);
    }
  }
  return esc[pos];
}

int isInSubtree (int a, int b) {
  //if a is in b's subtree, return greatest ancestor of a just below b
  //otherwise, return -1
  if (depth[a] <= depth[b]) {
    return -1;
  } else {
    int jump = depth[a] - depth[b] - 1;
    while (jump > 0) {
      a = LCA[a][(int)log2(jump & -jump)];
      jump -= jump & -jump;
    }
    if (LCA[a][0]==b) {
      return a;
    } else {
      return -1;
    }
  }
}

int main() {
  int a, b, q, t, g1, g2, c, aInSub, bInSub;
  scanf ("%d %d", &n, &e);
  for (int x = 1; x <= e; x++) {
    scanf ("%d %d", &a, &b);
    graph[a].push_back(make_pair(b, x));
    graph[b].push_back(make_pair(a, x));
  }
  LCA[1][0] = 1;
  depth[1] = 1;
  build (1, 1, -1);
  scanf ("%d", &q);
  while (q--) {
    scanf ("%d", &t);
    if (t==1) {
      scanf ("%d %d %d %d", &a, &b, &g1, &g2);
      if (depth[g1] > depth[g2]) {
        //make sure g1 is always higher up in the dfs tree
        c = g2;
        g2 = g1;
        g1 = c;
      }
      aInSub = isInSubtree(a, g1);
      bInSub = isInSubtree(b, g1);
      //cout << aInSub << " " << bInSub << endl;
      if (aInSub == -1 && bInSub == -1) {
        //neither a or b are in the subtrees affected by edge, therefore it is still reachable
        printf ("yes\n");
      } else if (aInSub == -1 && bInSub != -1) {
        //check if b can escape subtree
        if (esc[bInSub] <= depth[g1] || bInSub != g2) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      } else if (aInSub != -1 && bInSub == -1) {
        //check if a can escape subtree
        if (esc[aInSub] <= depth[g1] || aInSub != g2) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      } else if (aInSub == bInSub) {
        //both a and b are in the same subtree rooted at g1
        printf ("yes\n");
      } else {
        //a and b are in different subtrees rooted at g1
        if ((aInSub != g2 || esc[aInSub] <= depth[g1]) && (bInSub != g2 || esc[bInSub] <= depth[g1])) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      }
    } else {
      scanf ("%d %d %d", &a, &b, &c);
      if (a==c||b==c) {
        printf ("no\n");
        continue;
      }
      aInSub = isInSubtree (a, c);
      bInSub = isInSubtree (b, c);
      if (aInSub == -1 && bInSub == -1) {
        //neither a or b are in c's subtree, thus they are not affected
        printf ("yes\n");
      } else if (aInSub == -1 && bInSub != -1) {
        //check if b can escape subtree
        if (escWithoutPar[bInSub] < depth[c]) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      } else if (aInSub != -1 && bInSub == -1) {
        //check if a can escape subtree
        if (escWithoutPar[aInSub] < depth[c]) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      } else if (aInSub == bInSub) {
        //both a and b are in the same subtree rooted at c
        printf ("yes\n");
      } else {
        //a and b are in different subtrees rooted at c
        if (escWithoutPar[bInSub] < depth[c] && escWithoutPar[aInSub] < depth[c]) {
          printf ("yes\n");
        } else {
          printf ("no\n");
        }
      }
    }
  }
}
