#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	string temp;
	getline(cin, temp);
	for (int x = 0; x < n; x++) {
	    getline(cin, temp);
	    int ex = -1, power = -1, neg1 = -1, neg2 = -1, firstNum = -1;
	    for (int i = 0; i < temp.length(); i++) {
	        if (temp[i] == 'x') {
	            ex = i;
	        } else if (temp[i] == '^') {
	            power = i + 1;
	        } else if (temp[i] == '-') {
	            if (ex == -1) {
	                neg1 = i;
	            } else {
	                neg2 = i;
	            }
	        } 
	        if (ex == -1 && firstNum == -1 && (int)temp[i] - 48 >= 0 && (int)temp[i] - 48 <= 9) {
	            firstNum = i;
	        }
	    }
	    long long a = 0, b = 0;
	    bool aAdd0 = false, bAdd0 = false;
	    if (firstNum != -1) {
	    int upTo = ex;
	    if (ex == -1) {
	        upTo = temp.length();
	    }
	    if (neg1 != -1) {
	        for (int c = firstNum; c < upTo; c++) {
	            a += ((int)temp[c] - 48)*pow(10, upTo - c - 1);
	            if (temp[c] == '0' && temp[c - 1] == '-') {
	                aAdd0 = true;
	            }
	        }
	        a *= -1;
	    } else {
	        for (int c = firstNum; c < upTo; c++) {
	            a += ((int)temp[c] - 48)*pow(10, upTo - c - 1);
	            if (temp[c] == '0' && temp[c - 1] == ' ') {
	                aAdd0 = true;
	            }
	        }
	    }
	    }
	    int len = temp.length();
	    if (ex != len && power != -1) {
	    if (neg2 != -1) {
	        for (int c = power + 1; c < len; c++) {
	            b += ((int)temp[c] - 48)*pow(10, len - c - 1);
	            if (temp[c] == '0' && temp[c - 1] == '-') {
	                bAdd0 = true;
	            }
	        }
	        b *= -1;
	    } else {
	        for (int c = power; c < len; c++) {
	            b += ((int)temp[c] - 48)*pow(10, len - c - 1);
	            if (temp[c] == '0' && temp[c - 1] == '^') {
	                bAdd0 = true;
	            }
	        }
	    }
	    }
	    if (bAdd0 == false) {
	        if (b == 0 && ex != -1) {
	            b = 1;
	        }
	    }
	    if (aAdd0 == false) {
	        if (ex != -1 && a == 0 && neg1 != -1) {
	            a = -1;
	        }
	        if (ex != -1 && a == 0) {
	            a = 1;
	        } 
	    }
	    if (power == len) {
	        b = 1;
	    }
	    long long ab = a * b;
	    cout << "y' = ";
	    if (a == 0 || b == 0) {
	        cout << 0 << endl;
	    } else if (b - 1 == 0) {
	        cout << a << endl;
	    } else if (ab == 1 && b - 1 == 1) {
	        cout << "x" << endl;
	    } else if (ab == -1 && b - 1 == 1) {
	        cout << "-x" << endl;
	    } else if (ab == 1) {
	        cout << "x^" << b - 1 << endl;
	    } else if (ab == -1) {
	        cout << "-x^" << b - 1 << endl;
	    } else if (b - 1 == 1) {
	        cout << ab << "x" << endl;
	    } else {
	        cout << ab << "x^" << b - 1 << endl;
	    }
	}
	return 0;
}
