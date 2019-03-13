#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <bitset>
#include <string.h>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x) {
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

vector < vector < pair <int, int> > > graph(1001);
bitset<1001> black, w, g;

bool cycle (int pos) {
    if (g.test(pos)) {
        return true;
    } else if (w.test(pos)) {
        w.flip(pos);
        g.set(pos);
        for (int x = 0; x < graph[pos].size(); x++) {
            if (cycle (graph[pos][x].first)) {
                return true;
            }
        }
    } else if (black.test(pos)) {
        return false;
    }
    black.set(pos);
    g.flip(pos);
    return false;
}

int main() {
	// your code goes here
	w.set();
	int n, m, a, b, d;
	scanint(n);scanint(m);
	for (int x = 0; x < m; x++) {
	    scanint(a);scanint(b);scanint(d);
	    graph[a].push_back(make_pair(b, d));
	}
	if (cycle (1) || !black.test(n)) {
	    cout << -1 << endl;
	} else {
	    long long sp[1001];
	    int totalVisited[1001] = {0};
	    memset(sp, -1, sizeof(long long)*1001);
	    sp[1] = 0;
	    totalVisited[1] = 1;
	    priority_queue < pair <int, pair <int, int> >, vector< pair <int, pair <int, int> > > > minHeap;
	    for (int x = 0; x < graph[1].size(); x++) {
	        minHeap.push(make_pair(graph[1][x].second, make_pair(graph[1][x].first, 1)));
	    }
	    while (!minHeap.empty()) {
	        int dest = minHeap.top().second.first, from = minHeap.top().second.second;
	        int weight = minHeap.top().first;
	        minHeap.pop();
	        if (sp[dest] == -1 || sp[from] + weight > sp[dest] || (sp[from] + weight == sp[dest] && totalVisited[from] + 1 > totalVisited[dest])) {
	            sp[dest] = sp[from] + weight;
	            totalVisited[dest] = totalVisited[from] + 1;
	            for (int x = 0; x < graph[dest].size(); x++) {
	                if (graph[dest][x].second + sp[dest] >= sp[graph[dest][x].first]) {
	                    minHeap.push(make_pair(graph[dest][x].second, make_pair(graph[dest][x].first, dest)));
	                }
	            }
	        }
	    }
	    cout << sp[n] << " " << totalVisited[n] << endl;
	}
	return 0;
}
