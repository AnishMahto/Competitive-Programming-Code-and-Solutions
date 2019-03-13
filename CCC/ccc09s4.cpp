#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <cstdio>
using namespace std;

int visited[5001];
vector < vector < pair <int, int> > > graph(5001);

int main() {
	// your code goes here
	memset(visited, -1, sizeof(int)*5001);
	vector < pair <int, int> > pencils;
	int n, t, a, b, c, k, d;
	cin >> n >> t;
	while (t--) {
	    scanf("%d %d %d", &a, &b, &c);
	    graph[a].push_back(make_pair(b, c));
	    graph[b].push_back(make_pair(a, c));
	}
	cin >> k;
	while (k--) {
	    scanf("%d %d", &a, &b);
	    pencils.push_back(make_pair(a, b));
	}
	cin >> d;
	queue <int> temp;
	visited[d] = 0;
	temp.push(d);
	while (temp.size() != 0) {
	        for (int i = 0; i < graph[temp.front()].size(); i++) {
	            
	            if (graph[temp.front()][i].second + visited[temp.front()] < visited[graph[temp.front()][i].first] || visited[graph[temp.front()][i].first] == -1) {
	                
	                visited[graph[temp.front()][i].first] = graph[temp.front()][i].second + visited[temp.front()];
	                temp.push(graph[temp.front()][i].first);
	                
	            }
	            
	        }
	        
	        temp.pop();
	}
	
	int cheapest = -1;
	for (int x = 0; x < pencils.size(); x++) {
	    if (visited[pencils[x].first] != -1) {
	        if (visited[pencils[x].first] + pencils[x].second < cheapest || cheapest == -1) {
	            cheapest = visited[pencils[x].first] + pencils[x].second;
	        }
	    }
	}
	
	cout << cheapest << endl;
	
	return 0;
}
