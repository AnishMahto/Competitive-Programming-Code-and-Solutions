#include <iostream>
using namespace std;

int capA, capB, m, dp[1001][1001] = {0};
pair <int, pair <int, int> > next[1001][1001];
string commands[7] = {"NULL", "fill A", "fill B", "pour A B", "pour B A", "chug A", "chug B"};
//1 = fill A, 2 = fill B, 3 = pour A into B, 4 = pour B into A, 5 = chug A, 6 = chug B

int solve (int a, int b, int cmd) {
    if (dp[a][b] != 0) {
        return dp[a][b];
    } else if (a == m || b == m) {
        next[a][b].first = -1;
        next[a][b].second.first = next[a][b].second.second = -1;
        return 0;
    } else {
        dp[a][b] = 100000;
        next[a][b].first = 100000;
        if (a != capA) {
            dp[a][b] = min (dp[a][b], solve (capA, b, 1) + 1);
            if (dp[a][b] == solve (capA, b, 1) + 1) {
                next[a][b].first = 1;
                next[a][b].second.first = capA;
                next[a][b].second.second = b;
            }
        }
        if (b != capB) {
            dp[a][b] = min (dp[a][b], solve (a, capB, 2) + 1);
            if (dp[a][b] == solve (a, capB, 2) + 1) {
                next[a][b].first = 2;
                next[a][b].second.first = a;
                next[a][b].second.second = capB;
            }
        }
        if (max (0, a - (capB - b)) != 0 || min (capB, b + a) != 0) {
        dp[a][b] = min ( dp[a][b], solve ( max (0, a - (capB - b)), min (capB, b + a), 3) + 1);
        if (dp[a][b] == solve ( max (0, a - (capB - b)), min (capB, b + a), 3) + 1) {
            next[a][b].first = 3;
            next[a][b].second.first = max (0, a - (capB - b));
            next[a][b].second.second = min (capB, b + a);
        }
        }
        if (min(capA, a + b) != 0 || max (0, b - (capA - a)) != 0) {
        dp[a][b] = min ( dp[a][b], solve ( min(capA, a + b), max (0, b - (capA - a)), 4) + 1);
        if (dp[a][b] == solve ( min(capA, a + b), max (0, b - (capA - a)), 4) + 1) {
            next[a][b].first = 4;
            next[a][b].second.first = min(capA, a + b);
            next[a][b].second.second = max (0, b - (capA - a));
        }
        }
        if (b != 0) {
        dp[a][b] = min (dp[a][b], solve (0, b, 5) + 1);
        if (dp[a][b] == solve (0, b, 5) + 1) {
            next[a][b].first = 5;
            next[a][b].second.first = 0;
            next[a][b].second.second = b;
        }
        }
        if (a != 0) {
        dp[a][b] = min (dp[a][b], solve (a, 0, 6) + 1);
        if (dp[a][b] == solve (a, 0, 6) + 1) {
            next[a][b].first = 6;
            next[a][b].second.first = a;
            next[a][b].second.second = 0;
        }
        }
    }
    return dp[a][b];
}

int main() {
	// your code goes here
	cin >> capA >> capB >> m;
	if (solve (0, 0, -1) >= 100000) {
	    cout << "Not possible" << endl;
	} else {
	    bool done = false;
	    int x = 0, i = 0;
	    while (!done) {
	        if (next[x][i].first != -1) {
	            cout << commands[next[x][i].first] << endl;
	        }
	        if (next[x][i].second.first == -1) {
	            done = true;
	        } else if (next[x][i].first != -1) {
	            int temp = next[x][i].second.first;
	            i = next[x][i].second.second;
	            x = temp;
	        } else {
	            break;
	        }
	    }
	}
	return 0;
}
