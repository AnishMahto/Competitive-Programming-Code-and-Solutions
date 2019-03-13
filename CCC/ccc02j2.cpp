#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string word;
	cin >> word;
	
	while (word != "quit!") {
	    if (word.length() <= 4) {
	        cout << word << endl;
	    } else if (word[word.length() - 1] != 'r' || (word[word.length() - 2] != 'o')) {
	        cout << word << endl;
	    } else {
	        for (int x = 0; x < word.length() - 2; x++) {
	            cout << word[x];
	        }
	        if (word[word.length() - 3] != 'a' && word[word.length() - 3] != 'e' && word[word.length() - 3] != 'i' && word[word.length() - 3] != 'o' && word[word.length() - 3] != 'u' && word[word.length() - 3] != 'y') {
	            cout << "our" << endl;
	        } else {
	            cout << "or" << endl;
	        }
	    }
	    cin >> word;
	}
	
	return 0;
}
