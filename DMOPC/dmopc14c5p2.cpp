#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int x1, x2;
	int longest = 0;
	
	for (int a = 0; a < n; a++) {
	    cin >> x1;
	    cin >> x2;
	    
	    if ((x2 - x1) > longest) {
	        longest = x2 - x1;
	    }
	    
	}
	
	cout << longest;
	
	return 0;
}
