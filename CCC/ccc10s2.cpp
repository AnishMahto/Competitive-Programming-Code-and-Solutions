#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	//vector < vector <string> > code;
	vector <string> code;
	vector < vector <char> > letter;
 
	int letters;
	cin >> letters;
 
	vector <char> l;
	vector <string> c;
 
	char L;
	string C;
 
	for (int x = 0; x < letters; x++) {
		l.clear();
		c.clear();
		cin >> L;
		cin >> C;
		l.push_back(L);
		letter.push_back(l);
		code.push_back(C);
	}
 
	string decode;
	cin >> decode;
	string partial;
 
	for (int x = 0; x < decode.length(); x++) {
		partial = partial + decode[x];
		for (int y = 0; y < code.size(); y++) {
			if (code[y] == partial) {
				cout << letter[y][0];
				partial = "";
			}
		}
	}
 
	return 0;
}
