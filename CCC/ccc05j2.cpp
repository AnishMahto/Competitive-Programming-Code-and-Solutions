#include <iostream>
#include <math.h>
using namespace std;

bool rsa (int n) {
    int divisors = 2;
    //start at 2 coz ary number divisible by itself and 1
    for (int x = 2; x <= n/2; x++) {
        if (n % x == 0) {
            divisors++;
        }
        if (divisors > 4) {
            return false;
        }
    }
    if (divisors == 4) {
        return true;
    } else {
        return false;
    }
}

int main() {
	// your code goes here
	int a, b, numbers = 0;
	cin >> a >> b;
	for (int x = a; x <= b; x++) {
	    if (rsa(x)) {
	        numbers++;
	    }
	}
	cout << "The number of RSA numbers between " << a << " and " << b << " is " << numbers << endl; 
	return 0;
}
