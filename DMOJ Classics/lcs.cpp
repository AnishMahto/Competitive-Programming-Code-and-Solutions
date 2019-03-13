#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	scanf ("%d %d", &n, &m);
	vector <int> first(n), second(m);
	for (int x = 0; x < n; x++) {
	    scanf ("%d", &first[x]);
	}
	for (int x = 0; x < m; x++) {
	    scanf ("%d", &second[x]);
	}
	int dp[first.size()][second.size()] = {0};
	for (int x = 0; x < first.size(); x++) {
	    for (int i = 0; i < second.size(); i++) {
	        if (first[x] == second[i]) {
	            if (x > 0 && i > 0) {
	                dp[x][i] = 1 + dp[x - 1][i - 1];
	            } else {
	                dp[x][i] = 1;
	            }
	        } else {
	            if (x > 0 && i > 0) {
	                dp[x][i] = max (dp[x - 1][i], dp[x][i - 1]);
	            } else if (x > 0) {
	                dp[x][i] = dp[x - 1][i];
	            } else if (i > 0) {
	                dp[x][i] = dp[x][i - 1];
	            } else {
	                dp[x][i] = 0;
	            }
	        }
	    }
	}
	cout << dp[first.size() - 1][second.size() - 1] << endl;
	return 0;
}
