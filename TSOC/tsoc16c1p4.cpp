#include <iostream>
using namespace std;

int h, w, roomsWithMonkey = 0;
short room[36][51] = {0};

int solve (int x, int i) {
    if (room[x][i] != 0 && room[x][i] != 2) {
        return 0;
    }
    room[x][i] = 3;
    if (x > 0) {
        solve (x - 1, i);
    }
    if (x < h - 1) {
        solve (x + 1, i);
    }
    if (i > 0) {
        solve (x, i - 1);
    }
    if (i < w - 1) {
        solve (x, i + 1);
    }
}

int main() {
	// your code goes here
	cin >> h >> w;
	char current;
	for (int x = 0; x < h; x++) {
	    for (int i = 0; i < w; i++) {
	        cin >> current;
	        if (current == '#') {
	            room[x][i] = 1;
	        } else if (current == 'M') {
	            room[x][i] = 2;
	        }
	    }
	}
	for (int x = 0; x < h; x++) {
	    for (int i = 0; i < w; i++) {
	        if (room[x][i] == 2) {
	            roomsWithMonkey++;
	            solve (x, i);
	        }
	    }
	}
	cout << roomsWithMonkey << endl;
	return 0;
}
