#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	string current;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> m;
	    for (int i = 0; i < m; i++) {
	        bool caps = true, capLetter = false;
	        cin >> current;
	        for (int z = 0; z < current.length(); z++) {
	            int temp = current[z];
	            if (temp > 90 && temp < 123) {
	                caps = false;
	            }
	            if (temp > 64 && temp < 97) {
	                capLetter = true;
	            }
	        }
	        if (capLetter == false) {
	            caps = false;
	        }
	        if (caps) {
	            cout << "!!!";
	        }
	        for (int z = 0; z < current.length(); z++) {
	                if (current[z] == '.') {
	                    cout << "!!!";
	                } else {
	                    cout << current[z];
	                }
	        }
	        if (caps) {
	            cout << "!!!";
	        }
	        if (i != m - 1) {
	            cout << " ";
	        }
	    } cout << endl;
	}
	return 0;
}
