#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector < vector <int> > graph(400001);
int agri[400001] = {0};
int visited[400001] = {0};
int greatestAgri = -1000;

int solve (int pos) {
    if (visited[pos] == 1) {
        return agri[pos];
    }
    if (graph[pos].size() == 0) {
        visited[pos] = 1;
        return agri[pos];
    } else {
        visited[pos] = 1;
        for (int x = 0; x < graph[pos].size(); x++) {
            agri[pos] += solve (graph[pos][x]);
        }
        if (agri[pos] > greatestAgri) {
            greatestAgri = agri[pos];
        }
        return agri[pos];
    }
}

int main() {
	// your code goes here
	int n, a, b;
	cin >> n;
    for (int x = 0; x < n - 1; x++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int x = 1; x <= n; x++) {
        cin >> agri[x];
        if (agri[x] > greatestAgri) {
            greatestAgri = agri[x];
        }
    }
    solve (1);
    cout << greatestAgri << endl;
	return 0;
}
