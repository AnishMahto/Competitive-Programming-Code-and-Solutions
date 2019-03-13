#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int graph[51][51] = {0};
int visited[51] = {0};

int fof (int pos, int head) {
    int temp = 0;
    for (int x = 0; x <= 50; x++) {
        if (graph[pos][x] == 1 && visited[x] == 0) {
            visited[x] = 1;
            if (graph[x][head] != 1) {
                temp++;
            }
        }
    }
    return temp;
}

int seperation = -1;

int dfs (int pos, int end, int steps) {
    
        if (pos == end) {
            if (steps < seperation || seperation == -1) seperation = steps;
            return 0;
        } else {
            for (int x = 0; x <= 50; x++) {
                if (graph[pos][x] == 1 && (visited[x] == 0 || steps <= visited[x]) ) {
                    visited[x] = steps;
                    dfs (x, end, steps + 1);
                }
            }
        }
    return 0;
}

int main() {
	// your code goes here
	vector < pair <int, int> > edges;
	edges.push_back(make_pair(2, 6));
	edges.push_back(make_pair(1, 6));
	edges.push_back(make_pair(3, 6));
	edges.push_back(make_pair(4, 6));
	edges.push_back(make_pair(5, 6));
	edges.push_back(make_pair(7, 6));
	edges.push_back(make_pair(3, 4));
	edges.push_back(make_pair(4, 5));
	edges.push_back(make_pair(3, 5));
	edges.push_back(make_pair(3, 15));
	edges.push_back(make_pair(7, 8));
	edges.push_back(make_pair(8, 9));
	edges.push_back(make_pair(9, 10));
	edges.push_back(make_pair(9, 12));
	edges.push_back(make_pair(10, 11));
	edges.push_back(make_pair(11, 12));
	edges.push_back(make_pair(12, 13));
	edges.push_back(make_pair(15, 13));
	edges.push_back(make_pair(13, 14));
	edges.push_back(make_pair(16, 17));
	edges.push_back(make_pair(16, 18));
	edges.push_back(make_pair(17, 18));
	
	for (int x = 0; x < edges.size(); x++) {
	    graph[edges[x].first][edges[x].second] = 1;
	    graph[edges[x].second][edges[x].first] = 1;
	}
	
	char command;
	cin >> command;
	int a, b, friends = 0;
	
	while (command != 'q') {
	    
	    if (command == 'i') {
	        cin >> a >> b;
	        graph[a][b] = graph[b][a] = 1;
	    } else if (command == 'd') {
	        cin >> a >> b;
	        graph[a][b] = graph[b][a] = 0;
	    } else if (command == 'n') {
	        cin >> a;
	        friends = 0;
	        for (int x = 0; x <= 50; x++) {
	            if (graph[a][x] == 1) {
	                friends++;
	            }
	        }
	        cout << friends << endl;
	    } else if (command == 'f') {
	        memset(visited, 0, sizeof(int)*51);
	        cin >> a;
	        visited[a] = 1;
	        int fofs = 0;
	        for (int x = 0; x <= 50; x++) {
	            if (graph[a][x] == 1) {
	                visited[x] = 1;
	                fofs += fof (x, a);
	            }
	        }
	        cout << fofs << endl;
	    } else if (command == 's') {
	        seperation = -1;
	        memset(visited, 0, sizeof(int)*51);
	        cin >> a >> b;
	        dfs (a, b, 0);
	        if (seperation != -1) {
	            cout << seperation << endl;
	        } else {
	            cout << "Not connected" << endl;
	        }
	    }
	    
	    cin >> command;
	}
	
	
	return 0;
}
