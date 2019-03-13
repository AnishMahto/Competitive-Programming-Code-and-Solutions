#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, t = 0, s = 0;
	cin >> n;
	string current;
	getline(cin, current);
	for (int x = 0; x < n; x++) {
	    getline(cin, current);
	    for (int i = 0; i < current.length(); i++) {
	        if (current[i] == 't' || current[i] == 'T') {
	            t++;
	        } else if (current[i] == 's' || current[i] == 'S') {
	            s++;
	        }
	    }
	}
	if (s >= t) {
	    cout << "French" << endl;
	} else {
	    cout << "English" << endl;
	}
	return 0;
}
