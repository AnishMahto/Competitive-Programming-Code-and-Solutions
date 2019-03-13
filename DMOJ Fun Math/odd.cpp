#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int n, c, t;
	scanf ("%d", &n);
	for (int x = 0; x < n; x++) {
	    scanf ("%d", &c);
	    if (x == 0) {
	        t = c;
	    } else {
	        t ^= c;
	    }
	}
	cout << t << endl;
	return 0;
}
