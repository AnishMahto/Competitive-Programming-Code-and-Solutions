#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int ppl[51][3] = {0}, n;
pair <int, int> dp[51][1001];

pair <int, int> larger (pair <int, int> i, pair <int, int> j) {
	if (i.first < j.first) {
		return j;
	} else if (i.first > j.first) {
		return i;
	} else {
		if (i.second < j.second) {
			return i;
		} else {
			return j;
		}
	}
}

pair <int, int> solve (int pos, int t) {
    if (t == 0 || pos == n) {
        return make_pair(0, 0);
    } else if (dp[pos][t].first != 0) {
        return dp[pos][t];
    } else {
        int val = ppl[pos][0], added = 0;
        dp[pos][t] = solve (pos+1, t);
        for (int x = 1; x <= t/ppl[pos][2] && val != 0; x++) {
            added += val;
            dp[pos][t] = larger (dp[pos][t], make_pair(added + solve (pos+1, t-x*ppl[pos][2]).first, solve (pos+1, t-x*ppl[pos][2]).second + x));
            val -= ppl[pos][1];
            val = max (val, 0);
        }
    }
    return dp[pos][t];
}

int main() {
	// your code goes here
	for (int x = 0; x < 51; x++) {
		for (int i = 0; i < 1001; i++) {
			dp[x][i].first = dp[x][i].second = 0;
		}
	}
	int t;
	scanf ("%d", &n);
	for (int x = 0; x < n; x++) {
	    scanf ("%d %d %d", &ppl[x][0],&ppl[x][1],&ppl[x][2]);
	}
	scanf ("%d", &t);
	cout << solve (0, t).first << endl << solve (0, t).second << endl;
	return 0;
}
