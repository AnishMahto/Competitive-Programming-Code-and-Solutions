#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int n, wa = 0, ir = 0;
	cin >> n;
	string judge[n];
	for (int x = 0; x < n; x++) {
	    cin >> judge[x];
	    if (judge[x] == "WA") {
	        wa++;
	    }
	}
	wa = floor(((float)wa * .3));
	for (int x = 0; x < n; x++) {
	    if (judge[x] == "AC") {
	        cout << "AC" << endl;
	    } else if (judge[x] == "WA") {
	        if (wa > 0) {
	            cout << "AC" << endl;
	            wa--;
	        } else {
	            cout << "WA" << endl;
	        }
	    } else if (judge[x] == "TLE") {
	        cout << "WA" << endl;
	    } else if (judge[x] == "IR") {
	        ir++;
	        if (ir <= 10) {
	            cout << "AC" << endl;
	        } else if (ir <= 20) {
	           cout << "WA" << endl;
	        } else {
	            cout << "IR" << endl;
	        }
	    }
	}
	return 0;
}
