#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector < vector <int> > graph(21);
bool check[21][21] = {0};
bool six = false;

int solve (int start, int pos, int len) {
    if (len == 7 && pos == start) {
        six = true;
    } else if (len > 7) {
        return 0;
    } else {
        for (int x = 0; x < graph[pos].size(); x++) {
            if (check[start][graph[pos][x]] == 0 || (len == 6 && graph[pos][x] == start)) {
                check[start][graph[pos][x]] = 1;
                solve (start, graph[pos][x], len + 1);
            }
        } 
    }
    return 0;
}

int main() {
	// your code goes here
	int a, b;
	cin >> n >> m;
	if (n < 6 || m < 6) {
	    cout << "NO" << endl;
	    return 0;
	}
	for (int x = 0; x < m; x++) {
	    cin >> a >> b;
	    graph[a].push_back(b);
	    graph[b].push_back(a);
	}
	for (int x = 1; x <= n; x++) {
	    check[x][x] = 1;
	    solve (x, x, 1);
	    if (six) {
	        cout << "YES" << endl;
	        return 0;
	    }
	}
	cout << "NO" << endl;
	return 0;
}
