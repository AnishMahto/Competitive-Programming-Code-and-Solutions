#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int n, k, dp[251][251][251];
//          person/pi person has/pi remaining

int solve (int person, int curPi, int remPi) {
    if (dp[person][curPi][remPi] != -1) {
        return dp[person][curPi][remPi];
    } else if (person==k) {
        return 1;
    } else {
        dp[person][curPi][remPi] = 0;
        if (remPi > 0) {
            dp[person][curPi][remPi] += solve (person, curPi+1, remPi-1);
        }
        if (remPi >= curPi && curPi > 0) {
            dp[person][curPi][remPi] += solve (person+1, curPi, remPi-curPi);
        }
    }
    return dp[person][curPi][remPi];
}

int main()
{
    memset (dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << solve (1, 0, n) << endl;
    return 0;
}
