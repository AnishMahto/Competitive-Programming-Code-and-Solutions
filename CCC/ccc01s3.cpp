#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
 
vector < vector <int> > graph(300);
//'A' = 65, 'B' = 66
vector < pair <int, int> > edges;
int visited[30] = {0};
 
bool dfs (int pos, int a, int b) {
    if (pos == 66) {
        return true;
    } else {
        for (int x = 0; x < graph[pos].size(); x++) {
            if (visited[graph[pos][x] - 64] != 1) {
                if (pos == a || pos == b) {
                    if (graph[pos][x] != a && graph[pos][x] != b) {
                        visited[graph[pos][x] - 64] = 1;
                        if (dfs (graph[pos][x], a, b)) {
                            return true;
                        }
                    }
                } else {
                    visited[graph[pos][x] - 64] = 1;
                    if (dfs (graph[pos][x], a, b)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
 
int main() {
	// your code goes here
	char a, b;
	int temp1, temp2, total = 0;
	cin >> a >> b;
	while (a != '*' && b != '*') {
	    temp1 = a;
	    temp2 = b;
	    edges.push_back(make_pair(temp1, temp2));
	    graph[temp1].push_back(temp2);
	    graph[temp2].push_back(temp1);
	    cin >> a >> b;
	}
	for (int x = 0; x < edges.size(); x++) {
	    memset(visited, 0, sizeof(int)*30);
	    if (dfs (65, edges[x].first, edges[x].second) == false) {
	        a = edges[x].first;
	        b = edges[x].second;
	        cout << a << b << endl;
	        total++;
	    }
	}
	cout << "There are " << total << " disconnecting roads." << endl;
	return 0;
}
