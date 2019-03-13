#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	std::string word;
	int length;
	bool sign = true;
 
	cin >> word;
 
	length = word.length();
 
	//I, O, S, H, Z, X, and N
 
	for (int x = 0; x < length; x++) {
		if (word[x] != 'I' && word[x] != 'O' && word[x] != 'S' && word[x] != 'H' && word[x] != 'Z' && word[x] != 'X' && word[x] != 'N') {
			sign = false;
		}
	}
 
	if (sign) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
 
	return 0;
}
