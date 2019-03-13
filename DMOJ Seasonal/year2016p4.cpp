#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector < vector <int> > graph(50001);
vector <int> ans;
int n, c[50001] = {0}, l;

bool compare (const int a, const int b) {
    if (c[a] < c[b]) {
        return true;
    } else {
        return false;
    }
}

int child (int pos) {
    for (int x = 0; x < graph[pos].size(); x++) {
        c[pos] += child (graph[pos][x]);
    }
    c[pos]++;
    return c[pos];
}

int solve (int pos, int num, int l) {
    ans.push_back(num);
    if (graph[pos].size() != 0) {
        for (int x = 0; x < graph[pos].size(); x++) {
            solve (graph[pos][x], l - c[graph[pos][x]]+1, l);
            l -= c[graph[pos][x]];
        }
    }
}

int main() {
	// your code goes here
	int k, a;
	scanf ("%d", &n);
	for (int x = 1; x <= n; x++) {
	    scanf ("%d", &k);
	    for (int i = 0; i < k; i++) {
	        scanf ("%d", &a);
	        graph[x].push_back(a);
	    }
	}
	child (1);
	solve (1, 1, n);
    for (int x = 0; x < ans.size(); x++) {
        cout << ans[x] << " ";
    } cout << endl;
	return 0;
}
