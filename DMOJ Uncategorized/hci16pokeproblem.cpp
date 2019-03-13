#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, c, graph[101][101] = {0}, strongest[101] = {0}, a, b, t, greatest = 0;
	cin >> n >> c;
	for (int x = 0; x < c; x++) {
	    cin >> a >> b;
	    graph[a][b] = 1;
	}
	cin >> t;
	int types[t];
	for (int x = 0; x < t; x++) {
	    cin >> types[x];
	}
	for (int x = 1; x <= n; x++) {
	    int count = 0;
	    for (int i = 0; i < t; i++) {
	        if (graph[x][types[i]] == 1) {
	            count++;
	        } else if (graph[types[i]][x] == 1) {
	            count--;
	        }
	    }
	    strongest[x] = count;
	    if (count > strongest[greatest]) {
	        greatest = x;
	    }
	}
	cout << greatest << endl;
	return 0;
}
