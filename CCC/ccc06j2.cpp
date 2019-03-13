#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int m, n, ways = 0;
	cin >> m >> n;
	int least = min (m, n), greatest = max (m, n);
	for (int x = 1; x <= min (greatest, 10); x++) {
	    if (10 - x <= min (m, n) && 10 - x != 0) {
	        ways++;
	    }
	}
	if (ways == 1) {
	    cout << "There is " << 1 << " way to get the sum 10." << endl;
	} else {
	    cout << "There are " << ways << " ways to get the sum 10." << endl;
	}
	return 0;
}
