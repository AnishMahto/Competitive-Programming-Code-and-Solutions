#include <iostream>
#include <bitset>
#include <vector>
#include <cstdio>
using namespace std;

vector < vector <int> > dp(2000001);
vector < bitset<20> > possible;
int solAt, best = 100;

int solve (bitset<20>t, int pos) {
    long long con = t.to_ulong();
    if (dp[con].size() != 0 && dp[con].size() < best) {
        best = dp[con].size();
        solAt = con;
    }
    if (pos == 20) {
        return 0;
    }
    solve (t, pos + 1);
    if (!t.test(pos)) {
        t.set(pos);
        solve (t, pos + 1);
    }
}

int main() {
	// your code goes here
	int n, m;
	char in;
	scanf ("%d %d", &n, &m);
	vector < bitset <50> > subs;
	vector < bitset<20> > cases;
	bitset<50> t;
	bitset<20> c, ans;
	for (int x = 0; x < n; x++) {
	    t.reset();
	    for (int i = 0; i < m; i++) {
	        scanf (" %c", &in);
	        if (in == 'X') {
	            t.set(i);
	        }
	    }
	    if (t.count() > 0) {
	        ans.set(x);
	    }
	    subs.push_back(t);
	}
	if (ans.count() == 0) {
	    cout << 1 << endl << 1 << endl;
	    return 0;
	}
	for (int x = 0; x < m; x++) {
	    c.reset();
	    for (int i = 0; i < subs.size(); i++) {
	        if (subs[i].test(x)) {
	            c.set(i);
	        }
	    }
	    cases.push_back(c);
	}
	long long con;
	for (int x = 0; x < cases.size(); x++) {
	    vector < bitset<20> > temp;
	    for (int i = 0; i < possible.size(); i++) {
	        c = possible[i] | cases[x];
	        con = c.to_ulong();
	        if (dp[con].size() == 0) {
	            temp.push_back(c);
	        }
	        if (dp[con].size() == 0 || dp[con].size() > dp[possible[i].to_ulong()].size() + 1) {
	            dp[con].clear();
	            dp[con] = dp[possible[i].to_ulong()];
	            dp[con].push_back(x + 1);
	        }
	    }
	    for (int i = 0; i < temp.size(); i++) {
	        possible.push_back(temp[i]);
	    }
	    con = cases[x].to_ulong();
	    if (dp[con].size() == 0) {
	        possible.push_back(cases[x]);
	    }
	    if (dp[con].size() > 1 || dp[con].size() == 0) {
	        dp[con].clear();
	        dp[con].push_back(x + 1);
	    }
	}
	solve (ans, 0);
	cout << best << endl;
	for (int x = 0; x < dp[solAt].size(); x++) {
	    cout << dp[solAt][x] << " ";
	} cout << endl;
	return 0;
}
