#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int angle1;
	int angle2;
	int angle3;
 
	cin >> angle1;
	cin >> angle2;
	cin >> angle3;
 
	if (angle1 + angle2 + angle3 == 180) {
		if (angle1 == angle2 && angle2 == angle3 && angle3 == angle1) {
			cout << "Equilateral" << endl;
		} else if (angle1 != angle2 && angle2 != angle3 && angle3 != angle1) {
			cout << "Scalene" << endl;
		} else {
			cout << "Isosceles" << endl;
		}
	} else {
		cout << "Error" << endl;
	}
	return 0;
}
