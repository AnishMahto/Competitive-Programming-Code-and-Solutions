#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n, m, a, b, c, d;
vector < vector <int> > graph(2001);
bitset <2001> check;
bool possible = false;

int solve (int pos) {
    if (pos == b) {
        possible = true;
        return 0;
    }
    if (possible || check.test(pos)) {
        return 0;
    } else {
        check.set(pos);
        for (int x = 0; x < graph[pos].size(); x++) {
            solve (graph[pos][x]);
        }
    }
    return 0;
}

int main() {
	// your code goes here
	cin >> n >> m >> a >> b;
	for (int x = 0; x < m; x++) {
	    cin >> c >> d;
	    graph[c].push_back(d);
	    graph[d].push_back(c);
	}
	solve (a);
	if (possible) {
	    cout << "GO SHAHIR!" << endl;
	} else {
	    cout << "NO SHAHIR!" << endl;
	}
	return 0;
}
