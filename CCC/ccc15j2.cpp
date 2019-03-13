#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	char string[255];
	int happy = 0;
	int sad = 0;
 
	for (int x = 0; x < 255; x++) {
		cin >> string[x];
	}
 
	for (int i = 0; i < 255; i++) {
		if (string[i] == ':' && string[i+1] == '-') {
			if (string[i+2] == ')') {
				happy++;
			} else if (string[i+2] == '(') {
				sad++;
			}
		}
	}
 
	if (happy > sad) {
		cout << "happy";
	} else if (happy < sad) {
		cout << "sad";
	} else if (happy == 0 && sad == 0) {
		cout << "none";
	} else {
		cout << "unsure";
	}
 
	return 0;
}
