#define watch(x) cout << (#x) << " is " << (x) << endl
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char f[100001];
int dp[2][4][4][4][4] = {0}, n, c[201] = {0}, dp2[4][4][4] = {0};

int cnt (int v1, int v2, int v3) {
    int tot = 0;
    vector <int> tmp;
    if (v1 != 0) {
        tmp.push_back(v1);
    }
    if (v2 != 0) {
        tmp.push_back (v2);
    }
    if (v3 != 0) {
        tmp.push_back(v3);
    }
    tmp.push_back(-1);
    sort (tmp.begin(), tmp.end());
    for (int x = 1; x < tmp.size(); x++) {
        if (tmp[x] != tmp[x-1]) {
            tot++;
        }
    }
    return tot;
}

int solve (int pos) {
    int actualPos = pos;
    pos = pos%2;
    for (int f1 = 0; f1 < 4; f1++) {
        for (int f2 = 0; f2 < 4; f2++) {
            for (int s1 = 0; s1 < 4; s1++) {
                for (int s2 = 0; s2 < 4; s2++) {
                    //give to first mine
                    int tot = dp2[f1][f2][c[f[actualPos]]];
                    dp[pos][f1][f2][s1][s2] = max (dp[pos][f1][f2][s1][s2], dp[(actualPos-1)%2][c[f[actualPos]]][f1][s1][s2] + tot);
                    //give to second mine
                    tot = dp2[s1][s2][c[f[actualPos]]];
                    dp[pos][f1][f2][s1][s2] = max (dp[pos][f1][f2][s1][s2], dp[(actualPos-1)%2][f1][f2][c[f[actualPos]]][s1] + tot);
                }
            }
        }
    }
}

int main () {
    scanf ("%d", &n);
    c['M'] = 1;
    c['F'] = 2;
    c['B'] = 3;
    for (int x = 1; x <= n; x++) {
        scanf (" %c", &f[x]);
    }
    for (int x = 1; x <= n/2; x++) {
        //wtf code only ACs if I flip shit
        char tmp = f[n-x+1];
        f[n-x+1] = f[x];
        f[x] = tmp;
    }
    for (int x = 0; x < 4; x++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dp2[x][i][j] = cnt (x, i, j);
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        solve (x);
    }
    printf ("%d\n", dp[n%2][0][0][0][0]);
}
