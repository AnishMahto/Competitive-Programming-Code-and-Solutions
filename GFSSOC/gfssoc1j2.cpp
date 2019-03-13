#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, d, posX = 0, posY = 0;
	string current;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    cin >> d;
	    if (current == "North") {
	        posY += d;
	    } else if (current == "South") {
	        posY -= d;
	    } else if (current == "East") {
	        posX += d;
	    } else if (current == "West") {
	        posX -= d;
	    }
	}
	cout << posX << " " << posY << endl;
	return 0;
}
