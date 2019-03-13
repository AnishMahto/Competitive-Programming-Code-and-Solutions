#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <bitset>
using namespace std;

vector < vector <int> > graph(501); 
vector < pair < int, pair <int, int> > > beacons;
bitset<501> check;
bool possible;

int dfs (int pos, int end) {
    if (check.test(pos)) {
        return 0;
    } else {
        check.set(pos);
        if (pos == end) {
            possible = true;
            return 0;
        }
        for (int x = 0; x < graph[pos].size(); x++) {
            dfs (graph[pos][x], end);
        }
    }
}

int main() {
	// your code goes here
	int n, q, a, b, c;
	scanf ("%d %d", &n, &q);
	for (int x = 1; x <= n; x++) {
	    scanf ("%d %d %d", &a, &b, &c);
	    beacons.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int x = 1; x <= n; x++) {
	    for (int i = 0; i < beacons.size(); i++) {
	        if (i + 1 != x) {
	            if (sqrt((float)pow(abs(beacons[i].second.first - beacons[x - 1].second.first), 2) + (float)pow(abs(beacons[i].second.second - beacons[x - 1].second.second), 2) ) <= beacons[x - 1].first) {
	                graph[x].push_back(i + 1);
	            }
	        }
	    }
	}
	for (int x = 0; x < q; x++) {
	    scanf ("%d %d", &a, &b);
	    check.reset();
	    possible = false;
	    dfs (a, b);
	    if (possible) {
	        cout << "YES" << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
