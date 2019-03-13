#include <iostream>
#include <cstdio>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main() {
	// your code goes here
	int n, m, a, d;
	scanint(n);
	int dp[n + 1] = {0}, flowers[n + 1] = {0}, subtract[n + 1] = {0};
	for (int x = 1; x <= n; x++) {
	    scanint(flowers[x]);
	}
	scanint(m);
	for (int x = 0; x < m; x++) {
	    scanint(a); scanint(d);
	    subtract[a + 1] = d;
	}
	dp[1] = flowers[1];
	for (int x = 2; x <= n; x++) {
	    if (subtract[x] == 0) {
	        dp[x] = dp[x - 1] + flowers[x];
	    } else {
	        if (x >= 2) {
	            dp[x] = max (dp[x - 1] + flowers[x] - subtract[x], dp[x - 2] + flowers[x]);
	        } else {
	            dp[x] = dp[x - 1] + flowers[x] - subtract[x];
	        }
	        dp[x] = max (dp[x], dp[x - 1]);
	    }
	}
	cout << dp[n] << endl;
	return 0;
}
