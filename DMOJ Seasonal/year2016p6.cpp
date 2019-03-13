#include <iostream>
#include <vector>
#include <bitset>
#include <stdlib.h>
using namespace std;

int dp[1025][1025] = {0}, l, w, r;
vector <int> leftStuff, rightStuff;

int solve (bitset<10> leftI, bitset<10> rightI, pair <int, int> remL, pair <int, int> remR, int sumL, int sumR) {
    if (remL.first != -1) {
        for (int x = remL.first; x <= remL.second; x++) {
            if (leftI.test(x)) {
                leftI.flip(x);
            }
        }
    }
    if (remR.first != -1) {
        for (int x = remR.first; x <= remR.second; x++) {
            if (rightI.test(x)) {
                rightI.flip(x);
            }
        }
    }
    long long ll = leftI.to_ulong(), rr = rightI.to_ulong();
    if (sumL == 0 && sumR == 0) {
        return 0;
    } else if (dp[ll][rr] != 0) {
        return dp[ll][rr];
    } else {
        int sum;
        if (sumL > 0) {
            for (int x = 0; x < l; x++) {
                sum = 0;
                for (int i = x; i < l; i++) {
                    if (leftI.test(i)) {
                        sum += leftStuff[i];
                        if (abs((sumL - sum) - sumR) <= w) {
                            if (dp[ll][rr] != 0) {
                                dp[ll][rr] = min(solve (leftI, rightI, make_pair(x, i), make_pair(-1, -1), sumL - sum, sumR) + 1, dp[ll][rr]);
                            } else {
                                dp[ll][rr] = solve (leftI, rightI, make_pair(x, i), make_pair(-1, -1), sumL - sum, sumR) + 1;
                            }
                        } else {
                            i = l;
                            break;
                        }
                    }
                }
            }
        }
        if (sumR > 0) {
            for (int x = 0; x < r; x++) {
                sum = 0;
                for (int i = x; i < r; i++) {
                    if (rightI.test(i)) {
                        sum += rightStuff[i];
                        if (abs((sumR - sum) - sumL) <= w) {
                            if (dp[ll][rr] != 0) {
                                dp[ll][rr] = min (solve (leftI, rightI, make_pair(-1, -1), make_pair(x, i), sumL, sumR - sum) + 1, dp[ll][rr]);
                            } else {
                                dp[ll][rr] = solve (leftI, rightI, make_pair(-1, -1), make_pair(x, i), sumL, sumR - sum) + 1;
                            }
                        } else {
                            i = r;
                            break;
                        }
                    }
                }
            }
        }
    }
    return dp[ll][rr];
}

int main() {
	// your code goes here
	int current, sumL = 0, sumR = 0;
	bitset<10> ll, rr;
	cin >> l >> r >> w;
	for (int x = 0; x < l; x++) {
	    cin >> current;
	    leftStuff.push_back(current);
	    ll.set(x);
	    sumL += current;
	}
	for (int x = 0; x < r; x++) {
	    cin >> current;
	    rightStuff.push_back(current);
	    rr.set(x);
	    sumR += current;
	}
	cout << solve (ll, rr, make_pair(-1, -1), make_pair(-1, -1), sumL, sumR) << endl;
	return 0;
}
