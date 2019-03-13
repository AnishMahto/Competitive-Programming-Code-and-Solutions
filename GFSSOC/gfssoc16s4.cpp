#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[1001] = {0};
vector < pair <int, pair <int, int> > > cs;

int main() {
	// your code goes here
	int n, v, s, t, greatest = 0;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    scanf ("%d %d %d", &v, &s, &t);
	    if (s <= t) {
	        cs.push_back(make_pair(t, make_pair (s, v)));
	    }
	}
	sort (cs.begin(), cs.end());
	for (int x = 0; x < cs.size(); x++) {
	    t = cs[x].first;
	    s = cs[x].second.first;
	    v = cs[x].second.second;
	    for (int i = t; i - s >= 0; i--) {
	        dp[i] = max (dp[i - s] + v, dp[i]);
	        greatest = max (greatest, dp[i]);
	    }
	}
	
	cout << greatest << endl;
	return 0;
}
