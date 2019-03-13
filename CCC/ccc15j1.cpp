#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int month;
	int day;
	cin >> month;
	cin >> day;
 
	if (month > 2) {
		cout << "After";
	} else if (month < 2) {
		cout << "Before";
	} else {
		if (day > 18) {
			cout << "After";
		} else if (day < 18) {
			cout << "Before";
		} else {
			cout << "Special";
		}
	}
	return 0;
}
