#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int t, n, m, g, current, a, b, l;
	int visited[2001];
	memset(visited, -1, sizeof(int)*2001);
	vector < vector < pair <int, int> > > graph(2001);
	vector <int> fb; //dun dun dun
	scanf("%d%d%d%d", &t, &n, &m, &g);
	for (int x = 0; x < g; x++) {
	    scanf("%d", &current);
	    fb.push_back(current);
	}
	for (int x = 0; x < m; x++) {
	    scanf ("%d%d%d", &a, &b, &l);
	    graph[a].push_back(make_pair(b, l));
	}
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
	    
	    for (int x = 0; x < graph[q.front()].size(); x++) {
	        
	        if (visited[graph[q.front()][x].first] == -1 || visited[q.front()] + graph[q.front()][x].second < visited[graph[q.front()][x].first]) {
	            visited[graph[q.front()][x].first] = visited[q.front()] + graph[q.front()][x].second;
	            q.push(graph[q.front()][x].first);
	        }
	        
	    }
	    
	    q.pop();
	}
	int fbs = 0;
	for (int x = 0; x < fb.size(); x++) {
	    if (visited[fb[x]] < t && visited[fb[x]] != -1) {
	        fbs++;
	    }
	}
	cout << fbs << endl;
	return 0;
}
