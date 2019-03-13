#include <iostream>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	bitset <65> binary;
	int n, current, last;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    binary = current;
	    for (int i = 64; i >= 0; i--) {
	        if (binary.test(i)) {
	            last = i;
	            break;
	        }
	        
	    }
	    while ((last + 1) % 4 != 0) {
	        last++;
	    }
	    for (int i = last; i >= 0; i--) {
	        cout << binary[i];
	        if ((i) % 4 == 0 && i != last) {
	            cout << " ";
	        }
	    } cout << endl;
	}
	return 0;
}
