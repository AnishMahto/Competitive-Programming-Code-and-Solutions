#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	int w, h, x, y;
	cin >> w >> h;
	int mapping[h][w], sp[h][w];
	for (int x = 0; x < h; x++) {
	    for (int i = 0; i < w; i++) {
	        cin >> mapping[x][i];
	        sp[x][i] = -1;
	    }
	}
	sp[0][0] = mapping[0][0];
	queue < pair <int, int> > q;
	q.push(make_pair(0, 0));
	
	while (!q.empty()) {
	    x = q.front().first;
	    y = q.front().second;
	    
	    if (x > 0) {
	        if (sp[y][x - 1] == -1 || sp[y][x] + mapping[y][x - 1] < sp[y][x - 1]) {
	            sp[y][x - 1] = sp[y][x] + mapping[y][x - 1];
	            q.push(make_pair(x - 1, y));
	        }
	    }
	    if (x < w - 1) {
	        if (sp[y][x + 1] == -1 || sp[y][x] + mapping[y][x + 1] < sp[y][x + 1]) {
	            sp[y][x + 1] = sp[y][x] + mapping[y][x + 1];
	            q.push(make_pair(x + 1, y));
	        }
	    }
	    if (y < h - 1) {
	        if (sp[y + 1][x] == -1 || sp[y][x] + mapping[y + 1][x] < sp[y + 1][x]) {
	            sp[y + 1][x] = sp[y][x] + mapping[y + 1][x];
	            q.push(make_pair(x, y + 1));
	        }
	    }
	    
	    q.pop();
	}
	int gx, gy;
	cin >> gx >> gy;
	cout << sp[gy][gx] << endl;
	
	return 0;
}
