#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int deg[10001] = {0}, n, startNode = -1, longestPath = 0;
vector < vector <int> > graph(10001);
bool visited[10001] = {0};

int dfs (int pos) {
    visited[pos] = 1;
    int greatest = 0, secondGreatest = 0;
    for (int x = 0; x < graph[pos].size(); x++) {
        if (!visited[graph[pos][x]]) {
            visited[graph[pos][x]] = 1;
            int temp = dfs (graph[pos][x]);
            if (temp > greatest) {
                secondGreatest = greatest;
                greatest = temp;
            } else if (temp > secondGreatest) {
                secondGreatest = temp;
            }
        }
    }
    longestPath = max (longestPath, greatest + secondGreatest);
    greatest++;
    return greatest;
}

int solve () {
    int greatest = 0, secondGreatest = 0;
    for (int x = 0; x < graph[startNode].size(); x++) {
        int temp = dfs (graph[startNode][x]);
        if (temp > greatest) {
            secondGreatest = greatest;
            greatest = temp;
        } else if (temp > secondGreatest) {
            secondGreatest = temp;
        }
    }
    longestPath = max (longestPath, greatest + secondGreatest);
    return 0;
}

int main() {
	// your code goes here
	int a, b;
	scanf ("%d", &n);
	for (int x = 0; x < n - 1; x++) {
	    scanf ("%d %d", &a, &b);
	    graph[a].push_back(b);
	    graph[b].push_back(a);
	    deg[a]++;
	    deg[b]++;
	    (deg[a] > 1 && deg[a] > deg[max(0, startNode)]) ? startNode = a:deg[a] = deg[a];
	    (deg[b] > 1 && deg[b] > deg[max(0, startNode)]) ? startNode = b:deg[b] = deg[b];
	}
	if (startNode == -1 || n < 4) {
	    cout << n - 1 << endl;
	} else {
	    visited[startNode] = 1;
	    solve();
	    cout << longestPath << endl;
	}
	return 0;
}
