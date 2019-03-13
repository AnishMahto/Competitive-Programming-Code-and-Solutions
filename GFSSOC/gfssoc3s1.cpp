#include <iostream>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	long long temp;
	bool one = false;
	cin >> temp;
	bitset <65> t = temp;
	for (int x = 64; x >= 0; x--) {
	    if (t.test(x)) {
	        one = true;
	    }
	    if (one) {
	        cout << 1;
	    }
	} cout << endl;
	
	return 0;
}
