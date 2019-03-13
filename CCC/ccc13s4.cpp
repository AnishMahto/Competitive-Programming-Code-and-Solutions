#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector < vector <int> > graph(1000001);

int visited[1000001] = {0};

bool dfs (int pos, int end) {
    if (pos == end) {
        return true;
    } else {
        bool temp;
        for (int x = 0; x < graph[pos].size(); x++) {
            if (visited[graph[pos][x]] == 0) {
                visited[graph[pos][x]] = 1;
                temp = dfs (graph[pos][x], end);
                if (temp == true) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
	// your code goes here
	int n, a, b, m;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b;
	    graph[a].push_back(b);
	}
	cin >> a >> b;
	bool checkA = dfs(a, b);
	memset(visited, 0, sizeof(int)*1000001);
	bool checkB = dfs(b, a);
	
	if (checkB == checkA) {
	    cout << "unknown" << endl;
	} else if (checkA) {
	    cout << "yes" << endl;
	} else {
	    cout << "no" << endl;
	}
	
	return 0;
}
