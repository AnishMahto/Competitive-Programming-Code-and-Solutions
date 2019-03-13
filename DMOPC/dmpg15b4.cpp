#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int max = 1;
	int n;
	cin >> n;
	
	vector <int> negatives;
	
	bool neg = false;
	bool pos = false;
	
	int current;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (current > 0) {
	        max *= current;
	        pos = true;
	    } else if (current < 0) {
	        negatives.push_back(current);
	        neg = true;
	    }
	}
	
	sort (negatives.begin(), negatives.end());
	
	if (negatives.size() > 1) {
	    for (int x = 0; x < negatives.size() - 1; x+=2) {
	        if (x + 1 < negatives.size()) {
	            max *= negatives[x]*negatives[x + 1];
	        }
	    }
	}
	
	if (n == 1 && pos == false && neg == true) {
	    cout << negatives[0];
	} else if ( (neg == false && pos == false) || (pos == false && negatives.size() < 2)) {
	    cout << 0 << endl;
	} else {
	    cout << max << endl;
	}
	
	return 0;
}
