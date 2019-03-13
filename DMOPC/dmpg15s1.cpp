#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int cars, r, w, b, y, g;
	cin >> cars;
	cin >> r; //4
	cin >> w; //5
	cin >> b; //4
	cin >> y; //3
	cin >> g; //6
	
	int used = 0;
	
	while (r > 0) {
		used++;
		r -= 4;
	}
	while (w > 0) {
		used++;
		w -= 5;
	}
	while (b > 0) {
		used++;
		b -= 4;
	}
	while (y > 0) {
		used++;
		y -= 3;
	}
	while (g > 0) {
		used++;
		g -= 6;
	}
	
	if (used > cars) {
		cout << 0;
	} else {
		cout << cars - used;
	}
	return 0;
}
