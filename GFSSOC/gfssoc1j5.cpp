#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;

vector < vector <int> > graph(1001);
int visited[1001];

int dfs (int pos, int end, int cost) {
    if (pos == end && (pos < visited[end] || visited[end] == -1) ) {
        visited[end] = cost;
    } else {
        for (int x = 0; x < graph[pos].size(); x++) {
            if (visited[graph[pos][x]] == -1 || cost < visited[graph[pos][x]]) {
                visited[graph[pos][x]] = cost + 1;
                dfs (graph[pos][x], end, cost + 1);
            }
        }
    }
    return 0;
}

int main() {
	// your code goes here
	int n, m, t, answer, a, b, q;
	cin >> n >> m >> t;
	while (m--) {
	    scanf("%d %d", &a, &b);
	    graph[a].push_back(b);
	}
	cin >> q;
	while (q--) {
	    scanf("%d %d", &a, &b);
	    memset(visited, -1, sizeof(int) * (n + 1));
	    dfs(a, b, 0);
	    if (visited[b] == -1) {
	        cout << "Not enough hallways!" << endl;
	    } else {
	        cout << visited[b] * t << endl;
	    }
	}
	return 0;
}
