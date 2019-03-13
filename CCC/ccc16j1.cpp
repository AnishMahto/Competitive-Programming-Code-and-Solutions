#include <iostream>
using namespace std;
 
int main() {
 
	int wins = 0;
	int loses = 0;
 
	char current;
 
	for (int x = 0; x < 6; x++) {
		cin >> current;
		if (current == 'W') {
			wins++;
		} else if (current == 'L') {
			loses++;
		}
	}
 
	int group;
 
	if (wins == 5 || wins == 6) {
		group = 1;
	} else if (wins == 3 || wins == 4) {
		group = 2;
	} else if (wins == 1 || wins == 2) {
		group = 3;
	} else if (wins == 0) {
		group = -1;
	}
 
	cout << group;
 
	return 0;
}
