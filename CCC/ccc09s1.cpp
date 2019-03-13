#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int a, b;
	cin >> a >> b;
	int nums = 0;
	for (int x = 1; x <= floor(cbrt(b)); x++) {
	    float t = (float)x;
	    float temp = sqrt(t*t*t);
	    if (t*t*t >= a && t*t*t <= b && round(temp) == temp) {
	        nums++;
	    }
	}
	cout << nums << endl;
	return 0;
}
