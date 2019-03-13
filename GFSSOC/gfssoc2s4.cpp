#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>
#define gc getchar_unlocked
using namespace std;

int n, m, a, b, c;
long long dp[500001] = {0}, dp2[500001] = {0};

vector < vector < pair <long long, long long> > > graph(500001), cindy(500001), opp(500001);

void scanint(int &x) {
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

int main() {
	// your code goes here
	memset(dp, -1, sizeof(long long)*500001);
	memset(dp2, -1, sizeof(long long)*500001);
	scanint(n);scanint(m);
	for (int x = 0; x < m; x++) {
	    scanint(a);scanint(b);scanint(c);
	    graph[a].push_back(make_pair(b, c));
	    opp[b].push_back(make_pair(a, c));
	}
	scanint(m);
	for (int x = 0; x < m; x++) {
	    scanint(a);scanint(b);scanint(c);
	    cindy[a].push_back(make_pair(b, c));
	}
	priority_queue < pair <long long, long long>, vector < pair <long long, long long> >, greater < pair <long long, long long> > > minHeap;
	dp[n] = 0;
	for (int x = 0; x < opp[n].size(); x++) {
	    minHeap.push(make_pair(opp[n][x].second, opp[n][x].first));
	}
	while (!minHeap.empty()) {
	    int dest = minHeap.top().second, weight = minHeap.top().first;
	    minHeap.pop();
	    if (dp[dest] == -1 || dp[dest] > weight) {
	        dp[dest] = weight;
	        for (int x = 0; x < opp[dest].size(); x++) {
	            if (dp[opp[dest][x].first] == -1 || opp[dest][x].first > dp[dest] + opp[dest][x].second) {
	                minHeap.push(make_pair(dp[dest] + opp[dest][x].second, opp[dest][x].first));
	            }
	        }
	    }
	}
	dp2[1] = 0;
	for (int x = 0; x < graph[1].size(); x++) {
	    minHeap.push(make_pair(graph[1][x].second, graph[1][x].first));
	}
	while (!minHeap.empty()) {
	    int dest = minHeap.top().second, weight = minHeap.top().first;
	    minHeap.pop();
	    if (dp2[dest] == -1 || dp[dest] > weight) {
	        dp2[dest] = weight;
	        for (int x = 0; x < graph[dest].size(); x++) {
	            if (dp2[graph[dest][x].first] == -1 || dp2[graph[dest][x].first] > dp2[dest] + graph[dest][x].second) {
	                minHeap.push(make_pair(dp2[dest] + graph[dest][x].second, graph[dest][x].first));
	            }
	        }
	    }
	}
	long long least = -1;
	for (int x = 1; x < cindy.size(); x++) {
	    if (dp2[x] != -1) {
	        for (int i = 0; i < cindy[x].size(); i++) {
	            if (dp[cindy[x][i].first] != -1) {
	                if (least == -1) {
	                    least = dp2[x] + cindy[x][i].second + dp[cindy[x][i].first];
	                }
	                least = min (least, dp2[x] + cindy[x][i].second + dp[cindy[x][i].first]);
	            }
	        }
	    }
	}
	if (least == -1) {
	    least = dp2[n];
	} else if (dp2[n] != -1) {
	    least = min (least, dp2[n]);
	}
    cout << least << endl;
	return 0;
}
