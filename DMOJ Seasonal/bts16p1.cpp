#include <iostream>
#include <locale>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	string current;
	locale loc;
	int lower = 0, upper = 0;
	getline (cin, current);
	for (int x = 0; x < current.length(); x++) {
	    if (current[x] != ' ') {
	        if (isupper(current[x], loc)) {
	            upper++;
	        } else if (islower(current[x], loc)) {
	            lower++;
	        }
	    }
	}
	if (upper == lower) {
	    cout << current << endl;
	    return 0;
	}
	for (int x = 0; x < current.length(); x++) {
	    if (current[x] == ' ') {
	        cout << current[x];
	    } else {
	        if (upper > lower) {
	            cout << toupper(current[x], loc);
	        } else {
	            cout << tolower(current[x], loc);
	        }
	    }
	}
	return 0;
}
