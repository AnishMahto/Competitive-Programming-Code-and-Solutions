#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;

vector < vector < vector <int> > > graph(2001);
int visited[2001][201];
//island, left

int main() {
	// your code goes here
	int k, n, m, a, b, t, h, distance, destination, damage, least = -1;
	cin >> k >> n >> m;
    
    memset (visited, -1, sizeof(int)*2001*201);
	vector <int> temp;
	for (int x = 0; x < m; x++) {
	    temp.clear();
	    scanf("%d %d %d %d", &a, &b, &t, &h);
	    temp.push_back(a);
	    temp.push_back(t);
	    temp.push_back(h);
	    graph[b].push_back(temp);
	    temp.clear();
	    temp.push_back(b);
	    temp.push_back(t);
	    temp.push_back(h);
	    graph[a].push_back(temp);
	}
	cin >> a >> b;
	visited[a][k] = 0;
	priority_queue < pair <int, pair <int, int> >, vector < pair <int, pair <int, int> > >, greater < pair <int, pair <int, int> > > > minHeap;
	for (int x = 0; x < graph[a].size(); x++) {
	    minHeap.push(make_pair(graph[a][x][1], make_pair(graph[a][x][0], graph[a][x][2])));
	}
	while (!minHeap.empty()) {
	    distance = minHeap.top().first;
	    destination = minHeap.top().second.first;
	    damage = minHeap.top().second.second;
	    
	    minHeap.pop();
	    
	    if (damage < k) {
	        if (distance < visited[destination][damage] || visited[destination][damage] == -1) {
	            visited[destination][damage] = distance;
	            
	            for (int x = 0; x < graph[destination].size(); x++) {
	                minHeap.push(make_pair(distance + graph[destination][x][1], make_pair(graph[destination][x][0], damage + graph[destination][x][2]) ) );
	            }
	            
	        }
	    }
	    
	}
	for (int x = 0; x <= k; x++) {
	    if (visited[b][x] != -1 && (visited[b][x] < least || least == -1)) {
	        least = visited[b][x];
	    }
	}
	cout << least << endl;
	return 0;
}
