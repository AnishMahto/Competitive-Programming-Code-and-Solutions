#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	string m;
	getline(cin, m);
	string d;
	getline(cin, d);
 
	vector <char> dna;
 
	int children;
	cin >> children;
 
	for (int x = 0; x < 10; x++) {
		if (m[x] == 'A' || m[x] == 'B' || m[x] == 'C' || m[x] == 'D' || m[x] == 'E') {
			dna.push_back(m[x]);
		} else if (d[x] == 'A' || d[x] == 'B' || d[x] == 'C' || d[x] == 'D' || d[x] == 'E') {
			dna.push_back(d[x]);
		} else {
			dna.push_back(m[x]);
		}
	}
 
	string current;
 
	for (int x = 0; x < children; x++) {
		int child = 0;
		cin >> current;
 
		for (int i = 0; i < 5; i++) {
			for (int z = 0; z < 10; z++) {
				if (current[i] == dna[z]) {
					child++;
					z = 11;
				}
			}
		}
 
		if (child == 5) {
			cout << "Possible baby." << endl;
		} else {
			cout << "Not their baby!" << endl;
		}
 
	}
 
	return 0;
}
