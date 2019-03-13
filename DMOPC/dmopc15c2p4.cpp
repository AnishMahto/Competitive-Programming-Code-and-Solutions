#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
	// your code goes here
	int n;
	scanf ("%d", &n);
	vector < pair < pair <long long, long long>, long long> > anime(n);
	vector < pair < pair <long long, long long>, long long> >::iterator it;
	long long dp[n] = {0};
	for (int x = 0; x < n; x++) {
	    scanf ("%lld %lld %lld", &anime[x].first.first, &anime[x].first.second, &anime[x].second);
	}
	dp[n - 1] = anime[n - 1].second;
	for (int x = n - 2; x >= 0; x--) {
	    it = lower_bound(anime.begin() + x, anime.end(), make_pair (make_pair(anime[x].first.first + anime[x].first.second, numeric_limits<long long>::min()), numeric_limits<long long>::min()));
	    int temp = (it - anime.begin());
	    dp[x] = dp[x + 1];
	    if (temp >= 0 && temp != x && temp < n) {
	        if (anime[temp].first.first < anime[x].first.first + anime[x].first.second) {
	            temp++;
	        }
	        if (temp < n) {
	            dp[x] = max (anime[x].second + dp[temp], dp[x]);
	        }
	    }
	    dp[x] = max (dp[x], anime[x].second);
	}
	cout << dp[0] << endl;
	return 0;
}
