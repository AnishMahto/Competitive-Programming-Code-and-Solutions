#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	//A=−6t4+ht3+2t2+t
	int h, m;
	cin >> h >> m;
	for (int x = 1; x <= m; x++) {
	    if (-6*pow(x, 4) + h*pow(x, 3) + 2*pow(x, 2) + x <= 0) {
	        cout << "The balloon first touches ground at hour: " << endl << x << endl;
	        return 0;
	    } else if (x == m) {
	        cout << "The balloon does not touch ground in the given time." << endl;
	    }
	}
	
	return 0;
}
