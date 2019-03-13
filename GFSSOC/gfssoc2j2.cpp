#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int num1 = 1;
	int num2 = 1;
	int n;
	cin >> n;
	
	for (int x = 0; x < n; x++) {
	    
	    bool seven = false;
	    bool thirteen = false;
	    
	    if (num1 % 7 == 0 && num1 % 13 == 0) {
	        cout << "Fizz Fuzz ";
	    } else if (num1 % 7 == 0) {
	        cout << "Fizz ";
	    } else if (num1 % 13 == 0) {
	        cout << "Fuzz ";
	    } else {
	        cout << num1 << " ";
	    }
	    
	     if (num2 % 7 == 0 && num2 % 13 == 0) {
	        cout << "Fizz Fuzz" << endl;
	    } else if (num2 % 7 == 0) {
	        cout << "Fizz" << endl;
	    } else if (num2 % 13 == 0) {
	        cout << "Fuzz" << endl;
	    } else {
	        cout << num2 << endl;
	    }
	    
	    num1++;
	    num2+=2;
	}
	
	return 0;
}
