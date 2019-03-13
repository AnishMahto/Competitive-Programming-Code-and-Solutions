#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[6000] = {0};
vector <int> clubs;

int main() {
	// your code goes here
	int dist, c, current;
	cin >> dist >> c;
	while (c--) {
	    cin >> current;
	    clubs.push_back(current);
	}
	sort (clubs.begin(), clubs.end());
	for (int x = 0; x <= dist; x++) {
	    for (int i = 0; i < clubs.size(); i++) {
	        if (clubs[i] > x) {
	            break;
	        } else if (x - clubs[i] == 0 || dp[x - clubs[i]] != 0) {
	            if (dp[x] == 0) {
	                dp[x] = 1 + dp[x - clubs[i]];
	            } else {
	                dp[x] = min (dp[x], 1 + dp[x - clubs[i]]);
	            }
	        }
	    }
	}
	if (dp[dist] == 0) {
	    cout << "Roberta acknowledges defeat." << endl;
	} else {
	    cout << "Roberta wins in " << dp[dist] << " strokes." << endl;
	}
	return 0;
}
