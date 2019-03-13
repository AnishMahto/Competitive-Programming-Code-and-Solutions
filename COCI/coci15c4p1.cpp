#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	string n, m, newN, newM, a, b;
	n = m = newN = newM = "";
	cin >> a >> b;
	for (int x = a.length() - 1; x >= 0; x--) {
	    n += a[x]; 
	}
	for (int x = b.length() - 1; x >= 0; x--) {
	    m += b[x]; 
	}
	for (int x = 0; x < max (n.length(), m.length()); x++) {
	    if (x >= n.length()) {
	        newM += m[x];
	    } else if (x >= m.length()) {
	        newN += n[x];
	    } else {
	        if (m[x] > n[x]) {
	            newM += m[x];
	        } else if (m[x] < n[x]) {
	            newN += n[x];
	        } else {
	            newN += n[x];
	            newM += m[x];
	        }
	    }
	}
	if (newN.length() == 0) {
	    cout << "YODA" << endl;
	} else {
	    for (int x = 0; x < newN.length(); x++) {
	        if (newN[x] != '0') {
	            for (int x = newN.length() - 1; x >= 0; x--) {
	                cout << newN[x];
	            } cout << endl;
	            break;
	        } else if (x == newN.length() - 1) {
	            cout << 0 << endl;
	        }
	    }
	}
	if (newM.length() == 0) {
	    cout << "YODA" << endl;
	} else {
	    for (int x = 0; x < newM.length(); x++) {
	        if (newM[x] != '0') {
	            for (int x = newM.length() - 1; x >= 0; x--) {
	                cout << newM[x];
	            } cout << endl;
	            break;
	        } else if (x == newM.length() - 1) {
	            cout << 0 << endl;
	        }
	    }
	}
	return 0;
}
