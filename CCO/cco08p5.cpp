#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, c[101], k[101], tot = 0, half;
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++) {
        scanf ("%d %d", &k[x], &c[x]);
        tot += k[x]*c[x];
    }
    half = tot/2;
    int used[half+1];
    bool dp[half+1] = {0};
    dp[0] = true;
    for (int x = 1; x <= n; x++) {
        memset (used, 0, sizeof(used));
        for (int i = c[x]; i <= half; i++) {
            if (!dp[i] && dp[i-c[x]] && used[i-c[x]] < k[x]) {
                dp[i] = true;
                used[i] = used[i-c[x]] + 1;
            }
        }
    }
    for (int x = half; x >= 0; x--) {
        if (dp[x]) {
            cout << abs((tot-x)-x) << "\n";
            return 0;
        }
    }
    return 0;
}
