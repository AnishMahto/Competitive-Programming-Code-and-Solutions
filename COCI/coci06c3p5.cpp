#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

vector < vector <int> > graph(10001);
int n, m, visCtr = 0, v[10001] = {0}, low[10001] = {0};
bool cycle = false, greaterThan1e10[10001] = {0}, cycleNode[10001] = {0}, annoyingCycle = false;
long long dp[10001];
vector <int> order;

int detectCycle (int pos) {
    visCtr++;
    v[pos] = visCtr;
    low[pos] = v[pos];
    int least = low[pos];
    order.push_back(pos);
    for (int x = 0; x < graph[pos].size(); x++) {
        if (v[graph[pos][x]]==0) {
            least = min (least, detectCycle(graph[pos][x]));
        } else {
            least = min (least, low[graph[pos][x]]);
        }
    }
    if (low[pos] > least) {
        cycle = true;
        low[pos] = least;
    }
    if (order.back() != pos) {
        cycleNode[pos] = true;
    }
    while (order.back() != pos) {
        cycleNode[order.back()] = true;
        order.pop_back();
    }
    order.pop_back();
    least = low[pos];
    low[pos] = 1000001;
    return least;
}

long long solve (int pos) {
    if (dp[pos] != -1) {
        return dp[pos];
    } else {
        dp[pos] = 0;
        for (int x = 0; x < graph[pos].size(); x++) {
            if (cycleNode[graph[pos][x]]) {
                annoyingCycle = true;
                continue;
            }
            dp[pos] += solve (graph[pos][x]);
            greaterThan1e10[pos] |= greaterThan1e10[graph[pos][x]];
            if (dp[pos] >= 10000000000) {
                greaterThan1e10[pos] = true;
            }
            dp[pos] %= 10000000000;
        }
    }
    return dp[pos];
}

int main() {
    memset (dp, -1, sizeof(dp));
    scanf ("%d %d", &n, &m);
    int a, b;
    for (int x = 0; x < m; x++) {
        scanf ("%d %d", &a, &b);
        graph[a].push_back(b);
        if (a==b) {
            cycle = true;
        }
    }
    detectCycle (1);
    dp[2] = 1;
    long long ans = solve (1);
    if (annoyingCycle) {
        printf ("inf\n");
        return 0;
    }
    string digits = to_string(ans);
    if (greaterThan1e10[1]) {
        for (int x = (int)digits.length()-9; x < 0; x++) {
            printf ("0");
        }
    }
    for (int x = max (0, (int)digits.length()-9); x < (int)digits.length(); x++) {
        printf ("%c", digits[x]);
    } printf ("\n");
    return 0;
}
