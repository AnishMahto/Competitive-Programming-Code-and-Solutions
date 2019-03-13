#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int n, m, start, end;
vector < vector < pair <int, int> > > graph(100001), revGraph(100001);
vector < pair <pair <int, int>, pair <int, int> > > edges;
priority_queue < pair <int, int> , vector< pair <int, int> >, greater < pair <int, int> > > heap;
vector < pair <int, int> > edgeList;
int dijkStart[100001], dijkEnd[100001], pSum[100001] = {0};

int main() {
	// your code goes here
	memset(dijkStart, -1, sizeof(int)*100001);
	memset(dijkEnd, -1, sizeof(int)*100001);
	int a, b, c, d, q;
	scanint (n); scanint (m); scanint (start); scanint (end);
	for (int x = 0; x < m; x++) {
	    scanint(a); scanint(b); scanint(c); scanint(d);
	    graph[a].push_back(make_pair(b, c));
	    revGraph[b].push_back(make_pair(a, c));
	    edges.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
	}
	dijkStart[start] = dijkEnd[end] = 0;
	for (int x = 0; x < graph[start].size(); x++) {
	    heap.push(make_pair(graph[start][x].second, graph[start][x].first));
	}
	while (!heap.empty()) {
	    int cost = heap.top().first, node = heap.top().second;
	    heap.pop();
	    if (dijkStart[node] > cost || dijkStart[node] == -1) {
	        dijkStart[node] = cost;
	        for (int x = 0; x < graph[node].size(); x++) {
	            heap.push(make_pair(cost + graph[node][x].second, graph[node][x].first));
	        }
	    }
	}
	for (int x = 0; x < revGraph[end].size(); x++) {
        heap.push(make_pair(revGraph[end][x].second, revGraph[end][x].first));
	}
	while (!heap.empty()) {
	    int cost = heap.top().first, node = heap.top().second;
	    heap.pop();
	    if (dijkEnd[node] > cost || dijkEnd[node] == -1) {
	        dijkEnd[node] = cost;
	        for (int x = 0; x < revGraph[node].size(); x++) {
	            heap.push(make_pair(cost + revGraph[node][x].second, revGraph[node][x].first));
	        }
	    }
	}
	for (int x = 0; x < edges.size(); x++) {
	    int from = edges[x].first.first, to = edges[x].first.second, dist = edges[x].second.first, shutDown = edges[x].second.second;
	    if (from == start && to == end) {
	        edgeList.push_back(make_pair(dist, shutDown));
	    } else if (from == start && dijkEnd[to] != -1) {
	        edgeList.push_back(make_pair(dist + dijkEnd[to], shutDown));
	    } else if (to == end && dijkStart[from] != -1) {
	        edgeList.push_back(make_pair(dist + dijkStart[from], shutDown));
	    } else if (dijkStart[from] != -1 && dijkEnd[to] != -1) {
	        edgeList.push_back(make_pair(dist + dijkStart[from] + dijkEnd[to], shutDown));
	    }
	}
	sort (edgeList.begin(), edgeList.end());
	pSum[0] = edgeList[0].second;
	for (int x = 1; x < edgeList.size(); x++) {
	    pSum[x] = pSum[x - 1] + edgeList[x].second;
	}
	scanint (q);
	vector < pair <int, int> >::iterator it;
	for (int x = 0; x < q; x++) {
	    scanint(d);
	    if (d < edgeList[0].first) {
	        printf ("0\n");
	    } else {
	        it = upper_bound(edgeList.begin(), edgeList.end(), make_pair(d, 100000000));
	        if (it != edgeList.end()) {
	            printf ("%d\n", pSum[it - edgeList.begin() - 1]);
	        } else {
	            printf ("%d\n", pSum[edgeList.size() - 1]);
	        }
	    }
	}
	return 0;
}
