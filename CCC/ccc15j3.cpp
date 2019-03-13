#include <iostream>
#include<string.h>
using namespace std;
 
 
int main() {
	// your code goes here
	string word;
	cin >> word;
 
	char vowels[6] = "aeiou";
	char constants[22] = "bcdfghjklmnpqrstvwxyz";
	char closest[22] = "aaeeeiiiiooooouuuuuuu";
	int match;
 
	for (int x = 0; x < word.length(); x++) {
		if (word[x] != vowels[0] && word[x] != vowels[1] && word[x] != vowels[2] && word[x] != vowels[3] && word[x] != vowels[4]) {
			cout << word[x];
			for (int i = 0; i < 22; i++) {
				if (word[x] == constants[i]) {
					match = i;
					cout << closest[i];
					i = 22;
				}
			}
			if (word[x] == 'z') {
			    cout << 'z';
			}
			else if (constants[match+1] != vowels[0] && constants[match+1] != vowels[1] && constants[match+1] != vowels[2] && constants[match+1] != vowels[3] && constants[match+1] != vowels[4]) {
				cout << constants[match+1];
			} else {
				cout << constants[match+2];
			}
		} else {
			cout << word[x];
		}
	}
 
	return 0;
}
