#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, n, m, greatestA, greatestB, a, b;
	string temp = "";
	cin >> t;
	while (t--) {
	    cin >> n >> m;
	    greatestA = greatestB = 0;
	    for (int i = 0; i < m; i++) {
	        cin >> a >> b;
	        greatestA = max (greatestA, a);
	        greatestB = max (greatestB, b);
	    }
	    if (greatestA + greatestB > n) {
	        cout << -1 << endl;
	    } else {
	        for (int x = 0; x < greatestA; x++) {
	            cout << 'a';
	        }
	        for (int x = 0; x < greatestB; x++) {
	            cout << 'b';
	        }
	        cout << endl;
	    }
	}
	return 0;
}
