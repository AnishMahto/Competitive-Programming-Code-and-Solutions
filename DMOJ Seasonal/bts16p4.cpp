#include <iostream>
using namespace std;

//right = 1, down = 2, left = 3, up = 4; 

int main() {
	int n, m, t, posX, posY, prev = 1, steps = 0;
	cin >> n >> m >> t;
	char screen[m][n];
	for (int x = 0; x < m; x++) {
	    for (int i = 0; i < n; i++) {
	        cin >> screen[x][i];
	        if (screen[x][i] == 'O') {
	            posX = i;
	            posY = x;
	        }
	    }
	}
	while (t--) {
	    if (prev == 1) {
	        if (posX + 1 == n) {
	            cout << "The observer leaves the grid after " << steps + 1 << " tick(s)." << endl;
	            return 0;
	        } else {
	            posX++;
	        }
	    } else if (prev == 2) {
	        if (posY + 1 == m) {
	            cout << "The observer leaves the grid after " << steps + 1 << " tick(s)." << endl;
	            return 0;
	        } else {
	            posY++;
	        }
	    } else if (prev == 3) {
	        if (posX - 1 < 0) {
	            cout << "The observer leaves the grid after " << steps + 1 << " tick(s)." << endl;
	            return 0;
	        } else {
	            posX--;
	        }
	    } else if (prev == 4) {
	        if (posY - 1 < 0) {
	            cout << "The observer leaves the grid after " << steps + 1 << " tick(s)." << endl;
	            return 0;
	        } else {
	            posY--;
	        }
	    }
	    if (screen[posY][posX] == '-') {
	                if (prev == 2) {
	                    prev = 4;
	                    screen[posY][posX] = '|';
	                } else if (prev == 4) {
	                    prev = 2;
	                    screen[posY][posX] = '|';
	                }
	    } else if (screen[posY][posX] == '|') {
	                if (prev == 1) {
	                    prev = 3;
	                    screen[posY][posX] = '-';
	                } else if (prev == 3) {
	                    prev = 1;
	                    screen[posY][posX] = '-';
	                }
	    } else if (screen[posY][posX] == 92) {
	                if (prev == 1) {
	                    prev = 2;
	                } else if (prev == 3) {
	                    prev = 4;
	                } else if (prev == 2) {
	                    prev = 1;
	                } else if (prev == 4) {
	                    prev = 3;
	                }
	                screen[posY][posX] = '/';
	    } else if (screen[posY][posX] == '/') {
	                if (prev == 1) {
	                    prev = 4;
	                } else if (prev == 3) {
	                    prev = 2;
	                } else if (prev == 2) {
	                    prev = 3;
	                } else if (prev == 4) {
	                    prev = 1;
	                }
	                screen[posY][posX] = 92;
	    }
	    steps++;
	}
	cout << "The observer stays within the grid." << endl;
	return 0;
}
