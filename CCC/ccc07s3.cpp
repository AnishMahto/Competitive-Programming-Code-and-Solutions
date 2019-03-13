#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<10000> check;
vector < vector <int> > graph(10000);

int dfs (int pos, int end) {
    if (pos == end) {
        return 0;
    }
    for (int x = 0; x < graph[pos].size(); x++) {
        if (check.test(graph[pos][x]) == false) {
            check.set(graph[pos][x]);
            int temp = dfs(graph[pos][x], end);
            if (temp != -1) {
                return temp + 1;
            }
        }
    }
    return -1;
}

int main() {
	// your code goes here
	int n, a, b;
	cin >> n;
	while (n--) {
	    cin >> a >> b;
	    graph[a].push_back(b);
	}
	cin >> a >> b;
	while (a != 0 && b != 0) {
	    
	    check.reset();
	    int temp = dfs(a, b);
	    check.reset();
	    if (temp != -1 && dfs(b, a) != -1) {
	        cout << "Yes " << temp - 1 << endl;
	    } else {
	        cout << "No" << endl;
	    }
	    
	    cin >> a >> b;
	}
	return 0;
}
