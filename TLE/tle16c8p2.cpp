#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	scanf ("%d", &t);
	for (int a = 0; a < t; a++) {
	    scanf ("%d", &n);
	    bitset<65> temp = n;
	    int last = 0;
	    for (int x = 0; x < 65; x++) {
	        if (temp.test(x)) {
	            last = x;
	        }
	    }
	    for (int x = last; x >= 0; x--) {
	        if (temp.test(x)) {
	            cout << "dank ";
	        } else {
	            cout << "meme ";
	        }
	    } cout << endl;
	}
	return 0;
}
