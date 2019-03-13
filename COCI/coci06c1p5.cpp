#include <iostream>
#include <bitset>
#include <cstdio>
#include <math.h>
using namespace std;

double dp[1048576 + 1] = {0}, nums[20][20] = {0}, greatestSoFar = 0;
int n;

double solve (int pos, bitset<20> bits) {
    long long temp = bits.to_ulong();
    if (pos == n) {
        return 100;
    } else if (dp[temp] != 0) {
        return dp[temp];
    } else {
        for (int x = 0; x < n; x++) {
            if (!bits.test(x)) {
                bits.set(x);
                dp[temp] = max(solve (pos + 1, bits) * nums[pos][x]/100, dp[temp]);
                bits.flip(x);
            }
        }
    }
    return dp[temp];
}

int main() {
	// your code goes here
	cin >> n;
	bitset<20>bits;
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < n; i++) {
	        cin >> nums[x][i];
	    }
	}
	double answer = solve (0, bits);
	printf ("%.7f\n", answer);
	return 0;
}
