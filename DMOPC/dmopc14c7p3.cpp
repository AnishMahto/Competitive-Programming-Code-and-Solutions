#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	map<int, int> leftHand;
	//map<int, int> rightHand;
	
	int l, r;
	cin >> l;
	cin >> r;
	
	int matches = 0;
	int current;
	map<int, int>::iterator it;
	
	for (int x = 0; x < l; x++) {
	    cin >> current;
	    leftHand[current] = 0;
	}
	
	for (int x = 0; x < r; x++) {
	    cin >> current;
	    it = leftHand.find(current);
	    if (it != leftHand.end()) {
	        matches++;
	    }
	}

	cout << (l - matches) + (r - matches) + (n - ((l - matches) + (r - matches)) ) - matches << endl;
	
	return 0;
}
