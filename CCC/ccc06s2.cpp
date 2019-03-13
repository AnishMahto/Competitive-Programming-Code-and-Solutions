#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	string english;
	getline(cin, english);
	string cover;
	getline(cin, cover);
	string decode;
	getline(cin, decode);
 
	for (int x = 0; x < decode.length(); x++) {
		for (int i = 0; i < cover.length(); i++) {
			if (cover[i] == decode[x]) {
				cout << english[i];
				i = cover.length();
			} else if (i == (cover.length() - 1) && cover[x] != decode[x]) {
				cout << '.';
			}
		}
	}
 
	return 0;
}
