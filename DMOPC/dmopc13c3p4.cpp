#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int snow[10][10] = {0};
vector <int> balls;
int h, w;
bool answer = false;
bool first = true;

int solve (int ball, int land[][10], int sx, int sy, int ex, int ey) {
    
    if (first) {
        first = false;
    } else if (sx == ex) {
        for (int x = sy; x <= ey; x++) {
            land[x][sx] = 1;
        }
    } else if (sy == ey) {
        for (int x = sx; x <= ex; x++) {
            land[sy][x] = 1;
        }
    }
    
    if (ball == -1) {
        answer = true;
    } else if (answer == false) {
        //horizontal check
        for (int x = 0; x < h; x++) {
            for (int i = 0; i <= w - balls[ball]; i++) {
                for (int z = i; z < i + balls[ball]; z++) {
                    if (land[x][z] == 1) {
                        i = z;
                        break;
                    } else if (z == i + balls[ball] - 1) {
                        solve (ball - 1, land, i, x, z, x);
                    }
                }
            }
        }
        
        //vertical check
        for (int x = 0; x < w; x++) {
            for (int i = 0; i <= h - balls[ball]; i++) {
                for (int z = i; z < i + balls[ball]; z++) {
                    if (land[z][x] == 1) {
                        i = z;
                        break;
                    } else if (z == i + balls[ball] - 1) {
                        solve (ball - 1, land, x, i, x, z);
                    }
                }
            }
        }
        
    }
    return 0;
}

int main() {
	// your code goes here
	int b, current;
	char l;
	cin >> h >> w >> b;
	for (int x = 0; x < b; x++) {
	    cin >> current;
	    balls.push_back(current);
	}
	sort (balls.begin(), balls.end());
	for (int x = 0; x < h; x++) {
	    for (int i = 0; i < w; i++) {
	        cin >> l;
	        if (l == '0') {
	            snow[x][i] = 0;
	        } else if (l == '1') {
	            snow[x][i] = 1;
	        }
	    }
	}
	solve (b - 1, snow, 0, 0, 0, 0);
	
	if (answer) {
	    cout << "yes" << endl;
	} else {
	    cout << "no" << endl;
	}
	
	return 0;
}
