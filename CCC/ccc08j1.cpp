#include <iostream>
using namespace std;

int main() {
	// your code goes here
	float w, h, temp;
	cin >> w >> h;
	temp = (w)/(h*h);
	
	if (temp > 25) {
	    cout << "Overweight" << endl;
	} else if (temp >= 18.5) {
	    cout << "Normal weight" << endl;
	} else {
	    cout << "Underweight" << endl;
	}
	
	return 0;
}
