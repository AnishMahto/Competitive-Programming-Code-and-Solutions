#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int row, col, n, b, r, x1, y1, city[30002][1002] = {0}, greatest = 0, times = 0, lateral;
	scanf ("%d %d %d", &row, &col, &n);
	for (int l = 0; l < n; l++) {
	    scanf ("%d %d %d %d", &x1, &y1, &r, &b);
	    y1 = row - y1;
	    for (int x = 0; x <= r; x++) {
	        lateral = sqrt(pow(r, 2) - pow (x, 2)); 
	        if (x + y1 <= row) {
	            city[y1 + x][max(x1 - lateral, 0)] += b;
	            city[y1 + x][min(x1 + lateral + 1, 1001)] -= b;
	        }
	        if (y1 - x >= 0 && x != 0) {
	            city[y1 - x][max(x1 - lateral, 0)] += b;
	            city[y1 - x][min(x1 + lateral + 1, 1001)] -= b;
	        }
	    }
	}
	for (int x = 0; x < row; x++) {
	    for (int i = 1; i <= col; i++) {
	        if (i != 0) {
	            city[x][i] += city[x][i - 1];
	        }
	        if (city[x][i] > greatest) {
	            greatest = city[x][i];
	            times = 1;
	        } else if (city[x][i] == greatest) {
	            times++;
	        }
	    }
	}
	cout << greatest << endl << times << endl;
	return 0;
}
