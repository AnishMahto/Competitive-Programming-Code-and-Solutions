#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dp[101] = {0};
int items[101];
int pick[101] = {0};

int main() {
	// your code goes here
	int n, m, a, b, c, current;
	cin >> n;
	for (int x = 1; x <= n; x++) {
	    cin >> items[x];
	}
	vector < vector < vector <int> > > graph(n + 1);
	vector <int> temp;
	pick[1] = items[1];
	cin >> m;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b >> c;
	    temp.push_back(a);
	    temp.push_back(c);
	    graph[b].push_back(temp);
	    temp[0] = b;
	    graph[a].push_back(temp);
	    temp.clear();
	}
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
	    current = q.front();
	    for (int x = 0; x < graph[current].size(); x++) {
	        if (graph[current][x][0] != 1 && (graph[current][x][1] + dp[current] < dp[graph[current][x][0]] || dp[graph[current][x][0]] == 0)) {
	            dp[graph[current][x][0]] = graph[current][x][1] + dp[current];
	            pick[graph[current][x][0]] = pick[current] + items[graph[current][x][0]];
	            q.push(graph[current][x][0]);
	        } else if (graph[current][x][0] != 1 && (graph[current][x][1] + dp[current] == dp[graph[current][x][0]] && pick[current] + items[graph[current][x][0]] > pick[graph[current][x][0]])) {
	            pick[graph[current][x][0]] = pick[current] + items[graph[current][x][0]];
	            q.push(graph[current][x][0]);
	        }
	    }
	    q.pop();
	}
	if (dp[n] != 0) {
	    cout << dp[n] << " " << pick[n] << endl;
	} else {
	    cout << "impossible" << endl;
	}
	return 0;
}
