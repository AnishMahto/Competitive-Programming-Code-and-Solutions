#include <iostream>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int r, c, kats, x, y;
	cin >> r >> c >> kats;
	int grid[r][c];
	memset(grid, 0, sizeof(grid[0][0]) * r * c);
	grid[0][0] = 1;
	for (int a = 0; a < kats; a++) {
	    cin >> y >> x;
	    grid[y - 1][x - 1] = -1;
	}
	for (int i = 0; i < r; i++) {
	    for (int z = 0; z < c; z++) {
	        if (grid[i][z] != -1 && (i != 0 || z != 0) ) {
	            if (i == 0 && z != 0) {
	                if (grid[i][z - 1] == -1 || grid[i][z - 1] == 0) {
	                    grid[i][z] = 0;
	                } else {
	                    grid[i][z] = grid[i][z - 1];
	                }
	            } else if (z == 0 && i != 0) {
	                if (grid[i - 1][z] == -1 || grid[i - 1][z] == 0) {
	                    grid[i][z] = 0;
	                } else {
	                    grid[i][z] = grid[i - 1][z];
	                }
	            } else {
	                if (grid[i][z - 1] != -1) {
	                    grid[i][z] += grid[i][z - 1];
	                }
	                if (grid[i - 1][z] != -1) {
	                    grid[i][z] += grid[i - 1][z];
	                }
	            }
	        }
	    }
	}
	cout << grid[r - 1][c - 1] << endl;
	return 0;
}
