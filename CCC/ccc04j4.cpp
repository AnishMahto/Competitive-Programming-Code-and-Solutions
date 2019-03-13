#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string code;
	getline (cin, code);
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string phrase;
	getline (cin, phrase);
	
	int counter = -1;
	
	for (int x = 0; x < phrase.length(); x++) {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == phrase[x]) {
				
				if (counter < code.length() - 1) {
					counter++;
				} else {
					counter = 0;
				}
				
				int shift;
				
				for (int z = 0; z < 26; z++) {
					if (alpha[z] == code[counter]) {
						shift = z;
						z = 26;
					}
				}
				
				cout << alpha[i + shift];
				
				i = alpha.length();
				
			}
		}
	}
	
	return 0;
}
