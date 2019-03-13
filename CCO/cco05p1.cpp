#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int grid[101][101] = {0};
int v[101][101] = {0}, A, B, C, n, m;

bool check (int x, int y, int V) {
    if (grid[y][x] != A && grid[y][x] != B && grid[y][x] != C) {
        return false;
    } else {
        v[y][x] = V;
    }
    if (y==m) {
        return true;
    } else {
        if (v[y][x-1] != V && x-1 >= 1 && check(x-1, y, V)) {
            return true;
        }
        if (v[y][x+1] != V && x+1 <= n && check(x+1, y, V)) {
            return true;
        }
        if (v[y-1][x] != V && y-1 >= 1 && check(x, y-1, V)) {
            return true;
        }
        if (v[y+1][x] != V && y+1 <= m && check(x, y+1, V)) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf ("%d %d", &n, &m);
    for (int x = 1; x <= m; x++) {
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &grid[x][i]);
        }
    }
    int cnt = 0;
    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            for (int z = 0; z <= 9; z++) {
                cnt++;
                A = x; B = y; C = z;
                //there are repeats but too lazy to optimize
                for (int i = 1; i <= n; i++) {
                    if (v[1][i] != cnt) {
                        if (check (i, 1, cnt)) {
                            vector <int> temp;
                            temp.push_back(x);
                            temp.push_back(y);
                            temp.push_back(z);
                            sort (temp.begin(), temp.end());
                            for (int l = 0; l < 3; l++) {
                                cout << temp[l] << " ";
                            } cout << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << "\n";
    return 0;
}
