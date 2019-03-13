#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string poem[4];
	string current;
	int t;
	cin >> t;
	getline(cin, current);
	for (int a = 0; a < t; a++) {
	    for (int i = 0; i < 4; i++) {
	        current.clear();
	        getline(cin, current);
	        string suffix = "";
	        string letters = "";
	        for (int x = current.length() - 1; x >= 0; x--) {
	            current[x] = tolower(current[x]);
	            if (current[x] == 'a' || current[x] == 'e' || current[x] == 'i' || current[x] == 'o' || current[x] == 'u') {
	                suffix += current[x];
	                x = -1;
	            } else if (current[x] == ' ') {
	                x = -1;
	            } else {
	                suffix += current[x];
	            }
	        }
	        for (int x = suffix.length() - 1; x >= 0; x--) {
	            letters += suffix[x];
	        }
	        poem[i] = letters;
	    }
	    if (poem[0] == poem[1] && poem[1] == poem[2] && poem[2] == poem[3]) {
	        cout << "perfect" << endl;
	    } else if (poem[0] == poem[1] && poem[2] == poem[3]) {
	        cout << "even" << endl;
	    } else if (poem[0] == poem[2] && poem[1] == poem[3]) {
	        cout << "cross" << endl;
	    } else if (poem[0] == poem[3] && poem[1] == poem[2]) {
	        cout << "shell" << endl;
	    } else {
	        cout << "free" << endl;
	    }
	}
	
	return 0;
}
