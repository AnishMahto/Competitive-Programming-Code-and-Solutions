#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	int count[26] = {};
	
	string current;
	
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    for (int i = 0; i <= 26; i++) {
	        if (alpha[i] == current[0]) {
	            count[i]++;
	            i = 26;
	        }
	    }
	}
	
	bool minimum = false;
	for (int x = 0; x < 26; x++) {
	    if (count[x] >= 5) {
	        cout << alpha[x];
	        minimum = true;
	    } else if (x == 25 && minimum == false) {
	        cout << "PREDAJA";
	    }
	}
	
	return 0;
}
