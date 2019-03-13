#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int num[n];
	
	for (int x = 0; x < n; x++) {
	    cin >> num[x];
	}
	
	int greatest = 1;
	int current = 1;;
	
	for (int x = 1; x < n; x++) {
	    if ( abs(num[x - 1] - num[x]) <= 2) {
	        current++;
	        if (current > greatest) {
	            greatest = current;
	        }
	    }
	    else {
	        current = 1;
	    }
	}
	
	cout << greatest;
	
	return 0;
}
