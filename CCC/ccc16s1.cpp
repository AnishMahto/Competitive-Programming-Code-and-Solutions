#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	string w1;
	getline(cin, w1);
 
	vector <char> word;
	for (int x = 0; x < w1.length(); x++) {
		word.push_back(w1[x]);
	}
 
	string a1;
	getline(cin, a1);
 
	vector <char> ana;
	for (int x = 0; x < a1.length(); x++) {
		ana.push_back(a1[x]);
	}
 
	int matches = 0;
 
	for (int x = 0; x < word.size(); x++) {
		for (int i = 0; i < ana.size(); i++) {
			if (ana[i] == word[x]) {
				ana[i] = ' ';
				word[x] = ' ';
				matches++;
				i = ana.size();
			}
		}
	}
 
	int asteriks = 0;
	for (int x = 0; x < ana.size(); x++) {
		if (ana[x] == '*') {
			asteriks++;
		}
	}
 
	if (asteriks >= (word.size() - matches)) {
		cout << "A";
	} else {
		cout << "N";
	}
 
 
 
	return 0;
}
