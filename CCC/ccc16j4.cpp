#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int hour, min, distLeft = 120;
	char waste;
	cin >> hour >> waste >> min;
	while (distLeft > 0) {
	    distLeft -= 1;
	    if ((hour >= 7 && hour < 10) || (hour >= 15 && hour < 19)) {
	        min += 2;
	    } else {
	        min++;
	    }
	    if (min >= 60) {
	        min -= 60;
	        hour++;
	    }
	}
	if (hour >= 24) {
	    hour -= 24;
	}
	if (hour > 9) {
	    cout << hour << ":";
	} else {
	    cout << "0" << hour << ":";
	}
	if (min > 9) {
	    cout << min << endl;
	} else {
	    cout << "0" << min << endl;
	}
	return 0;
}
