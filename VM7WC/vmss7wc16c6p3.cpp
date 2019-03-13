#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int timer = 0, disc[100001] = {0}, low[100001] = {0}, root = 1; 
bool visited[100001] = {0}, articulation[100001] = {0};
vector <int> articulationPoints;
vector < vector <int> > graph(100001);

int solve (int pos, int parent) {
    timer++;
    int children = 0;
    disc[pos] = low[pos] = timer;
    visited[pos] = 1;
    for (int x = 0; x < graph[pos].size(); x++) {
        if (!visited[graph[pos][x]]) {
            children++;
            solve (graph[pos][x], pos);
            low[pos] = min (low[pos], low[graph[pos][x]]);
            if (low[graph[pos][x]] >= disc[pos]) {
                if (pos != 1 && !articulation[pos]) {
                    articulation[pos] = 1;
                    articulationPoints.push_back(pos);
                }
            }
        } else if (graph[pos][x] != parent) {
            low[pos] = min (low[pos], disc[graph[pos][x]]);
        }
    }
    if (pos == root && children >= 2 && !articulation[pos]) {
        articulation[pos] = 1;
        articulationPoints.push_back(pos);
    }
    return 0;
}

int main() {
	// your code goes here
	int n, m, a, b;
	scanf ("%d %d", &n, &m);
	for (int x = 0; x < m; x++) {
	    scanf ("%d %d", &a, &b);
	    graph[a].push_back(b);
	    graph[b].push_back(a);
	}
	solve (1, -1);
	cout << articulationPoints.size() << endl;
	sort (articulationPoints.begin(), articulationPoints.end());
	for (int x = 0; x < articulationPoints.size(); x++) {
	    cout << articulationPoints[x] << endl;
	}
	return 0;
}
