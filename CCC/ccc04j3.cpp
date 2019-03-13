#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int adj;
	cin >> adj;
	int noun;
	cin >> noun;
 
	string adjectives[adj];
	string nouns[noun];
 
	for (int x = 0; x < adj; x++) {
		cin >> adjectives[x];
	}
	for (int x = 0; x < noun; x++) {
		cin >> nouns[x];
	}
 
	for (int x = 0; x < adj; x++) {
		for (int i = 0; i < noun; i++) {
			cout << adjectives[x] << " as " << nouns[i] << endl;
		}
	}
 
	return 0;
}
