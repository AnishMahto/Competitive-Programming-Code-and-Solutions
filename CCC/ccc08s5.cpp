#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	bool dp[31][31][31][31] = {0};
	//dp[2][1][0][2] = dp[1][1][1][1] = dp[0][0][2][1] = dp[0][3][0][0] = dp[1][0][0][1] = 1;
	for (int x = 0; x < 31; x++) {
	    for (int i = 0; i < 31; i++) {
	        for (int z = 0; z < 31; z++) {
	            for (int y = 0; y < 31; y++) {
	                if (x >= 2 && i >= 1 && y >= 2 && dp[x][i][z][y] != 1) {
	                    dp[x][i][z][y] = !(dp[x - 2][i - 1][z][y - 2]);
	                }
	                if (x >= 1 && i >= 1 && z >= 1 && y >= 1 && dp[x][i][z][y] != 1) {
	                    dp[x][i][z][y] = !(dp[x - 1][i - 1][z - 1][y - 1]);
	                }
	                if (z >= 2 && y >= 1 && dp[x][i][z][y] != 1) {
	                    dp[x][i][z][y] = !(dp[x][i][z - 2][y - 1]);
	                }
	                if (i >= 3 && dp[x][i][z][y] != 1) {
	                    dp[x][i][z][y] = !(dp[x][i - 3][z][y]);
	                }
	                if (x >= 1 && y >= 1 && dp[x][i][z][y] != 1) {
	                    dp[x][i][z][y] = !(dp[x - 1][i][z][y - 1]);
	                }
	            }
	        }
	    }
	}
	int n, a, b, c, d;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> a >> b >> c >> d;
	    if (dp[a][b][c][d] == 1) {
	        cout << "Patrick" << endl;
	    } else if (dp[a][b][c][d] == 0) {
	        cout << "Roland" << endl;
	    }
	}
	return 0;
}
