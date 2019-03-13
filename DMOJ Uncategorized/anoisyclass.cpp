#include <iostream>
#include <vector>
using namespace std;

vector < vector <int> > kids(10001);
int visited[10001] = {0};

bool cycle (int pos) {
    if (visited[pos] && kids[pos].size() != 0) {
        return true;
    } else {
        visited[pos] = 1;
        for (int x = 0; x < kids[pos].size(); x++) {
            if (cycle (kids[pos][x])) {
                return true;
            }
        }
    }
    return false;
}

int main() {
	// your code goes here
	int n, m, a, b;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b;
	    kids[a].push_back(b);
	}
	for (int x = 1; x <= n; x++) {
	    if (visited[x] != 1) {
	        if (cycle(x)) {
	            cout << "N" << endl;
	            return 0;
	        }
	    }
	}
	cout << "Y" << endl;
	return 0;
}
