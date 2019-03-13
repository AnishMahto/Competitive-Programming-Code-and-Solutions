#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int c, r, a, b, posX = 0, posY = 0;
	cin >> c >> r;
	cin >> a >> b;
	while (a != 0 || b != 0) {
	    posX += a;
	    posY += b;
	    if (posX < 0) posX = 0;
	    if (posY < 0) posY = 0;
	    if (posX > c) posX = c;
	    if (posY > r) posY = r;
	    cout << posX << " " << posY << endl;
	    cin >> a >> b;
	}
	return 0;
}
