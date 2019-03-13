#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	char characters[3][3] = {
		{'*', 'x', '*'},
		{' ', 'x', 'x'},
		{'*', ' ', '*'}
	};
 
	int k;
	cin >> k;
 
	vector <char> line;
	vector <char> line2;
	vector <char> line3;
 
	vector < vector<char> > list;
 
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < k; x++) {
			line.push_back(characters[0][i]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < k; x++) {
			line2.push_back(characters[1][i]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < k; x++) {
			line3.push_back(characters[2][i]);
		}
	}
 
	for (int x = 0; x < k; x++) {
		list.push_back(line);
	}
	for (int x = 0; x < k; x++) {
		list.push_back(line2);
	}
	for (int x = 0; x < k; x++) {
		list.push_back(line3);
	}
 
	for (int i = 0; i < list.size(); i++) {
		for (int x = 0; x < list[i].size(); x++) {
			cout << list[i][x];
		}
		cout << endl;
	}
 
	return 0;
}
