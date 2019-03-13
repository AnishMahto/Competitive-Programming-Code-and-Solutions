#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int limit, speed;
	cin >> limit >> speed;
	speed -= limit;
	if (speed <= 0) {
	    cout << "Congratulations, you are within the speed limit!" << endl;
	} else if (speed <= 20) {
	    cout << "You are speeding and your fine is $" << 100 << "." << endl;
	} else if (speed <= 30) {
	    cout << "You are speeding and your fine is $" << 270 << "." << endl;
	} else if (speed >= 31) {
	    cout << "You are speeding and your fine is $" << 500 << "." << endl;
	}
	return 0;
}
