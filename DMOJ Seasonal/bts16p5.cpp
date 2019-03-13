#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, c, k, ways = 0;
int cherries[10001], weights[10001] = {0};
bool visited[10001] = {0};
vector < vector < pair <int, int> > > graph(10001);

int sums (int pos) {
    visited[pos] = true;
    pair <int, int> temp;
    for (int x = 0; x < graph[pos].size(); x++) {
        if (visited[graph[pos][x].first] == false) {
            cherries[pos] += sums(graph[pos][x].first);
            weights[pos] += graph[pos][x].second + weights[graph[pos][x].first];
            weights[graph[pos][x].first] += graph[pos][x].second;
            if (cherries[graph[pos][x].first] >= c && weights[graph[pos][x].first] <= k) {
                ways++;
            }
        }
    }
    return cherries[pos];
}

int main() {
	// your code goes here
	int a, b, w;
	cin >> n >> c >> k;
	for (int x = 1; x <= n; x++) {
	    scanf ("%d", &cherries[x]);
	}
	for (int x = 0; x < n - 1; x++) {
	    scanf ("%d %d %d", &a, &b, &w);
	    graph[a].push_back(make_pair(b, w));
	    graph[b].push_back(make_pair(a, w));
	}
	sums (1);
	cout << ways << endl;
	return 0;
}
