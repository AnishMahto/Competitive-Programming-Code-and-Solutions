#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct greatestToLeast {
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

vector < vector <long long> > e(2001);

int main() {
    int n, r, used[2001][2001];
    memset (used, -1, sizeof(used));
    long long dp[201], ans;
    long long E, C1, V1, CA, CB, CM, VA, VB,  VM;
    scanf ("%d %d", &n, &r);
    for (int x = 0; x < n; x++) {
        scanf ("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &E, &C1, &V1, &CA, &CB, &CM, &VA, &VB, &VM);
        if (C1 <= r) {
            e[C1].push_back(V1);
        }
        for (int x = 2; x <= E; x++) {
            C1 = ((C1*(CA%CM))%CM+CB%CM)%CM;
            V1 = ((V1*(VA%VM))%VM+VB%VM)%VM;
            if (C1 <= r) {
                e[C1].push_back(V1);
            }
        }
    }
    for (int x = 1; x <= r; x++) {
        sort (e[x].begin(), e[x].end(), greatestToLeast());
    }
    memset (dp, -1, sizeof(dp));
    dp[0]=0;
    for (int x = 0; x < e[0].size(); x++) {
        //apply freebies
        dp[0]+=e[0][x];
    }
    for (int x = 1; x <= r; x++) {
        int best = -1;
        for (int i = 1; i <= x; i++) {
            if (e[i].size()==0) {
                continue;
            }
            if (x-i>=0 && dp[x-i]!=-1 && used[x-i][i]+1 <= e[i].size()-1 && dp[x-i]+e[i][used[x-i][i]+1] > dp[x]) {
                dp[x] = dp[x-i]+e[i][used[x-i][i]+1];
                best = i;
            }
        }
        if (best!=-1) {
            for (int i = 1; i <= x; i++) {
                used[x][i] = used[x-best][i];
            }
            used[x][best]++;
        }
        ans = max (ans, dp[x]);
    }
    cout << ans << "\n";
    return 0;
}
