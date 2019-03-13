#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int minH[101][101] = {0}, minT[101][101] = {0}, f[101][101] = {0}, greatest = 0, sx, sy, ex = -1, ey = -1;
int r, c;

int solve (int px, int py, int t, int h) {
    //px = currRow, py = currCol
    if (minH[px][py] == -1 || h < minH[px][py]) {
        minH[px][py] = h;
        minT[px][py] = t;
    } else if (h == minH[px][py] && t < minT[px][py]) {
        minT[px][py] = t;
    } else {
        return 0;
    }
    if (px == ey && py == ex) {
        return 0;
    } else {
        if (px > 0) {
            solve (px - 1, py, (f[px - 1][py] > 0) ? t + 1:t, f[px - 1][py] + h);
        }
        if (px < r - 1) {
            solve (px + 1, py, (f[px + 1][py] > 0) ? t + 1:t, f[px + 1][py] + h);
        }
        if (py > 0) {
            solve (px, py - 1, (f[px][py - 1] > 0) ? t + 1:t, f[px][py - 1] + h);
        }
        if (py < c - 1) {
            solve (px, py + 1, (f[px][py + 1] > 0) ? t + 1:t, f[px][py + 1] + h);
        }
    }
    return 0;
}

int main() {
	// your code goes here
	memset(minH, -1, sizeof(minH));
	memset(minT, -1, sizeof(minT));
	char curr;
	cin >> r >> c;
	for (int x = 0; x < r; x++) {
	    for (int i = 0; i < c; i++) {
	        cin >> curr;
	        if (curr == 'X') {
	            sx = i;
	            sy = x;
	        } else if ((char)curr != '.') {
	            f[x][i] = (int)curr - 48;
	            greatest = max (greatest, f[x][i]);
	        }
	    }
	}
	for (int x = 0; x < r; x++) {
	    for (int i = 0; i < c; i++) {
	        if (f[x][i] == greatest) {
	            double t1 = pow(abs(sx - ex), 2) + pow(abs(sy - ey), 2);
	            double t2 = pow(abs(sx - i), 2) + pow(abs(sy - x), 2);
	            if (ex == -1 || sqrt(t1) > sqrt(t2) ) {
	                ex = i;
	                ey = x;
	            }
	        }
	    }
	}]
	solve (sy, sx, 0, 0);
	cout << minT[ey][ex] - 1 << endl;
	return 0;
}
