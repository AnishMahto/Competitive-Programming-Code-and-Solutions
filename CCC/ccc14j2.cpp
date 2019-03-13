#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int votes;
	cin >> votes;
 
	int A = 0;
	int B = 0;
 
	for (int x = 0; x < votes; x++) {
		char current;
		cin >> current;
		if (current == 'A') {
			A++;
		} else {
			B++;
		}
	}
 
	if (A > B) {
		cout << 'A' << endl;	
	} else if (B > A) {
		cout << 'B' << endl;
	} else if (A == B) {
		cout << "Tie" << endl;
	}
 
 
	return 0;
}
