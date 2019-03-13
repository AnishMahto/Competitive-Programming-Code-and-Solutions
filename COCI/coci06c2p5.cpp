#include <iostream>
#include <cstdio>
using namespace std;

int vertical[401][401] = {0}, horizontal[401][401] = {0}, dpH[401][401] = {0}, dpV[401][401] = {0};
bool map[401][401] = {0};

int main() {
	// your code goes here
	int r, c;
	char current;
	scanf ("%d %d", &r, &c);
	for (int x = 0; x < r; x++) {
	    for(int i = 0; i < c; i++) {
	        scanf(" %c", &current);
	        if (current == 'X') {
	            map[x][i] = 1;
	        }
	    }
	}
	for (int x = 0; x < r; x++) {
	    for (int i = 0; i < c; i++) {
	        if (!map[x][i]) {
	            horizontal[x][i] = vertical[x][i] = 1;
	        }
	        if (i > 0 && !map[x][i - 1] && !map[x][i]) {
	            horizontal[x][i] = max (horizontal[x][i], 1 + horizontal[x][i - 1]);
	        }
	        if (x > 0 && !map[x - 1][i] && !map[x][i]) {
	            vertical[x][i] = max (vertical[x][i], 1 + vertical[x - 1][i]);
	        }
	    }
	}
	int greatest = 0;
	for (int x = 0; x < r; x++) {
	    for (int i = 0; i < c; i++) {
	        if (!map[x][i]) {
	        if (x == 0) {
	            dpH[x][i] = 2 + 2*horizontal[x][i];
	        } else {
	            if (horizontal[x - 1][i] == horizontal[x][i] && !map[x - 1][i]) {
	                dpH[x][i] = max (2 + horizontal[x][i]*2, dpH[x - 1][i] + 2);
	            } else {
	                dpH[x][i] = 2 + horizontal[x][i]*2;
	            }
	        }
	        if (i == 0) {
	            dpV[x][i] = 2 + 2*vertical[x][i];
	        } else {
	            if (vertical[x][i - 1] == vertical[x][i] && !map[x][i - 1]) {
	                dpV[x][i] = max (2 + vertical[x][i]*2, dpV[x - 1][i] + 2);
	            } else {
	                dpV[x][i] = 2 + vertical[x][i]*2;
	            }
	        }
	        }
	        if (dpH[x][i] <= 1600) {
	            greatest = max (greatest, dpH[x][i]);
	        }
	        if (dpV[x][i] <= 1600) {
	            greatest = max (greatest, dpV[x][i]);
	        }
	    }
	}
	cout << greatest - 1 << endl;
	return 0;
}
