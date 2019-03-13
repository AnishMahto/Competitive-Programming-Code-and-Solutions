#include <iostream>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	char img[n][n] = {0};
	memset(img, ' ', sizeof(char)*n*n);
	for (int x = 0; x < (n - 1)/2; x++) {
	    for (int i = 0; i <= (n - 1)/2 - x; i++) {
	        img[x][i] = '*';
	    }
	    for (int i = (n - 1)/2 + x; i < n; i++) {
	        img[x][i] = '*';
	    }
	}
	img[(n - 1)/2][0] = img[(n - 1)/2][n - 1] = '*';
	for (int x = (n - 1)/2; x < n; x++) {
	    for (int i = 0; i <= (n + 1)/2 - (n - x); i++) {
	        img[x][i] = '*';
	    }
	    for (int i = (n - 1)/2 + (n - x) - 1; i < n; i++) {
	        img[x][i] = '*';
	    }
	}
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < n; i++) {
	        cout << img[x][i];
	    } cout << endl;
	}
	return 0;
}
