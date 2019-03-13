#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string current;
	int count = 0;
	cin >> current;
	while (current != "True" && current != "False") {
	    count++;
	    cin >> current;
	}
	if (count % 2 == 0) {
	    if (current == "True") {
	        cout << "True" << endl;
	    } else {
	        cout << "False" << endl;
	    }
	} else {
	    if (current == "True") {
	        cout << "False" << endl;
	    } else {
	        cout << "True" << endl;
	    }
	}
	return 0;
}
