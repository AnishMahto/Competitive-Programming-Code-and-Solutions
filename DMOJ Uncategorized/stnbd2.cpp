#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

long long pSum[100001] = {0}, paths[100001] = {0}, totalSum = 0;
bool parent[100001] = {0}, end[100001] = {0};
//1 if not parent, 0 otherwise; same for end
vector < vector <int> > revGraph(100001);

int solve (int pos) {
    for (int x = 0; x < revGraph[pos].size(); x++) {
        if (pSum[revGraph[pos][x]] == 0 && paths[revGraph[pos][x]] == 0 && parent[revGraph[pos][x]]) {
            solve (revGraph[pos][x]);
        }
        if (!parent[revGraph[pos][x]]) {
            paths[revGraph[pos][x]] = 1;
        }
        paths[pos] += paths[revGraph[pos][x]]; 
        pSum[pos] += pSum[revGraph[pos][x]];
        pSum[pos] %= 1000000007;
        paths[pos]  %= 1000000007;
    }
    pSum[pos] += paths[pos];
    pSum[pos] %= 1000000007;
}

int main() {
	// your code goes here
	int n, m, a, b;
	scanf ("%d %d", &n, &m);
	for (int x = 0; x < m; x++) {
	    scanf ("%d %d", &a, &b);
	    revGraph[b].push_back(a);
	    parent[b] = 1;
	    end[a] = 1;
	}
	for (int x = 1; x <= n; x++) {
	    if (!parent[x] && !end[x]) {
	    } else if (!end[x]) {
	        solve (x);
	        totalSum += pSum[x];
	    }
	    totalSum %= 1000000007;
	}
	cout << totalSum << endl;
	return 0;
}
