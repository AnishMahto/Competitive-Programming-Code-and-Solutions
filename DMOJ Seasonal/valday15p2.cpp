#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int c, m, a, b, dp[1001][1001] = {0};
	cin >> c >> m;
	vector < pair <int, int> > cages(c);
	for (int x = 0; x < c; x++) {
	    cin >> a >> b;
	    cages[x] = make_pair(a, b);
	}
	for (int x = 0; x < c; x++) {
	    for (int i = 0; i <= m; i++) {
	        if (x > 0) {
	            dp[x][i] = max (dp[x][i], dp[x - 1][i]);
	        }
	        if (i > 0) {
	            dp[x][i] = max (dp[x][i], dp[x][i - 1]);
	        }
	        if (cages[x].second <= i && x > 0) {
	            dp[x][i] = max (dp[x][i], dp[x - 1][i - cages[x].second] + cages[x].first);
	        }
	    }
	}
	cout << dp[c - 1][m] << endl;
	return 0;
}
