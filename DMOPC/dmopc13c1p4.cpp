#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int w, h, least = -1, endX, endY;
int map[51][51] = {0};

int solve (int posX, int posY, int step) {
    if (step >= 60) {
        return 0;
    }
    if (map[posY][posX] <= step && map[posY][posX] != 0) {
        return 0;
    } else {
        map[posY][posX] = step;
    }
    if (posX == endX && posY == endY) {
        if (least == -1 || step < least) {
            least = step;
        }
        return 0;
    }
    if (posX > 0) {
        solve (posX - 1, posY, step + 1);
    }
    if (posX < w - 1) {
        solve (posX + 1, posY, step + 1);    
    }
    if (posY > 0) {
        solve (posX, posY - 1, step + 1);
    }
    if (posY < h - 1) {
        solve (posX, posY + 1, step + 1);
    }
    return 0;
}

int main() {
	char current;
	int t, startX, startY;
	cin >> t;
	while (t--) {
	    scanf ("%d %d", &w, &h);
	    least = -1;
	    memset(map, 0, sizeof(int)*51*51);
	    for (int x = 0; x < h; x++) {
	        for (int i = 0; i < w; i++) {
	            scanf(" %c", &current);
	            if (current == 'X') {
	                map[x][i] = -1;
	            } else if (current == 'C') {
	                startX = i;
	                startY = x;
	            } else if (current == 'W') {
	                endX = i;
	                endY = x;
	            }
	        }
	    }
	    solve (startX, startY, 0);
	    if (least >= 60 || least == -1) {
	        cout << "#notworth" << endl;
	    } else {
	        cout << least << endl;
	    }
	}
	return 0;
}
