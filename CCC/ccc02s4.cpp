#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

//map <int, string> names;
string names[101];
int times[101] = {0}, maxTime[101][101] = {0}, dp[101] = {0};
vector < vector < vector <int> > > groups(101);

int main() {
	// your code goes here
	string current;
	int m, q, temp;
	vector <int> tempV;
	cin >> m >> q;
	for (int x = 0; x < q; x++) {
	    cin >> current >> times[x];
	    names[x] = current;
	}
	memset(dp, 10000, sizeof(int)*101);
	for (int x = 0; x < q; x++) {
	    for (int i = x; i < q; i++) {
	        if (i > 0) {
	            maxTime[x][i] = max (times[i], maxTime[x][i - 1]);
	        } else {
	            maxTime[x][i] = times[i];
	        }
	    }
	}
	dp[q - 1] = times[q - 1];
	tempV.push_back(q-1);
	groups[q - 1].push_back(tempV);
	tempV.clear();
	for (int x = q - 2; x >= 0; x--) {
	    tempV.clear();
	    for (int i = x; i < min (x + m, q); i++) {
	        tempV.push_back(i);
	        if (i < q - 1) {
	            dp[x] = min (dp[x], maxTime[x][i] + dp[i + 1]);
	            if (dp[x] == maxTime[x][i] + dp[i + 1]) {
	                groups[x].clear();
	                groups[x].push_back(tempV);
	                for (int a = 0; a < groups[i + 1].size(); a++) {
	                    groups[x].push_back(groups[i + 1][a]);
	                }
	            }
	        } else {
	            dp[x] = min (dp[x], maxTime[x][i]);
	            if (dp[x] == maxTime[x][i]) {
	                groups[x].clear();
	                groups[x].push_back(tempV);
	            }
	        }
	    }
	}
	cout << "Total Time: " << dp[0] << endl;
	for (int x = 0; x < groups[0].size(); x++) {
	    for (int i = 0; i < groups[0][x].size(); i++) {
	        cout << names[groups[0][x][i]] << " ";
	    } cout << endl;
	}
	return 0;
}
