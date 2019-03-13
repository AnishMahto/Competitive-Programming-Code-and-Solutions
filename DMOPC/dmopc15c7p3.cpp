#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int crew[25][3] = {0}, n;
float maxChance = 0, tc, ts, tp;

int solve (float c, float s, float p, int left, bool check[26]) {
    if (left > 0) {
        for (int x = 0; x < n; x++) {
            if (check[x] == 0) {
                check[x] = 1;
                solve (c + crew[x][0], s + crew[x][1], p + crew[x][2], left - 1, check);
                check[x] = 0;
            }
        }
    } else {
        maxChance = max (maxChance, min (c/tc, min (s/ts, p/tp)));
    }
    return 0;
}

int main() {
	// your code goes here
	cin >> tc >> ts >> tp >> n;
	for (int x = 0; x < n; x++) {
	    cin >> crew[x][0] >> crew[x][1] >> crew[x][2];
	}
	bool check[26] = {0};
	memset(check, false, sizeof(bool)*26);
	solve (0, 0, 0, min (5, n), check);
	maxChance = min (maxChance, (float)1);
	printf ("%.1f\n", maxChance * 100);
	return 0;
}
