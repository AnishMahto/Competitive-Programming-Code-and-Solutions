#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

vector < vector < pair <int, int> > > graph(2001);
int dp[2001];

int main() {
	// your code goes here
	memset(dp, -1, sizeof(int)*2001);
	int n, m, s, q, a, b, c;
	cin >> n >> m >> s >> q;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b >> c;
	    graph[a].push_back(make_pair(b, c));
	    graph[b].push_back(make_pair(a, c));
	}
	dp[s] = 0;
	priority_queue<pair <int, int>, std::vector< pair <int, int> >, std::greater< pair <int, int> > > minHeap;
	for (int x = 0; x < graph[s].size(); x++) {
	    minHeap.push(make_pair(graph[s][x].second, graph[s][x].first));
	}
	while (!minHeap.empty()) {
	    int pos = minHeap.top().second, weight = minHeap.top().first;
	    minHeap.pop();
	    if (dp[pos] == -1 || weight < dp[pos]) {
	        dp[pos] = weight;
	        for (int x = 0; x < graph[pos].size(); x++) {
	            minHeap.push(make_pair(graph[pos][x].second + weight, graph[pos][x].first));
	        }
	    }
	}
	for (int x = 0; x < q; x++) {
	    cin >> a;
	    cout << dp[a] << endl;
	}
	return 0;
}
