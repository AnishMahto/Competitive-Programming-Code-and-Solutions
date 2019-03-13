#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
 
	int number;
	cin >> number;
 
	int hand;
	int hand2;
 
	if (number <= 5) {
		hand = number;
		hand2 = 0;
	} else {
		hand = 5;
		hand2 = number - 5;
	}
 
	int methods = 1;
 
	while (hand > hand2) {
		hand--;
		hand2++;
		if (hand >= hand2) {
			methods++;
		}
	}
 
	cout << methods;
	return 0;
}
