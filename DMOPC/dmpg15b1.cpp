#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	string current;
	
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (current.length() != 10) {
	        cout << "not a phone number" << endl;
	    } else {
	        if (current[0] == '6' && current[1] == '4' && current[2] == '7') {
	            cout << "(647)-" << current[3] << current[4] << current[5] << "-" << current[6] << current[7] << current[8] << current[9] << endl;
	        } else if (current[0] == '4' && current[1] == '1' && current[2] == '6') {
	            cout << "(416)-" << current[3] << current[4] << current[5] << "-" << current[6] << current[7] << current[8] << current[9] << endl;
	        } else {
	            cout << "not a phone number" << endl;
	        }
	    }
	}
	
	
	return 0;
}
