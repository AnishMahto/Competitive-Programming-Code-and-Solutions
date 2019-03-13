#include <iostream>
#include <string.h>
using namespace std;

int w, h;
char map[21][21];
int sp[21][21];

bool left (int x, int y) {
    if (x - 1 >= 0 && map[y][x - 1] != '*' && (sp[y][x] + 1 < sp[y][x - 1] || sp[y][x - 1] == -1) ) {
        return true;
    }
    return false;
}
bool right (int x, int y) {
    if (x + 1 < w && map[y][x + 1] != '*' && (sp[y][x] + 1 < sp[y][x + 1] || sp[y][x + 1] == -1) ) {
        return true;
    }
    return false;
}
bool up (int x, int y) {
    if (y - 1 >= 0 && map[y - 1][x] != '*' && (sp[y][x] + 1 < sp[y - 1][x] || sp[y - 1][x] == -1) ) {
        return true;
    }
    return false;
}
bool down (int x, int y) {
    if (y + 1 < h && map[y + 1][x] != '*' && (sp[y][x] + 1 < sp[y + 1][x] || sp[y + 1][x] == -1) ) {
        return true;
    }
    return false;
}

int solve (int x, int y) {
    if (map[y][x] == '+') {
        if (left(x, y)) {
            sp[y][x - 1] = sp[y][x] + 1;
            solve (x - 1, y);
        }
        if (right(x, y)) {
            sp[y][x + 1] = sp[y][x] + 1;
            solve (x + 1, y);
        }
        if (up(x, y)) {
            sp[y - 1][x] = sp[y][x] + 1;
            solve (x, y - 1);
        }
        if (down(x, y)) {
            sp[y + 1][x] = sp[y][x] + 1;
            solve (x, y + 1);
        }
    } else if (map[y][x] == '-') {
        if (left(x, y)) {
            sp[y][x - 1] = sp[y][x] + 1;
            solve (x - 1, y);
        }
        if (right(x, y)) {
            sp[y][x + 1] = sp[y][x] + 1;
            solve (x + 1, y);
        }
    } else if (map[y][x] == '|') {
        if (up(x, y)) {
            sp[y - 1][x] = sp[y][x] + 1;
            solve (x, y - 1);
        }
        if (down(x, y)) {
            sp[y + 1][x] = sp[y][x] + 1;
            solve (x, y + 1);
        }
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
	    cin >> h >> w;
	    memset(sp, -1, sizeof(int)*21*21);
	    sp[0][0] = 1;
	    for (int x = 0; x < h; x++) {
	        for (int i = 0; i < w; i++) {
	            cin >> map[x][i];
	        }
	    }
	    solve (0, 0);
	    cout << sp[h - 1][w - 1] << endl;
	}
	return 0;
}
