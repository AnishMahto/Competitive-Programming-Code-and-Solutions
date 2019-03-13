#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	long long t, d, n, p, a, b, dp[100002] = {0}, pSum[100002] = {0};
	cin >> t;
	if (t == 1) {
    	scanf ("%lld %lld %lld", &d, &n, &p);
    	long long planets[100001] = {0};
    	planets[0] = n;
    	for (int x = 0; x < p; x++) {
    	    scanf ("%lld %lld", &a, &b);
    	    planets[a] = b;
    	}
	    pSum[d] = dp[d] = 1;
	    for (int x = d - 1; x >= 0; x--) {
	        dp[x] = pSum[x + 1] - pSum[min(x + planets[x] + 1, d + 1)];
	        dp[x] %= 1000000007;
	        pSum[x] = dp[x] + pSum[x + 1];
	    }
	    dp[0] %= 1000000007;
	    cout << dp[0] << endl;
	} else {
	    long long w, ones = 0, sum[69] = {0};
	vector < pair<long long, bool> > nums;
	vector < pair <long long, long long> > planets; 
	cin >> w;
	if (w == 0) {
	        cout << 68 << " " << 1 << " " << 1 << endl;
	        cout << 1 << " " << 1 << endl;
	        return 0;
	    }
	while (w > 1) {
	    if (w % 2 == 1) {
	        ones++;
	        w--;
	        nums.push_back(make_pair(w/2, true));
	    } else {
	        nums.push_back(make_pair(w/2, false));
	    }
	    w /= 2;
	}
	ones += 2;
	for (int x = 0; x < ones; x++) {
	    planets.push_back(make_pair(68 - x, 1));
	    sum[68 - x] = 1;
	}
	for (int x = nums.size() - 1; x >= 0; x--) { 
	    if (nums[x].second == false) {
	        planets.push_back(make_pair(68 - planets.size(), planets[planets.size() - 1].second + 1));
	    } else {
	        planets.push_back(make_pair(68 - planets.size(), planets[planets.size() - 1].second + 2));
	    }
	}
	cout << 69 << " " << 68 - planets.size() + 1 << " " << planets.size() << endl;
	for (int x = 0; x < planets.size(); x++) {
	    cout << planets[x].first << " " << planets[x].second << endl;
	}
	}
	return 0;
}
