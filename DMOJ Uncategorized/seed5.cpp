#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int rg[201][201] = {0}, n, m, par[201] = {0};
vector < vector <int> > g (201);

bool dfs () {
    memset (par, 0, sizeof(par));
    queue <int> q;
    bool visited[201] = {0};
    par[1] = -1;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int x = 0; x < g[pos].size(); x++) {
            if (!visited[g[pos][x]] && rg[pos][g[pos][x]] > 0) {
                q.push(g[pos][x]);
                visited[g[pos][x]] = true;
                par[g[pos][x]] = pos;
            }
        }
    }
    if (visited[n]) {
        return true;
    }
    return false;
}

int ff () {
    int maxFlow = 0;
    while (dfs ()) {
        int pathFlow = 2000000001, pos = n;
        while (pos != 1) {
            pathFlow = min (pathFlow, rg[par[pos]][pos]);
            pos = par[pos];
        }
        
        pos = n;
        while (pos != 1) {
            rg[par[pos]][pos] -= pathFlow;
            rg[pos][par[pos]] += pathFlow;
            pos = par[pos];
        }
        
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int a, b;
    scanf ("%d", &n);
    for (int x = 1; x < n; x++) {
        int in = x, out = 100+x;
        scanf ("%d", &rg[in][out]);
        g[in].push_back(out);
        g[out].push_back(in);
    }
    scanf ("%d", &m);
    for (int x = 0; x < m; x++) {
        scanf ("%d %d", &a, &b);
        int c = 1001*101+1, inA = a, outA = 100+a, inB = b, outB = 100+b;
        if (a==n) {
            outA = a;
        } else if (b==n) {
            outB = b;
        }
        g[outA].push_back(inB);
        rg[outA][inB] = c;
        g[inB].push_back(outA);
    }
    cout << ff () << endl;
    return 0;
}
