#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	char g[5*n][5*n];
	for (int x = 0; x < 5*n; x++) {
	    for (int i = 0; i < 5*n; i++) {
	        g[x][i] = '.';
	    }
	}
	for (int i = 0; i < n; i++) {
	    for (int x = 0; x < 5*n; x++) {
	        g[i][x] = 'G';
	    }
	}
	for (int i = 4*n; i < 5*n; i++) {
	    for (int x = 0; x < 5*n; x++) {
	        g[i][x] = 'G';
	    }
	}
	for (int i = 0; i < 5*n; i++) {
	    for (int x = 0; x < n; x++) {
	        g[i][x] = 'G';
	    }
	}
	for (int i = 5*n - 1; i >= 2*n; i--) {
	    for (int x = 4*n; x < 5*n; x++) {
	        g[i][x] = 'G';
	    }
	}
	for (int i = 2*n; i < 2*n+n; i++) {
	    for (int x = 5*n - 1; x >= 5*n - 2*n; x--) {
	        g[i][x] = 'G';
	    }
	}
	for (int x = 0; x < 5*n; x++) {
	    for (int i = 0; i < 5*n; i++) {
	        if (g[x][i] == 'G') {
	            cout << "G";
	        } else {
	            cout << ".";
	        }
	    } cout << endl;
	}
	return 0;
}
