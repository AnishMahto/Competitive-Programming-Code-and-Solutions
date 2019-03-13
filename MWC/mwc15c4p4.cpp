#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector < vector <int> > graph(1001);
bitset<1001> check;
bool done = false;

int dfs (int pos, int find) {
    if (done || check.test(pos)) {
        return 0;
    } else if (pos == find) {
        done = true;
        return 0;
    } else {
        check.set(pos);
        for (int x = 0; x < graph[pos].size(); x++) {
            dfs (graph[pos][x], find);
        }
    }
    return 0;
}

int main() {
	// your code goes here
	int n, a, b;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> a >> b;
	    graph[a].push_back(b);
	    //graph[b].push_back(a);
	}
	cin >> a >> b;
	dfs (a, b);
	if (done) {
	    cout << "Tangled" << endl;
	} else {
	    cout << "Not Tangled" << endl;
	}
	return 0;
}
