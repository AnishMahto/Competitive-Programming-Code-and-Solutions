#include <iostream>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	bitset<1000001> large;
	bitset<1000001> medium;
	bitset<1000001> small;
	int j, a, matching = 0, n;
	char size;
	cin >> j >> a;
	for (int x = 1; x <= j; x++) {
	    cin >> size;
	    if (size == 'L') {
	        large.set(x);
	    }
	    if (size == 'M') {
	        medium.set(x);
	    }
	    if (size == 'S') {
	        small.set(x);
	    }
	}
	for (int x = 0; x < a; x++) {
	    cin >> size >> n;
	    if (size == 'L') {
	        if (large.test(n)) {
	            matching++;
	            large.flip(n);
	        }
	    } else if (size == 'M') {
	        if (medium.test(n)) {
	            matching++;
	            medium.flip(n);
	        } else if (large.test(n)) {
	            matching++;
	            large.flip(n);
	        }
	    } else if (size == 'S') {
	        if (small.test(n)) {
	            matching++;
	            small.flip(n);
	        } else if (medium.test(n)) {
	            matching++;
	            medium.flip(n);
	        } else if (large.test(n)) {
	            matching++;
	            large.flip(n);
	        }
	    }
	}
	cout << matching << endl;
	return 0;
}
