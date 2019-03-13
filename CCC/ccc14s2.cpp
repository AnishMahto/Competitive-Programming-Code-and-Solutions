#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int students;
	bool check = true;
	cin >> students;
 
	string list[students], list2[students];
 
	for (int x = 0; x < students; x++) {
		cin >> list[x];
	}
	for (int y = 0; y < students; y++) {
		cin >> list2[y];
	}
	for (int i = 0; i < students; i++) {
		if (list[i] == list2[i]) {
			check = false;
		} else {
			string name = list[i];
			string partner = list2[i];
			for (int a = 0; a < students; a++) {
				if (list2[a] == name && list[a] != partner) {
					check = false;
					a = students;
				} else {
					a = a;
				}
			}
		}
	}
 
	if (check) {
		cout << "good";
	} else {
		cout << "bad";
	}
 
	return 0;
}
