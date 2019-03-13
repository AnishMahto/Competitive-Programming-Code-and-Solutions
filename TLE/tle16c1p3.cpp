#include <iostream>
#include <math.h>
using namespace std;

string temp;

int output (int a, int b, int c, int d) {
    for (int x = 4; x >= 2; x--) {
        if (a % x == 0 && b % x == 0 && c % x == 0 && d % x == 0) {
            a /= x;
            b /= x;
            c /= x;
            d /= x;
            break;
        }
    }
    cout << a << temp << " + " << b << "O2 -> " << c << "CO2 + " << d << "H2O" << endl;
}

int main() {
	// your code goes here
	int H = 0, C = 0, O = 0, current = 0, add = 0;
	char letter, prev;
	string temp2;
	temp2.clear();
	cin >> temp;
	for (int x = 0; x < temp.length(); x++) {
	    if (temp[x] > 57) {
	        if (x != 0) {
	            add = 0;
	            for (int i = 0; i < temp2.length(); i++) {
	                add += (((int)(temp2[i])) - 48) * pow(10, temp2.length() - i - 1);
	            }
	            if (add == 0) {
	                add++;
	            }
	            if (letter == 'C') {
	                C += add;
	            } else if (letter == 'H') {
	                H += add;
	            } else if (letter == 'O') {
	                O += add;
	            }
	        }
	        letter = temp[x];
	        temp2.clear();
	    } else {
	        temp2 += temp[x];
	    }
	}
	add = 0;
	for (int i = 0; i < temp2.length(); i++) {
	    add += (((int)(temp2[i])) - 48) * pow(10, temp2.length() - i - 1);
	}
	if (add == 0) {
	    add++;
	}
	if (letter == 'C') {
	   C += add;
	} else if (letter == 'H') {
	   H += add;
	} else if (letter == 'O') {
	   O += add;
	}
	if (C == 0 || H == 0) {
	    cout << "Impossible" << endl;
	    return 0;
	}
	for (int a = 1; a <= 4; a++) {
	    if ((a*H) % 4 == 0 && (a*O) % 2 == 0 && (a*H)/4 + a*C - a*O/2 >= 0) {
	        output (a, (a*H)/4 + a*C - (a*O)/2, a*C, (a*H)/2);
	        return 0;
	    }
	}
	cout << "Impossible" << endl;
	return 0;
}
