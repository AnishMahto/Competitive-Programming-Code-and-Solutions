#include <iostream>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int t, s, h;
	cin >> t >> s >> h;
	char top[t][2*s + 3];
	memset(top, ' ', sizeof(char)*t*2*s + 3);
	
	for (int x = 0; x < t; x++) {
	    top[x][0] = top[x][s + 1] = top[x][2*s + 2] = '*';
	}
	
	for (int x = 0; x < t; x++) {
	    
	    for (int i = 0; i < 2*s + 3; i++) {
	        if (top[x][i] != '*') {
	            top[x][i] = ' ';
	        }
	        cout << top[x][i];
	    } cout << endl;
	}
	
	for (int x = 0; x < 2*s + 3; x++) {
	    cout << '*';
	} cout << endl;
	
	for (int x = 0; x < h; x++) {
	    for (int i = 0; i < 2*s + 3; i++) {
	        if (i == s + 1) {
	            cout << '*';
	        } else {
	            cout << ' ';
	        }
	    } cout << endl;
	}
	
	return 0;
}
