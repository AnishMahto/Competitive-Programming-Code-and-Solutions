#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	float h, r;
	cin >> r;
	cin >> h;
	float pi = 3.14159265358979323;
	
	float volume = (pi*pow(r, 2)*h)/3;
	
	printf("%.2f", volume);
	
	return 0;
}
