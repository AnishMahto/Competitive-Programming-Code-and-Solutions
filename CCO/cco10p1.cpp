#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int spentBarking[1002] = {0}, wait[1002], greatest[1002] = {0}, d, t;
vector < vector <int> > graph(1001);

int solve () {
    int dog = 1, sec = 0;
    priority_queue< pair <int,int> , std::vector< pair <int,int> >, std::greater< pair <int,int> > > minH;
    for (int x = 0; x < graph[dog].size(); x++) {
        minH.push(make_pair(sec, graph[dog][x]));
    }
    spentBarking[1]++;
    while (!minH.empty()) {
        dog = minH.top().second;
        sec = minH.top().first;
        minH.pop();
        if (sec>greatest[dog] && sec+wait[dog]<=t) {
            greatest[dog] = sec+wait[dog];
            spentBarking[dog]++;
            for (int x = 0; x < graph[dog].size(); x++) {
                if (sec+wait[dog] > greatest[graph[dog][x]]) {
                    minH.push(make_pair(sec+wait[dog], graph[dog][x]));
                }
            }
        }
    }
}

int main() {
	// your code goes here
	memset(greatest, -1, sizeof(greatest));
	int a, b, f;
	scanf ("%d", &d);
	for (int x = 1; x <= d; x++) {
	    scanf ("%d", &wait[x]);
	}
	scanf ("%d", &f);
	for (int x = 0; x < f; x++) {
	    scanf ("%d %d", &a, &b);
	    graph[a].push_back(b);
	}
	scanf ("%d", &t);
	solve ();
	for (int x = 1; x <= d; x++) {
	    printf ("%d\n", spentBarking[x]);
	}
	return 0;
}
