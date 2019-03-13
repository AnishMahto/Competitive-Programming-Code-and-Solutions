#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <unordered_map>
using namespace std;

struct edge {
    int b;
    int c;
};

unordered_map<int, int> count;
vector < vector < edge > > graph(100001);
vector <int> q;
long long sz[100001] = {0}, n;
bool removed[100001] = {0};
long long ans = 0;

int findCentroid (int pos, int par, int total) {
    for (int x = 0; x < graph[pos].size(); x++) {
        if (graph[pos][x].b != par && !removed[graph[pos][x].b] && sz[graph[pos][x].b]*2 > total) {
            return findCentroid (graph[pos][x].b, pos, total);
        }
    }
    return pos;
}

int getSize (int pos, int par) {
    sz[pos] = 1;
    for (int x = 0; x < graph[pos].size(); x++) {
        if (graph[pos][x].b==par || removed[graph[pos][x].b]) {
            continue;
        } else {
            sz[pos] += getSize (graph[pos][x].b, pos);
        }
    }
    return sz[pos];
}

int countPaths (int pos, int par, int val, int centroid) {
    if (pos != centroid) {
        //connect current node to any other possible nodes
        ans += count[-val-1] + count[-val+1];
        q.push_back(val);
    }
    for (int x = 0; x < graph[pos].size(); x++) {
        if (!removed[graph[pos][x].b] && par != graph[pos][x].b) {
            countPaths (graph[pos][x].b, pos, val+graph[pos][x].c, centroid);
            if (pos==centroid) {
                for (int i = 0; i < q.size(); i++) {
                    count[q[i]]++;
                }
                q.clear();
            }
        }
    }
    if (par != centroid && (val==-1 || val==1)) {
        //if you can connect current node to the root
        ans++;
    }
}

int solve (int pos, int par) {
    count.clear();
    int centroid = findCentroid (pos, par, getSize (pos, par));
    removed[centroid] = true;
    countPaths (centroid, -1, 0, centroid);
    for (int x = 0; x < graph[centroid].size(); x++) {
        if (!removed[graph[centroid][x].b]) {
            solve (graph[centroid][x].b, centroid);
        }
    }
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    char c;
    cin >> n;
    for (int x = 0; x < n-1; x++) {
        cin >> a >> b >> c;
        edge e;
        e.b = b;
        if (c=='r') {
            e.c = 1;
        } else {
            e.c = -1;
        }
        graph[a].push_back(e);
        e.b = a;
        graph[b].push_back(e);
    }
    solve (1,-1);
    cout << ans << endl;
}
