#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	vector < vector < pair <int, int> > > graph(100001);
	int fromHome[100001], fromDC[100001];
	memset(fromHome, -1, sizeof(int)*100001);
	memset(fromDC, -1, sizeof(int)*100001);
	int n, m, a, b, t;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    scanf ("%d%d%d", &a, &b, &t);
	    graph[a].push_back(make_pair(b, t));
	    graph[b].push_back(make_pair(a, t));
	}
	fromDC[n - 1] = 0;
	fromHome[0] = 0;
	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > heap;
	for (int x = 0; x < graph[0].size(); x++) {
	    heap.push(make_pair(graph[0][x].second, graph[0][x].first));
	}
	int destination, cost;
	while (!heap.empty()) {
	    destination = heap.top().second;
	    cost = heap.top().first;
	    heap.pop();
	    if (fromHome[destination] == -1 || cost < fromHome[destination]) {
	       fromHome[destination] = cost;
	       for (int x = 0; x < graph[destination].size(); x++) {
	           heap.push(make_pair(cost + graph[destination][x].second, graph[destination][x].first));
	       }
	    }
	}
	for (int x = 0; x < graph[n - 1].size(); x++) {
	    heap.push(make_pair(graph[n - 1][x].second, graph[n - 1][x].first));
	}
	while (!heap.empty()) {
	    destination = heap.top().second;
	    cost = heap.top().first;
	    heap.pop();
	    if (fromDC[destination] == -1 || cost < fromDC[destination]) {
	       fromDC[destination] = cost;
	       for (int x = 0; x < graph[destination].size(); x++) {
	           heap.push(make_pair(cost + graph[destination][x].second, graph[destination][x].first));
	       }
	    }
	}
	fromHome[0] = 0;
	fromDC[n - 1] = 0;
	int greatest = -1;
	for (int x = 0; x < n; x++) {
	    if (fromHome[x] + fromDC[x] > greatest) {
	        greatest = fromHome[x] + fromDC[x];
	    }
	}
	cout << greatest << endl;
	return 0;
}
