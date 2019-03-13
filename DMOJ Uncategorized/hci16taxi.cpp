#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include<cstdio>
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
vector < vector < pair <int, int> > > graph(100001);
int dp[100001], dp2[100001];
int main() {
	// your code goes here
	int v, e, p, d, r, a, b, w;
	priority_queue< pair <int, int> ,vector< pair <int, int> >,greater< pair <int, int> > > minHeap;
	scanint(v); scanint(e); scanint(p); scanint(d); scanint(r);
	for (int x = 0; x < e; x++) {
	    scanint(a); scanint(b); scanint(w);
	    graph[a].push_back(make_pair(b, w));
	    graph[b].push_back(make_pair(a, w));
	}
	memset(dp, -1, sizeof(int)*100001);
	dp[p] = 0;
	for (int x = 0; x < graph[p].size(); x++) {
	    minHeap.push(make_pair(graph[p][x].second, graph[p][x].first));
	}
	while(!minHeap.empty()) {
	    int destination = minHeap.top().second, weight = minHeap.top().first;
	    minHeap.pop();
	    if (dp[destination] == -1 || dp[destination] > weight) {
	        dp[destination] = weight;
	        for (int x = 0; x < graph[destination].size(); x++) {
	            minHeap.push(make_pair(graph[destination][x].second + weight, graph[destination][x].first));
	        }
	    }
	}
	memset(dp2, -1, sizeof(int)*100001);
	dp2[d] = 0;
	for (int x = 0; x < graph[d].size(); x++) {
	    minHeap.push(make_pair(graph[d][x].second, graph[d][x].first));
	}
	while(!minHeap.empty()) {
	    int destination = minHeap.top().second, weight = minHeap.top().first;
	    minHeap.pop();
	    if (dp2[destination] == -1 || dp2[destination] > weight) {
	        dp2[destination] = weight;
	        for (int x = 0; x < graph[destination].size(); x++) {
	            minHeap.push(make_pair(graph[destination][x].second + weight, graph[destination][x].first));
	        }
	    }
	}
    if (dp[d] == -1) {
        cout << "Nooooooooo!!!" << endl;
    } else if (dp2[r] == -1) {
        int total = dp[d];
        if (total <= 10) {
            cout << total * 2 + 3 << endl;
        } else {
            cout << 10 * 2 + 3 + (total - 10) << endl;
        }
        cout << "Yippee!!!" << endl;
    } 
    else {
        int total = dp[d] + dp2[r];
        if (total <= 10) {
            cout << total * 2 + 3 << endl;
        } else {
            cout << 10 * 2 + 3 + (total - 10) << endl;
        }
    }
	return 0;
}
