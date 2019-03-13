#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
vector < vector < vector <int> > > graph(101);
int microwaves[101];
int visited[101][101];

int reach (int pos, int distance, int start) {
    if (distance > k || visited[start][pos] == 1) {
        return 0;
    } else {
        visited[start][pos] = 1;
    } 
    for (int x = 0; x < graph[pos].size(); x++) {
        if (visited[start][graph[pos][x][0]] == 0 && distance + graph[pos][x][1] <= k) {
            visited[start][graph[pos][x][0]] = 1;
            reach (graph[pos][x][0], distance + graph[pos][x][1], start);
        }
    }
    return 0;
}

int main() {
	// your code goes here
	memset (visited, -1, sizeof(visited));
	int a, b, d;
	vector <int> t;
	cin >> n >> m >> k;
	for (int x = 1; x <= n; x++) {
	    cin >> microwaves[x];
	}
	for (int x = 0; x < m; x++) {
	    cin >> a >> b >> d;
	    t.push_back(b);
	    t.push_back(d);
	    graph[a].push_back(t);
	    t[0] = a;
	    graph[b].push_back(t);
	    t.clear();
	}
	queue <int> temp;
	for (int a = 1; a <= n; a++) {
	    temp.push(a);
	    visited[a][a] = 0;
	    while (temp.empty() == false) {
	        int first = temp.front();
	        for (int x = 0; x < graph[first].size(); x++) {
	            
	            if (visited[a][first] + graph[first][x][1] < visited[a][graph[first][x][0]] || visited[a][graph[first][x][0]] == -1) {
	                if (visited[a][first] + graph[first][x][1] <= k) {
	                    visited[a][graph[first][x][0]] = visited[a][first] + graph[first][x][1];
	                    temp.push(graph[first][x][0]);
	                }
	            }
	            
	        }
	        
	        temp.pop();
	    }
	    
	}
	
	int destroy = 0, maxDestroy = -1;
	for (int x = 1; x <= n - 2; x++) {
	    for (int i = x + 1; i <= n - 1; i++) {
	        if (x != i) {
	            for (int z = i + 1; z <= n; z++) {
	                if (z != i) {
	                    for (int a = 1; a <= n; a++) {
	                        if (visited[x][a] != -1 || visited[i][a] != -1 || visited[z][a] != -1) {
	                            destroy += microwaves[a];
	                        }
	                    }
	                    maxDestroy = max (maxDestroy, destroy);
	                    destroy = 0;
	                }
	            }
	        }
	    }
	}
	cout << maxDestroy << endl;
	return 0;
}
