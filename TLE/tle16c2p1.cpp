#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, value, greatest = 0, currentv = 0, pos = 0;
	string current;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current >> value;
	    if (current == "borrow") {
	        currentv += value;
	        if (greatest < currentv) {
	            greatest = currentv;
	            pos = x + 1;
	        }
	    } else if (current == "return") {
	        currentv -= value;
	    }
	}
	cout << pos << endl;
	return 0;
}
