#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

vector < vector <int> > graph(20001);
int dp[20001] = {0};
long long paths[20001] = {0}, total = 0;
bitset<20001> start, end;

int solve (int pos, int step) {
    if (paths[pos] == 0) {
        paths[pos] = 1;
    }
    dp[pos] = min (dp[pos], step);
    if (dp[pos] == 0) {
        dp[pos] = step;
    }
    for (int x = 0; x < graph[pos].size(); x++) {
        if (paths[graph[pos][x]] == 0) {
            paths[graph[pos][x]] = 1;
        }
        paths[graph[pos][x]] *= paths[pos];
        solve (graph[pos][x], step + 1);
    }
    if (graph[pos].size() == 0) {
        total += paths[pos];
        total = total % (long long)(pow (10, 9) + 7);
    }
}

int main() {
	// your code goes here
	int n, m, a, b;
	start.set();
	end.set();
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b;
	    graph[a].push_back(b);
	    if (end.test(a)) {
	        end.flip(a);
	    }
	    if (start.test(b)) {
	        start.flip(b);
	    }
	}
	for (int x = 0; x < n; x++) {
	    if (start.test(x)) {
	        solve (x, 1);
	    }
	}
	cout << total << endl;
	for (int x = 0; x < n; x++) {
	    if (end.test(x)) {
	        cout << dp[x] << " ";
	    }
	} cout << endl;
	return 0;
}
