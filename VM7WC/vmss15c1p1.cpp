#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int area;
	cin >> area;
	
	int upTo;
	
	if (area % 2 == 0) {
	    upTo = area/2;
	} else {
	    upTo = (area + 1)/2;
	}
    int least = 1000000;
    for (int x = 1; x <= upTo; x++) {
        if (area % x == 0) {
            if ( (2*(area / x) + 2*x) < least ) {
                least = (2*(area / x) + 2*x);
            }
        }
    }
    cout << least;
    
	return 0;
}
