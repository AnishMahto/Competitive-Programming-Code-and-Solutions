#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int roll, pos = 1;
	cin >> roll;
	while (roll != 0) {
	    if (pos + roll < 100) {
	        pos += roll;
	        if (pos == 9) {
	            pos = 34;
	        } else if (pos == 40) {
	            pos = 64;
	        } else if (pos == 67) {
	            pos = 86;
	        } else if (pos == 54) {
	            pos = 19;
	        } else if (pos == 90) {
	            pos = 48;
	        } else if (pos == 99) {
	            pos = 77;
	        }
	    } else if (pos + roll == 100) {
	        cout << "You are now on square 100" << endl;
	        cout << "You Win!" << endl;
	        return 0;
	    }
	    cout << "You are now on square " << pos << endl;
	    cin >> roll;
	}
	cout << "You Quit!" << endl;
	return 0;
}
