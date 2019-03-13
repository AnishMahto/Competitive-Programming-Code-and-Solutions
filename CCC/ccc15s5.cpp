#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2][3102][102][102] = {0}, n, m, current, answer = 0;
// take/or not, newLine pos, taken mPie 2d range 
vector <int> line, add;

int solve (bool take, int pos, int a, int b, int nPie) {
    if (dp[take][pos][a][b] != 0) {
        return dp[take][pos][a][b];
    } else if (pos == n + m - 1) {
        if (take) {
            if (nPie == line.size() - 1) {
                dp[take][pos][a][b] = line[nPie];
                return line[nPie];
            } else if (a == b) {
                dp[take][pos][a][b] = add[a];
                return add[a];
            }
        } else {
            return 0;
        }
    } else {
        
        if (nPie < line.size() && take) {
            dp[take][pos][a][b] = max (solve (false, pos + 1, a, b, nPie + 1) + line[nPie], dp[take][pos][a][b]);
        }
        if (nPie < line.size()/* && !take*/) {
            dp[take][pos][a][b] = max (solve (true, pos + 1, a, b, nPie + 1), dp[take][pos][a][b]);
        }
        if (b - a >= 0 && take) {
            dp[take][pos][a][b] = max (solve (false, pos + 1, a, b - 1, nPie) + add[b], dp[take][pos][a][b]);
        }
        if (b - a >= 0 /*&& !take*/) {
            dp[take][pos][a][b] = max (solve (true, pos + 1, a + 1, b, nPie), dp[take][pos][a][b]);
        }
    }
    return dp[take][pos][a][b];
}

int main() {
	// your code goes here
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    line.push_back(current);
	}
	cin >> m;
	for (int x = 0; x < m; x++) {
	    cin >> current;
	    add.push_back(current);
	}
	sort (add.begin(), add.end());
	cout << max (solve (0, 0, 0, m - 1, 0), solve (1, 0, 0, m - 1, 0)) << endl;
	return 0;
}
