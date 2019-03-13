#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, items[5001][3] = {0}, used[5001] = {0}, bestTrck[5001] = {0};
    long long dp[5001];
    memset (dp, -1, sizeof(dp));
    dp[0] = 0;
    scanf ("%d %d", &n, &m);
    for (int x = 0; x < n; x++) {
        scanf ("%d %d %d", &items[x][0], &items[x][1], &items[x][2]);
    }
    for (int x = 0; x < n; x++) {
        memset (used, 0, sizeof(used));
        for (int i = items[x][1]; i <= 5000; i++) {
            if (dp[i-items[x][1]] != -1 && used[i-items[x][1]]+1 <= items[x][0] && dp[i-items[x][1]]+items[x][2] > dp[i]) {
                dp[i] = dp[i-items[x][1]]+items[x][2];
                used[i] = used[i-items[x][1]]+1;
            }
        }
    }
    long long ans = -2e9;
    int trcks[m][2];
    vector < pair <int, int> > t, bt;
    for (int x = 0; x < m; x++) {
        scanf ("%d %d", &trcks[x][0], &trcks[x][1]);
        t.push_back(make_pair(trcks[x][0], trcks[x][1]));
    }
    sort (t.begin(), t.end());
    for (int x = 0; x < t.size(); x++) {
        if (x==0) {
            bt.push_back(t[x]);
        } else {
            while (bt.size() > 0 && bt.back().second >= t[x].second) {
                bt.pop_back();
            }
            bt.push_back(t[x]);
        }
    }
    vector < pair <int, int> >::iterator it;
    for (int x = 0; x <= 5000; x++) {
        if (x > bt.back().first) {
            break;
        }
        it = lower_bound(bt.begin(), bt.end(), make_pair(x, 0));
        int pos = it-bt.begin();
        ans = max (ans, dp[x]-bt[pos].second);
    }
    cout << ans << "\n";
    return 0;
}
