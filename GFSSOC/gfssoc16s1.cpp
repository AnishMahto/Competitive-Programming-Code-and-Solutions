#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

map <string, int> assign;
vector < vector <int> > graph(401);
int dp[401] = {0};

int solve (int pos, int steps) {
    if (pos == 400) {
        if (dp[pos] == -1) {
            dp[pos] = steps;
        } else {
            dp[pos] = min (dp[pos], steps);
        }
        return 0;
    }
    if (dp[pos] < steps && dp[pos] != -1) {
        return 0;
    } else {
        dp[pos] = steps;
        for (int x = 0; x < graph[pos].size(); x++) {
            solve (graph[pos][x], steps + 1);
        }
    }
}

int main() {
	// your code goes here
	memset(dp, -1, sizeof(int)*401);
	int n, t;
	string temp;
	cin >> n >> t;
	getline (cin, temp);
	assign.insert(make_pair("home", 1));
	assign.insert(make_pair("Waterloo GO", 400));
	map <string, int>::iterator it, it2;
	for (int x = 2; x < n + 2; x++) {
	    getline (cin, temp);
	    assign.insert(make_pair(temp, x));
	}
	for (int x = 0; x < t; x++) {
	    getline(cin, temp);
	    string temp1 = "", temp2 = "";
	    int divide = 0;
	    for (int x = 0; x < temp.length(); x++) {
	        if (temp[x] != '-') {
	            temp1 += temp[x];
	        } else {
	            divide = x;
	            break;
	        }
	    }
	    for (int x = divide + 1; x < temp.length(); x++) {
	        temp2 += temp[x];
	    }
	    it = assign.find(temp1);
	    it2 = assign.find(temp2);
	    graph[it->second].push_back(it2->second);
	    graph[it2->second].push_back(it->second);
	}
	solve (1, 0);
	if (dp[400] == -1) {
	    cout << "RIP ACE" << endl;
	} else {
	    cout << dp[400] << endl;
	}
	return 0;
}
