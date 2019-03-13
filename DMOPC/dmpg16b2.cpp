#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t, n, m, bob, current;
	float answer;
	cin >> t;
	while (t--) {
	    cin >> n >> bob;
	    m = 0;
	    for (int x = 0; x < n - 1; x++) {
	        cin >> current;
	        if (current > bob) m++;
	    }
	    answer = sqrt(n - m) * 100;
	    printf("Bob wins $%.2f at IOI!\n", answer);
	}
	return 0;
}
