#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	double total = 0, current;
	cin >> n;
	while (n--) {
	    cin >> current;
	    total += current;
	    if (total > 360) {
	        total = (long long)floor(total) % 360 + (total - floor(total));
	    }
	}
	cout << total << endl;
	return 0;
}
