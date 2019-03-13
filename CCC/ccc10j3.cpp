#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int command, a = 0, b = 0, n;
	char x, y;
	cin >> command;
	while (command != 7) {
	    if (command == 1) {
	        cin >> x >> n;
	        (x == 'A') ? a = n:b = n;
	    } else if (command == 2) {
	        cin >> x;
	        (x == 'A') ? cout << a << endl:cout << b << endl;
	    } else if (command == 3) {
	        cin >> x >> y;
	        if (x == 'A' && y == 'B') {
	            a = a + b;
	        } else if (x == 'B' && y == 'A') {
	            b = a + b;
	        } else if (x == 'A' && y == 'A') {
	            a = a + a;
	        } else if (x == 'B' && y == 'B') {
	            b = b + b;
	        }
	    } else if (command == 4) {
	        cin >> x >> y;
	        if (x == 'A' && y == 'B') {
	            a = a*b;
	        } else if (x == 'B' && y == 'A') {
	            b = a*b;
	        } else if (x == 'A' && y == 'A') {
	            a = a*a;
	        } else if (x == 'B' && y == 'B') {
	            b = b*b;
	        }
	    } else if (command == 5) {
	        cin >> x >> y;
	        if (x == 'A' && y == 'B') {
	            a = a - b;
	        } else if (x == 'B' && y == 'A') {
	            b = b - a;
	        } else if (x == 'A' && y == 'A') {
	            a = 0;
	        } else if (x == 'B' && y == 'B') {
	            b = 0;
	        }
	    } else if (command == 6) {
	        cin >> x >> y;
	        if (x == 'A' && y == 'B') {
	            a = (a - a%b)/b;
	        } else if (x == 'B' && y == 'A') {
	            b = (b - b%a)/a;
	        } else if (x == 'A' && y == 'A') {
	            a = a/a;
	        } else if (x == 'B' && y == 'B') {
	            b = b/b;
	        }
	    }
	    cin >> command;
	}
	
	return 0;
}
