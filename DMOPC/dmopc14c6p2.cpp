#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, minFirst = 0, minCounter = 0, maxFirst = 0, maxCounter = 0, in = 0, out = 0;
	cin >> n;
	for (int x = 0; x < n - 1; x++) {
	    if (x == 0) {
	        cin >> minFirst >> in;
	        maxFirst = minFirst;
	    } else {
	        cin >> in >> out;
	        if (out > minFirst) {
	            minCounter -= out - minFirst;
	            minFirst = 0;
	        } else {
	            minFirst -= out;
	        }
	        if (out > maxCounter) {
	            maxFirst -= out - maxCounter;
	            maxCounter = 0;
	        } else {
	            maxCounter -= out;
	        }
	        maxCounter += in;
	        minCounter += in;
	    }
	}
	cout << minFirst << endl << maxFirst << endl;
	return 0;
}
