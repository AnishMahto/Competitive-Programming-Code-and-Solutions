#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int n, t, v, tt, et, pt, pe, greatest = 0;
	cin >> n >> t;
	vector < vector < pair <int, int> > > skills(n);
	for (int a = 0; a < n; a++) {
	    cin >> v;
	    if (v == 1) {
	        cin >> tt >> et;
	        skills[a].push_back(make_pair(tt, et));
	    } else {
	        for (int x = 0; x < v; x++) {
	            cin >> tt >> et;
	            if (x == 0) {
	                skills[a].push_back(make_pair(tt, et));
	            } else {
	                skills[a].push_back(make_pair(tt + skills[a][x - 1].first, skills[a][x - 1].second + et));
	            }
	            pt = tt;
	            pe = et;
	        }
	    }
	}
	int dp[n + 1][t + 1] = {0};
	memset(dp, 0, sizeof(int)*(n + 1)*(t + 1));
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i <= t; i++) {
	            for (int z = 0; z < skills[x].size(); z++) {
	                if (skills[x][z].first <= i) {
	                    if (x > 0) {
	                        dp[x][i] = max (dp[x][i], dp[x - 1][i - skills[x][z].first] + skills[x][z].second);
	                    } else {
	                        dp[x][i] = skills[x][z].second;
	                    }
	                } else {
	                    break;
	                }
	            }
	        if (x > 0) {
	            dp[x][i] = max (dp[x][i], dp[x - 1][i]);
	        }
	        if (i > 0) {
	            dp[x][i] = max (dp[x][i], dp[x][i - 1]);
	        }
	    }
	}
	cout << dp[n - 1][t] << endl;
	return 0;
}
