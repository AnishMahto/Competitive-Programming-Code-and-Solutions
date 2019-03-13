#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <deque>
#include <math.h>
using namespace std;

int main () {
	cin.sync_with_stdio(0);cin.tie(0);
	int w, h, n, sx, sy, ex, ey, sp[101][101][40][40];
	memset (sp, -1, sizeof(sp));
	bool W[101][101] = {0};
	cin >> w >> h >> n;
	cin >> sx >> sy >> ex >> ey;
	for (int x = 0; x < n; x++) {
		int a, b;
		cin >> a >> b;
		W[b][a] = true;
	}
	sp[sy][sx][20][20] = 0;
	deque < pair < pair <int, int>, pair <int, int> > > q;
	q.push_back (make_pair (make_pair (sy, sx), make_pair (0+20, 0+20)));
	while (!q.empty()) {
		int py = q.front().first.first, px = q.front().first.second, vy =  q.front().second.first, vx = q.front().second.second;
		q.pop_front();
		vx -= 20;
		vy -= 20;
		for (int ax = -1; ax <= 1; ax++) {
			for (int ay = -1; ay <= 1; ay++) {
				if (ax != 0 && ay != 0) {
					continue;
				}
				int nxtX = vx+ax+px, nxtY = vy+ay+py;
				int nxtSx = vx+ax+20, nxtSy = vy+ay+20;
				if (nxtX <= w && nxtY <= h && nxtX >= 0 && nxtY >= 0) {
					if (nxtSx >= 0 && nxtSx < 40 && nxtSy >= 0 && nxtSy < 40) {
						if (sp[nxtY][nxtX][nxtSy][nxtSx] == -1) {
							bool possible = true;
							if (possible && nxtX == px) {
								for (int y = min (py, nxtY); y <= max (py, nxtY); y++) {
									if (W[y][px]) {
										possible = false;
										break;
									}
								}
							} else if (possible && nxtY == py) {
								for (int x = min (px, nxtX); x <= max (px, nxtX); x++) {
									if (W[py][x]) {
										possible = false;
										break;
									}
								}
							} else if (possible) {
								double m = (double)(nxtY-py)/(double)(nxtX-px);
								if (px >= nxtX) {
									for (int x = px; x >= nxtX; x--) {
										if (abs ( (int)(m*(double)(x-px)) - (m*(double)(x-px))) > 0.001) {
											continue;
										} 
										if (W[(int)(m*(double)(x-px)) + py][x]) {
											possible = false;
											break;
										}
									}
								} else {
									for (int x = px; x <= nxtX; x++) {
										if (abs ( (int)(m*(double)(x-px)) - (m*(double)(x-px))) > 0.001) {
											continue;
										}
										if (W[(int)(m*(double)(x-px)) + py][x]) {
											possible = false;
											break;
										}
									}
								}
							}

							if (possible) {
								sp[nxtY][nxtX][nxtSy][nxtSx] = sp[py][px][vy+20][vx+20] + 1;
								q.push_back (make_pair ( make_pair (nxtY, nxtX), make_pair (nxtSy, nxtSx) ));
							}
						}
					}
				}
			}
		}
	}
	cout << sp[ey][ex][20][20] << "\n";
}
