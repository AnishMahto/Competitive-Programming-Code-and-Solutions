#include <iostream>
#include <string.h>
using namespace std;

int dp[401] = {0};

int main() {
	// your code goes here
	string current;
	bool add;
	int temp = 10;
	while (temp--) {
	    cin >> current;
	    memset(dp, 0, sizeof(int)*401);
	    for (int x = 1; x <= current.length(); x++) {
	        //strings are 0 index based
	        int i = x - 1;
	        add = false;
	        if (x < 2) {
	            dp[x] = 0;
	        } 
	        if (x >= 2) {
	            if (current[i] == 'g' && current[i - 1] == 'u') {
	                dp[x] += dp[x - 2];
	                if (x == 2) {add = true;}
	            }
	        }
	        if (x >= 3) {
	            if ((current[i] == 'k' || current[i] == 'g') && current[i - 1] == 'o' && current[i - 2] == 'o') {
	                dp[x] += dp[x - 3];
	                if (x == 3) {add = true;}
	            }
	        }
	        if (x >= 4) {
	            if (current[i] == 'a' && current[i - 1] == 'g' && current[i - 2] == 'o' && current[i - 3] == 'o') {
	                dp[x] += dp[x - 4];
	                if (x == 4) {add = true;}
	            } else if (current[i] == 'k' && current[i - 1] == 'o' && current[i - 2] == 'o' && current[i - 3] == 'm') {
	                dp[x] += dp[x - 4];
	                if (x == 4) {add = true;}
	            } else if (current[i] == 'g' && current[i - 1] == 'u' && current[i - 2] == 'g' && current[i - 3] == 'u') {
	                dp[x] += dp[x - 4];
	                if (x == 4) {add = true;}
	            }
	        }
	        if (x >= 5) {
	            if (current[i] == 'm' && (current[i - 1] == 'a' || current[i - 1] == 'u') && current[i - 2] == 'g' && current[i - 3] == 'o' && current[i - 4] == 'o') {
	                dp[x] += dp[x - 5];
	                if (x == 5) {add = true;}
	            }
	        }
	        if (x >= 6) {
	            if (current[i] == 'k' && current[i - 1] == 'o' && current[i - 2] == 'o' && current[i - 3] == 'k' && current[i - 4] == 'o' && current[i - 5] == 'o') {
	                dp[x] += dp[x - 6];
	                if (x == 6) {add = true;}
	            }
	        }
	        if (x >= 8) {
	            if (current[i] == 'k' && current[i - 1] == 'o' && current[i - 2] == 'o' && current[i - 3] == 'm') {
	                if (current[i - 4] == 'k' && current[i - 5] == 'o' && current[i - 6] == 'o' && current[i - 7] == 'm') {
	                    dp[x] += dp[x - 8];
	                    if (x == 8) {add = true;}
	                }
	            }
	        }
	        if (add) {
	            dp[x]++;
	        }
	    }
	    cout << dp[current.length()] << endl;
	}
	return 0;
}
