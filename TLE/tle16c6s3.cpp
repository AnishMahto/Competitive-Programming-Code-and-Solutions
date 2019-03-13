#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

int dp[2001][2001][2] = {0}, dist[2001][2001][2] = {0}, start, answer = 0;
vector < pair <int, int> > pie;

//side -> 0 == left, side -> 1 == right 
int solve (int left, int right, bool side) {
    if (dp[left][right][side] != -1) {
        return dp[left][right][side];
    } else if (left == right && right == start) {
        return pie[start].second;
    } else {
        int atLeft, atRight, d;
        if (right > start && side) {
            atLeft = solve (left, right - 1, false);
            atRight = solve (left, right - 1, true);
            d = abs(pie[right].first - pie[right - 1].first);
            if (atRight >= d) {
                dp[left][right][side] = max (dp[left][right][side], atRight - d + pie[right].second);
                if (dp[left][right][side] == (atRight - d + pie[right].second)) {
                    dist[left][right][side] = d + dist[left][right - 1][1];
                }
            }
            d = abs(pie[right].first - pie[left].first);
            if (atLeft >= d) {
                dp[left][right][side] = max (dp[left][right][side], atLeft - d + pie[right].second);
                if (dp[left][right][side] == (atLeft - d + pie[right].second)) {
                    dist[left][right][side] = d + dist[left][right - 1][0];
                }
            }
        } else if (!side && left < start) {
            atLeft = solve (left + 1, right, false);
            atRight = solve (left + 1, right, true);
            d = abs(pie[left + 1].first - pie[left].first);
            if (atLeft >= d) {
                dp[left][right][side] = max (dp[left][right][side], atLeft - d + pie[left].second);
                if (dp[left][right][side] == (atLeft - d + pie[left].second)) {
                    dist[left][right][side] = d + dist[left + 1][right][0];
                }
            }
            d = abs(pie[right].first - pie[left].first);
            if (atRight >= d) {
                dp[left][right][side] = max (dp[left][right][side], atRight - d + pie[left].second);
                if (dp[left][right][side] == (atRight - d + pie[left].second)) {
                    dist[left][right][side] = d + dist[left + 1][right][1];
                }
            }
        }
    }
    answer = max (answer, dist[left][right][side] + dp[left][right][side]);
    dp[left][right][side] = max (0, dp[left][right][side]);
    return dp[left][right][side];
}

int main() {
	// your code goes here
	int n, a, b;
	memset(dp, -1, sizeof(dp));
	scanf ("%d", &n);
	for (int x = 0; x < n; x++) {
	    scanf ("%d %d", &a, &b);
	    pie.push_back(make_pair(a, b));
	}
	sort (pie.begin(), pie.end());
	vector < pair <int, int> >::iterator it = lower_bound(pie.begin(), pie.end(), make_pair(0, 0));
	start = (it - pie.begin());
	answer = pie[start].second;
	solve (0, n - 1, 0);
	solve (0, n - 1, 1);
	cout << answer << endl;
	return 0;
}
