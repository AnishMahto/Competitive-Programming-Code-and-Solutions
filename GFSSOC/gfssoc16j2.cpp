#include <iostream>
using namespace std;

int main() {
	// your code goes here
	float avg = 0, current, req;
	for (int x = 0; x < 6; x++) {
	    cin >> current;
	    avg += current;
	}
	avg /= 6;
	cin >> current;
	avg += current;
	cin >> req;
	if (avg - req >= 0) {
	    cout << "yes" << endl;
	} else {
	    cout << "no" << endl;
	}
	return 0;
}
