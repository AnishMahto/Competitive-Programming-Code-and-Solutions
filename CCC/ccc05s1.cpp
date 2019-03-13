#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
 
	int tests;
	cin >> tests;
 
	vector <char> number;
	vector <char> temp;
	string current;
 
	for (int a = 0; a < tests; a++) {
		temp.clear();
		current.clear();
		cin >> current;
		number.clear();
 
		for (int x = 0; x < current.length(); x++) {
			temp.push_back(current[x]);
		}
 
		for (int x = 0; x < temp.size(); x++) {
			if (temp[x] != '-') {
				if (temp[x] == 'A' || temp[x] == 'B' || temp[x] == 'C') {
					number.push_back('2');
				} else if (temp[x] == 'D' || temp[x] == 'E' || temp[x] == 'F') {
					number.push_back('3');
				} else if (temp[x] == 'G' || temp[x] == 'H' || temp[x] == 'I') {
					number.push_back('4');
				} else if (temp[x] == 'J' || temp[x] == 'K' || temp[x] == 'L') {
					number.push_back('5');
				} else if (temp[x] == 'M' || temp[x] == 'N' || temp[x] == 'O') {
					number.push_back('6');
				} else if (temp[x] == 'P' || temp[x] == 'Q' || temp[x] == 'R' || temp[x] == 'S') {
					number.push_back('7');
				} else if (temp[x] == 'T' || temp[x] == 'U' || temp[x] == 'V') {
					number.push_back('8');
				} else if (temp[x] == 'W' || temp[x] == 'X' || temp[x] == 'Y' || temp[x] == 'Z') {
					number.push_back('9');
				} else {
					number.push_back(temp[x]);
				}
			}
		}
 
		for (int x = 0; x < number.size(); x++) {
 
			if (x == 3 || x == 6) {
				cout << "-";
			}
			if (x < 10) {
				cout << number[x];
			}
		} cout << endl;
 
	}
 
	return 0;
}
