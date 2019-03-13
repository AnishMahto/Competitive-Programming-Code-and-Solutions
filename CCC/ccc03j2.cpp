#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int current;
	cin >> current;
	while (current != 0) {
	    int x = round(sqrt((float)current));
	    while (current % x != 0) {
	        x++;
	    }
	    cout << "Minimum perimeter is " << 2*x + 2*(current / x) << " with dimensions " << x << " x " << current / x << endl;
	    cin >> current;
	}
	return 0;
}
