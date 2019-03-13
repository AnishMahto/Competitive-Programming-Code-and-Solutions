#include <iostream>
#include <string.h>
using namespace std;

bool dp[101][101] = {0};
bool calc[101][101] = {0};
string current;

bool solve (int start, int end) {
    if (calc[start][end]) {
        return dp[start][end];
    }
    if (start == end) {
        calc[start][end] = true;
        if (current[start] == 'A') {
            dp[start][end] = true;
            return true;
        } else if (current[start] == 'N') {
            if (start == 0 || end == current.length() - 1) {
                return false;
            } else if (solve (0, start - 1) && solve (start + 1, current.length() - 1)) {
                dp[start][end] = true;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
	if (current[start] == 'B' && current[end] == 'S') {
        calc[start][end] = true;
        if (solve (start + 1, end - 1)) {
            dp[start][end] = true;
            return true;
        }
    }
    calc[start][end] = true;
    for (int x = start + 1; x < end; x++) {
        if (current[x] == 'N' && solve (start, x - 1) && solve (x + 1, end)) {
            dp[start][end] = true;
            return true;
        }
    }
    return false;
}

int main() {
	// your code goes here
	cin >> current;
	while (current != "X") {
	    memset(dp, 0, sizeof(bool)*101*101);
	    memset(calc, 0, sizeof(bool)*101*101);
	    if (solve (0, current.length() - 1)) {
	        cout << "YES" << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	    cin >> current;
	}
	return 0;
}
