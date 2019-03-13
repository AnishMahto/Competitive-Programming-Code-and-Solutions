#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int check[2];
	check[0] = check[1] = -1;
	int n, cmd;
	int b;
	string temp;
	cin >> n;
	while (n--) {
	    cin >> cmd;
	    if (cmd == 1) {
	        cin >> temp;
	        if (temp == "true") {
	            b = 1;
	        } else {
	            b = 0;
	        }
	        if (check[b] == -1) {
	            check[b] = 1;
	            cout << "true" << endl;
	        } else {
	            cout << "false" << endl;
	        }
	    } else if (cmd == 2) {
	        cin >> temp;
	        if (temp == "true") {
	            b = 1;
	        } else {
	            b = 0;
	        }
	        if (check[b] == 1) {
	            check[b] = -1;
	            cout << "true" << endl;
	        } else {
	            cout << "false" << endl;
	        }
	    } else if (cmd == 3) {
	        cin >> temp;
	        if (temp == "true") {
	            b = 1;
	        } else {
	            b = 0;
	        }
	        if (check[b] == 1) {
	            cout << b << endl;
	        } else {
	            cout << -1 << endl;
	        }
	    } else if (cmd == 4) {
	        if (check[0] == 1) {
	            cout << "false ";
	        }
	        if (check[1] == 1) {
	            cout << "true";
	        }
	        if (check[0] == 1 || check[1] == 1) {
	            cout << endl;
	        }
	    }
	}
	return 0;
}
