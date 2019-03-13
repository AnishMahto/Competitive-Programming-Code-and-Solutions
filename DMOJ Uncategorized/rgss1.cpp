#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int greatest = 0;

int dp[1001] = {0};

int solve (int sum) {
    
    if (dp[sum] == 0) {
    
        if (sum + a <= c && sum + b <= c) {
            solve (sum + a);
            solve (sum + b);
        } else if (sum + a <= c) {
            solve (sum + a);
        } else if (sum + b <= c) {
            solve (sum + b);
        }
        
        dp[sum] = 1;
    }
    
    if (sum > greatest) {
        greatest = sum;
    }
    
    return 0;
}

int main() {
	// your code goes here
	
	cin >> a >> b >> c;
	
	solve (0);
	
	cout << greatest << endl;
	
	return 0;
}
