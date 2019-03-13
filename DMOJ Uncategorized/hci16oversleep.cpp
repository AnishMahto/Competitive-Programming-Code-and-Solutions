#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <limits>
#define gc getchar_unlocked
#define long long ll
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_LONG std::numeric_limits<long long>::max()
#define MIN_LONG std::numeric_limits<long long>::max()
using namespace std;

void scanint(int &x) {
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

int n, m, map[1001][1001] = {0}, startX, startY, endX, endY;

int solve (int posX, int posY, int step) {
    if (map[posY][posX] < step && map[posY][posX] != -1) {
        return 0;
    } else {
        map[posY][posX] = step;
        if (posX > 0 && map[posY][posX - 1] != -2) {
            solve (posX - 1, posY, step + 1);
        }
        if (posX < m - 1 && map[posY][posX + 1] != -2) {
            solve (posX + 1, posY, step + 1);
        }
        if (posY > 0 && map[posY - 1][posX] != -2) {
            solve (posX, posY - 1, step + 1);
        }
        if (posY < n - 1 && map[posY + 1][posX] != -2) {
            solve (posX, posY + 1, step + 1);
        }
    }
    return 0;
}

int main() {
    char current;
	scanint(n); scanint(m);
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < m; i++) {
	        scanf(" %c", &current);
	        if (current == 's') {
	            startX = i;
	            startY = x;
	        } else if (current == 'e') {
	            endX = i;
	            endY = x;
	            map[x][i] = -1;
	        } else if (current == 'X') {
	            map[x][i] = -2;
	        } else {
	            map[x][i] = -1;
	        }
	    }
	}
	solve (startX, startY, 0);
	map[endY][endX]--;
	cout << max(map[endY][endX], -1) << endl;
	return 0;
}
