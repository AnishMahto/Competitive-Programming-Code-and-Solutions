#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int lowestX = 1000000;
	int greatestX = 0;
	int lowestY = 1000000;
	int greatestY = 0;
	int x, y;
	
	for (int a = 0; a < n; a++) {
	    cin >> x;
	    cin >> y;
	    
	    if (x > greatestX) {
	        greatestX = x;
	    }
	    if (x < lowestX) {
	        lowestX = x;
	    }
	    
	    if (y > greatestY) {
	        greatestY = y;
	    }
	    if (y < lowestY) {
	        lowestY = y;
	    }
	    
	}
	
	if (greatestY - lowestY > greatestX - lowestX) {
	    cout << (greatestY - lowestY) * (greatestY - lowestY);
	} else {
	    cout << (greatestX - lowestX) * (greatestX - lowestX);
	}
	
	return 0;
}
