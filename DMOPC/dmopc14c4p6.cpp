#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;

vector < vector <int> > graph(500001);
int n, dp[500001] = {0}, greatest = 0, start, end;
bool visited[500001] = {0};

int dfs (int pos, int l) {
    if (visited[pos]) {
        return 0;
    } else {
        visited[pos] = 1;
        if (l > greatest) {
            greatest = l;
            start = pos;
        }
        for (int x = 0; x < graph[pos].size(); x++) {
            if (!visited[graph[pos][x]]) {
                dfs (graph[pos][x], l + 1);
            }
        }
    }
    return 0;
}

int dfs2 (int pos, int l) {
    if (visited[pos]) {
        return 0;
    } else {
        visited[pos] = 1;
        dp[pos] = l;
        if (l > greatest) {
            greatest = l;
            end = pos;
        }
        for (int x = 0; x < graph[pos].size(); x++) {
            if (!visited[graph[pos][x]]) {
                dfs2 (graph[pos][x], l + 1);
            }
        }
    }
    return 0;
}

int dfs3 (int pos, int l) {
    if (visited[pos]) {
        return 0;
    } else {
        visited[pos] = 1;
        dp[pos] = max(l, dp[pos]);
        for (int x = 0; x < graph[pos].size(); x++) {
            if (!visited[graph[pos][x]]) {
                dfs3 (graph[pos][x], l + 1);
            }
        }
    }
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
	}
	dfs (1, 0);
	memset(visited, 0, sizeof(visited));
	greatest = 0;
	dfs2 (start, 0);
	memset(visited, 0, sizeof(visited));
	dfs3 (end, 0);
	for (int x = 1; x <= n; x++) {
	    printf ("%d\n", dp[x] + 1);
	}
	return 0;
}
