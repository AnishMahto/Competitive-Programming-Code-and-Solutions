#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	float a = 0, b = 0, morning, evening, weekend;
	cin >> morning >> evening >> weekend;
	
	if (morning > 100) {
	    a += (morning - 100) * .25;
	}
	if (morning > 250) {
	    b += (morning - 250) * .45;
	}
	a += evening * .15;
	b += evening * .35;
	a += weekend * .2;
	b += weekend * .25;
	cout << "Plan A costs " << a << "\nPlan B costs " << b << "\n";
	
	if (a > b) {
	    printf("Plan B is cheapest.");
	} else if (b > a) {
	    printf("Plan A is cheapest.");
	} else {
	    printf("Plan A and B are the same price.");
	}
	
	return 0;
}
