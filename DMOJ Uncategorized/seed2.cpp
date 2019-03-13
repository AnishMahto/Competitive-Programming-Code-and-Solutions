#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long n = 2000000000/2, lowerBound = 1, upperBound = 2000000000;
	string response = "";
	while (response != "OK") {
	    if (response == "SINKS") {
	        if (upperBound - n == 1) {
	            n++;
	        } else {
	            lowerBound = n;
	            n = (n + upperBound)/2;
	        }
	    } else if (response == "FLOATS") {
	        if (n - lowerBound == 1) {
	            n--;
	        }
	        upperBound = n;
	        n = (n + lowerBound)/2;
	    }
	    cout << n << endl;
	    cin >> response;
	}
	return 0;
}
