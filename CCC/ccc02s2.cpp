#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int num;
	cin >> num;
	int den;
	cin >> den;
 
	int whole;
 
	if (num % den == 0) {
		cout << (num / den);
	} else {
		whole = (num - (num % den)) / den;
		num = num % den;
 
		for (int x = num; x > 0; x--) {
			if (num % x == 0 && den % x == 0) {
				num = num / x;
				den = den / x;
				x = 0;
			}
		}
		
		if (whole == 0) {
		    cout << num << "/" << den;
		} else {
		    cout << whole << " " << num << "/" << den;
		}
		
	}
	return 0;
}
