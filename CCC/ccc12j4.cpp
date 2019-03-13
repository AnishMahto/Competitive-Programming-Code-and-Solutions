#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
 
	int k;
	cin >> k;
 
	string word;
	cin >> word;
 
	int s;
	char current;
	int b;
 
	for (int x = 0; x < word.length(); x++) {
		current = word[x];
		s = (3 * (x + 1)) + k;
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == current) {
				if (i >= s) {
					cout << alpha[i - s];
				} else {
					cout << alpha[25 - (s - (i + 1))];
 
				}
			}
		}
	}
 
	return 0;
}
