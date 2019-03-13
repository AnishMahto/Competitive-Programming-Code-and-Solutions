#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue < pair <int, int> , vector< pair <int, int> >, greater< pair <int, int> > > pq;
vector < vector < pair <int, int> > > graph(5*1000+1);

int dp[5*1000+1][2];

int main() {
    memset (dp, -1, sizeof(dp));
    int n, m, a, b, c;
    scanf ("%d %d", &n, &m);
    for (int x = 0; x < m; x++) {
        scanf ("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    dp[1][0] = 0;
    for (int x = 0; x < graph[1].size(); x++) {
        pq.push(make_pair(graph[1][x].second, graph[1][x].first));
    }
    while (!pq.empty()) {
        int pos = pq.top().second, cost = pq.top().first;
        pq.pop();
        bool addedGreatest = false, addedSecondGreatest = false;
        for (int x = 0; x < 2; x++) {
            if (dp[pos][x]==-1 || dp[pos][x] > cost) {
                if (x==0) {
                    dp[pos][1] = dp[pos][0];
                    addedGreatest = true;
                } else {
                    addedSecondGreatest = true;
                }
                if (x==1 && cost==dp[pos][0]) {
                    break;
                }
                dp[pos][x] = cost;
                break;
            }
        }
        if (addedGreatest) {
            for (int x = 0; x < graph[pos].size(); x++) {
                if (graph[pos][x].second+dp[pos][0]==dp[graph[pos][x].first][0] || graph[pos][x].second+dp[pos][0] <= dp[graph[pos][x].first][1]) {
                    continue;
                }
                pq.push(make_pair(graph[pos][x].second+dp[pos][0], graph[pos][x].first));
            }
        } else if (addedSecondGreatest) {
            for (int x = 0; x < graph[pos].size(); x++) {
                if (graph[pos][x].second+dp[pos][1]==dp[graph[pos][x].first][0] || graph[pos][x].second+dp[pos][1] <= dp[graph[pos][x].first][1]) {
                    continue;
                }
                pq.push(make_pair(graph[pos][x].second+dp[pos][1], graph[pos][x].first));
            }
        }
    }
    printf ("%d\n", dp[n][1]);
    return 0;
}
