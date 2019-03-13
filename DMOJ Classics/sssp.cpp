#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int n, m, it, a, b, c;
	bool done = false;
	scanf ("%d %d", &n, &m);
	vector < vector < pair <int, int> > > graph(n + 1);
	int bellman[n + 1];
	for (int x = 0; x < m; x++) {
	    scanf ("%d %d %d", &a, &b, &c);
	    graph[a].push_back(make_pair(b, c));
	    graph[b].push_back(make_pair(a, c));
	}
	memset (bellman, -1, sizeof(int)*(n+1));
	bellman[1] = 0;
	for (int x = 0; x <= n && done == false; x++) {
	    done = true;
	    for (int i = 1; i <= n; i++) {
	        if (bellman[i] != -1) {
	            for (int z = 0; z < graph[i].size(); z++) {
	                if (bellman[i] + graph[i][z].second < bellman[graph[i][z].first] || bellman[graph[i][z].first] == -1) {
	                    bellman[graph[i][z].first] = bellman[i] + graph[i][z].second;
	                    done = false;
	                }
	            }
	        }
	    }
	}
	for (int x = 1; x <= n; x++) {
	    cout << bellman[x] << endl;
	}
	return 0;
}
