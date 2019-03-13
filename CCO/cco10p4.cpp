#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int t, n, b, d, e, f;
	cin >> t >> n;
	vector < vector < pair <int, int> > > parts(t);
	for (int x = 0; x < n; x++) {
	    scanf("%d %d %d", &d, &e, &f);
	    parts[f - 1].push_back(make_pair(d, e));
	}
	cin >> b;
	int dp[t][b + 1] = {0};
	memset(dp, 0, sizeof(int)*(t)*(b + 1));
	for (int x = 0; x < t; x++) {
	    sort (parts[x].begin(), parts[x].end());
	    for (int i = 0; i <= b; i++) {
	        auto it = upper_bound (parts[x].begin(), parts[x].end(), make_pair(i, 10000));
	        int temp = it - parts[x].begin();
	        for (int a = 0; a < temp; a++) {
	            if (x == 0) {
	                dp[x][i] = max (dp[x][i], parts[x][a].second);
	            } else if (i >= parts[x][a].first) {
	                dp[x][i] = max (dp[x][i], dp[x - 1][i - parts[x][a].first] + parts[x][a].second);
	            }
	            if (x > 0) {
	                dp[x][i] = max (dp[x][i], dp[x - 1][i]);
	            }
	            if (i > 0) {
	                dp[x][i] = max (dp[x][i], dp[x][i - 1]);
	            }
	        }
	    }
	}
	cout << dp[t - 1][b] << endl;
	return 0;
}
