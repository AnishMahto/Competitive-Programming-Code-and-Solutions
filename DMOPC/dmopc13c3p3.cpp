#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	int n, h;
	
	cin >> n;
	cin >> h;
	
	int field[n][n] = {};
	int pos[n][n] = {};
	
	pos[0][0] = 1;
	
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < n; i++) {
	        cin >> field[x][i];
	        
	        if (x > 0) {
	            if (abs(field[x - 1][i] - field[x][i]) <= h && pos[x - 1][i] == 1) {
	                pos[x][i] = 1;
	            }
	        }
	        
	        if (i > 0) {
	            if (abs(field[x][i - 1] - field[x][i]) <= h && pos[x][i - 1] == 1) {
	                pos[x][i] = 1;
	            }
	        }
	        
	        if (pos[x][i] == 1) {
	            if (x > 0) {
	               if (abs(field[x - 1][i] - field[x][i]) <= h) {
	                    pos[x - 1][i] = 1;
	              }
	            }
	            if (i > 0) {
	                if (abs(field[x][i - 1] - field[x][i]) <= h) {
	                    pos[x][i - 1] = 1;
	                }
	            }
	        }
	    }
	}
	
	if (pos[n - 1][n - 1] == 1) {
	    cout << "yes" << endl;
	} else {
	    cout << "no" << endl;
	}
	
	return 0;
}
