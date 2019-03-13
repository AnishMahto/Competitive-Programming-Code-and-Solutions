#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int rounds;
	cin >> rounds;
 
	int antoniaPoints = 100;
	int davidPoints = 100;
 
	int antonia;
	int david;
 
	for (int x = 0; x < rounds; x++) {
 
		cin >> antonia;
		cin >> david;
 
		if (antonia > david) {
			davidPoints -= antonia;
		} else if (david > antonia) {
			antoniaPoints -= david;
		} else {
			antoniaPoints = antoniaPoints;
			davidPoints = davidPoints;
		}
 
	}
 
	cout << antoniaPoints << endl;
	cout << davidPoints << endl;
 
	return 0;
}
