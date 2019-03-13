#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
using namespace std;

int dp[19][262144 + 1] = {0}, n, m, a, b, l;
vector < vector < pair <int, int> > > graph(20);

int solve (int pos, bitset<18> visited) {
    if (pos == n - 1) {
        return 0;
    }
    int temp = visited.to_ulong();
    if (dp[pos][temp] != 0) {
        return dp[pos][temp];
    } else {
        dp[pos][temp] = -1000000;
        for (int x = 0; x < graph[pos].size(); x++) {
            if (!visited.test(graph[pos][x].first)) {
                visited.set(graph[pos][x].first);
                dp[pos][temp] = max (dp[pos][temp], solve (graph[pos][x].first, visited) + graph[pos][x].second);
                visited.flip(graph[pos][x].first);
            }
        }
    }
    return dp[pos][temp];
}

int main() {
	// your code goes here
	bitset<18>temp;
	scanf ("%d %d", &n, &m);
	for (int x = 0; x < m; x++) {
	    scanf ("%d %d %d", &a, &b, &l);
	    graph[a].push_back(make_pair(b, l));
	}
	temp.set(0);
	cout << solve (0, temp) << endl;
	return 0;
}
