#include <iostream>
#include <math.h> 
using namespace std;

int main() {
	// your code goes here
	//orange ones, then blue, green, yellow, pink, violet, brown and finally red
	string color;
	float orange = 0;
	float blue = 0;
	float green = 0;
	float yellow = 0;
	float pink = 0;
	float violet = 0;
	float brown = 0;
	float red = 0;
	
	int t = 0;
	
	for (int a = 0; a < 10; a++) {
		t = 0;
		
		orange = 0;
		blue = 0;
		green = 0;
		yellow = 0;
		pink = 0;
		violet = 0;
		brown = 0;
		red = 0;
		
		getline (cin, color);
		while (color != "end of box") {
			if (color == "orange") {
				orange++;
			} else if (color == "blue") {
				blue++;
			} else if (color == "green") {
				green++;
			} else if (color == "yellow") {
				yellow++;
			} else if (color == "pink") {
				pink++;
			} else if (color == "violet") {
				violet++;
			} else if (color == "brown") {
				brown++;
			} else if (color == "red") {
				red++;
			}
			getline (cin, color);
		}
		t += ceil(orange / 7) * 13;
		t += ceil(blue / 7) * 13;
		t += ceil(green / 7) * 13;
		t += ceil(yellow / 7) * 13;
		t += ceil(pink / 7) * 13;
		t += ceil(violet / 7) * 13;
		t += ceil(brown / 7) * 13;
		
		t += red * 16;
		cout << t << endl;
	}
	
	return 0;
}
