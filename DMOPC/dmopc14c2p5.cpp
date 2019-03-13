#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	double probs[1000001] = {0};
	vector < vector <int> > graph(1000001);
	int n, m, a, b, greatest = -1;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    scanf("%d %d", &a, &b);
	    graph[a].push_back(b);
	    if (a > greatest) {
	        greatest = a;
	    }
	}
	probs[1] = 1;
	double temp;
	vector <int> leafs;
	for (int x = 1; x <= greatest; x++) {
	    if (graph[x].size() > 0) {
	        temp = graph[x].size();
	        for (int i = 0; i < graph[x].size(); i++) {
	            probs[graph[x][i]] += probs[x]/temp;
	        }
	    } else {
	        leafs.push_back(x);
	    }
	}
	for (int x = 0; x < leafs.size(); x++) {
	    printf ("%.9f\n", probs[leafs[x]]);
	}
	if (greatest != n) {
    	for (int x = greatest + 1; x <= n; x++) {
	        printf ("%.9f\n", probs[x]);
	    }
	}
	return 0;
}
